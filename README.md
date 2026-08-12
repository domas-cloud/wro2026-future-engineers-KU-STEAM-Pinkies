# KU STEAM Pinkies — WRO 2026 Future Engineers

## Quick navigation

| Purpose | Open |
|---|---|
| Start here | [`START_HERE.md`](START_HERE.md) |
| **Continue the next review** | **[`NEXT_REVIEW.md`](NEXT_REVIEW.md)** |
| Hardware V2 status | [`Hardware V2 decision register`](docs/hardware/hardware_v2_decision_register.md) |
| Custom PCB work | [`Custom PCB migration plan`](docs/hardware/hardware_v2_custom_pcb_plan.md) |
| Active BOM | [`Parts list`](docs/hardware/parts_list.md) |
| Electronics architecture | [`Electronics overview`](docs/hardware/electronics_overview.md) |
| Software redesign status | [`Software status`](docs/code/README.md) |
| Software brainstorm/history | [`Software redesign brainstorm`](brainstorm/software-redesign/README.md) |
| Motor upgrade | [`Motor upgrade plan`](docs/design/hardware_v2_motor_upgrade_plan.md) |
| Testing | [`Hardware V2 validation template`](docs/testing/hardware_v2_validation_template.md) |
| Evidence by rubric area | [`Evidence map`](docs/reproducibility/evidence_map.md) |
| Historical Hardware V1 | [`archivo/hardware-v1-esp32-250rpm/`](archivo/hardware-v1-esp32-250rpm/) |

> **Repository status:** `[HW1-HISTORY]` Hardware V1 is the last verified and measured robot baseline. `[HW2-IMPROVEMENT]` Hardware V2 is the active redesign. Hardware V2 must not be described as final until its exact motor, motor driver, LiPo, regulators, PCB files, software and repeated field results are available.

> **Software status:** on **2026-08-12** the active Hardware V2 software documentation and source were intentionally reset. Previous software material was preserved under [`brainstorm/software-redesign/`](brainstorm/software-redesign/) so the next implementation can be designed from the final Hardware V2 hardware rather than from old assumptions.

> **[NEXT-REVIEW]** All missing information, update locations and completion conditions are indexed in [`NEXT_REVIEW.md`](NEXT_REVIEW.md). Search the repository for `HW2-TBD`, `HW2-VERIFY` or `NEXT-REVIEW` during the next check.

We are **KU STEAM Pinkies**, competing in **WRO 2026 Future Engineers**. This repository records the engineering process rather than hiding earlier versions. When an active design changes, previous work is preserved as engineering history before the judge-facing version is rewritten.

## Status markers

- `[HW1-HISTORY]` — verified older evidence;
- `[HW2-IMPROVEMENT]` — what changed or will improve after Hardware V1;
- `[HW2-CONFIRMED]` — selected Hardware V2 fact;
- `[HW2-TBD]` — exact information is still missing;
- `[HW2-VERIFY]` — selected but still needs a real test;
- `[HW2-DONE]` — implementation and evidence are complete;
- `[NEXT-REVIEW]` — item to check during the next repository review.

## Contents

