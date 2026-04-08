# Legacy Algorithm Mapping

## What Stays The Same

What carries over from the older robot is not the exact sensor implementation, but the same control-logic structure:

- error calculation;
- PD or similar corrective control;
- steering and drive command generation;
- obstacle logic and safe stopping.

The input types and hardware change, but the core control idea does not.
This means the same sensor-reading layer is not reused directly; instead, the decision-making and corrective-control structure is adapted.

## What Changes

| Old repository component | New repository component | Note |
| --- | --- | --- |
| `Arduino Mega 2560` | `ESP32` | Control moves to the `ESP32`, because it performs all computation and command output. |
| `Raspberry Pi Zero 2` | `Raspberry Pi Zero` | In the new version, the Pi provides `OV5647` camera data, and forward-distance estimation is handled inside the shared control logic. |
| `Adafruit Motor Shield V2` | `L298N H-bridge` | The motor-control hardware changes, but the drive logic remains similar. |
| `VL53L1X` | 2 x `VL53L5CX` | ToF-based obstacle confirmation remains, but the system uses only 2 modules to save power. |
| `TCS34725` | not used | If this function is unnecessary in the new robot, its logic is not carried over. |
| `SG90` | `MG90S` | The steering-servo principle stays the same, but the specific servo changes. |
| DC motor + gearbox | `N20` + `L298N` | The drive logic remains, while the hardware solution changes. |

## Main Differences Between The Robots

- The current robot is smaller and simpler than the previous one because we learned that too many subsystems make tuning harder.
- The previous robot used more separate hardware layers and a broader sensor mix, while this robot is reduced to what directly improves stable driving.
- In the current robot, the `Raspberry Pi Zero` is used only for camera capture, and all decisions and calculations are handled by the `ESP32`.
- The ToF sensor count is reduced to 2 matrix `VL53L5CX` modules because the camera now contributes more to forward-distance estimation.
- Mechanically, the current robot is built around shorter mechanical paths, less play, and easier maintenance.
- The current repository does not keep active code in an external `src` submodule; the full active software logic should live in this repository.

## Logic That Is Carried Over

The old repository README showed a control sequence like this:

1. input acquisition;
2. error estimation;
3. PD control;
4. servo steering;
5. motor-speed correction;
6. obstacle logic.

The same structure can be transferred to the new robot, but adapted to `ESP32` computation, camera data from the `Raspberry Pi Zero`, and a smaller ToF set.

## How It Looks In The New Robot

- the `Raspberry Pi Zero` captures the `OV5647` camera and forwards image data;
- the `ESP32` combines the camera information with the `BNO085` and 2 `VL53L5CX` modules;
- the `ESP32` calculates error, estimates the forward situation, and chooses a behavior state;
- the `ESP32` sends steering-servo and motor commands;
- the safety logic interrupts driving if the inputs become unreliable.

## Purpose Of This Document

This document shows how the old control scheme was transferred into the new robot architecture without changing the core control philosophy.
