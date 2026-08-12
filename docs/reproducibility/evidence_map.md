# Evidence Map

## How to read this repository

The repository contains three evidence levels:

- `[HW1-HISTORY]` **Hardware V1** — verified historical robot, measurements, photos, video and archived documentation;
- `[HW2-IMPROVEMENT]` **Hardware V2** — active custom-PCB/PixyCam redesign with confirmed hardware direction and missing implementation evidence;
- **Software brainstorm/history** — previous source and software-design material preserved outside the active judge-facing path after the 2026-08-12 software reset.

The master list of missing information, update locations and completion conditions is [`../../NEXT_REVIEW.md`](../../NEXT_REVIEW.md).

## Criterion 1 — mobility and mechanical design

### [HW1-HISTORY] Evidence already available

- [`drivetrain_and_steering.md`](../design/drivetrain_and_steering.md) — Hardware V1 motor, differential, steering and wheel iterations;
- [`engineering_decisions.md`](../design/engineering_decisions.md) — trade-offs behind the verified baseline;
- [`risk_and_failures.md`](../design/risk_and_failures.md) — mechanical failure reasoning;
- [`models/README.md`](../../models/README.md) — CAD/STL evidence;
- [`performance_measurements.md`](../testing/performance_measurements.md) — strict Hardware V1 measurements.

### [HW2-IMPROVEMENT] What is changing

Hardware V2 keeps the successful steering, wheel-grip and differential lessons but reopens the drive-motor choice for greater speed and integrates the new electronics and battery layout.

### [HW2-TBD] Evidence still required

Tracker IDs: `HW2-MOTOR-01`, `HW2-SENSOR-01/02/03`, `HW2-REBUILD-01`.

- exact faster motor and datasheet;
- torque/speed/current comparison;
- loaded speed and repeated-run results;
- final robot mass, wheel diameter, wheelbase and track widths;
- mechanical changes required by the PCB, battery and new motor;
- final CAD and assembly photos.

## Criterion 2 — power and sensor architecture

### [HW2-CONFIRMED] Design evidence already available

- [`electronics_overview.md`](../hardware/electronics_overview.md);
- [`parts_list.md`](../hardware/parts_list.md);
- [`hardware_v2_custom_pcb_plan.md`](../hardware/hardware_v2_custom_pcb_plan.md);
- [`hardware_v2_decision_register.md`](../hardware/hardware_v2_decision_register.md);
- [`sensor_list.md`](../hardware/sensor_list.md);
- [`pcb_wiring_diagrams.md`](../hardware/pcb_wiring_diagrams.md).

### [HW1-HISTORY] Historical evidence

- existing schematic PDF and perfboard photographs under [`schemes/`](../../schemes/);
- archived Hardware V1 electronics and wiring text under [`archivo/`](../../archivo/).

### [HW2-IMPROVEMENT] What is changing

The development-board, perfboard, `2x 18650` and `L298N` arrangement is being replaced by an ESP32-WROOM-32 custom PCB, LiPo power architecture and an H-bridge selected for the final motor.

### [HW2-TBD] Evidence still required

Tracker IDs: `HW2-POWER-01`, `HW2-DRIVER-01`, `HW2-PCB-01`.

- exact LiPo, motor, driver and regulators;
- power calculations and measured current;
- schematic and editable source;
- PCB source, Gerbers, drill files and BOM;
- connector/pin map;
- assembled-board photos;
- rail-sag and thermal tests;
- ten-start I2C/SPI reliability results.

## Criterion 3 — software architecture and obstacle strategy

### Current active status

`[HW2-TBD]` The final Hardware V2 software architecture is **not yet claimed as complete**.

On 2026-08-12 the previous active software pages and source were moved out of the active path because the software is being redesigned around the final Hardware V2 hardware.

Active status pages:

- [`docs/code/README.md`](../code/README.md);
- [`src/README.md`](../../src/README.md).

### Engineering history / brainstorm evidence

- [`brainstorm/software-redesign/README.md`](../../brainstorm/software-redesign/README.md) — reason for the reset and new design questions;
- [`previous-docs/`](../../brainstorm/software-redesign/previous-docs/) — exact pre-reset software documentation;
- [`previous-source/`](../../brainstorm/software-redesign/previous-source/) — exact pre-reset source tree;
- [`engineering-journal/2026-08-12-software-redesign.md`](../../engineering-journal/2026-08-12-software-redesign.md) — journal-ready record of the decision.

This material proves iteration and previous software work, but it is not final Hardware V2 software evidence.

### [HW2-TBD] Evidence still required

Tracker IDs: `HW2-VISION-02`, `HW2-VISION-03`, `HW2-SW-01`.

- final source code;
- tested PixyCam SPI communication;
- final board configuration and pin map;
- implemented state transitions and fault handling;
- matching code comments and diagrams;
- red/green detection results;
- stale/ambiguous-data tests if that handling is part of the final design;
- repeated Open and Obstacle Challenge validation.

## Criterion 4 — systems thinking and engineering decisions

### Evidence already available

- [`system_overview.md`](../design/system_overview.md);
- [`engineering_decisions.md`](../design/engineering_decisions.md);
- [`risk_and_failures.md`](../design/risk_and_failures.md);
- [`hardware_v2_decision_register.md`](../hardware/hardware_v2_decision_register.md);
- [`iteration_log.md`](../testing/iteration_log.md);
- [`hardware_v2_validation_template.md`](../testing/hardware_v2_validation_template.md);
- [`software-redesign journal entry`](../../engineering-journal/2026-08-12-software-redesign.md).

The software reset itself is systems-thinking evidence: the team chose not to preserve a software architecture that no longer matched the changed perception, PCB, power and drive assumptions.

### [HW2-TBD] Evidence still required

Tracker IDs: `HW2-PCB-01`, `HW2-MOTOR-01`, `HW2-TEST-01`.

- failure and correction log for PCB revision A;
- measured effect of faster speed on perception and turning;
- V1 versus V2 comparison;
- decisions tied to commit, photo, measurement or video evidence;
- final explanation of rejected battery, motor and driver options;
- software decisions tied to implementation and retest evidence.

## Criterion 5 — reproducibility and GitHub quality

### Evidence already available

- [`README.md`](../../README.md);
- [`START_HERE.md`](../../START_HERE.md);
- [`NEXT_REVIEW.md`](../../NEXT_REVIEW.md);
- [`docs/README.md`](../README.md);
- [`submission_checklist.md`](submission_checklist.md);
- [`full_rebuild_guide.md`](full_rebuild_guide.md);
- [`models/README.md`](../../models/README.md);
- archived Hardware V1 documentation and preserved software history.

### [HW2-TBD] Evidence still required

Tracker IDs: `HW2-REBUILD-01`, `HW2-MEDIA-01`, `HW2-TEST-01`.

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
3. [`NEXT_REVIEW.md`](../../NEXT_REVIEW.md)
4. [`Hardware V2 decision register`](../hardware/hardware_v2_decision_register.md)
5. [`Hardware V2 PCB plan`](../hardware/hardware_v2_custom_pcb_plan.md)
6. [`Software status`](../code/README.md)
7. [`Software redesign brainstorm`](../../brainstorm/software-redesign/README.md)
8. [`Hardware V2 validation template`](../testing/hardware_v2_validation_template.md)
9. [`Hardware V1 performance measurements`](../testing/performance_measurements.md)

This map does not claim that missing Hardware V2 artifacts already exist. An item becomes `[HW2-DONE]` only when the implementation, repository files and measured evidence describe the same physical robot.
