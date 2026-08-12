# Documentation Index

## Current project state

- `[HW1-HISTORY]` Hardware V1: verified historical baseline;
- `[HW2-IMPROVEMENT]` Hardware V2: active ESP32 + PixyCam SPI + custom-PCB migration;
- `[HW2-TBD]` final Hardware V2 software: intentionally reset on 2026-08-12 and being redesigned.

For the next review, missing information and the exact update locations are maintained in [`../NEXT_REVIEW.md`](../NEXT_REVIEW.md).

## Status markers

- `[HW1-HISTORY]` — older verified evidence;
- `[HW2-IMPROVEMENT]` — change from Hardware V1;
- `[HW2-CONFIRMED]` — selected V2 fact;
- `[HW2-TBD]` — missing exact information;
- `[HW2-VERIFY]` — requires physical validation;
- `[HW2-DONE]` — complete and verified.

## Best first files

1. [`../README.md`](../README.md)
2. [`../START_HERE.md`](../START_HERE.md)
3. [`../NEXT_REVIEW.md`](../NEXT_REVIEW.md)
4. [`hardware/hardware_v2_decision_register.md`](hardware/hardware_v2_decision_register.md)
5. [`reproducibility/evidence_map.md`](reproducibility/evidence_map.md)
6. [`testing/hardware_v2_validation_template.md`](testing/hardware_v2_validation_template.md)

## Hardware V2 design

- [`design/system_overview.md`](design/system_overview.md)
- [`hardware/hardware_v2_custom_pcb_plan.md`](hardware/hardware_v2_custom_pcb_plan.md)
- [`hardware/hardware_v2_decision_register.md`](hardware/hardware_v2_decision_register.md)
- [`design/hardware_v2_motor_upgrade_plan.md`](design/hardware_v2_motor_upgrade_plan.md)

## Electronics

- [`hardware/electronics_overview.md`](hardware/electronics_overview.md)
- [`hardware/parts_list.md`](hardware/parts_list.md)
- [`hardware/sensor_list.md`](hardware/sensor_list.md)
- [`hardware/pcb_wiring_diagrams.md`](hardware/pcb_wiring_diagrams.md)
- [`hardware/as_built_wiring_checklist.md`](hardware/as_built_wiring_checklist.md)

Battery, motor, H-bridge, regulator, PCB and pin-map follow-up requirements are indexed under the matching IDs in [`../NEXT_REVIEW.md`](../NEXT_REVIEW.md).

## Software

Active status:

- [`code/README.md`](code/README.md) — current Hardware V2 software status and completion gate;
- [`../src/README.md`](../src/README.md) — intentionally cleared active source area.

Engineering history / brainstorm:

- [`../brainstorm/software-redesign/README.md`](../brainstorm/software-redesign/README.md);
- [`../brainstorm/software-redesign/previous-docs/`](../brainstorm/software-redesign/previous-docs/);
- [`../brainstorm/software-redesign/previous-source/`](../brainstorm/software-redesign/previous-source/);
- [`../engineering-journal/2026-08-12-software-redesign.md`](../engineering-journal/2026-08-12-software-redesign.md).

The previous software architecture, state machine, PixyCam plan and source are no longer active Hardware V2 claims. They are preserved to show the engineering process and to inform the next implementation.

## Testing

- [`testing/hardware_v2_validation_template.md`](testing/hardware_v2_validation_template.md)
- [`testing/tests.md`](testing/tests.md)
- [`testing/final_validation_results.md`](testing/final_validation_results.md)
- [`testing/performance_measurements.md`](testing/performance_measurements.md) — `[HW1-HISTORY]` measurement source;
- [`testing/iteration_log.md`](testing/iteration_log.md).

## Reproducibility and submission

- [`reproducibility/evidence_map.md`](reproducibility/evidence_map.md)
- [`reproducibility/full_rebuild_guide.md`](reproducibility/full_rebuild_guide.md)
- [`reproducibility/exact_rebuild_wiring_upload_start.md`](reproducibility/exact_rebuild_wiring_upload_start.md)
- [`reproducibility/submission_checklist.md`](reproducibility/submission_checklist.md)
- [`reproducibility/final_submission_pack.md`](reproducibility/final_submission_pack.md)

## Historical evidence

- [`../archivo/hardware-v1-esp32-250rpm/`](../archivo/hardware-v1-esp32-250rpm/) — `[HW1-HISTORY]` archived text snapshots;
- [`../schemes/`](../schemes/) — Hardware V1 schematic/media status and Hardware V2 requirements;
- [`../v-photos/`](../v-photos/) — Hardware V1 robot views until replaced;
- [`../video/`](../video/) — Hardware V1 Open video until replaced.

Old information remains useful as iteration evidence, but active pages must identify it as history or brainstorming. No file should be treated as final Hardware V2 evidence unless its implementation and validation match the physical robot.
