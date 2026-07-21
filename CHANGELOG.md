# Changelog

This changelog tracks repository milestones so judges can quickly understand which state of the robot and documentation they are reading.

## Current milestone

### v1.2 hardware-v2 architecture confirmation - 2026-07-21

- opened a separate `hardware-v2-custom-pcb-migration` development branch;
- established the rule that nothing from Hardware V1 is deleted during migration;
- created `archivo/hardware-v1-esp32-250rpm/` and `archivo/hardware-v2-planning-snapshots/` for copies of files before they are rewritten;
- confirmed `ESP32-WROOM-32` as the main Hardware V2 controller;
- removed Raspberry Pi Zero from the active Hardware V2 architecture while preserving its Hardware V1 documentation;
- confirmed a first-generation `PixyCam` / CMUcam5 with wired `SPI` communication to the ESP32;
- confirmed `1x VL53L1X` front ToF, `2x VL53L4CD` side ToF sensors, `BNO085` IMU and `MG90S` steering servo;
- confirmed the move from the Hardware V1 `2x 18650` pack to a LiPo architecture, while leaving the exact LiPo specification `TBD`;
- retained the plan to replace the Hardware V1 `250 rpm` motor with a faster motor, exact model `TBD`;
- left the exact motor driver, regulators, PCB pinout and physical ESP32 integration unconfirmed until the parts and schematic are available;
- archived the previous active BOM and electronics overview before replacing them with Hardware V2 documents;
- added a Hardware V2 decision register;
- added a PixyCam SPI integration and validation plan;
- added a Hardware V2 power, sensor, camera, motor and field-test template;
- corrected the active side-ToF designation from `VL53L1CD` to `VL53L4CD` without altering the archived historical snapshot;
- added verification gates for schematic review, power integrity, motor-driver thermal/current testing, sensor stability, PixyCam reliability, field performance and reproducibility.

## Planned milestones

- `v1.3 hardware-v2 component lock` — exact LiPo, motor, driver, regulator and ESP32 PCB implementation selected;
- `v1.4 hardware-v2 schematic` — reviewed custom PCB schematic and locked pin map;
- `v1.5 hardware-v2 prototype` — assembled PCB and bench-validation evidence;
- `v1.6 hardware-v2 field-tested` — PixyCam, motor and repeated Open / Obstacle track results;
- `v2.0 final hardware documentation` — complete BOM, PCB production files, code, calibration and rebuild guide.

## v0.8 regional-ready - 2026-04-07

- built the documentation structure for the WRO Future Engineers robot;
- added the main subsystem documentation;
- added the wiring overview, parts list, test templates, and reproducibility checklist;
- added project metadata and repo hygiene files;
- prepared the repository for private GitHub hosting.

## v1.0 documentation submission - 2026-04-19

- strengthened judge-facing evidence for drivetrain, steering, software testing, and system interaction;
- added visual schematic previews and design-comparison images for key hardware decisions;
- aligned the main README and reproducibility checklist more closely with the WRO 2026 rubric and general rules.

## 2026-04-23

- added `docs/testing/tests.md` with a documented testing workflow for open challenge and obstacle challenge;
- documented acceptance criteria, fail/pass criteria, stable-version rules, and change-to-result logging expectations;
- linked the testing workflow from the docs index and reproducibility files for easier judge navigation.
