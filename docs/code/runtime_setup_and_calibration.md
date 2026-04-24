# Runtime Setup And Calibration

This page explains how to move from source code to a ready-to-run robot using only documented repository information.

## Software Layers

| Layer | Location | Role |
| --- | --- | --- |
| ESP32 controller | [src/src/main.cpp](../../src/src/main.cpp) | real-time motor, steering, sensor, and state control |
| ESP32 libraries | [src/lib/](../../src/lib/) | compass, lidar, engine, and lights helpers |
| PlatformIO project | [src/platformio.ini](../../src/platformio.ini) | build and upload configuration |
| Pi Zero interface | [src/pi-zero/README.md](../../src/pi-zero/README.md) | perception-side runtime note |
| Pi packet format | [src/pi-zero/protocol.md](../../src/pi-zero/protocol.md) | UART message contract |

## ESP32 Build And Upload

1. Open [src/](../../src/) as the PlatformIO project.
2. Confirm the selected board/environment in [platformio.ini](../../src/platformio.ini).
3. Connect the `ESP32-WROOM-32` by USB.
4. Build the firmware.
5. Upload the firmware.
6. Open the serial monitor at `115200` baud for startup checks.

## Pi Zero Runtime

If perception packets are used:

1. connect the camera to the `Raspberry Pi Zero`;
2. connect Pi UART to `ESP32 GPIO16/GPIO17` using `3.3 V` TTL;
3. install dependencies listed for the Pi runtime;
4. start the Pi runtime according to [src/pi-zero/README.md](../../src/pi-zero/README.md);
5. verify packet format against [protocol.md](../../src/pi-zero/protocol.md).

Expected packet:

```text
VISION,<mode>,<lane_shift_mm>,<obstacle_side>,<confidence>,<age_ms>
```

## Pre-Run Calibration

| Step | Why it matters | Pass condition |
| --- | --- | --- |
| charge battery | low voltage changes motor and servo behavior | robot can steer and drive without brownout |
| center steering | reduces first-meter drift | front wheels return close to straight |
| check motor direction | prevents immediate wrong-way launch | forward command moves robot forward |
| keep robot still during IMU start | yaw baseline depends on stable startup | heading is stable while stationary |
| check ToF sensors | wall and obstacle logic depends on valid distance | front/left/right values change when blocked |
| check Pi packet age if used | stale vision data should not guide the robot | packets are fresh before starting |

## Start Procedure

1. Place the robot in the required start position.
2. Power the robot and wait for sensor initialization.
3. Keep the robot still and aligned with the track.
4. Press the physical start button.
5. The controller stores the current yaw as the target heading.
6. The run loop starts motor, steering, sensor, and state updates.

## Post-Run Logging

After a test run, record:

- date;
- code commit or branch;
- battery condition;
- challenge type;
- field layout;
- pass/fail result;
- visible cause of failure if any;
- whether calibration was changed before the next run.

Use [docs/testing/final_validation_results.md](../testing/final_validation_results.md) for the final counted run table.

