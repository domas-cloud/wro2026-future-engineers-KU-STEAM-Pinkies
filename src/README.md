# Control Software

This folder stores the robot control code.
Active project code should remain in this repository, not in an external `src` submodule.

## Code Structure

- `perception/` for camera and sensor data capture on the `Raspberry Pi Zero`;
- `control/` for steering, driving, and state logic;
- `communication/` for messages between the Pi Zero and `ESP32`;
- `safety/` for safe stop and error-handling logic;
- `tests/` for software validation.

## Responsibilities

- camera input and vision processing on the `Raspberry Pi Zero` side;
- use of `BNO085` and the 2 `VL53L5CX` matrix ToF modules on the `ESP32` side;
- transfer of high-level visual results to the `ESP32`;
- `MG90S` steering control and `N20` motor output on the `ESP32` side.

## Current Hardware Baseline

- steering servo: `MG90S`
- drive motor: `N20`
- drive motor rating: `6 V [SET_REAL_RPM] rpm`
