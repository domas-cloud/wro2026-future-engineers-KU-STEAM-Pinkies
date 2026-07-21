# Hardware V2 Decision Register

This page records what is confirmed, what is still open and what evidence is required before a decision can be presented as final.

> **[NEXT-REVIEW]** Every open decision is expanded in [`../../NEXT_REVIEW.md`](../../NEXT_REVIEW.md), including the exact information required, files to update and completion condition.

## Decision states and search markers

- `CONFIRMED` / `[HW2-CONFIRMED]` — selected by the team;
- `TBD` / `[HW2-TBD]` — not selected yet; no value should be invented;
- `VERIFY` / `[HW2-VERIFY]` — selected in principle but still requires measured validation;
- `DONE` / `[HW2-DONE]` — implemented, measured and consistent across the repository;
- `ARCHIVED` / `[HW1-HISTORY]` — no longer active, but preserved as development evidence;
- `[HW2-IMPROVEMENT]` — explains how V2 changes an older Hardware V1 solution.

Search for the decision ID, for example `HW2-POWER-01`, in [`NEXT_REVIEW.md`](../../NEXT_REVIEW.md) during the next update.

## Current register

| ID | Decision | Current state | Hardware V1 history and V2 improvement | Evidence still required |
|---|---|---|---|---|
| HW2-CTRL-01 | use `ESP32-WROOM-32` as the main controller | `[HW2-CONFIRMED]` | `[HW1-HISTORY]` V1 used an ESP32 development board; `[HW2-IMPROVEMENT]` V2 integrates the ESP32-WROOM-32 into the custom-PCB design | exact PCB implementation, GPIO map and bring-up test |
| HW2-VISION-01 | remove Raspberry Pi Zero from the active robot | `[HW2-CONFIRMED]` | `[HW1-HISTORY]` V1 used Pi Zero perception; `[HW2-IMPROVEMENT]` V2 removes the extra computer and its boot/power/UART path | archive completeness and final architecture diagram |
| HW2-VISION-02 | use first-generation `PixyCam` / CMUcam5 | `[HW2-CONFIRMED]` / `[HW2-VERIFY]` | `[HW2-IMPROVEMENT]` colour processing moves to the camera's onboard processor | exact hardware revision photo, power requirement, PixyMon settings and field detection tests |
| HW2-VISION-03 | connect PixyCam to ESP32 through wired SPI | `[HW2-CONFIRMED]` / `[HW2-VERIFY]` | `[HW1-HISTORY]` V1 used Pi-to-ESP32 UART; `[HW2-IMPROVEMENT]` V2 uses a direct camera-to-controller SPI link | logic-level check, pin map, clock rate, firmware and motor-on stability test |
| HW2-SENSOR-01 | use `VL53L1X` as the front ToF sensor | `[HW2-CONFIRMED]` / `[HW2-VERIFY]` | front-distance and turn-trigger role is retained | final mounting position, runtime settings and measured repeatability |
| HW2-SENSOR-02 | use `2x VL53L4CD` as left/right ToF sensors | `[HW2-CONFIRMED]` / `[HW2-VERIFY]` | `[HW1-HISTORY]` some V1 text incorrectly said `VL53L1CD`; `[HW2-IMPROVEMENT]` active V2 documentation uses the correct model | physical sensor-label photo, address plan and motor-on stability test |
| HW2-SENSOR-03 | retain `BNO085` IMU | `[HW2-CONFIRMED]` / `[HW2-VERIFY]` | the fused-yaw role is retained and must be validated in the final mounting | final mounting, orientation and calibration log |
| HW2-STEER-01 | retain `MG90S` steering servo | `[HW2-CONFIRMED]` / `[HW2-VERIFY]` | successful V1 steering lessons are retained while higher-speed load must be retested | peak current, centre repeatability and higher-speed steering validation |
| HW2-POWER-01 | move from `2x 18650` to LiPo | `[HW2-CONFIRMED]` / `[HW2-TBD]` | `[HW1-HISTORY]` V1 used a 2x18650 pack; `[HW2-IMPROVEMENT]` V2 moves to LiPo and recalculates the complete power tree | cell count, voltage, capacity, C-rating, connector, dimensions, regulators and safety process |
| HW2-MOTOR-01 | replace the 250 rpm motor with a faster motor | `[HW2-CONFIRMED]` / `[HW2-TBD]` | `[HW1-HISTORY]` V1 retained N20 250 rpm; `[HW2-IMPROVEMENT]` V2 reopens the choice for greater speed while requiring measured control and current evidence | candidate table, datasheets, loaded speed, current, temperature and repeated-run tests |
| HW2-DRIVER-01 | replace the `L298N` assumption with a custom-PCB drive stage | `[HW2-TBD]` | `[HW1-HISTORY]` V1 used an L298N module; `[HW2-IMPROVEMENT]` V2 selects an H-bridge from the actual motor and LiPo requirements | IC selection, current margin, logic compatibility, losses, protection and temperature test |
| HW2-PCB-01 | replace development-board/perfboard integration with custom PCB | `[HW2-CONFIRMED]` / `[HW2-VERIFY]` | `[HW1-HISTORY]` V1 used separate boards and perfboard; `[HW2-IMPROVEMENT]` V2 creates a labelled, reproducible integrated board | schematic, source files, Gerbers, drill files, BOM, assembly photos and bring-up log |
| HW2-SW-01 | publish final Hardware V2 firmware | `[HW2-TBD]` | `[HW1-HISTORY]` current source still contains V1 sensor/control and Pi/UART work; `[HW2-IMPROVEMENT]` V2 adds PixyCam SPI, final pin map and matching fault handling | code, build configuration, comments, upload test and code/document alignment |
| HW2-TEST-01 | validate the complete Hardware V2 robot | `[HW2-TBD]` | `[HW1-HISTORY]` V1 measurements remain historical; `[HW2-IMPROVEMENT]` V2 must be tested again with the new power, motor, camera and PCB | power, thermal, startup, camera, Open and Obstacle result tables |
| HW2-MEDIA-01 | publish final Hardware V2 media | `[HW2-TBD]` | `[HW1-HISTORY]` current six-view photos and Open video show V1; `[HW2-IMPROVEMENT]` V2 media must show the exact final revision | six-view photos, PCB photos, Pixy settings, Open video and Obstacle video |
| HW2-REBUILD-01 | publish a verified Hardware V2 rebuild path | `[HW2-TBD]` | V1 rebuild evidence remains historical; V2 requires exact parts, production files, source and calibration | exact BOM, manufacturing package, final code, startup steps and acceptance tests |

