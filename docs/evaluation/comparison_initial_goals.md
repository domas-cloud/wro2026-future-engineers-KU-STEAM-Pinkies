# Comparison With Initial Goals

This table compares the first planned robot with the final repository-state robot.

| Initial goal | Final outcome | What changed | Why it changed | Evidence file |
| --- | --- | --- | --- | --- |
| simple front steering with enough torque | three-gear steering with corrected geometry and `MG90S` servo | steering pivots and geometry were rebuilt | the earlier wheel lever arm overloaded the servo and reduced repeatability | `docs/design/drivetrain_and_steering.md` |
| single-sensor navigation concept | mixed sensing with camera, `BNO085`, and `front VL53L1X + 2x VL53L1CD` | architecture became multi-layer instead of single-source | one sensor type alone was not reliable enough across layouts | `docs/hardware/electronics_overview.md` |
| direct drive without much drivetrain complexity | rear differential retained in the final robot | drivetrain became mechanically more forgiving | the version without a differential increased corner resistance and slip | `docs/evaluation/what_didnt.md` |
| fastest possible motor choice | `N20 6 V 250 rpm` chosen as the final balance | slower and faster motors were rejected | the team prioritized controllability and usable torque over headline speed | `docs/testing/performance_measurements.md` |
| software driven mostly from one controller | split `Raspberry Pi Zero` and `ESP32` runtime | perception and low-level control were separated | this made the control loop simpler and the perception role clearer | `docs/code/software_architecture_improved.md` |
| generic rebuild notes | judge-oriented rebuild path with BOM, CAD, schematics, and runtime docs | documentation became part of the engineered solution | reproducibility is judged directly in WRO submission review | `docs/reproducibility/evidence_map.md` |

## Most Logical Next Improvement

The next practical improvement is not a new subsystem. It is tighter repeatability: more counted full-route runs and a cleaner perception-to-controller interface under more obstacle layouts.

