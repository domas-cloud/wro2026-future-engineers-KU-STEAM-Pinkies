# Evidence Map

## How to read this repository

The repository contains two evidence levels:

- **Hardware V1** — verified historical robot, code, measurements, photos and video;
- **Hardware V2** — active custom-PCB/PixyCam redesign with confirmed architecture and missing implementation evidence.

The earlier evidence map was archived at [`archivo/hardware-v1-esp32-250rpm/docs/reproducibility/evidence_map.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/reproducibility/evidence_map.md).

## Criterion 1 — mobility and mechanical design

### Evidence already available

- [`drivetrain_and_steering.md`](../design/drivetrain_and_steering.md) — Hardware V1 motor, differential, steering and wheel iterations;
- [`engineering_decisions.md`](../design/engineering_decisions.md) — trade-offs behind the verified baseline;
- [`risk_and_failures.md`](../design/risk_and_failures.md) — mechanical failure reasoning;
- [`models/README.md`](../../models/README.md) — CAD/STL evidence;
- [`performance_measurements.md`](../testing/performance_measurements.md) — strict Hardware V1 measurements.

### Hardware V2 evidence still required

- exact faster motor and datasheet;
- torque/speed/current comparison;
- loaded speed and repeated-run results;
- final robot mass, wheel diameter, wheelbase and track widths;
- mechanical changes required by the PCB, battery and new motor;
- final CAD and assembly photos.

## Criterion 2 — power and sensor architecture

### Confirmed design evidence

- [`electronics_overview.md`](../hardware/electronics_overview.md);
- [`parts_list.md`](../hardware/parts_list.md);
- [`hardware_v2_custom_pcb_plan.md`](../hardware/hardware_v2_custom_pcb_plan.md);
- [`hardware_v2_decision_register.md`](../hardware/hardware_v2_decision_register.md);
- [`sensor_list.md`](../hardware/sensor_list.md);
- [`pcb_wiring_diagrams.md`](../hardware/pcb_wiring_diagrams.md).

### Historical Hardware V1 evidence

- existing schematic PDF and perfboard photographs under [`schemes/`](../../schemes/);
- archived Hardware V1 electronics and wiring text under [`archivo/`](../../archivo/).

### Hardware V2 evidence still required

- exact LiPo, motor, driver and regulators;
- power calculations and measured current;
- schematic and editable source;
- PCB source, Gerbers, drill files and BOM;
- connector/pin map;
- assembled-board photos;
- rail-sag and thermal tests;
- ten-start I2C/SPI reliability results.

## Criterion 3 — software architecture and obstacle strategy

### Evidence already available

- [`src/README.md`](../../src/README.md) — honest status of the published Hardware V1 code;
- [`software_architecture_improved.md`](../code/software_architecture_improved.md) — Hardware V2 target architecture;
- [`vision_interface.md`](../code/vision_interface.md) — required PixyCam SPI contract;
- [`pixycam_spi_integration_plan.md`](../code/pixycam_spi_integration_plan.md) — camera implementation and test plan;
- [`software_state_machine_and_obstacle_flow.md`](../code/software_state_machine_and_obstacle_flow.md) — target state flow and unresolved thresholds;
- [`control_algorithms.md`](../code/control_algorithms.md) — Hardware V1 low-level control reasoning.

### Hardware V2 evidence still required

- published PixyCam SPI source;
- final board configuration and pin map;
- exact state transitions and fault handling;
- matching code comments and diagrams;
- red/green detection results;
- stale/ambiguous-data tests;
- repeated Obstacle Challenge validation.

## Criterion 4 — systems thinking and engineering decisions

### Evidence already available

- [`system_overview.md`](../design/system_overview.md);
- [`engineering_decisions.md`](../design/engineering_decisions.md);
- [`risk_and_failures.md`](../design/risk_and_failures.md);
- [`hardware_v2_decision_register.md`](../hardware/hardware_v2_decision_register.md);
- [`iteration_log.md`](../testing/iteration_log.md);
- [`hardware_v2_validation_template.md`](../testing/hardware_v2_validation_template.md).

### Evidence still required

- failure and correction log for PCB revision A;
- measured effect of faster speed on perception and turning;
- V1 versus V2 comparison;
- decisions tied to commit, photo, measurement or video evidence;
- final explanation of rejected battery, motor and driver options.

## Criterion 5 — reproducibility and GitHub quality

### Evidence already available

- [`README.md`](../../README.md);
- [`START_HERE.md`](../../START_HERE.md);
- [`docs/README.md`](../README.md);
- [`submission_checklist.md`](submission_checklist.md);
- [`full_rebuild_guide.md`](full_rebuild_guide.md);
- [`models/README.md`](../../models/README.md);
- archived Hardware V1 code, wiring and documentation.

### Hardware V2 evidence still required

- final exact BOM;
- complete PCB manufacturing package;
- final source code and dependencies;
- calibration and startup procedure verified on the custom PCB;
- final six-view photos and both challenge videos;
- completed final validation tables;
- one release/tag or clearly identified final commit.

## Fast review path

1. [`README.md`](../../README.md)
2. [`START_HERE.md`](../../START_HERE.md)
3. [`Hardware V2 decision register`](../hardware/hardware_v2_decision_register.md)
4. [`Hardware V2 PCB plan`](../hardware/hardware_v2_custom_pcb_plan.md)
5. [`PixyCam SPI plan`](../code/pixycam_spi_integration_plan.md)
6. [`Hardware V2 validation template`](../testing/hardware_v2_validation_template.md)
7. [`Hardware V1 performance measurements`](../testing/performance_measurements.md)

This map does not claim that missing Hardware V2 artifacts already exist.
