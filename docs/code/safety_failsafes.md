# Safety and Fail-safes

## Purpose

The robot needs a safe fallback when a sensor fails, the control loop becomes unstable, or the robot loses track of the environment.

## Examples

- reduce speed when perception confidence is low;
- stop or hold state when sensor data is invalid;
- return steering toward center if the command stream fails;
- prevent unsafe motor output during startup.

## Priority Order

1. protect the hardware;
2. keep the robot from making unsafe motion;
3. preserve enough state to recover cleanly if possible;
4. resume normal driving only when sensors and communication are healthy.

## Build-Specific Failsafes

- if `Raspberry Pi Zero` vision stalls, the robot should not keep applying stale steering commands;
- if `BNO085` data becomes invalid, heading-based corrections should be reduced or disabled;
- if `VL53L5CX` readings jump unexpectedly, the robot should fall back to conservative motion or a stop state;
- if the command link between `Raspberry Pi Zero` and `ESP32` is interrupted, the `ESP32` should enter a safe idle behavior.

## Documentation Rule

Every safety action should be linked to the failure mode it protects against.

## Test Expectation

Each fail-safe should be exercised at least once in a controlled test so the team can describe what happened and confirm that the fallback worked.
