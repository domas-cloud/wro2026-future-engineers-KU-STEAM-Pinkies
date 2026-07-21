# Embedded Controller

This folder contains the active PlatformIO project for the robot controller.

## Main Files

- [src/src/main.cpp](src/main.cpp): main robot loop
- [src/lib/Lidar/Lidar.h](lib/Lidar/Lidar.h): distance sensor abstraction
- [src/lib/Compass/Compass.h](lib/Compass/Compass.h): `BNO085` yaw handling
- [src/lib/Engine/Engine.h](lib/Engine/Engine.h): motor control wrapper
- [src/lib/Lights/](lib/Lights/): status lights
- [src/platformio.ini](platformio.ini): PlatformIO configuration
- [src/pi-zero/README.md](pi-zero/README.md): perception-side architecture note
- [src/pi-zero/protocol.md](pi-zero/protocol.md): Pi-to-ESP32 packet format

## Current Runtime Model

The documented runtime is split into two controllers:

- an `ESP32` low-level controller under `src/src/main.cpp`;
- a `Raspberry Pi Zero` perception-side architecture described under `src/pi-zero/`.

The `ESP32` controller:

- initializes three distance sensors and one compass;
- waits for a start button;
- drives forward at constant power;
- keeps heading close to `targetAngle`;
- uses side distance as an additional steering correction;
- performs a hard left or right turn when the front sensor detects a close boundary;
- counts sector transitions with `edge`;
- stops cleanly when the run is finished.

The documented `Raspberry Pi Zero` side:

- selects a reference shift and obstacle-pass side at a higher level;
- is intended to send a compact packet to the `ESP32`;
- should time out to a neutral command if fresh perception data is unavailable.

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
4. Review the Pi-side interface notes in `src/pi-zero/` if the perception layer is used.
5. Use the physical start button to toggle the run state.

## Related Documentation

- [Root README](../README.md)
- [Software Architecture](../docs/code/software_architecture_improved.md)
- [Software Flow and State Logic](../docs/code/software_flow_and_state_logic.md)
- [Electronics Overview](../docs/hardware/electronics_overview.md)
