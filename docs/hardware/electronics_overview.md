# Electronics Overview

## System Split

The robot uses two main computing layers:

- `Raspberry Pi Zero` for camera input only;
- `ESP32` for control, decision-making, and time-sensitive tasks.

## Functional Boundaries

- The `Raspberry Pi Zero` is responsible only for camera capture and passing visual input onward.
- The `ESP32` handles computation, steering output, motor control, and fast safety reactions.
- The camera feed comes through the Pi Zero, while the `BNO085` and 2 `VL53L5CX` modules are read by the `ESP32`.
- The battery and regulators supply clean power; they are not part of the behavior logic.

## Main Electrical Blocks

- `L298N H-bridge` for the `N20` motor;
- `MG90S` steering servo;
- `OV5647 5Mpx wide-angle` camera (`Waveshare 14037`) connected to the `Raspberry Pi Zero`;
- `BNO085 9-DOF IMU`;
- 2 `VL53L5CX` matrix ToF modules;
- electronics assembly built on perfboard;
- power regulation and distribution stage.

## Design Goal

The electronics architecture is intended to keep the control chain easy to understand:

- The Pi Zero provides camera input.
- The `ESP32` uses that visual input to estimate the forward situation, reducing the need for many separate ToF sensors.
- The `ESP32` makes driving decisions and sends commands to the actuators.
- The sensors feed navigation context and safety data directly into the `ESP32`.
- The main electronics connections are assembled on perfboard to simplify mounting and wire routing.
- The battery pack provides motor power, while the logic rails are regulated separately.
