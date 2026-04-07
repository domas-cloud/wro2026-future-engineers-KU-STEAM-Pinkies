# Control Software

This folder contains the robot's control code and anything needed to run it.

## Intended Structure

- `perception/` for camera and sensor processing on the `Raspberry Pi Zero`;
- `control/` for steering, drive, and state logic;
- `communication/` for messages between the Pi Zero and `ESP32`;
- `tests/` for software validation helpers if needed.

## Responsibilities

- camera interpretation and obstacle awareness on the `Raspberry Pi Zero`;
- `BNO085` and `VL53L5CX` preprocessing;
- serial command generation for the `ESP32`;
- `MG90S` steering control and `N20` drive output on the `ESP32` side.

## Documentation Expectations

- list the modules clearly;
- explain which parts run on the Pi Zero and which parts run on the `ESP32`;
- keep command names aligned with `docs/code/message_protocol.md`;
- describe the startup sequence;
- note any assumptions about control loop rate or sensor update rate.
