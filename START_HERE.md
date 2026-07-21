# Start Here

> **Active development branch:** Hardware V2 is preparing a custom PCB and a faster drive motor. The previous ESP32 development-board / perfboard / 250 rpm implementation is not being deleted. Changed historical files are copied to [`archivo/hardware-v1-esp32-250rpm/`](archivo/hardware-v1-esp32-250rpm/).

## Hardware V2 Migration

Read these two files before treating any Hardware V2 component as final:

1. [Custom PCB migration plan](docs/hardware/hardware_v2_custom_pcb_plan.md)
2. [Faster motor selection plan](docs/design/hardware_v2_motor_upgrade_plan.md)

The exact controller, motor, motor driver, PCB pinout and power system remain **to be validated**. Existing ESP32-based documentation describes Hardware V1 and remains useful as engineering history and a comparison baseline.

Start here if you want the quickest way into the repository.

Current repository milestone: **`v1.2 hardware-v2 migration preparation`**. Version history is tracked in [CHANGELOG.md](CHANGELOG.md).

## Team

We are **KU STEAM Pinkies**, competing in **WRO 2026 Future Engineers**.

Main roles in the team:

- **Marius** - software development and mechanical design
- **Domas** - project coordination, testing, and documentation
- **Jonas** - electronics and hardware design

We split responsibilities, but the important decisions were made together and tested on the robot as one system.

## Best Quick Reading Path

If you only have a few minutes, read these files first:

1. [README.md](README.md)
2. [docs/hardware/hardware_v2_custom_pcb_plan.md](docs/hardware/hardware_v2_custom_pcb_plan.md)
3. [docs/design/hardware_v2_motor_upgrade_plan.md](docs/design/hardware_v2_motor_upgrade_plan.md)
4. [docs/reproducibility/final_submission_pack.md](docs/reproducibility/final_submission_pack.md)
5. [docs/reproducibility/evidence_map.md](docs/reproducibility/evidence_map.md)
6. [docs/design/drivetrain_and_steering.md](docs/design/drivetrain_and_steering.md)
7. [docs/hardware/electronics_overview.md](docs/hardware/electronics_overview.md)
8. [docs/code/software_state_machine_and_obstacle_flow.md](docs/code/software_state_machine_and_obstacle_flow.md)
9. [docs/testing/performance_measurements.md](docs/testing/performance_measurements.md)
10. [docs/reproducibility/exact_rebuild_wiring_upload_start.md](docs/reproducibility/exact_rebuild_wiring_upload_start.md)

## Full Reading Order

### 1. Overview

- [README.md](README.md)
- [docs/reproducibility/final_submission_pack.md](docs/reproducibility/final_submission_pack.md)
- [docs/design/system_overview.md](docs/design/system_overview.md)
- [docs/reproducibility/evidence_map.md](docs/reproducibility/evidence_map.md)

### 2. Mechanical Design

- [docs/design/hardware_v2_motor_upgrade_plan.md](docs/design/hardware_v2_motor_upgrade_plan.md)
- [docs/design/chassis_design_improved.md](docs/design/chassis_design_improved.md)
- [docs/design/drivetrain_and_steering.md](docs/design/drivetrain_and_steering.md)
- [docs/design/engineering_decisions.md](docs/design/engineering_decisions.md)
- [docs/design/risk_and_failures.md](docs/design/risk_and_failures.md)

### 3. Electronics

- [docs/hardware/hardware_v2_custom_pcb_plan.md](docs/hardware/hardware_v2_custom_pcb_plan.md)
- [docs/hardware/electronics_overview.md](docs/hardware/electronics_overview.md)
- [docs/hardware/pcb_wiring_diagrams.md](docs/hardware/pcb_wiring_diagrams.md)
- [schemes/Wro_customPCBs.pdf](schemes/Wro_customPCBs.pdf)

### 4. Software

- [docs/code/software_state_machine_and_obstacle_flow.md](docs/code/software_state_machine_and_obstacle_flow.md)
- [docs/code/software_architecture_improved.md](docs/code/software_architecture_improved.md)
- [docs/code/navigation_strategy_improved.md](docs/code/navigation_strategy_improved.md)
- [docs/code/software_flow_and_state_logic.md](docs/code/software_flow_and_state_logic.md)

### 5. Testing

- [docs/testing/mechanical_and_software_testing.md](docs/testing/mechanical_and_software_testing.md)
- [docs/testing/track_testing.md](docs/testing/track_testing.md)
- [docs/testing/performance_measurements.md](docs/testing/performance_measurements.md)

If you prefer a section-based index instead of a reading order, open [docs/README.md](docs/README.md).

## Rebuild Path

Hardware V1 remains the only fully described rebuild baseline until Hardware V2 passes its verification gates. For the historical build use:

1. [README.md](README.md)
2. [docs/hardware/parts_list.md](docs/hardware/parts_list.md)
3. [docs/hardware/pcb_wiring_diagrams.md](docs/hardware/pcb_wiring_diagrams.md)
4. [schemes/Wro_customPCBs.pdf](schemes/Wro_customPCBs.pdf)
5. [docs/reproducibility/exact_rebuild_wiring_upload_start.md](docs/reproducibility/exact_rebuild_wiring_upload_start.md)
6. [docs/design/drivetrain_and_steering.md](docs/design/drivetrain_and_steering.md)
7. [models/README.md](models/README.md)

## Note

Hardware V2 is intentionally documented as a migration, not falsely presented as a finished design. Once measurements, PCB files and motor tests exist, the main electronics, BOM, wiring, software and rebuild documents can be revised while their previous versions are first copied into `archivo/`.