- [1. Version map](#1-version-map)
- [2. Team](#2-team)
- [3. Verified Hardware V1 baseline](#3-verified-hardware-v1-baseline)
- [4. Confirmed Hardware V2 architecture](#4-confirmed-hardware-v2-architecture)
- [5. Decisions still open](#5-decisions-still-open)
- [6. Mechanical engineering history](#6-mechanical-engineering-history)
- [7. Electronics and sensing](#7-electronics-and-sensing)
- [8. Software status](#8-software-status)
- [9. Testing evidence](#9-testing-evidence)
- [10. Reproducibility status](#10-reproducibility-status)
- [11. Photos and video](#11-photos-and-video)
- [12. Repository layout](#12-repository-layout)
- [13. Current conclusion](#13-current-conclusion)

## 1. Version map

| Version | Meaning | Evidence state |
|---|---|---|
| `[HW1-HISTORY]` Hardware V1 | ESP32 development-board/perfboard robot with Raspberry Pi Zero, `N20 250 rpm`, `L298N` and `2x 18650` supply | historical working and measured baseline |
| `[HW2-IMPROVEMENT]` Hardware V2 | custom-PCB robot using ESP32-WROOM-32 and first-generation PixyCam over SPI | hardware architecture confirmed; implementation, software and validation incomplete |

Hardware V1 material is not presented as the current target. It remains valuable because it shows real iterations, measured results, rejected choices and the reason for the Hardware V2 redesign. The exact V1-to-V2 improvement map is in [`NEXT_REVIEW.md`](NEXT_REVIEW.md).

## 2. Team

- **Marius** — software development and mechanical design;
- **Domas** — project coordination, testing and documentation;
- **Jonas** — electronics and hardware design.

Responsibilities are divided, but major decisions are reviewed as one robot system because mechanics, electronics, power and software affect each other.

## 3. Verified Hardware V1 baseline

`[HW1-HISTORY]` The last fully documented baseline used:

- rear-wheel drive and front-wheel steering;
- ESP32 low-level control;
- Raspberry Pi Zero camera processing;
- `BNO085` heading feedback;
- one front `VL53L1X` and two side ToF sensors;
- `MG90S` steering servo;
- `N20 6 V 250 rpm` drive motor;
- `L298N` module;
- `2x 18650` Li-ion supply;
- perfboard-based integration;
- LEGO rear differential and custom silicone front wheels.

The old Raspberry Pi, UART, perfboard, battery and motor documents are preserved under [`archivo/hardware-v1-esp32-250rpm/`](archivo/hardware-v1-esp32-250rpm/). The previous software source and software-planning documents are additionally preserved under [`brainstorm/software-redesign/`](brainstorm/software-redesign/). The existing schematic PDF and current robot photos describe Hardware V1 unless explicitly stated otherwise.

`[HW2-IMPROVEMENT]` Hardware V2 removes the Pi/UART path, changes to PixyCam SPI, moves to a custom PCB, changes to LiPo power and reopens the motor/driver selection.

## 4. Confirmed Hardware V2 architecture

The team has confirmed the following hardware direction:

| Subsystem | Hardware V2 decision | Status |
|---|---|---|
| main controller | `ESP32-WROOM-32` | `[HW2-CONFIRMED]` |
| perception | first-generation `PixyCam` / CMUcam5 with onboard colour processing | `[HW2-CONFIRMED]` |
| camera link | wired `SPI` | `[HW2-CONFIRMED]` |
| front distance sensor | `VL53L1X` | `[HW2-CONFIRMED]` |
| side distance sensors | `2x VL53L4CD` | `[HW2-CONFIRMED]` |
| orientation | `BNO085` | `[HW2-CONFIRMED]` |
| steering | `MG90S` | `[HW2-CONFIRMED]` |
| power chemistry | LiPo | `[HW2-CONFIRMED]` direction; exact pack `[HW2-TBD]` |
| drive motor | faster than the Hardware V1 `250 rpm` baseline | exact part `[HW2-TBD]` |
| motor driver | custom-PCB H-bridge stage | exact IC `[HW2-TBD]` |
| electronics integration | purpose-built custom PCB | `[HW2-CONFIRMED]` direction; `[HW2-VERIFY]` design incomplete |

At hardware-interface level, PixyCam is intended to provide compact object information to the ESP32 over SPI. The **final software architecture that uses those inputs is not yet locked**.

Raspberry Pi Zero is not part of the active Hardware V2 architecture.

## 5. Decisions still open

The repository deliberately leaves these values visible as `[HW2-TBD]`:

1. exact LiPo cell count, voltage, capacity, C-rating and connector;
2. exact faster motor, voltage, rpm, gearbox, torque and current;
3. exact motor-driver IC and thermal design;
4. exact power regulators and current margins;
5. whether the ESP32 module is soldered directly or used through a carrier;
6. complete GPIO and connector pin map;
7. PCB dimensions, layer count, mounting holes and production files;
8. PixyCam signature numbers, settings and measured detection limits;
9. final robot dimensions and mass;
10. final Hardware V2 software architecture and source;
11. final repeated Open and Obstacle results.

The required content, repository update locations and completion conditions for every item are described in [`NEXT_REVIEW.md`](NEXT_REVIEW.md). No missing measurement is replaced with an estimate presented as a fact.

## 6. Mechanical engineering history

`[HW1-HISTORY]` The verified mechanical baseline is still useful for Hardware V2 because the main chassis and steering lessons remain relevant:

- reducing the steering lever arm lowered servo load;
- custom silicone front wheels improved the transfer of steering commands to the field surface;
- the LEGO differential reduced binding in turns;
- limiting the useful steering range improved stability;
- practical repeatability mattered more than maximum theoretical speed.

Hardware V1 compared `50 rpm`, `250 rpm` and `1000 rpm` N20 options and retained `250 rpm` for that robot. This does **not** mean `250 rpm` is the final Hardware V2 motor.

`[HW2-IMPROVEMENT]` Hardware V2 reopens the motor selection and requires loaded-speed, current, thermal and repeated-run evidence while retaining the successful steering and differential lessons.

Mechanical references:

- [`drivetrain_and_steering.md`](docs/design/drivetrain_and_steering.md)
- [`engineering_decisions.md`](docs/design/engineering_decisions.md)
- [`risk_and_failures.md`](docs/design/risk_and_failures.md)
- [`hardware_v2_motor_upgrade_plan.md`](docs/design/hardware_v2_motor_upgrade_plan.md)
- [`models/README.md`](models/README.md)

## 7. Electronics and sensing

The active Hardware V2 sensor set is:

- front `VL53L1X`;
- left `VL53L4CD`;
- right `VL53L4CD`;
- `BNO085` IMU;
- first-generation PixyCam.

`[HW1-HISTORY]` The earlier `VL53L1CD` label in several Hardware V1 text files was a documentation error. Archived snapshots remain unchanged.

`[HW2-IMPROVEMENT]` Active Hardware V2 documents use the correct `VL53L4CD` side-sensor model and require the final address, startup and placement evidence.

The final PCB documentation still needs `[HW2-TBD]`:

- exact power tree;
- reverse-polarity and over-current protection;
- I2C voltage, pull-ups, addresses and startup sequence;
- PixyCam supply and SPI electrical compatibility;
- servo transient-current handling;
- motor suppression and H-bridge thermal design;
- labelled connectors, test points and complete pin map;
- editable schematic, PCB source, Gerbers, drill files and BOM;
- assembled-board photos and measured rail stability.

See [`electronics_overview.md`](docs/hardware/electronics_overview.md), [`hardware_v2_custom_pcb_plan.md`](docs/hardware/hardware_v2_custom_pcb_plan.md) and the `HW2-POWER-01`, `HW2-DRIVER-01` and `HW2-PCB-01` sections in [`NEXT_REVIEW.md`](NEXT_REVIEW.md).

## 8. Software status

`[HW2-TBD]` **Hardware V2 software is being redesigned from a clean active state.**

On 2026-08-12 we removed the previous software architecture, state-machine, PixyCam integration-plan and source tree from the active Hardware V2 path. They were not deleted; exact copies were moved to:

- [`brainstorm/software-redesign/previous-docs/`](brainstorm/software-redesign/previous-docs/)
- [`brainstorm/software-redesign/previous-source/`](brainstorm/software-redesign/previous-source/)

The reason is simple: Hardware V2 changed the perception device, communication path, PCB, power and drive system. Carrying forward an old state machine, pin map, thresholds or control logic before the final hardware is implemented would make the documentation look more complete than the robot really is.

The active software page is now [`docs/code/README.md`](docs/code/README.md). The active source directory [`src/`](src/) contains only the reset status until new code is implemented.

The software reset is also documented as an engineering iteration in [`engineering-journal/2026-08-12-software-redesign.md`](engineering-journal/2026-08-12-software-redesign.md).

Before software is presented as final Hardware V2 evidence, it must:

1. match the final PCB GPIO and electrical interfaces;
2. communicate with PixyCam over tested SPI;
3. support the selected motor driver;
4. initialize the BNO085 and all ToF sensors reliably;
5. implement and document start, stop and fault behaviour;
6. demonstrate Open and Obstacle behaviour in repeated physical tests;
7. have documentation that matches the tested source.

## 9. Testing evidence

`[HW1-HISTORY]` The strict Hardware V1 measurement source is [`performance_measurements.md`](docs/testing/performance_measurements.md). The currently documented quantitative snapshot is:

| Metric | Earlier version | Hardware V1 result |
|---|---:|---:|
| average drift over `3 m` | `10.6 cm` | `4.0 cm` |
| approximate `90°` turn space | `46 cm` | `39 cm` |
| open straight clean passes | not recorded as a matched earlier set | `5/5` |
| obstacle slalom clean passes | not recorded as a matched earlier set | `4/5` |
| full practice route completions | not recorded as a matched earlier set | `4/5` |

These values are historical Hardware V1 evidence, not Hardware V2 results.

`[HW2-TBD]` Final Hardware V2 tables remain empty until real tests are performed. Use [`hardware_v2_validation_template.md`](docs/testing/hardware_v2_validation_template.md) and `HW2-TEST-01` in [`NEXT_REVIEW.md`](NEXT_REVIEW.md) for power, thermal, sensor-startup, camera, motor, software and field validation.

## 10. Reproducibility status

- `[HW1-HISTORY]` Hardware V1: historical parts, code, wiring and media remain available as engineering evidence;
- `[HW2-TBD]` Hardware V2: not yet reproducible as a complete robot because exact power, motor, driver, pin map, PCB files, final source and validation are still missing.

A final Hardware V2 rebuild guide must include exact parts, assembly files, pinout, firmware configuration, calibration procedure and measured acceptance results. The complete required package is listed under `HW2-REBUILD-01` in [`NEXT_REVIEW.md`](NEXT_REVIEW.md).

## 11. Photos and video

`[HW1-HISTORY]` The current six-view robot photos and the linked Open Challenge video show Hardware V1. They are retained as verified historical evidence.

`[HW2-TBD]` Hardware V2 still requires:

- final six-view robot photos;
- PCB top and bottom photos;
- connector and sensor-placement photos;
- PixyCam training screenshots;
- final Open Challenge video;
- final Obstacle Challenge video.

See [`v-photos/README.md`](v-photos/README.md), [`video/video.md`](video/video.md) and `HW2-MEDIA-01` in [`NEXT_REVIEW.md`](NEXT_REVIEW.md).

## 12. Repository layout

- `NEXT_REVIEW.md` — single searchable tracker for every missing V2 item and the next full review;
- `docs/design/` — mechanical decisions, risks and system reasoning;
- `docs/hardware/` — active Hardware V2 architecture, BOM and PCB planning;
- `docs/code/` — active software status only until the new implementation is tested;
- `docs/testing/` — historical results and Hardware V2 validation templates;
- `docs/evaluation/` — evaluation of the verified baseline;
- `docs/reproducibility/` — evidence and rebuild-status maps;
- `schemes/` — Hardware V1 schematic evidence and Hardware V2 requirements;
- `models/` — CAD/STL evidence;
- `src/` — intentionally cleared active Hardware V2 source area;
- `brainstorm/software-redesign/` — exact pre-reset software documents/source plus future software ideas;
- `engineering-journal/` — journal-ready engineering decisions and iteration notes;
- `archivo/` — preserved earlier text snapshots from the Hardware V1/HW2 migration;
- `t-photos/`, `v-photos/`, `video/` — media evidence with version status documented.

## 13. Current conclusion

The repository separates verified history from the active redesign. Hardware V1 proves that the team built, tested and improved a working robot. Hardware V2 keeps the successful mechanical lessons while changing the perception, power, drive and electronics integration.

The software has now been deliberately reset rather than pretending the old implementation is already the final V2 solution. The next engineering milestones are component lock, PCB implementation and measured evidence, followed by a new software implementation built against that real hardware.

Until the final LiPo, motor, H-bridge, PCB, PixyCam settings, source code and repeated field tests exist together, Hardware V2 remains an honestly documented engineering migration rather than a falsely completed final robot.

Open [`NEXT_REVIEW.md`](NEXT_REVIEW.md) at the start of the next update so no missing item or old-version reference is overlooked.
