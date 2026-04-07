# Electronics Overview

## System Split

The robot uses two main compute layers:

- Raspberry Pi Zero for camera capture only;
- ESP32 for calculations, control, and timing-sensitive tasks.

## Functional Boundaries

- the `Raspberry Pi Zero` handles camera capture only;
- the `ESP32` handles calculations, steering output, motor control, and fast safety response;
- the camera feed is the Pi Zero input; the `BNO085` and `VL53L5CX` are read by the `ESP32`;
- the battery and regulators provide clean power, not behavior.

## Main Electrical Blocks

- `L298N H-bridge` for the `N20` drive motor;
- `MG90S` steering servo;
- camera on the `Raspberry Pi Zero`;
- `BNO085 9-DOF IMU`;
- `VL53L5CX` matrix ToF lidar;
- power regulation and distribution.

## Design Intent

The electronics architecture should keep the control stack understandable:

- Pi Zero provides camera input;
- ESP32 makes the driving decisions and executes actuator commands;
- sensors provide navigation context and safety data directly to the ESP32;
- the battery pack supplies motor power while logic rails are regulated separately.

## Documentation Output

This section should be backed by wiring diagrams and a clear connection list in `schemes/`.
