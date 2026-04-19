# Evidence Map

This page is a judge-oriented map of where the main evidence exists in this repository.

Its purpose is simple: the WRO rubric should be scored from visible evidence, so this file helps evaluators find the strongest evidence quickly instead of searching through the whole repository.

## Criterion 1: Mobility And Mechanical Design

Main evidence:

- `README.md`
- `docs/design/chassis_design_improved.md`
- `docs/design/drivetrain_and_steering.md`
- `docs/design/engineering_decisions.md`
- `docs/design/risk_and_failures.md`
- `models/README.md`

What these files show:

- chassis concept
- steering and drivetrain architecture
- motor and differential choices
- trade-offs such as steering angle versus stability
- mechanical iterations and practical improvements
- printable steering-part files

## Criterion 2: Power And Sensor Architecture

Main evidence:

- `docs/hardware/electronics_overview.md`
- `docs/hardware/pcb_wiring_diagrams.md`
- `docs/hardware/sensor_list.md`
- `docs/hardware/parts_list.md`
- `schemes/README.md`
- `schemes/wiring_overview.md`
- `schemes/Wro_customPCBs.pdf`
- `schemes/custom_pcb_description.md`

What these files show:

- power branches and regulated rails
- current-draw reasoning and power budget
- sensor selection and placement justification
- calibration approach
- wiring structure and schematic evidence
- failure-point analysis and sensor trade-offs

## Criterion 3: Software Architecture And Obstacle Strategy

Main evidence:

- `docs/code/software_architecture_improved.md`
- `docs/code/navigation_strategy_improved.md`
- `docs/code/software_flow_and_state_logic.md`
- `docs/code/message_protocol.md`
- `src/README.md`

What these files show:

- how the robot behavior is organized
- obstacle-handling concept
- state-based behavior explanation
- where the software explanation is documented

## Criterion 4: Systems Thinking And Engineering Decisions

Main evidence:

- `docs/design/system_overview.md`
- `docs/design/engineering_decisions.md`
- `docs/design/risk_and_failures.md`
- `docs/evaluation/comparison_initial_goals.md`
- `docs/evaluation/what_worked.md`
- `docs/evaluation/what_didnt.md`

What these files show:

- subsystem interactions
- why one solution was chosen over another
- practical constraints and trade-offs
- risks, failure modes, and mitigations
- iteration-based improvement across the season

## Criterion 5: Reproducibility And GitHub Quality

Main evidence:

- `README.md`
- `START_HERE.md`
- `docs/README.md`
- this file
- `docs/reproducibility/submission_checklist.md`
- `models/README.md`
- `video/video.md`
- `t-photos/README.md`
- `v-photos/README.md`

What these files show:

- repository entry path for judges
- grouped structure by rubric area
- final submission quality check
- rebuild-oriented pointers
- CAD, wiring, image, and video evidence
- the intent that another team should be able to understand and reproduce the robot with reasonable effort

## Fast Rebuild Path

If another team wanted the shortest practical path through the repository, the recommended order is:

1. `README.md`
2. `START_HERE.md`
3. `docs/hardware/parts_list.md`
4. `docs/hardware/pcb_wiring_diagrams.md`
5. `docs/design/drivetrain_and_steering.md`
6. `models/README.md`

## Final Note

This map does not replace the detailed documents. It exists to make the repository easier to evaluate and easier to navigate.
