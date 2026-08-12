import argparse
import time

import cv2
import numpy as np
import serial

from scripts.camera import HEIGHT, IS_RASPBERRY, WIDTH, Camera
from scripts.pillar import Pillar


LOWER_GREEN = np.array([35, 60, 30])
UPPER_GREEN = np.array([90, 255, 255])

LOWER_RED_1 = np.array([0, 100, 100])
UPPER_RED_1 = np.array([8, 255, 255])
LOWER_RED_2 = np.array([168, 100, 100])
UPPER_RED_2 = np.array([180, 255, 255])

PILLAR_REAL_WIDTH_MM = 45
FOCAL_LENGTH_PX = (130 * 30) / 4.5


def find_largest_pillar(mask, color):
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    largest = Pillar(color=color)

    for contour in contours:
        area = cv2.contourArea(contour)
        if area <= largest.area:
            continue

        x, y, w, h = cv2.boundingRect(contour)
        largest = Pillar(x=x, y=y, w=w, h=h, cx=x + w // 2, cy=y + h // 2, area=area, color=color)

    return largest


def estimate_lateral_offset_mm(pillar):
    if pillar.w <= 0:
        return 0

    offset_x_px = pillar.cx - (WIDTH / 2)
    distance_y_mm = (PILLAR_REAL_WIDTH_MM * FOCAL_LENGTH_PX) / pillar.w
    return int(round(offset_x_px * distance_y_mm / FOCAL_LENGTH_PX))


def confidence_from_area(area):
    return max(0.0, min(1.0, area / 12000.0))


def packet_for_pillar(pillar, frame_started_at):
    age_ms = int((time.monotonic() - frame_started_at) * 1000)

    if not pillar.is_valid or pillar.area < 100:
        return f"VISION,TRACK,0,NONE,0.00,{age_ms}"

    obstacle_side = "LEFT" if pillar.color == "GREEN" else "RIGHT"
    lane_shift_mm = max(-250, min(250, estimate_lateral_offset_mm(pillar)))
    confidence = confidence_from_area(pillar.area)
    return f"VISION,OBSTACLE,{lane_shift_mm},{obstacle_side},{confidence:.2f},{age_ms}"


def draw_debug(frame, pillar):
    cv2.line(frame, (WIDTH // 2, 0), (WIDTH // 2, HEIGHT), (255, 255, 255), 2)

    if not pillar.is_valid:
        return

    color = (0, 255, 0) if pillar.color == "GREEN" else (0, 0, 255)
    cv2.rectangle(frame, (pillar.x, pillar.y), (pillar.x + pillar.w, pillar.y + pillar.h), color, 2)
    cv2.circle(frame, (pillar.cx, pillar.cy), 4, color, -1)


def open_serial(port, baud):
    return serial.Serial(port, baud, timeout=0.1)


def run_mock(port, baud, period_s):
    serial_out = open_serial(port, baud)
    packets = [
        "VISION,TRACK,0,NONE,0.95,0",
        "VISION,OBSTACLE,-120,LEFT,0.82,0",
        "VISION,OBSTACLE,120,RIGHT,0.82,0",
    ]

    index = 0
    while True:
        packet = packets[index % len(packets)]
        print(packet)
        serial_out.write((packet + "\n").encode("ascii"))
        serial_out.flush()
        index += 1
        time.sleep(period_s)


def parse_args():
    parser = argparse.ArgumentParser(description="Raspberry Pi Zero traffic pillar detector")
    parser.add_argument("--serial-port", "--port", default="/dev/ttyS0")
    parser.add_argument("--baud", type=int, default=9600)
    parser.add_argument("--camera", type=int, default=0)
    parser.add_argument("--display", action="store_true")
    parser.add_argument("--record", default="")
    parser.add_argument("--mock", action="store_true")
    parser.add_argument("--period", type=float, default=0.05)
    return parser.parse_args()


def main():
    args = parse_args()

    if args.mock:
        run_mock(args.serial_port, args.baud, args.period)
        return

    camera = Camera(device=args.camera)
    serial_out = open_serial(args.serial_port, args.baud)
    writer = None

    if args.record:
        writer = cv2.VideoWriter(
            args.record,
            cv2.VideoWriter_fourcc("M", "J", "P", "G"),
            15,
            (WIDTH, HEIGHT),
        )

    try:
        while True:
            frame_started_at = time.monotonic()
            frame = camera.get_output()

            if frame is None:
                time.sleep(args.period)
                continue

            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            mask_red = cv2.bitwise_or(
                cv2.inRange(hsv, LOWER_RED_1, UPPER_RED_1),
                cv2.inRange(hsv, LOWER_RED_2, UPPER_RED_2),
            )
            mask_green = cv2.inRange(hsv, LOWER_GREEN, UPPER_GREEN)

            red = find_largest_pillar(mask_red, "RED")
            green = find_largest_pillar(mask_green, "GREEN")
            pillar = green if green.area > red.area else red

            packet = packet_for_pillar(pillar, frame_started_at)
            serial_out.write((packet + "\n").encode("ascii"))
            serial_out.flush()
            print(packet)

            if args.display or writer:
                draw_debug(frame, pillar)

            if writer:
                writer.write(frame)

            if args.display and not IS_RASPBERRY:
                cv2.imshow("Pi Zero Vision", frame)
                if cv2.waitKey(1) & 0xFF == ord("q"):
                    break

            elapsed = time.monotonic() - frame_started_at
            time.sleep(max(0.0, args.period - elapsed))
    finally:
        camera.release()
        serial_out.close()
        if writer:
            writer.release()
        cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
