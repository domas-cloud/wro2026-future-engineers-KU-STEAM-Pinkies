# Start Here

> **Current state:** Hardware V1 is the verified historical baseline. Hardware V2 is the active custom-PCB/PixyCam redesign. Nothing from Hardware V1 is deleted; rewritten text is preserved under [`archivo/`](archivo/).

> **[NEXT-REVIEW] Continue here next time:** open [`NEXT_REVIEW.md`](NEXT_REVIEW.md). It contains the complete missing-information list, the files that must be updated, completion conditions and searchable status markers.

## Status markers

- `[HW1-HISTORY]` — verified older information retained as evidence;
- `[HW2-IMPROVEMENT]` — the change made or planned after Hardware V1;
- `[HW2-CONFIRMED]` — selected Hardware V2 fact;
- `[HW2-TBD]` — exact information is still missing;
- `[HW2-VERIFY]` — selected but still needs a physical test;
- `[HW2-DONE]` — implementation and evidence are complete.

Search for `HW2-TBD`, `HW2-VERIFY` or `NEXT-REVIEW` during the next repository check.

## Hardware V2 confirmed

- `[HW2-CONFIRMED]` main controller: `ESP32-WROOM-32`;
- `[HW2-CONFIRMED]` Raspberry Pi Zero removed from the active robot;
- `[HW2-CONFIRMED]` first-generation `PixyCam` / CMUcam5;
- `[HW2-CONFIRMED]` PixyCam communication: wired SPI;
- `[HW2-CONFIRMED]` front ToF: `VL53L1X`;
- `[HW2-CONFIRMED]` side ToF: `2x VL53L4CD`;
- `[HW2-CONFIRMED]` IMU: `BNO085`;
- `[HW2-CONFIRMED]` steering servo: `MG90S`;
- `[HW2-CONFIRMED]` battery chemistry direction: LiPo;
- `[HW2-CONFIRMED]` custom PCB direction;
- `[HW2-CONFIRMED]` faster drive motor direction.

## Hardware V2 still TBD

- `[HW2-TBD]` exact LiPo pack and connector;
- `[HW2-TBD]` exact faster motor;
- `[HW2-TBD]` exact H-bridge;
- `[HW2-TBD]` regulators and protection parts;
- `[HW2-TBD]` ESP32 physical PCB implementation;
- `[HW2-TBD]` complete GPIO and connector map;
- `[HW2-TBD]` PCB dimensions, layers and mounting holes;
- `[HW2-TBD]` PixyCam signatures and measured detection limits;
- `[HW2-TBD]` final firmware;
- `[HW2-TBD]` final power, thermal, Open and Obstacle results.

Each item is expanded in [`NEXT_REVIEW.md`](NEXT_REVIEW.md), including what evidence is needed and which files must be updated.

## Best reading path

1. [`README.md`](README.md)
2. [`NEXT_REVIEW.md`](NEXT_REVIEW.md)
3. [`Hardware V2 decision register`](docs/hardware/hardware_v2_decision_register.md)
4. [`Hardware V2 custom PCB plan`](docs/hardware/hardware_v2_custom_pcb_plan.md)
5. [`Active BOM`](docs/hardware/parts_list.md)
6. [`Electronics overview`](docs/hardware/electronics_overview.md)
7. [`PixyCam SPI plan`](docs/code/pixycam_spi_integration_plan.md)
8. [`Software architecture`](docs/code/software_architecture_improved.md)
9. [`Motor upgrade plan`](docs/design/hardware_v2_motor_upgrade_plan.md)
10. [`Hardware V2 validation template`](docs/testing/hardware_v2_validation_template.md)
11. [`Evidence map`](docs/reproducibility/evidence_map.md)

## Team

- **Marius** — software development and mechanical design;
- **Domas** — project coordination, testing and documentation;
- **Jonas** — electronics and hardware design.

## Version guide

### [HW1-HISTORY] Hardware V1

The historical working baseline used Raspberry Pi Zero, ESP32, perfboard, L298N, N20 250 rpm and a 2x18650 supply. Its code, documents, media and measurements remain available as development evidence.

### [HW2-IMPROVEMENT] Hardware V2

The active target replaces the Pi/UART/perfboard/18650/L298N arrangement with ESP32-WROOM-32, first-generation PixyCam over SPI, a custom PCB, LiPo power and a faster motor. It is not yet a finished or reproducible final robot.

The exact V1-to-V2 upgrade map is recorded in [`NEXT_REVIEW.md`](NEXT_REVIEW.md).

## Rebuild status

- `[HW1-HISTORY]` Hardware V1: historical rebuild evidence available;
- `[HW2-TBD]` Hardware V2: exact rebuild instructions pending component lock, PCB files, final firmware and measured validation.

## Archive rule

Before changing an active historical text file:

1. copy its current blob into the matching `archivo/` path;
2. rewrite the active file using confirmed facts;
3. label old information as `[HW1-HISTORY]` and state the Hardware V2 improvement;
4. label missing information as `[HW2-TBD]` and describe what is required;
5. record the change in `CHANGELOG.md`;
6. never present an estimate as a measurement.

Current milestone: **v1.2 Hardware V2 architecture, text alignment and follow-up tracking**.
