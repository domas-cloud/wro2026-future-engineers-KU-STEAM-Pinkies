# KU STEAM Pinkies — WRO 2026 Future Engineers

## Quick navigation

| Purpose | Open |
|---|---|
| Start here | [`START_HERE.md`](START_HERE.md) |
| Hardware V2 status | [`Hardware V2 decision register`](docs/hardware/hardware_v2_decision_register.md) |
| Custom PCB work | [`Custom PCB migration plan`](docs/hardware/hardware_v2_custom_pcb_plan.md) |
| Active BOM | [`Parts list`](docs/hardware/parts_list.md) |
| Electronics architecture | [`Electronics overview`](docs/hardware/electronics_overview.md) |
| PixyCam integration | [`PixyCam SPI plan`](docs/code/pixycam_spi_integration_plan.md) |
| Motor upgrade | [`Motor upgrade plan`](docs/design/hardware_v2_motor_upgrade_plan.md) |
| Testing | [`Hardware V2 validation template`](docs/testing/hardware_v2_validation_template.md) |
| Evidence by rubric area | [`Evidence map`](docs/reproducibility/evidence_map.md) |
| Historical Hardware V1 | [`archivo/hardware-v1-esp32-250rpm/`](archivo/hardware-v1-esp32-250rpm/) |

> **Repository status:** Hardware V1 is the last verified and measured robot baseline. Hardware V2 is the active redesign. Hardware V2 must not be described as final until its exact motor, motor driver, LiPo, regulators, PCB files, firmware and repeated field results are available.

We are **KU STEAM Pinkies**, competing in **WRO 2026 Future Engineers**. This repository records the engineering process rather than hiding earlier versions. When an active text file is rewritten, its previous version is copied into `archivo/` first.

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
| Hardware V1 | ESP32 development-board/perfboard robot with Raspberry Pi Zero, `N20 250 rpm`, `L298N` and `2x 18650` supply | historical working and measured baseline |
| Hardware V2 | custom-PCB robot using ESP32-WROOM-32 and first-generation PixyCam over SPI | architecture confirmed; implementation and validation incomplete |

Hardware V1 material is not presented as the current target. It remains valuable because it shows real iterations, measured results, rejected choices and the reason for the Hardware V2 redesign.

## 2. Team

- **Marius** — software development and mechanical design;
- **Domas** — project coordination, testing and documentation;
- **Jonas** — electronics and hardware design.

Responsibilities are divided, but major decisions are reviewed as one robot system because mechanics, electronics, power and software affect each other.

## 3. Verified Hardware V1 baseline

The last fully documented baseline used:

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

The old Raspberry Pi, UART, perfboard, battery and motor documents are preserved under [`archivo/hardware-v1-esp32-250rpm/`](archivo/hardware-v1-esp32-250rpm/). The existing schematic PDF and current robot photos also describe Hardware V1 unless explicitly stated otherwise.

## 4. Confirmed Hardware V2 architecture

The team has confirmed the following direction:

| Subsystem | Hardware V2 decision | Status |
|---|---|---|
| main controller | `ESP32-WROOM-32` | confirmed |
| perception | first-generation `PixyCam` / CMUcam5 with onboard colour processing | confirmed |
| camera link | wired `SPI` | confirmed |
| front distance sensor | `VL53L1X` | confirmed |
| side distance sensors | `2x VL53L4CD` | confirmed |
| orientation | `BNO085` | confirmed |
| steering | `MG90S` | confirmed |
| power chemistry | LiPo | confirmed in principle; exact pack TBD |
| drive motor | faster than the Hardware V1 `250 rpm` baseline | exact part TBD |
| motor driver | custom-PCB H-bridge stage | exact IC TBD |
| electronics integration | purpose-built custom PCB | confirmed direction; design not complete |

The active data path is intended to be:

```text
red / green traffic pillar
        ↓
first-generation PixyCam
(onboard colour-signature processing)
        ↓ wired SPI block data
ESP32-WROOM-32
        ↓
heading + distance + obstacle decision
        ↓
MG90S steering and motor-driver commands
```

Raspberry Pi Zero is not part of the active Hardware V2 architecture.

## 5. Decisions still open

The repository deliberately leaves these values visible as `TBD`:

1. exact LiPo cell count, voltage, capacity, C-rating and connector;
2. exact faster motor, voltage, rpm, gearbox, torque and current;
3. exact motor-driver IC and thermal design;
4. exact power regulators and current margins;
5. whether the ESP32 module is soldered directly or used through a carrier;
6. complete GPIO and connector pin map;
7. PCB dimensions, layer count, mounting holes and production files;
8. PixyCam signature numbers, settings and measured detection limits;
9. final robot dimensions and mass;
10. final repeated Open and Obstacle results.

The required content for these sections is described in the PCB plan, decision register and validation template. No missing measurement is replaced with an estimate presented as a fact.

## 6. Mechanical engineering history

The verified mechanical baseline is still useful for Hardware V2 because the main chassis and steering lessons remain relevant:

- reducing the steering lever arm lowered servo load;
- custom silicone front wheels improved the transfer of steering commands to the field surface;
- the LEGO differential reduced binding in turns;
- limiting the useful steering range improved stability;
- practical repeatability mattered more than maximum theoretical speed.

