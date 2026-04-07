# KU STEAM Pinkies - WRO 2026 Future Engineers

Documentation for our autonomous Future Engineers robot.

## Summary

- Drive: `MG90S` steering servo, `N20` drive motor, `L298N H-bridge`.
- Compute: `Raspberry Pi Zero` for camera capture, `ESP32` for all calculations and control.
- Sensors: `BNO085 9-DOF IMU`, `VL53L5CX` ToF, camera.
- Power: `2x 18650 Li-ion` battery pack with regulated logic rails.

## Team

KU STEAM Pinkies.

## Robot

The robot is a car-style build with servo steering and a rear drive motor.
The documentation focuses on mechanical design, power and sensor architecture, software behavior, testing, and reproducibility.

## License

This repository uses the [MIT License](LICENSE).

## Performance Video

- [Competition video notes](video/video.md)

## Mobility Management

- [Chassis Design](docs/design/chassis_design.md)
- [Steering System](docs/design/steering_system.md)
- [Gear Ratios & Mechanics](docs/design/gear_ratios_mechanics.md)
- [Wheel Mounting & Suspension Choices](docs/design/wheel_mounting_suspension.md)
- [CAD Models](docs/design/cad_models.md)
- [Parts List](docs/hardware/parts_list.md)

## Build Documentation

- [Documentation Index](docs/README.md)
- [Brainstorming](docs/brainstorming/problem_identification.md)
- [Planning](docs/planning/timeline_deadlines.md)
- [Hardware](docs/hardware/electronics_overview.md)
- [Power & Wiring](docs/power_management/power_distribution.md)
- [Software](docs/code/code_architecture.md)
- [Testing](docs/testing/test_log_template.md)
- [Evaluation](docs/evaluation/reproducibility_checklist.md)
- [Problems and Fixes](docs/Encountered_Problems_and_Solutions/solutions_fix_log.md)

## Release Notes

- [Changelog](CHANGELOG.md)

## Artifact Folders

- `models/` - CAD exports and STL files.
- `schemes/` - wiring and electromechanical diagrams.
- `src/` - control software.
- `t-photos/` - team photos.
- `v-photos/` - vehicle photos.
- `video/` - video references and notes.
- `other/` - extra files that do not fit elsewhere.

## How To Read This Repo

1. Start with the summary and robot sections.
2. Read the mobility and build documentation for the hardware choices.
3. Read the software and testing sections for behavior and validation.
4. Use the artifact folders to match the text against the actual files.
