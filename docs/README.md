# Technical Documentation

The main project story is in the [root README](../README.md). This page is an index for readers who need more detail.

## Main documents

| Area | Main document | What it contains |
| --- | --- | --- |
| Mechanics | [Drivetrain and steering](design/drivetrain_and_steering.md) | motor comparison, differential, steering versions and wheel grip |
| Electronics | [Electronics overview](hardware/electronics_overview.md) | power budget, controller roles, sensors and calibration |
| Software | [Software state and obstacle flow](code/software_state_machine_and_obstacle_flow.md) | control flow, serial interface, fallback behaviour and obstacle strategy |
| Testing | [Performance measurements](testing/performance_measurements.md) | recorded measurements and repeated-run results |
| Rebuild | [Full rebuild guide](reproducibility/full_rebuild_guide.md) | parts, assembly, wiring, upload and calibration path |

These five files are the normal reading path. The remaining pages provide supporting evidence or narrower implementation details.

## Supporting mechanical evidence

- [Chassis development](design/chassis_design_improved.md)
- [Engineering decisions](design/engineering_decisions.md)
- [Risks and failures](design/risk_and_failures.md)
- [Mechanical rebuild notes](reproducibility/mechanical_rebuild.md)
- [CAD/STL index](../models/README.md)

## Supporting electronics evidence

- [Parts list](hardware/parts_list.md)
- [Sensor list](hardware/sensor_list.md)
- [Motor and servo selection](hardware/motor_servo_selection.md)
- [Wiring diagrams](hardware/pcb_wiring_diagrams.md)
- [As-built wiring checklist](hardware/as_built_wiring_checklist.md)
- [Schematics](../schemes/README.md)

## Supporting software evidence

- [Control algorithms](code/control_algorithms.md)
- [Software architecture](code/software_architecture_improved.md)
- [Navigation strategy](code/navigation_strategy_improved.md)
- [Vision interface](code/vision_interface.md)
- [Runtime setup and calibration](code/runtime_setup_and_calibration.md)
- [ESP32 project](../src/README.md)
- [Pi Zero runtime](../src/pi-zero/README.md)

## Supporting test records

- [Testing method](testing/tests.md)
- [Iteration log](testing/iteration_log.md)
- [Mechanical and software testing](testing/mechanical_and_software_testing.md)
- [Final validation table](testing/final_validation_results.md)
- [What worked](evaluation/what_worked.md)
- [What did not work](evaluation/what_didnt.md)

## Submission material

- [Evidence map](reproducibility/evidence_map.md)
- [Submission checklist](reproducibility/submission_checklist.md)
- [Team photo](../t-photos/team.jpg)
- [Robot photos](../v-photos/README.md)
- [Video links](../video/video.md)

Some supporting pages overlap because they were written during development. When two pages repeat the same information, the document listed in the **Main documents** table should be treated as the current explanation.
