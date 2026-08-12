# Changelog

## 2026-08-12

We cleaned up the Hardware V2 branch after deciding that the software needed a fresh start. The old source and software notes were moved to `brainstorm/software-redesign/`, while `src/` and `docs/code/` now only describe the current state.

We also simplified the documentation so it reads more like our engineering notes and less like a checklist. The V1 robot remains archived and its measurements are still used as a baseline.

## 2026-07-21

Started the Hardware V2 rebuild. Main changes: custom PCB, ESP32-WROOM-32, PixyCam over SPI, LiPo power and a faster motor. Raspberry Pi Zero was removed from the active design. We also corrected the side ToF name to `VL53L4CD` in the active documentation.

At this point the exact battery, motor, H-bridge, regulators and final PCB files were still open.

## 2026-04-24

Added the plywood case design and corrected the documented V1 motor test speeds.

## 2026-04-23

Added the Open/Obstacle testing workflow and linked it from the documentation.

## April 2026

Built the first full documentation structure: subsystem notes, wiring, parts, test pages, CAD links and the first submission-oriented README. Hardware V1 was the working robot at this stage.
