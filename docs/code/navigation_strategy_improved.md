# Navigation Strategy

## Version status

The previous Hardware V1 strategy was archived at [`archivo/hardware-v1-esp32-250rpm/docs/code/navigation_strategy_improved.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/code/navigation_strategy_improved.md).

## Hardware V2 target strategy

- BNO085 provides heading feedback;
- front VL53L1X contributes corner-approach information;
- side VL53L4CD sensors provide local spacing;
- PixyCam identifies red/green pillar blocks;
- ESP32 selects the required passing reference and controls steering/motor outputs.

## Obstacle rule

- red pillar → pass right;
- green pillar → pass left.

The final code must define how block position and size become a path offset, when avoidance begins/ends, and how camera decisions interact with corner logic.

## Direction and corner logic

The Hardware V1 code selected direction and corner entry from sensor/sector conditions. Hardware V2 must publish the exact final method after it is implemented and tested. Old fixed-threshold descriptions should not override the source code.

## Finish and parking

The final strategy must document:

- direction selection;
- lap/sector counting;
- finish detection;
- parking approach;
- final steering state;
- restart behaviour.

Parking and final Obstacle behaviour remain `TBD` until the final runtime is tested.
