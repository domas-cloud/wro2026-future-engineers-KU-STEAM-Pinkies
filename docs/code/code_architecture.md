# Code Architecture

## Intended Separation

- camera capture layer on the Raspberry Pi Zero;
- control and actuation layer on the ESP32;
- shared interface for commands, sensor readings, and safety states.

## Module Map

- `camera`:
  - camera capture on the Raspberry Pi Zero;
  - frame forwarding to the ESP32;
  - capture health handling.
- `sensing`:
  - `BNO085` orientation and motion input on the ESP32;
  - `VL53L5CX` distance frames on the ESP32;
  - sensor health checks and simple filtering.
- `control`:
  - steering correction;
  - drive output shaping;
  - state-machine based behavior selection;
  - all calculations on the ESP32.
- `communication`:
  - Pi Zero to ESP32 camera-data messages;
  - acknowledgements or heartbeat messages if used;
  - safe fallback when the link pauses.

## Interface Contract

The inter-board message should carry the minimum information needed to deliver camera data reliably:

- camera frame or camera observation data;
- frame timestamp or sequence counter;
- capture status;
- a short health indicator if the link supports it.

The exact transport can vary, but the purpose should stay the same: the Pi Zero supplies camera data and the ESP32 handles the calculations.

## Data Flow

1. Camera data is captured on the Raspberry Pi Zero.
2. The Pi Zero forwards the camera data to the ESP32.
3. The ESP32 processes camera, IMU, and distance sensor input.
4. The ESP32 chooses a behavior state such as lane follow or obstacle handling.
5. The ESP32 converts those decisions into `MG90S` steering output and `L298N` motor control.
6. The ESP32 keeps checking sensor validity and can drop into a safe state if the inputs are unreliable.

## Why This Structure

This split keeps the system understandable and reduces the chance that one function becomes responsible for everything.
It also makes the repository easier to reproduce because each layer has a clear responsibility.

## What Should Be Included

- module list;
- data flow diagram;
- startup sequence;
- error handling and recovery behavior.

## Startup Sequence

- initialize compute boards;
- bring up the camera capture path and sensor buses;
- check `BNO085` and `VL53L5CX` readiness on the ESP32;
- confirm camera data flow between `Raspberry Pi Zero` and `ESP32`;
- set `MG90S` steering to center;
- keep the `N20` drive output disabled until the system is ready.

## Error Handling

- if camera data is missing, keep the robot in a safe idle or hold state;
- if sensor input is missing, use the safest available behavior instead of guessing;
- if the camera link drops, the ESP32 should stop or hold the last safe state according to the chosen safety policy;
- if the startup sequence does not complete, do not arm the drive motor.
