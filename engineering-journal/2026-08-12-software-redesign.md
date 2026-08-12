# Engineering Journal — Software Redesign Reset

**Date:** 2026-08-12  
**Robot:** Hardware V2  
**Area:** Software architecture and control

## Situation

The software material in the Hardware V2 branch still carried a large amount of thinking from the previous robot and from the first PixyCam migration plan.

Hardware V1 had used a Raspberry Pi Zero perception layer, ESP32 controller and UART communication. During Hardware V2 the robot architecture changed: the Raspberry Pi Zero was removed, first-generation PixyCam was selected, communication changed to wired SPI, electronics moved toward a custom PCB, power changed toward LiPo, and the drive motor / driver selection was reopened.

That meant the old software assumptions no longer described one stable physical robot.

## Decision

We decided to **clear the active Hardware V2 software documentation and source area before writing the next software version**.

The previous files were not discarded. They were copied to:

- `brainstorm/software-redesign/previous-docs/`
- `brainstorm/software-redesign/previous-source/`

The active `docs/code/` and `src/` locations now only describe the reset status and the conditions that must be met before new software is presented as current.

## Why we made this change

Keeping the old files in the active path would make it too easy to describe planned or untested behaviour as if it were already the final Hardware V2 implementation.

The reset gives us a clean boundary:

- old software = engineering history;
- new software = must match the final PCB, sensors, PixyCam connection, motor driver and real robot tests.

This also makes the development process clearer for the Engineering Journal because it records that we did not simply keep adding features to an architecture that no longer matched the hardware.

## Useful lessons kept from the previous software

We are not rejecting all previous ideas. The earlier work showed the value of:

- separating perception decisions from low-level steering and motor control;
- combining IMU heading feedback with local ToF distance measurements;
- handling missing or stale perception data;
- organizing autonomous behaviour as explicit states rather than one long loop;
- tuning software only after the steering and drivetrain are mechanically repeatable.

These lessons will be reconsidered when the new implementation is designed. They are not automatically final Hardware V2 choices.

## Next software steps

1. Lock the final custom-PCB GPIO and electrical interfaces.
2. Lock the motor driver and the motor behaviour that software must control.
3. Verify PixyCam SPI communication on the real hardware.
4. Record the exact PixyCam block data and signatures that are reliable on the field.
5. Build a minimal sensor / actuator bring-up program before navigation logic.
6. Define the smallest state machine required for Open and Obstacle Challenge operation.
7. Add fault handling and start / stop behaviour.
8. Tune heading, wall-distance, turn and obstacle behaviour from measured runs.
9. Record failures, parameter changes and repeated-run results.
10. Only then move the tested software from brainstorm/development into the active judge-facing documentation.

## Evidence rule

Future software claims should be tied to at least one of the following:

- source commit;
- field-test result;
- logged parameter comparison;
- photo / video;
- measured timing or sensor behaviour;
- documented failure and retest.

This reset is therefore not a loss of work. It is an explicit engineering iteration: the previous software remains evidence, while the active design starts again from the real Hardware V2 constraints.