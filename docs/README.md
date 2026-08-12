# Documentation

The root [`README`](../README.md) tells the project story. The files here hold the technical detail behind it.

## Design

- [`design/system_overview.md`](design/system_overview.md) — how the mechanical, electrical and sensing parts affect each other
- [`design/chassis_design_improved.md`](design/chassis_design_improved.md) — chassis and packaging
- [`design/drivetrain_and_steering.md`](design/drivetrain_and_steering.md) — steering, differential and motor history
- [`design/engineering_decisions.md`](design/engineering_decisions.md) — important choices and what led to them
- [`design/risk_and_failures.md`](design/risk_and_failures.md) — failures we already saw and risks we still need to test

## Hardware

- [`hardware/electronics_overview.md`](hardware/electronics_overview.md)
- [`hardware/parts_list.md`](hardware/parts_list.md)
- [`hardware/sensor_list.md`](hardware/sensor_list.md)
- [`hardware/hardware_v2_custom_pcb_plan.md`](hardware/hardware_v2_custom_pcb_plan.md)
- [`hardware/pcb_wiring_diagrams.md`](hardware/pcb_wiring_diagrams.md)
- [`hardware/as_built_wiring_checklist.md`](hardware/as_built_wiring_checklist.md)

## Software

The V2 software is being rewritten. [`code/README.md`](code/README.md) explains the current state. Old code and software notes are preserved in [`../brainstorm/software-redesign/`](../brainstorm/software-redesign/).

## Testing

- [`testing/performance_measurements.md`](testing/performance_measurements.md) — real measurements from Hardware V1
- [`testing/iteration_log.md`](testing/iteration_log.md) — changes and failures
- [`testing/hardware_v2_validation_template.md`](testing/hardware_v2_validation_template.md) — measurements to collect on V2
- [`testing/final_validation_results.md`](testing/final_validation_results.md) — final run table once V2 is ready

## Rebuilding the robot

The [`reproducibility/`](reproducibility/) folder contains the BOM/wiring/build/submission notes. Some pages still describe what must be filled in after the final PCB and software are finished.

Mechanical files are in [`../models/`](../models/), electrical drawings in [`../schemes/`](../schemes/), vehicle photos in [`../v-photos/`](../v-photos/) and videos in [`../video/`](../video/).

Older V1 documentation lives in [`../archivo/`](../archivo/). We keep it because the rejected and replaced versions are part of the engineering process.
