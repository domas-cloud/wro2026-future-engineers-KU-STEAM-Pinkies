# Code Architecture

## Intended Separation

- perception layer on the Raspberry Pi Zero;
- control and actuation layer on the ESP32;
- shared interface for commands, sensor readings, and safety states.

## Module Map

- `perception`:
  - camera capture and frame preprocessing;
  - lane and obstacle interpretation;
  - confidence handling when vision is unstable.
- `sensing`:
  - `BNO085` orientation and motion input;
  - `VL53L5CX` distance frames;
  - sensor health checks and simple filtering.
- `control`:
  - steering correction;
  - drive output shaping;
  - state-machine based behavior selection.
- `communication`:
  - Pi Zero to ESP32 command messages;
  - acknowledgements or watchdog-style heartbeats if used;
  - safe fallback when the link pauses.

## Interface Contract

The inter-board message should carry the minimum information needed for stable driving:

- requested behavior state;
- steering target or correction value;
- drive enable and drive level;
- sensor or confidence flags that affect safety behavior;
- a short health indicator if the link supports it.

The exact transport can vary, but the purpose should stay the same: the Pi Zero tells the ESP32 what to do, and the ESP32 confirms it can still execute safely.

## Data Flow

1. Camera and sensor data are captured on the Raspberry Pi Zero.
2. The Pi Zero estimates the current state of the robot and field.
3. The robot chooses a behavior state such as lane follow or obstacle handling.
4. High-level commands are sent to the ESP32.
5. The ESP32 converts those commands into `MG90S` steering output and `L298N` motor control.
6. The robot keeps checking sensor validity and can drop into a safe state if the inputs are unreliable.

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
- bring up the camera and sensor buses;
- check `BNO085` and `VL53L5CX` readiness;
- confirm communication between `Raspberry Pi Zero` and `ESP32`;
- set `MG90S` steering to center;
- keep the `N20` drive output disabled until the system is ready.

## Error Handling

- if perception confidence is low, reduce steering aggression or hold the robot in a conservative state;
- if sensor input is missing, use the safest available behavior instead of guessing;
- if the command link drops, the ESP32 should stop or hold the last safe state according to the chosen safety policy;
- if the startup sequence does not complete, do not arm the drive motor.
