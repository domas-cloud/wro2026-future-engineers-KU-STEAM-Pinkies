# Navigation Logic

## Expected Behavior

The robot must follow the lane, identify relevant obstacles, and change behavior when the track situation changes.

The navigation layer should combine camera data with input from the `BNO085` and the 2 `VL53L5CX` matrix ToF modules, rather than relying on only one sensor source.

## High-Level Flow

- estimate the current scene on the `ESP32`;
- decide whether lane following or obstacle handling has higher priority;
- send steering and drive commands;
- monitor error conditions.

## Proposed State Model

- `INIT` for hardware and sensor startup;
- `LANE_FOLLOW` for normal driving;
- `OBSTACLE_CHECK` for local distance confirmation;
- `AVOID_OR_STOP` when the path is blocked or uncertain;
- `RECOVER` when the lane becomes visible again.

## Transition Rules

- `INIT -> LANE_FOLLOW` when the sensors and compute boards report ready;
- `LANE_FOLLOW -> OBSTACLE_CHECK` when a nearby obstacle or boundary is detected;
- `OBSTACLE_CHECK -> AVOID_OR_STOP` when the obstacle is confirmed;
- `AVOID_OR_STOP -> RECOVER` when the path becomes safe again;
- `RECOVER -> LANE_FOLLOW` when lane visibility and sensor reliability return to normal.

## Behavior Notes

- lane following should be the default state;
- obstacle handling should temporarily take priority over lane following;
- the robot should return to lane following only when the path is clear and sensor input is stable;
- when the robot is in recovery or uncertainty, steering commands should be limited.

## Decision Inputs

- camera data from the `Raspberry Pi Zero`;
- `BNO085` for heading stability and motion awareness;
- 2 `VL53L5CX` matrix ToF modules for nearby obstacle confirmation;
- link status between the `Raspberry Pi Zero` and `ESP32`;
- power or startup state if the software monitors it.

## What The Documentation Should Show

- the decision sequence;
- state changes;
- how obstacle handling interacts with lane following;
- how the system recovers after an interruption.