## Archived Hardware V1 decisions

The following remain valid as evidence of the previous working baseline:

- Raspberry Pi Zero perception layer;
- Pi CSI camera;
- Pi-to-ESP32 UART architecture;
- ESP32 development board and perfboard integration;
- `N20 6 V 250 rpm` motor;
- `L298N` module;
- `2x 18650` Li-ion pack.

Archived material is stored under [`archivo/hardware-v1-esp32-250rpm/`](../../archivo/hardware-v1-esp32-250rpm/). These items must be labelled `[HW1-HISTORY]` when referenced outside the archive and paired with the relevant V2 improvement.

## Change-control rule

When a current active file is changed because a Hardware V2 decision becomes final:

1. open [`NEXT_REVIEW.md`](../../NEXT_REVIEW.md) and locate the decision ID;
2. copy the previous active version into `archivo/`;
3. update every file listed under that decision;
4. record the reason and evidence here;
5. add the date and change to `CHANGELOG.md`;
6. move from `[HW2-TBD]` to `[HW2-VERIFY]` after selection;
7. use `[HW2-DONE]` only after implementation and measured validation;
8. avoid claiming test results that were not measured.

## Next decisions needed

1. `[HW2-TBD] HW2-POWER-01` — exact LiPo pack and power parts;
2. `[HW2-TBD] HW2-MOTOR-01` — exact faster motor;
3. `[HW2-TBD] HW2-DRIVER-01` — exact H-bridge / motor-driver IC;
4. `[HW2-TBD] HW2-PCB-01` — ESP32 physical implementation, pin map and PCB files;
5. `[HW2-TBD] HW2-VISION-02/03` — PixyCam settings, pins and firmware;
6. `[HW2-TBD] HW2-SW-01` — final Hardware V2 source;
7. `[HW2-TBD] HW2-TEST-01` — measured complete-system validation;
8. `[HW2-TBD] HW2-MEDIA-01` — final V2 photos and videos;
9. `[HW2-TBD] HW2-REBUILD-01` — verified final rebuild package.
