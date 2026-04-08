# KU STEAM Pinkies - WRO 2026 Future Engineers

Documentation for our autonomous Future Engineers robot.

## Summary

- Drive system: `MG90S` steering servo, `N20` motor, `L298N H-bridge`.
- Computing: `Raspberry Pi Zero` for camera input only, `ESP32` for control and onboard decision-making.
- Sensors: `BNO085 9-DOF IMU`, 2 `VL53L5CX` matrix ToF modules, and a camera.
- Power: `2x 18650 Li-ion` battery pack with regulated logic rails.

## Team

KU STEAM Pinkies.

## Robot

This is a car-style robot with servo steering and a rear drive motor.
The documentation focuses on mechanics, power and sensor architecture, software behavior, testing, and reproducibility.

## Latest Mechanical Updates

- Added a first-iteration summary to the steering system documentation, including the early three-gear prototype.
- Clarified that the side steering assemblies rotate around their own axis, so the servo does not require a long lever arm.
- Added a differential description and explained why it was removed in a later version.
- Documented an earlier robot issue: without a differential, turning resistance increased significantly during cornering.

## License

This repository uses the [MIT License](LICENSE).

## Motion And Chassis Documentation

- [Chassis Design](docs/design/chassis_design.md)
- [Steering System](docs/design/steering_system.md)
- [Wheel Mounting And Suspension](docs/design/wheel_mounting_suspension.md)
- [CAD Models](docs/design/cad_models.md)
- [Parts List](docs/hardware/parts_list.md)

## Build And Technical Documentation

- [Documentation Index](docs/README.md)
- [Problem Identification](docs/brainstorming/problem_identification.md)
- [Hardware Overview](docs/hardware/electronics_overview.md)
- [Code Architecture](docs/code/code_architecture.md)

## Version Notes

- [Changelog](CHANGELOG.md)

## How To Read This Repository

1. Start with the summary and robot sections.
2. Read the motion and build documentation to understand the main technical choices.
3. Continue with the software section to understand the behavior and control logic.
