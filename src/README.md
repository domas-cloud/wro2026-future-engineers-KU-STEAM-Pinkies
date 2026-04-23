# Embedded Controller

This folder contains the active PlatformIO project for the robot controller.

## Main Files

- `src/src/main.cpp`: main robot loop
- `src/lib/Lidar/Lidar.h`: distance sensor abstraction
- `src/lib/Compass/Compass.h`: `BNO085` yaw handling
- `src/lib/Engine/Engine.h`: motor control wrapper
- `src/lib/Lights/`: status lights
- `src/platformio.ini`: PlatformIO configuration

## Current Runtime Model

The published firmware is an `ESP32` controller that:

- initializes three distance sensors and one compass;
- waits for a start button;
- drives forward at constant power;
- keeps heading close to `targetAngle`;
- uses side distance as an additional steering correction;
- performs a hard left or right turn when the front sensor detects a close boundary;
- counts sector transitions with `edge`.

## Important Runtime Variables

- `targetAngle`: desired heading reference
- `edge`: number of completed sector turns
- `isClockwise`: selected turning direction
- `Kp`, `Kg`, `Kd`: control gains
- `TARGET_DISTANCE`: desired wall offset
- `TURN_DISTANCE`: threshold that triggers a corner turn

## Build And Upload

1. Open `src/` as a PlatformIO project.
2. Build the environment from `src/platformio.ini`.
3. Upload to the `ESP32`.
4. Use the physical start button to toggle the run state.
