# Electronics Overview

## System Split

The robot uses two main compute layers:

- ESP32 for low-level hardware control and timing-sensitive tasks;
- Raspberry Pi Zero for camera processing and higher-level logic.

## Functional Boundaries

- the `Raspberry Pi Zero` handles perception and high-level driving decisions;
- the `ESP32` handles steering output, motor control, and fast safety response;
- the sensor set is split between global perception (`camera`) and local confirmation (`BNO085`, `VL53L5CX`);
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

- Pi Zero decides what the robot should do;
- ESP32 executes fast actuator commands;
- sensors provide navigation context and safety data;
- the battery pack supplies motor power while logic rails are regulated separately.

## Documentation Output

This section should be backed by wiring diagrams and a clear connection list in `schemes/`.
