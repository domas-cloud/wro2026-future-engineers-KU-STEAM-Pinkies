# Control Software

This directory contains the robot's control software and any files required to build or run it.

Recommended layout:

- `perception/` for camera and sensor processing on the Raspberry Pi Zero;
- `control/` for steering, drive, and state logic;
- `communication/` for messages between the Pi Zero and ESP32;
- `tests/` for software-level validation helpers if needed.

Keep the code structure aligned with the documentation in `docs/code/`.

Suggested responsibilities:

- camera interpretation and obstacle awareness on the `Raspberry Pi Zero`;
- `BNO085` and `VL53L5CX` preprocessing;
- serial command generation for the `ESP32`;
- `MG90S` steering control and `N20` drive output on the `ESP32` side.

Minimum documentation expectations for future code:

- include a short module list;
- include a startup or boot sequence;
- keep the command names aligned with `docs/code/message_protocol.md`;
- describe which parts run on the Pi Zero and which parts run on the ESP32;
- note any assumptions about the control loop rate or sensor update rate.
