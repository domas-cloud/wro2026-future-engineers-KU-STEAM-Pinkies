# KU STEAM Pinkies - WRO 2026 Future Engineers

This repository documents the engineering process behind our autonomous Future Engineers robot.
The goal is not only to store files, but to show how the robot was designed, built, tested, and iterated so another team can understand and reproduce it.

## Robot Snapshot

- Drive concept: servo-steered front axle with an `MG90S` servo, an `N20` drive motor, and an `L298N H-bridge`.
- Compute split: `ESP32` for low-level control and `Raspberry Pi Zero` for higher-level perception and decision logic.
- Sensors: camera, `BNO085 9-DOF IMU`, and `VL53L5CX` matrix ToF lidar.
- Power: `2x 18650 Li-ion` battery pack feeding the drive stage and regulated logic rails.
- Documentation focus: mechanical design, power and sensor architecture, software behavior, systems thinking, and reproducibility.

## Repository Map

### 1. Brainstorming
- [Problem Identification](docs/brainstorming/problem_identification.md)
- [Idea Generation](docs/brainstorming/idea_generation.md)
- [Concept Selection](docs/brainstorming/concept_selection.md)
- [Early Requirements](docs/brainstorming/early_requirements.md)

### 2. Planning
- [Timeline & Deadlines](docs/planning/timeline_deadlines.md)
- [Task Distribution](docs/planning/task_distribution.md)
- [Version Control Strategy](docs/planning/version_control_strategy.md)
- [Risk Assessment](docs/planning/risk_assessment.md)

### 3. Hardware
- [Electronics Overview](docs/hardware/electronics_overview.md)
- [Motor & Servo Selection](docs/hardware/motor_servo_selection.md)
- [Sensor List](docs/hardware/sensor_list.md)
- [PCB / Wiring Diagrams](docs/hardware/pcb_wiring_diagrams.md)

### 4. Mechanical Design
- [Chassis Design](docs/design/chassis_design.md)
- [Steering System](docs/design/steering_system.md)
- [Gear Ratios & Mechanics](docs/design/gear_ratios_mechanics.md)
- [Wheel Mounting & Suspension Choices](docs/design/wheel_mounting_suspension.md)
- [CAD Models](docs/design/cad_models.md)

### 5. Power & Sensor Management
- [Power Distribution](docs/power_management/power_distribution.md)
- [Battery Selection](docs/power_management/battery_selection.md)
- [Noise Reduction & Filtering](docs/power_management/noise_filtering.md)
- [Sensor Placement Strategy](docs/power_management/sensor_placement.md)
- [IMU & Encoder Integration](docs/power_management/imu_encoder_integration.md)
- [Wiring Overview](schemes/wiring_overview.md)

### 6. Software / Code
- [Control Algorithms](docs/code/control_algorithms.md)
- [PID Tuning](docs/code/pid_tuning.md)
- [Navigation Logic](docs/code/navigation_logic.md)
- [Safety & Fail-safes](docs/code/safety_failsafes.md)
- [Code Architecture](docs/code/code_architecture.md)
- [Message Protocol](docs/code/message_protocol.md)

### 7. Testing
- [Unit Testing](docs/testing/unit_testing.md)
- [Track Testing](docs/testing/track_testing.md)
- [Performance Measurements](docs/testing/performance_measurements.md)
- [Steering Accuracy Tests](docs/testing/steering_accuracy.md)
- [Iterations & Adjustments](docs/testing/iterations_adjustments.md)
- [Test Log Template](docs/testing/test_log_template.md)

### 8. Evaluation
- [What Worked](docs/evaluation/what_worked.md)
- [What Didn't](docs/evaluation/what_didnt.md)
- [Final Performance](docs/evaluation/final_performance.md)
- [Comparison with Initial Goals](docs/evaluation/comparison_initial_goals.md)
- [Reproducibility Checklist](docs/evaluation/reproducibility_checklist.md)

### 9. Problems and Fixes
- [Mechanical Failures](docs/Encountered_Problems_and_Solutions/mechanical_failures.md)
- [Sensor Issues](docs/Encountered_Problems_and_Solutions/sensor_issues.md)
- [Code Bugs](docs/Encountered_Problems_and_Solutions/code_bugs.md)
- [Power Instability](docs/Encountered_Problems_and_Solutions/power_instability.md)
- [Solutions & Fix Log](docs/Encountered_Problems_and_Solutions/solutions_fix_log.md)

## Artifact Folders

- `models/` - CAD exports and STL files for the steering mechanism and related parts.
- `schemes/` - electromechanical diagrams and wiring references.
- `src/` - control software and any files needed to build or run it.
- `t-photos/` - team photos used for documentation evidence.
- `v-photos/` - vehicle photos and build progress images.
- `video/` - competition or test videos and related notes.
- `other/` - extra files that do not fit in the main categories.

## How To Read This Repo

1. Start with the brainstorming documents to understand the robot concept.
2. Continue through hardware, mechanical design, and power management to see the build decisions.
3. Read the software section to understand how the robot behaves on the field.
4. Use the testing and evaluation sections to see how the design changed over time.
5. Use the artifact folders to verify the documentation against the actual files.

## Current Documentation Status

The repository is intentionally written as a living engineering record.
Where measured results are not yet available, the documentation describes the method, the intended validation step, and the decision rationale instead of inventing numbers.
