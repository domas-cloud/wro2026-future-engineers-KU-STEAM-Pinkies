# Changelog

This changelog tracks repository milestones so judges can quickly understand which state of the robot and documentation they are reading.

## Current milestone

### v1.2 hardware-v2 migration preparation - 2026-07-21

- opened a separate `hardware-v2-custom-pcb-migration` development branch;
- established the rule that nothing from Hardware V1 is deleted during migration;
- created `archivo/hardware-v1-esp32-250rpm/` for copies of files that must be rewritten;
- documented the transition away from the ESP32 development-board/perfboard electronics stack toward a purpose-built custom PCB;
- documented a measured selection process for a faster drive motor;
- added verification gates for schematic review, power integrity, motor-driver thermal/current testing, sensor stability, field performance and reproducibility;
- left the exact controller, motor, motor driver, battery and PCB details explicitly unconfirmed until real parts and measurements are available.

## Planned Milestones

- `v1.3 hardware-v2 schematic` - reviewed custom PCB schematic, selected controller and motor-driver architecture;
- `v1.4 hardware-v2 prototype` - assembled PCB and bench validation evidence;
- `v1.5 hardware-v2 field-tested` - measured motor comparison and repeated track testing;
- `v2.0 final hardware documentation` - complete BOM, PCB production files, code, calibration and rebuild guide.

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
