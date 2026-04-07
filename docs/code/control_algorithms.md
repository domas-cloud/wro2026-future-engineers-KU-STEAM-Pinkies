# Control Algorithms

## Architecture

The control logic should separate perception from actuation:

- the Pi Zero captures and forwards camera data;
- the ESP32 interprets camera and sensor information and drives the hardware.
- the ESP32 receives control commands and drives the hardware.

## Core Control Responsibilities

- extract lane position or lane error from the camera input;
- combine camera input with `BNO085` and `VL53L5CX` support signals;
- convert the current error into a steering command;
- limit steering changes so the robot does not oscillate;
- reduce drive output when confidence is low or the robot is in recovery.

## Algorithm Types

- lane-following control;
- steering correction;
- obstacle response;
- safety overrides when a sensor input looks invalid.

## Preferred Behavior Stack

- camera input first for lane geometry;
- inertial support for heading stability;
- local distance sensing for obstacle confirmation;
- state-machine logic for deciding whether to follow, avoid, slow down, or stop.

## Documentation Notes

If the team later chooses a different control method, the document should explain why that choice was better than the previous one and what evidence led to the change.

## Documentation Requirement

Explain the algorithm choice, the reason it fits the robot, and the failure cases it must handle.
