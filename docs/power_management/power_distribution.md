# Power Distribution

## Power Path

The robot must distribute battery power to the motor, steering servo, ESP32, Raspberry Pi Zero, and sensors in a controlled way.

## Design Goals

- keep noisy motor loads from disturbing the compute boards;
- use regulated rails where needed;
- make the power path easy to trace in the wiring diagram;
- document which component depends on which voltage.

## Why This Matters

Power issues often look like software bugs.
This section should make it clear how the robot avoids that confusion.

## Power Architecture For This Robot

The robot uses a shared battery source but separates the load by function:

- the drive motor is powered through the `L298N` motor path;
- the `ESP32` handles low-level control on a regulated logic rail;
- the `Raspberry Pi Zero` receives its own stable logic supply;
- the `MG90S` servo is powered from a rail that can handle steering transients;
- the `BNO085` and `VL53L5CX` are powered from the sensor-side logic supply according to the breakout requirements.

## Design Reasoning

This layout reduces the chance that drive current dips will reset the compute boards or corrupt sensor readings.
It also makes troubleshooting easier, because any power issue can be traced to a specific branch instead of the whole robot.

## Power-Up Sequence

1. battery connects to the power distribution path;
2. logic rails stabilize first;
3. `ESP32` and `Raspberry Pi Zero` boot and confirm internal readiness;
4. sensors initialize and report valid status;
5. `MG90S` centers the steering;
6. `N20` drive output is enabled only after the system is ready.

## Failure Handling

- if logic voltage sags, the robot should not continue driving;
- if the motor branch causes resets, the drive path needs to be isolated or filtered more aggressively;
- if the servo current disturbs the logic rail, the servo supply needs its own buffering or regulator path;
- if sensor readings become unstable during motion, verify grounding and cable routing first.
