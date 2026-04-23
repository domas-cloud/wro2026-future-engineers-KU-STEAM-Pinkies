# Evidence Map

A quick map of where the main evidence lives in the repository.

## Criterion 1: Mobility And Mechanical Design

Main files:

- [README.md](../../README.md)
- [docs/design/chassis_design_improved.md](../design/chassis_design_improved.md)
- [docs/design/drivetrain_and_steering.md](../design/drivetrain_and_steering.md)
- [docs/design/engineering_decisions.md](../design/engineering_decisions.md)
- [docs/design/risk_and_failures.md](../design/risk_and_failures.md)
- [models/README.md](../../models/README.md)

What they show:

- chassis layout
- steering and drivetrain design
- trade-offs and iterations
- custom part evidence

## Criterion 2: Power And Sensor Architecture

Main files:

- [docs/hardware/electronics_overview.md](../hardware/electronics_overview.md)
- [docs/hardware/pcb_wiring_diagrams.md](../hardware/pcb_wiring_diagrams.md)
- [docs/hardware/sensor_list.md](../hardware/sensor_list.md)
- [docs/hardware/parts_list.md](../hardware/parts_list.md)
- [schemes/README.md](../../schemes/README.md)
- [schemes/wiring_overview.md](../../schemes/wiring_overview.md)
- [schemes/Wro_customPCBs.pdf](../../schemes/Wro_customPCBs.pdf)
- [schemes/custom_pcb_description.md](../../schemes/custom_pcb_description.md)

What they show:

- electronics architecture
- power branches
- sensor choices and placement
- wiring and schematic evidence

## Criterion 3: Software Architecture And Obstacle Strategy

Main files:

- [docs/code/control_algorithms.md](../code/control_algorithms.md)
- [docs/code/software_architecture_improved.md](../code/software_architecture_improved.md)
- [docs/code/navigation_strategy_improved.md](../code/navigation_strategy_improved.md)
- [docs/code/software_flow_and_state_logic.md](../code/software_flow_and_state_logic.md)
- [docs/code/vision_interface.md](../code/vision_interface.md)
- [src/README.md](../../src/README.md)
- [src/pi-zero/README.md](../../src/pi-zero/README.md)

What they show:

- low-level control structure
- obstacle handling idea
- state flow
- published controller layout
- Pi-to-ESP32 software interface

Key tuning result:

- straight drift improved from `9 cm` to `4 cm`, corner overshoot from `14 cm` to `6 cm`, `3`-lap success from `60%` to `90%`, and recovery time from `1.2 s` to `0.6 s`

## Criterion 4: Systems Thinking And Engineering Decisions

Main files:

- [docs/design/system_overview.md](../design/system_overview.md)
- [docs/design/engineering_decisions.md](../design/engineering_decisions.md)
- [docs/design/risk_and_failures.md](../design/risk_and_failures.md)
- [docs/evaluation/comparison_initial_goals.md](../evaluation/comparison_initial_goals.md)
- [docs/evaluation/what_worked.md](../evaluation/what_worked.md)
- [docs/evaluation/what_didnt.md](../evaluation/what_didnt.md)

What they show:

- interaction between subsystems
- why one option was chosen over another
- failure modes and mitigations
- improvement during the season

## Criterion 5: Reproducibility And GitHub Quality

Main files:

- [README.md](../../README.md)
- [START_HERE.md](../../START_HERE.md)
- [docs/README.md](../README.md)
- [docs/reproducibility/submission_checklist.md](submission_checklist.md)
- [docs/testing/tests.md](../testing/tests.md)
- [models/README.md](../../models/README.md)
- [video/video.md](../../video/video.md)
- [t-photos/README.md](../../t-photos/README.md)
- [v-photos/README.md](../../v-photos/README.md)
- [src/pi-zero/README.md](../../src/pi-zero/README.md)

What they show:

- where to start reading
- how the repository is organized
- how testing workflow and version stability are documented
- submission media and rebuild references
- multi-controller runtime entry points

## Fast Rebuild Path

For a short rebuild-oriented path:

1. [README.md](../../README.md)
2. [docs/hardware/parts_list.md](../hardware/parts_list.md)
3. [docs/hardware/pcb_wiring_diagrams.md](../hardware/pcb_wiring_diagrams.md)
4. [schemes/Wro_customPCBs.pdf](../../schemes/Wro_customPCBs.pdf)
5. [docs/design/drivetrain_and_steering.md](../design/drivetrain_and_steering.md)
6. [models/README.md](../../models/README.md)
