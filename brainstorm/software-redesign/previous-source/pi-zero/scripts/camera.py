import platform

import cv2


WIDTH = 640
HEIGHT = 360


def is_raspberry_pi() -> bool:
    uname = platform.uname()
    text = " ".join([uname.node, uname.machine, uname.release]).lower()
    return "raspberry" in text or "aarch64" in text


IS_RASPBERRY = is_raspberry_pi()

if IS_RASPBERRY:
    from picamera2 import Picamera2


class Camera:
    def __init__(self, device: int = 0, width: int = WIDTH, height: int = HEIGHT):
        self.width = width
        self.height = height

        if IS_RASPBERRY:
            self.camera = Picamera2()
            self.camera.configure(
                self.camera.create_video_configuration(
                    main={"format": "RGB888", "size": (1640, 922)}
                )
            )
            self.camera.set_controls({"FrameRate": 15})
            self.camera.start()
        else:
            self.camera = cv2.VideoCapture(device)

    def get_output(self):
        if IS_RASPBERRY:
            frame = self.camera.capture_array()
        else:
            success, frame = self.camera.read()
            if not success:
                return None

        return cv2.resize(frame, (self.width, self.height), interpolation=cv2.INTER_AREA)

    def release(self):
        if not IS_RASPBERRY:
            self.camera.release()