Hardware V1 compared `50 rpm`, `250 rpm` and `1000 rpm` N20 options and retained `250 rpm` for that robot. This does **not** mean `250 rpm` is the final Hardware V2 motor. Hardware V2 reopens the motor selection and requires loaded-speed, current, thermal and repeated-run evidence.

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

The earlier `VL53L1CD` label in several Hardware V1 text files was a documentation error. Archived snapshots remain unchanged, while active Hardware V2 documents use `VL53L4CD`.

The final PCB documentation still needs:

- exact power tree;
- reverse-polarity and over-current protection;
- I2C voltage, pull-ups, addresses and startup sequence;
- PixyCam supply and SPI electrical compatibility;
- servo transient-current handling;
- motor suppression and H-bridge thermal design;
- labelled connectors, test points and complete pin map;
- editable schematic, PCB source, Gerbers, drill files and BOM;
- assembled-board photos and measured rail stability.

See [`electronics_overview.md`](docs/hardware/electronics_overview.md) and [`hardware_v2_custom_pcb_plan.md`](docs/hardware/hardware_v2_custom_pcb_plan.md).

## 8. Software status

The source currently published under [`src/`](src/) is the Hardware V1 ESP32 controller and legacy Raspberry Pi perception work. It is real development evidence, but it is not yet the final Hardware V2 runtime.

Confirmed Hardware V2 software work still required:

1. replace the Pi/UART perception path with first-generation PixyCam SPI access;
2. map Pixy signatures to the legal red/green passing decisions;
3. document freshness, ambiguous-detection and camera-fault handling;
4. integrate the selected motor driver and final pin map;
5. align code, diagrams and runtime instructions;
6. test communication while motor and servo loads are active.

The current code should not be described as already implementing PixyCam SPI. See [`pixycam_spi_integration_plan.md`](docs/code/pixycam_spi_integration_plan.md) and [`src/README.md`](src/README.md).

## 9. Testing evidence

The strict Hardware V1 measurement source is [`performance_measurements.md`](docs/testing/performance_measurements.md). The currently documented quantitative snapshot is:

| Metric | Earlier version | Hardware V1 result |
|---|---:|---:|
| average drift over `3 m` | `10.6 cm` | `4.0 cm` |
| approximate `90°` turn space | `46 cm` | `39 cm` |
| open straight clean passes | not recorded as a matched earlier set | `5/5` |
| obstacle slalom clean passes | not recorded as a matched earlier set | `4/5` |
| full practice route completions | not recorded as a matched earlier set | `4/5` |

These values are historical Hardware V1 evidence, not Hardware V2 results. Final Hardware V2 tables remain empty until real tests are performed. Use [`hardware_v2_validation_template.md`](docs/testing/hardware_v2_validation_template.md) for power, thermal, sensor-startup, camera, motor and field validation.

## 10. Reproducibility status

- **Hardware V1:** historical parts, code, wiring and media remain available.
- **Hardware V2:** not yet reproducible as a complete robot because exact power, motor, driver, pin map, PCB files and final code are still missing.

A final Hardware V2 rebuild guide must include exact parts, assembly files, pinout, firmware configuration, calibration procedure and measured acceptance results. Current rebuild documents therefore distinguish the historical baseline from the incomplete V2 target.

## 11. Photos and video

The current six-view robot photos and the linked Open Challenge video show Hardware V1. They are retained as verified historical evidence.

Hardware V2 still requires:

- final six-view robot photos;
- PCB top and bottom photos;
- connector and sensor-placement photos;
- PixyCam training screenshots;
- final Open Challenge video;
- final Obstacle Challenge video.

See [`v-photos/README.md`](v-photos/README.md) and [`video/video.md`](video/video.md).

## 12. Repository layout

- `docs/design/` — mechanical decisions, risks and system reasoning;
- `docs/hardware/` — active Hardware V2 architecture, BOM and PCB planning;
- `docs/code/` — controller documentation and PixyCam integration planning;
- `docs/testing/` — historical results and Hardware V2 validation templates;
- `docs/evaluation/` — evaluation of the verified baseline;
- `docs/reproducibility/` — evidence and rebuild-status maps;
- `schemes/` — Hardware V1 schematic evidence and Hardware V2 requirements;
- `models/` — CAD/STL evidence;
- `src/` — current Hardware V1 code and future Hardware V2 controller work;
- `archivo/` — preserved text snapshots before migration edits;
- `t-photos/`, `v-photos/`, `video/` — media evidence with version status documented.

## 13. Current conclusion

The repository now separates verified history from the active redesign. Hardware V1 proves that the team built, tested and improved a working robot. Hardware V2 keeps the successful mechanical lessons while changing the perception, power, drive and electronics integration.

The next engineering milestone is not more descriptive text. It is component lock and measured evidence: exact LiPo, motor, H-bridge, regulator design, PCB pin map, PixyCam settings, final firmware and repeated field tests. Until those exist, Hardware V2 remains an honestly documented engineering migration rather than a falsely completed final robot.
