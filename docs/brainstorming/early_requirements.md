# Early Requirements

## Functional Requirements

- follow the lane reliably;
- detect obstacles and respond without leaving the intended trajectory;
- maintain proportional and stable steering commands;
- clearly separate camera capture on the `Raspberry Pi Zero` from all computation on the `ESP32`.

## Non-Functional Requirements

- the repository should be clear enough that another team could reproduce the robot;
- the structure must remain rigid over repeated runs;
- the power system must be safe for controllers, sensors, and motors;
- the software architecture must be understandable from the modules and documentation.

## Early Design Goals

- the `ESP32` handles real-time control;
- the `Raspberry Pi Zero` provides camera input only;
- the `BNO085` and 2 `VL53L5CX` modules complement the camera input;
- the robot should be easy to inspect, tune, and maintain.
