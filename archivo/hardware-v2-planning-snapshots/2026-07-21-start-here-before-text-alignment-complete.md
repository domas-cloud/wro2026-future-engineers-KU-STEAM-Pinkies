# Start Here

> **Active development branch:** Hardware V2 is moving to a custom PCB, a first-generation PixyCam over SPI and a faster motor. Hardware V1 is preserved under [`archivo/`](archivo/) and in Git history. Nothing from the previous working robot is deleted.

## Current Hardware V2 status

### Confirmed

- main controller: `ESP32-WROOM-32`;
- Raspberry Pi Zero removed from the active robot;
- perception camera: first-generation `PixyCam` / CMUcam5;
- PixyCam-to-ESP32 communication: wired `SPI`;
- front ToF: `1x VL53L1X`;
- side ToF: `2x VL53L4CD`;
- IMU: `BNO085`;
- steering servo: `MG90S`;
- battery type: LiPo;
- electronics direction: custom PCB;
- drive direction: replace the Hardware V1 `250 rpm` motor with a faster motor.

### Still TBD

- exact LiPo cell count, voltage, capacity, C-rating and connector;
- exact faster motor;
- exact motor-driver IC;
- regulator selection and current headroom;
- final PCB pinout, dimensions, mounting holes and layer count;
- whether the ESP32-WROOM-32 module is soldered directly or used through another carrier arrangement;
- final PixyCam signature numbers and measured detection limits.

Hardware V2 is confirmed in architecture but is not yet a completed or fully verified robot.

## Read these first

1. [Hardware V2 custom PCB plan](docs/hardware/hardware_v2_custom_pcb_plan.md)
2. [Hardware V2 decision register](docs/hardware/hardware_v2_decision_register.md)
3. [Active Hardware V2 BOM](docs/hardware/parts_list.md)
4. [Electronics overview](docs/hardware/electronics_overview.md)
5. [PixyCam SPI integration plan](docs/code/pixycam_spi_integration_plan.md)
6. [Faster motor selection plan](docs/design/hardware_v2_motor_upgrade_plan.md)
7. [Hardware V2 validation template](docs/testing/hardware_v2_validation_template.md)
8. [Archived Hardware V1 baseline](archivo/hardware-v1-esp32-250rpm/)

Current repository milestone: **`v1.2 hardware-v2 architecture confirmation`**. Version history is tracked in [CHANGELOG.md](CHANGELOG.md).

## Team

We are **KU STEAM Pinkies**, competing in **WRO 2026 Future Engineers**.

- **Marius** — software development and mechanical design;
- **Domas** — project coordination, testing and documentation;
- **Jonas** — electronics and hardware design.

Responsibilities are divided, but major decisions are reviewed as one robot system because mechanical, electrical and software changes affect each other.

## Judge-facing quick path

For a fast review:

1. [README.md](README.md)
2. [Hardware V2 custom PCB plan](docs/hardware/hardware_v2_custom_pcb_plan.md)
3. [Hardware V2 decision register](docs/hardware/hardware_v2_decision_register.md)
4. [Faster motor selection plan](docs/design/hardware_v2_motor_upgrade_plan.md)
5. [Evidence map](docs/reproducibility/evidence_map.md)
6. [Drivetrain and steering](docs/design/drivetrain_and_steering.md)
7. [Electronics overview](docs/hardware/electronics_overview.md)
8. [PixyCam SPI integration plan](docs/code/pixycam_spi_integration_plan.md)
9. [Performance measurements](docs/testing/performance_measurements.md)
10. [Hardware V2 validation template](docs/testing/hardware_v2_validation_template.md)

## Full reading order

### 1. Overview and evidence

- [README.md](README.md)
- [Final submission pack](docs/reproducibility/final_submission_pack.md)
- [System overview](docs/design/system_overview.md)
- [Evidence map](docs/reproducibility/evidence_map.md)

### 2. Mechanical design

- [Faster motor selection plan](docs/design/hardware_v2_motor_upgrade_plan.md)
- [Chassis design](docs/design/chassis_design_improved.md)
- [Drivetrain and steering](docs/design/drivetrain_and_steering.md)
- [Engineering decisions](docs/design/engineering_decisions.md)
- [Risks and failures](docs/design/risk_and_failures.md)

### 3. Electronics and PCB

- [Hardware V2 custom PCB plan](docs/hardware/hardware_v2_custom_pcb_plan.md)
- [Hardware V2 decision register](docs/hardware/hardware_v2_decision_register.md)
- [Active BOM](docs/hardware/parts_list.md)
- [Electronics overview](docs/hardware/electronics_overview.md)
- [PCB wiring diagrams](docs/hardware/pcb_wiring_diagrams.md)
- [Existing schematic material](schemes/Wro_customPCBs.pdf)

### 4. Software and perception

- [PixyCam SPI integration plan](docs/code/pixycam_spi_integration_plan.md)
- [Software state machine and obstacle flow](docs/code/software_state_machine_and_obstacle_flow.md)
- [Software architecture](docs/code/software_architecture_improved.md)
- [Navigation strategy](docs/code/navigation_strategy_improved.md)
- [Software flow and state logic](docs/code/software_flow_and_state_logic.md)

Some older software documents still describe the Raspberry Pi Zero architecture. They remain useful as Hardware V1 history and must be archived before their active Hardware V2 replacements are written.

### 5. Testing

- [Hardware V2 validation template](docs/testing/hardware_v2_validation_template.md)
- [Mechanical and software testing](docs/testing/mechanical_and_software_testing.md)
- [Track testing](docs/testing/track_testing.md)
- [Performance measurements](docs/testing/performance_measurements.md)
- [Final validation results](docs/testing/final_validation_results.md)

## Rebuild status

- **Hardware V1:** the current fully documented historical baseline.
- **Hardware V2:** active redesign with several confirmed components and several unresolved `TBD` fields.

A final Hardware V2 rebuild guide should only be published after the exact motor, driver, LiPo, regulators, pin map, PCB files and measured validation results are available.

## Archive rule

Before replacing an active Hardware V1 or early Hardware V2 document:

1. copy its current version into `archivo/`;
2. update the active file;
3. record confirmed facts separately from `TBD` values;
4. never replace missing measurements with invented numbers.
