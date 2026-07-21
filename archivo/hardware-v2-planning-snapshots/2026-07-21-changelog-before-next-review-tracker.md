# Changelog

This changelog tracks repository milestones so judges can distinguish verified history from active development.

## Current milestone

### v1.2 hardware-v2 architecture and text alignment — 2026-07-21

- opened the `hardware-v2-custom-pcb-migration` branch;
- established the rule that active text is archived before it is rewritten;
- confirmed `ESP32-WROOM-32` as the main Hardware V2 controller;
- removed Raspberry Pi Zero from the active Hardware V2 architecture;
- confirmed first-generation PixyCam / CMUcam5 over wired SPI;
- confirmed `VL53L1X`, `2x VL53L4CD`, `BNO085` and `MG90S`;
- confirmed LiPo as the new battery chemistry while leaving the exact pack `TBD`;
- retained the plan for a faster drive motor while leaving the motor and H-bridge `TBD`;
- added the Hardware V2 PCB plan, decision register, BOM, PixyCam plan and validation template;
- corrected active side-ToF text to `VL53L4CD`;
- archived and rewrote the root README, sensor list, PCB/wiring pages and schemes descriptions;
- separated Hardware V1 schematic/perfboard evidence from the incomplete Hardware V2 PCB target;
- removed unsupported Hardware V2 claims from active text and replaced missing details with explicit required-evidence sections;
- did not delete source code, CAD, photos, videos, schematics or historical documentation.

## Planned milestones

- `v1.3 hardware-v2 component lock` — exact LiPo, motor, driver, regulators and ESP32 PCB implementation selected;
- `v1.4 hardware-v2 schematic` — reviewed schematic and locked pin map;
- `v1.5 hardware-v2 prototype` — assembled PCB and bench-validation evidence;
- `v1.6 hardware-v2 field-tested` — PixyCam, motor and repeated Open/Obstacle results;
- `v2.0 final hardware documentation` — final BOM, PCB production files, code, calibration and rebuild guide.

## v0.8 regional-ready — 2026-04-07

- built the main documentation structure;
- added subsystem documentation, wiring overview, parts list and test templates;
- prepared the repository for GitHub-based review.

## v1.0 documentation submission — 2026-04-19

- strengthened judge-facing mechanical, software, testing and systems evidence;
- added schematic previews and design-comparison images;
- aligned the repository with the WRO documentation structure.

## 2026-04-23

- added `docs/testing/tests.md` with the Open and Obstacle testing workflow;
- documented pass/fail criteria and stable-version rules;
- linked the testing workflow from the documentation index and reproducibility pages.
