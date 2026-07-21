# Start Here

> **Current state:** Hardware V1 is the verified historical baseline. Hardware V2 is the active custom-PCB/PixyCam redesign. Nothing from Hardware V1 is deleted; rewritten text is preserved under [`archivo/`](archivo/).

## Hardware V2 confirmed

- main controller: `ESP32-WROOM-32`;
- Raspberry Pi Zero removed from the active robot;
- first-generation `PixyCam` / CMUcam5;
- PixyCam communication: wired SPI;
- front ToF: `VL53L1X`;
- side ToF: `2x VL53L4CD`;
- IMU: `BNO085`;
- steering servo: `MG90S`;
- battery chemistry: LiPo;
- custom PCB direction;
- faster drive motor direction.

## Hardware V2 still TBD

- exact LiPo pack and connector;
- exact faster motor;
- exact H-bridge;
- regulators and protection parts;
- ESP32 physical PCB implementation;
- complete GPIO and connector map;
- PCB dimensions, layers and mounting holes;
- PixyCam signatures and measured detection limits;
- final firmware;
- final power, thermal, Open and Obstacle results.

## Best reading path

1. [`README.md`](README.md)
2. [`Hardware V2 decision register`](docs/hardware/hardware_v2_decision_register.md)
3. [`Hardware V2 custom PCB plan`](docs/hardware/hardware_v2_custom_pcb_plan.md)
4. [`Active BOM`](docs/hardware/parts_list.md)
5. [`Electronics overview`](docs/hardware/electronics_overview.md)
6. [`PixyCam SPI plan`](docs/code/pixycam_spi_integration_plan.md)
7. [`Software architecture`](docs/code/software_architecture_improved.md)
8. [`Motor upgrade plan`](docs/design/hardware_v2_motor_upgrade_plan.md)
9. [`Hardware V2 validation template`](docs/testing/hardware_v2_validation_template.md)
10. [`Evidence map`](docs/reproducibility/evidence_map.md)

## Team

- **Marius** — software development and mechanical design;
- **Domas** — project coordination, testing and documentation;
- **Jonas** — electronics and hardware design.

## Version guide

### Hardware V1

The historical working baseline used Raspberry Pi Zero, ESP32, perfboard, L298N, N20 250 rpm and a 2x18650 supply. Its code, documents, media and measurements remain available as development evidence.

### Hardware V2

The active target uses ESP32-WROOM-32, first-generation PixyCam over SPI, custom PCB, LiPo and a faster motor. It is not yet a finished or reproducible final robot.

## Rebuild status

- Hardware V1: historical rebuild evidence available;
- Hardware V2: exact rebuild instructions pending component lock, PCB files and final firmware.

## Archive rule

Before changing an active historical text file:

1. copy its current blob into the matching `archivo/` path;
2. rewrite the active file using confirmed facts;
3. label missing information as `TBD` or describe the evidence required;
4. record the change in `CHANGELOG.md`;
5. never present an estimate as a measurement.

Current milestone: **v1.2 Hardware V2 architecture and text alignment**.
