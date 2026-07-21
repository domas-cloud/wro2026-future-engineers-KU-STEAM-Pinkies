# WRO Submission Pack Status

## Current state

The previous submission-pack page was archived at [`archivo/hardware-v1-esp32-250rpm/docs/reproducibility/final_submission_pack.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/reproducibility/final_submission_pack.md).

The repository currently contains a complete Hardware V1 documentation package and an incomplete Hardware V2 migration package. Hardware V2 is not yet ready to be called the final submission robot.

## Judge entry points

1. [`README.md`](../../README.md)
2. [`START_HERE.md`](../../START_HERE.md)
3. [`Evidence map`](evidence_map.md)
4. [`Hardware V2 decision register`](../hardware/hardware_v2_decision_register.md)
5. [`Hardware V2 validation template`](../testing/hardware_v2_validation_template.md)

## Current Hardware V2 documentation

### Design

- [`System overview`](../design/system_overview.md)
- [`Custom PCB plan`](../hardware/hardware_v2_custom_pcb_plan.md)
- [`Motor upgrade plan`](../design/hardware_v2_motor_upgrade_plan.md)
- [`Decision register`](../hardware/hardware_v2_decision_register.md)

### Hardware

- [`Electronics overview`](../hardware/electronics_overview.md)
- [`Active BOM`](../hardware/parts_list.md)
- [`Sensor list`](../hardware/sensor_list.md)
- [`PCB/wiring status`](../hardware/pcb_wiring_diagrams.md)

### Software

- [`Software architecture`](../code/software_architecture_improved.md)
- [`Vision interface`](../code/vision_interface.md)
- [`PixyCam SPI plan`](../code/pixycam_spi_integration_plan.md)
- [`State machine`](../code/software_state_machine_and_obstacle_flow.md)
- [`Source status`](../../src/README.md)

### Testing

- [`Hardware V2 validation template`](../testing/hardware_v2_validation_template.md)
- [`Testing workflow`](../testing/tests.md)
- [`Hardware V1 measurements`](../testing/performance_measurements.md)
- [`Final validation status`](../testing/final_validation_results.md)

## Historical Hardware V1 evidence

- archived documents under [`archivo/hardware-v1-esp32-250rpm/`](../../archivo/hardware-v1-esp32-250rpm/);
- current legacy source under [`src/`](../../src/);
- existing schematic PDF and perfboard media under [`schemes/`](../../schemes/);
- current robot six-view photographs under [`v-photos/`](../../v-photos/);
- current Open Challenge video under [`video/`](../../video/).

These artifacts remain useful evidence but do not represent the completed Hardware V2 robot.

## Missing before final Hardware V2 submission

- exact LiPo, motor, driver and regulators;
- reviewed schematic and PCB files;
- production package and BOM;
- assembled-board photos;
- final firmware with PixyCam SPI;
- calibration and exact rebuild instructions;
- power, thermal, sensor and camera results;
- repeated Open and Obstacle tables;
- final six-view photos;
- final Open and Obstacle videos;
- final public commit/tag matching the physical robot.

## Release rule

The submission pack becomes final only when every linked document and artifact describes the same Hardware V2 revision. Missing evidence remains visible as `TBD`; it is not replaced by assumed values.
