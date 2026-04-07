# Navigation Logic

## Expected Behavior

The robot should follow the lane, recognize relevant obstacles, and switch behavior when the field situation changes.

The navigation layer should combine camera data with `BNO085` and `VL53L5CX` inputs rather than relying on a single sensor stream.

## High-Level Flow

- sense the current scene;
- decide whether lane following or obstacle handling has priority;
- send steering and drive commands;
- monitor for error conditions.

## Suggested State Model

- `INIT` for hardware and sensor startup;
- `LANE_FOLLOW` for normal driving;
- `OBSTACLE_CHECK` for local distance confirmation;
- `AVOID_OR_STOP` when the path is blocked or uncertain;
- `RECOVER` when the lane becomes visible again.

## Transition Rules

- `INIT -> LANE_FOLLOW` when sensors and compute boards report ready;
- `LANE_FOLLOW -> OBSTACLE_CHECK` when a nearby obstacle or boundary is detected;
- `OBSTACLE_CHECK -> AVOID_OR_STOP` when the obstacle is confirmed;
- `AVOID_OR_STOP -> RECOVER` when the path becomes safe again;
- `RECOVER -> LANE_FOLLOW` when lane visibility and sensor confidence return to normal.

## Behavior Notes

- lane following should be the default state;
- obstacle handling should temporarily override lane following;
- the robot should return to lane following only after the path is clear and the sensor input is stable;
- steering commands should be limited when the robot is in a recovery or uncertainty state.

## Decision Inputs

- camera for lane geometry and obstacle context;
- `BNO085` for heading stability and motion awareness;
- `VL53L5CX` for nearby obstacle confirmation;
- communication health between the Raspberry Pi Zero and ESP32;
- power or startup status if the robot exposes that to software.

## What The Documentation Must Show

- the decision sequence;
- the state changes;
- how obstacle handling interacts with lane following;
- how the system recovers after an interruption.
