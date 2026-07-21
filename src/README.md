# Source Code Status

## Important version note

The previous source index was archived at [`archivo/hardware-v1-esp32-250rpm/src/README.md`](../archivo/hardware-v1-esp32-250rpm/src/README.md).

The source tree currently contains **Hardware V1 controller and Raspberry Pi development code**. Hardware V2 has confirmed PixyCam SPI architecture, but its final firmware is not yet implemented in this repository.

## Current directories

| Path | Current meaning |
|---|---|
| [`src/src/main.cpp`](src/main.cpp) | Hardware V1 ESP32 controller and legacy UART vision parser |
| [`src/lib/`](lib/) | Hardware V1 helpers for compass, distance sensors, motor and lights |
| [`src/platformio.ini`](platformio.ini) | current development-board PlatformIO environment |
| [`src/pi-zero/`](pi-zero/) | legacy Raspberry Pi Zero perception implementation |
| [`src/python/`](python/) | earlier legacy Raspberry Pi/OpenCV perception prototype |

The two Raspberry Pi directories are kept as development evidence. Raspberry Pi Zero is not part of Hardware V2.

## What the current ESP32 source does

The published controller includes:

- start-button handling;
- BNO085 yaw reading;
- front VL53L1X and side VL53L4CD reading;
- heading and wall-distance steering correction;
- corner execution;
- motor and MG90S output;
- legacy `VISION,...` UART parsing.

## What it does not yet do

The current source does not yet provide:

- first-generation PixyCam SPI initialization and block reading;
- final Hardware V2 GPIO map;
- final custom-PCB programming configuration;
- selected Hardware V2 H-bridge support;
- verified LiPo/power fault handling;
- final obstacle logic tested with the faster motor.

## Known text/code alignment items

Before Hardware V2 is marked final, resolve and test:

- code uses `GPIO14` for the button while old text used `GPIO13`;
- legacy UART code uses `9600` while old text also listed `115200`;
- obstacle mode is disabled by default in the current source;
- corner entry uses a dynamic expression, not one fixed `400 mm` threshold;
- finish behaviour calls `ESP.restart()` after stopping;
- derivative/error history should be reviewed and tested;
- sensor type should not be inferred from the XSHUT GPIO number;
- BNO085 reset and status LED pins must appear in the final pin map.

This README records discrepancies but does not silently change untested control code.

## Hardware V2 source required

The final source should contain clearly named modules for:

- PixyCam SPI;
- `VL53L1X` front sensor;
- `VL53L4CD` side sensors;
- BNO085;
- MG90S steering;
- selected motor driver;
- state machine and fault handling;
- final board configuration.

It must build from the published PlatformIO configuration and match the PCB schematic and wiring tables.

## Related documents

- [`Hardware V2 software architecture`](../docs/code/software_architecture_improved.md)
- [`Hardware V2 vision interface`](../docs/code/vision_interface.md)
- [`PixyCam SPI integration plan`](../docs/code/pixycam_spi_integration_plan.md)
- [`Runtime setup and calibration`](../docs/code/runtime_setup_and_calibration.md)
