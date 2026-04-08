# Code Architecture

## Separation Of Subsystems

- the camera capture layer runs on the `Raspberry Pi Zero`;
- the control and actuator layer runs on the `ESP32`;
- a shared interface layer transfers commands, sensor-related data, and safety states.

## Module Map

- `camera`: camera capture on the `Raspberry Pi Zero`, frame transfer to the `ESP32`, and camera-link status monitoring;
- `sensing`: `BNO085` orientation data, input from the 2 `VL53L5CX` matrix ToF modules, and sensor health checks on the `ESP32` side;
- `control`: error calculation, steering correction, drive output generation, and state logic on the `ESP32` side;
- `safety`: input validity checks, communication-loss behavior, and safe stop handling;
- `communication`: camera-data transfer from the Pi Zero to the `ESP32` and optional keepalive messages if used.

## Interface Contract

The message sent between the boards should carry only the information needed for reliable camera-data transfer:

- camera frame or processed observation data;
- frame timestamp or sequence number;
- capture status;
- a short status indicator if the link supports it.

The exact transport may vary, but the purpose should remain the same: the `Raspberry Pi Zero` supplies camera data, while the `ESP32` performs all computation.
In this project, the code should be stored in the same repository rather than in an external submodule.

## Data Flow

1. Camera data is captured on the `Raspberry Pi Zero`.
2. The Pi Zero transfers the camera data to the `ESP32`.
3. The `ESP32` processes camera, IMU, and distance-sensor information.
4. The `ESP32` selects a behavior state, such as lane following or obstacle avoidance.
5. The `ESP32` turns those decisions into `MG90S` steering output and `L298N` motor control.
6. The `ESP32` keeps checking sensor validity and can switch to a safe state if the inputs become unreliable.

## Why This Structure

This split keeps the system understandable and reduces the risk of one function becoming responsible for everything.
It also makes the repository easier to reproduce because each layer has a clear responsibility.

## Startup Sequence

- initialize the compute boards;
- activate the camera path and sensor buses;
- confirm readiness of the `BNO085` and 2 `VL53L5CX` modules on the `ESP32` side;
- confirm camera-data flow between the `Raspberry Pi Zero` and `ESP32`;
- set the `MG90S` to its center position;
- keep the `N20` output disabled until the full system is ready.

## Fault Handling

- if camera data is missing, the robot should remain in a safe idle or hold state;
- if sensor input is missing, the system should choose the safest available behavior rather than guessing;
- if the camera link drops, the `ESP32` should stop or hold the last safe state according to the selected safety policy;
- if the startup sequence is incomplete, the motor must not be enabled.
