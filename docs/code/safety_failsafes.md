# Safety And Failsafes

## Purpose

The robot needs safe fallback behavior when a sensor fails, the control loop becomes unstable, or the robot loses awareness of its surroundings.

## Examples

- reduce speed when camera confidence is low;
- stop or hold state when sensor data becomes invalid;
- return steering to center if the command stream fails;
- prevent unsafe motor output during startup.

## Priority Order

1. protect the hardware;
2. prevent unsafe robot movement;
3. keep enough state for graceful recovery;
4. return to normal driving only when sensors and communication are healthy.

## Specific Failsafes

- if camera capture on the `Raspberry Pi Zero` stops, the robot must not continue applying stale steering commands;
- if `BNO085` data becomes invalid, heading corrections should be reduced or disabled;
- if readings from the 2 `VL53L5CX` matrix ToF modules begin to jump unexpectedly, the robot should switch to more cautious motion or a stopped state;
- if the camera-data link between the `Raspberry Pi Zero` and `ESP32` drops, the `ESP32` must switch to a safe no-command mode.

## Documentation Rule

Each safety action should be tied to the specific failure type it protects against.

## Testing Expectation

Each failsafe should be tested at least once in a controlled scenario so the team can describe what happened and confirm that the fallback behavior works.
