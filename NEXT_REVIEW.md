# Next Review — Hardware V2 Follow-up Tracker

This is the single file to open at the start of the next repository review.

It records:

- which information is verified Hardware V1 history;
- what was improved for Hardware V2;
- which Hardware V2 facts are confirmed;
- exactly what information, files or measurements are still missing;
- which repository files must be updated when new evidence becomes available.

## Search markers

Use these exact markers when reviewing or extending the repository:

- `[HW1-HISTORY]` — verified older information retained as development evidence;
- `[HW2-IMPROVEMENT]` — what changed or is being improved compared with Hardware V1;
- `[HW2-CONFIRMED]` — selected Hardware V2 architecture or component;
- `[HW2-TBD]` — exact information has not been provided yet;
- `[HW2-VERIFY]` — selected in principle but still requires a real test or measurement;
- `[HW2-DONE]` — implementation and evidence are complete and consistent;
- `[NEXT-REVIEW]` — item that must be checked during the next full repository review.

The fastest future check is to search the repository for `HW2-TBD`, `HW2-VERIFY` and `NEXT-REVIEW`.

## Version rule

### [HW1-HISTORY] Verified older robot

Hardware V1 remains valid historical evidence. It used:

- ESP32 development-board integration;
- Raspberry Pi Zero and camera perception;
- Pi-to-ESP32 UART communication;
- perfboard/module-based power and wiring;
- `N20 6 V 250 rpm` motor;
- `L298N` motor-driver module;
- `2x 18650` Li-ion supply;
- the previous firmware, photos, videos and measured results.

Old information must not be silently deleted or presented as current Hardware V2 information. It should be labelled as Hardware V1 history and linked to the relevant improvement.

### [HW2-IMPROVEMENT] Active redesign

| Hardware V1 history | Hardware V2 improvement | Current status |
|---|---|---|
| Raspberry Pi Zero + camera | first-generation PixyCam / CMUcam5 with onboard colour processing | `[HW2-CONFIRMED]` |
| Pi-to-ESP32 UART | direct wired SPI connection from PixyCam to ESP32 | `[HW2-CONFIRMED]` |
| ESP32 development board + perfboard | purpose-built custom PCB around ESP32-WROOM-32 | `[HW2-VERIFY]` design incomplete |
| `2x 18650` Li-ion supply | LiPo-based power system | `[HW2-TBD]` exact pack unknown |
| `N20 250 rpm` motor | faster geared DC motor | `[HW2-TBD]` exact model unknown |
| `L298N` module | custom-PCB H-bridge matched to the selected motor | `[HW2-TBD]` exact IC unknown |
| older `VL53L1CD` side-sensor text | correct side sensors documented as `2x VL53L4CD` | `[HW2-CONFIRMED]` |
| Hardware V1 UART vision parser | PixyCam SPI interface and obstacle-decision logic | `[HW2-TBD]` firmware not implemented |
| Hardware V1 media | new Hardware V2 photos and Open/Obstacle videos | `[HW2-TBD]` not recorded |

## Confirmed Hardware V2 facts

- `[HW2-CONFIRMED]` main controller: `ESP32-WROOM-32`;
- `[HW2-CONFIRMED]` camera: first-generation `PixyCam` / CMUcam5;
- `[HW2-CONFIRMED]` camera communication: wired SPI;
- `[HW2-CONFIRMED]` front ToF: `VL53L1X`;
- `[HW2-CONFIRMED]` side ToF: `2x VL53L4CD`;
- `[HW2-CONFIRMED]` IMU: `BNO085`;
- `[HW2-CONFIRMED]` steering servo: `MG90S`;
- `[HW2-CONFIRMED]` power chemistry direction: LiPo;
- `[HW2-CONFIRMED]` electronics direction: custom PCB;
- `[HW2-CONFIRMED]` drive direction: faster than the Hardware V1 250 rpm baseline;
- `[HW2-CONFIRMED]` Raspberry Pi Zero is not part of active Hardware V2.

## Master missing-information list

### 1. Battery and power

**Marker:** `[HW2-TBD] HW2-POWER-01`

Information required:

- exact LiPo cell count, for example 2S or 3S;
- nominal and maximum charged voltage;
- capacity in mAh;
- C-rating;
- connector type;
- battery dimensions and mass;
- charger and safe handling procedure;
- regulator part numbers and output rails;
- fuse or resettable protection choice;
- measured idle, normal-run and peak current;
- measured rail sag during motor launch and servo movement.

Update these files when known:

- `docs/hardware/parts_list.md`;
- `docs/hardware/electronics_overview.md`;
- `docs/hardware/hardware_v2_custom_pcb_plan.md`;
- `docs/hardware/pcb_wiring_diagrams.md`;
- `schemes/custom_pcb_description.md`;
- `docs/testing/hardware_v2_validation_template.md`;
- final rebuild documents.

Completion condition: exact pack, regulators and protection are documented and verified by measurements.

### 2. Drive motor

**Marker:** `[HW2-TBD] HW2-MOTOR-01`

Information required:

- exact manufacturer and model;
- rated voltage;
- gearbox ratio;
- no-load rpm;
- loaded wheel speed or 3 m time;
- free-run, launch and stall current;
- torque data or measured acceleration;
- shaft dimensions and motor-mount requirements;
- compatibility with the LEGO differential;
- comparison against at least one realistic alternative;
- repeated Open and Obstacle results.

Update these files when known:

- `docs/design/hardware_v2_motor_upgrade_plan.md`;
- `docs/design/drivetrain_and_steering.md`;
- `docs/hardware/motor_servo_selection.md`;
- `docs/hardware/parts_list.md`;
- `docs/testing/hardware_v2_validation_template.md`;
- `docs/testing/iteration_log.md`;
- README and evidence map after verification.

Completion condition: the chosen motor is supported by current, speed, temperature and repeated-run evidence.

### 3. Motor driver

**Marker:** `[HW2-TBD] HW2-DRIVER-01`

Information required:

- exact H-bridge IC;
- continuous and peak current rating;
- logic voltage compatibility with ESP32;
- voltage drop or conduction-loss calculation;
- PWM frequency and control mode;
- reverse, brake and coast behaviour;
- thermal copper area and cooling strategy;
- motor-noise suppression;
- measured driver temperature after repeated runs;
- stall or over-current protection behaviour.

Update these files when known:

- `docs/hardware/parts_list.md`;
- `docs/hardware/electronics_overview.md`;
- `docs/hardware/hardware_v2_custom_pcb_plan.md`;
- `schemes/custom_pcb_description.md`;
- `src/lib/Engine/` or its Hardware V2 replacement;
- power and thermal validation tables.

Completion condition: the driver is electrically matched to the final motor and LiPo and passes the thermal test.

### 4. Custom PCB and ESP32 implementation

**Marker:** `[HW2-TBD] HW2-PCB-01`

Information required:

- whether ESP32-WROOM-32 is soldered directly or used through a carrier;
- complete GPIO map;
- boot, reset and programming circuit;
- flash and PlatformIO board configuration;
- exact PCB dimensions, layers and mounting holes;
- connector family and complete pinout;
- I2C voltage, pull-ups and sensor startup sequence;
- PixyCam power and SPI electrical compatibility;
- servo and motor power routing;
- reverse-polarity and over-current protection;
- test points;
- schematic source and PDF;
- PCB source, Gerbers, drill files, fabrication BOM and assembly drawing;
- top and bottom photographs;
- first-power-up and board-revision log.

Update these files when known:

- `docs/hardware/hardware_v2_custom_pcb_plan.md`;
- `docs/hardware/pcb_wiring_diagrams.md`;
- `docs/hardware/as_built_wiring_checklist.md`;
- `schemes/README.md`;
- `schemes/custom_pcb_description.md`;
- `schemes/wiring_overview.md`;
- `src/platformio.ini`;
- `src/README.md`;
- final rebuild guides.

Completion condition: another person can manufacture, assemble, program and test the same board from repository files.

### 5. PixyCam configuration and SPI firmware

**Marker:** `[HW2-TBD] HW2-VISION-02 / HW2-VISION-03`

Information required:

- photo confirming the exact first-generation PixyCam hardware;
- supply-voltage requirement and connector pin order;
- ESP32 SPI pins and stable clock rate;
- Pixy signature number used for red;
- Pixy signature number used for green;
- PixyMon screenshots or exported settings;
- exact fields read by ESP32, such as signature, x, y, width and height;
- block-selection rule when several objects are visible;
- minimum size or repeated-frame filtering;
- stale-data timeout;
- ambiguous or camera-fault behaviour;
- measured detection and stable-decision distance;
- bright, dark and side-lit test results;
- motor-on and servo-on communication stability;
- final obstacle-decision code.

Update these files when known:

- `docs/code/pixycam_spi_integration_plan.md`;
- `docs/code/vision_interface.md`;
- `docs/code/software_architecture_improved.md`;
- `docs/code/software_state_machine_and_obstacle_flow.md`;
- `docs/code/runtime_setup_and_calibration.md`;
- `src/README.md`;
- Hardware V2 source code;
- validation and final-result tables.

Completion condition: published source and measured tests demonstrate both red and green decisions through SPI.

### 6. Sensor placement and final geometry

**Marker:** `[HW2-VERIFY] HW2-SENSOR-01 / 02 / 03`

Information required:

- final mounting position and orientation of each sensor;
- sensor height from the floor;
- final I2C addresses;
- XSHUT/startup pin assignments;
- BNO085 mounting orientation and calibration procedure;
- final wheelbase, track widths, ground clearance and wheel diameters;
- final mass and external dimensions;
- measured steering centre and limits;
- final camera height and angle.

Update these files when known:

- `docs/hardware/sensor_list.md`;
- `docs/hardware/pcb_wiring_diagrams.md`;
- `docs/design/chassis_design_improved.md`;
- `docs/design/drivetrain_and_steering.md`;
- `docs/reproducibility/mechanical_rebuild.md`;
- final photos and diagrams.

Completion condition: all placements and dimensions match the physical Hardware V2 robot.

### 7. Firmware alignment

**Marker:** `[HW2-TBD] HW2-SW-01`

Current source is Hardware V1 evidence. Hardware V2 still requires:

- PixyCam SPI implementation;
- removal or isolation of active Pi/UART assumptions;
- final PCB pin map;
- explicit sensor type selection instead of inferring sensor type from one GPIO number;
- verified start-button pin;
- documented corner-trigger formula;
- final stop and steering-centre behaviour;
- review of derivative/error-state handling;
- camera, sensor and driver fault handling;
- final PlatformIO environment;
- code comments matching the state diagrams;
- build and upload test on the custom PCB.

Update these files when complete:

- `src/src/main.cpp`;
- `src/lib/` modules;
- `src/platformio.ini`;
- `src/README.md`;
- all active `docs/code/` pages;
- wiring and pin-map documents.

Completion condition: code, PCB, documentation and measured behaviour describe the same implementation.

### 8. Validation results

**Marker:** `[HW2-TBD] HW2-TEST-01`

Required evidence:

- at least ten cold/full power-cycle startup checks;
- idle, normal-run and peak current;
- 5 V and 3.3 V rail stability;
- motor, driver and regulator temperatures;
- red/green detection table;
- false-positive and false-negative notes;
- PixyCam stability with motor and servo active;
- motor comparison table;
- final Open Challenge repeated runs;
- final Obstacle Challenge repeated runs;
- parking result;
- failure and correction log tied to commits and media.

Primary files:

- `docs/testing/hardware_v2_validation_template.md`;
- `docs/testing/final_validation_results.md`;
- `docs/testing/iteration_log.md`;
- `docs/testing/track_testing.md`;
- `docs/testing/performance_measurements.md` after V2 measurements exist.

Completion condition: final claims are supported by counted or measured data rather than estimates.

### 9. Final media

**Marker:** `[HW2-TBD] HW2-MEDIA-01`

Required files:

- front, rear, left, right, top and bottom Hardware V2 views;
- PCB top and bottom photos;
- connector and sensor-position photos;
- PixyCam/PixyMon screenshots;
- Open Challenge video;
- Obstacle Challenge video;
- captions identifying the exact robot revision and commit.

Update:

- `v-photos/README.md`;
- `video/video.md`;
- root README;
- evidence map;
- final submission pack.

Completion condition: media clearly shows the same Hardware V2 configuration documented in the BOM, PCB and code.

### 10. Final reproducibility package

**Marker:** `[HW2-TBD] HW2-REBUILD-01`

Required final package:

- exact BOM;
- mechanical files and dimensions;
- schematic and PCB manufacturing files;
- pin map and wiring tables;
- source code and dependencies;
- upload instructions;
- calibration steps;
- exact startup procedure;
- expected sensor checks;
- final acceptance criteria;
- final photos and videos;
- release/tag or clearly identified final commit.

Update:

- `docs/reproducibility/full_rebuild_guide.md`;
- `docs/reproducibility/exact_rebuild_wiring_upload_start.md`;
- `docs/reproducibility/submission_checklist.md`;
- `docs/reproducibility/final_submission_pack.md`;
- `docs/reproducibility/evidence_map.md`.

Completion condition: a technically competent person can rebuild and validate the robot without private team notes.

## What to do when new information is provided

1. Open this file and find the matching `HW2-...` item.
2. Copy the current active file into `archivo/` before rewriting it.
3. Replace only the relevant `TBD` with confirmed facts.
4. Add the source: datasheet, photo, CAD file, code commit, measurement or video.
5. Update the decision register and changelog.
6. Update every linked file listed under that item.
7. Keep Hardware V1 information labelled as history rather than deleting it.
8. Change the marker to `[HW2-VERIFY]` when selected but not tested.
9. Change it to `[HW2-DONE]` only after implementation and evidence match.

## Next full-review procedure

During the next detailed repository review:

1. open `NEXT_REVIEW.md` first;
2. search active files for `Raspberry Pi`, `UART`, `L298N`, `2x 18650`, `250 rpm` and `VL53L1CD`;
3. outside `archivo/`, each old term must either be explicitly labelled `[HW1-HISTORY]` or explained as a V1-to-V2 improvement;
4. search for `HW2-TBD`, `HW2-VERIFY`, `TBD` and `NEXT-REVIEW`;
5. compare the active BOM, PCB plan, source code, photos and test tables;
6. confirm that no old media or result is described as final Hardware V2 evidence;
7. confirm that no missing measurement has been replaced by an invented value;
8. keep the PR in draft until every required final item is genuinely complete.

## Current next priorities

1. `[HW2-TBD]` identify the exact LiPo;
2. `[HW2-TBD]` identify and test the faster motor;
3. `[HW2-TBD]` select the H-bridge from measured motor current;
4. `[HW2-TBD]` lock ESP32 PCB implementation and pin map;
5. `[HW2-TBD]` implement PixyCam SPI firmware;
6. `[HW2-VERIFY]` assemble and bench-test the PCB;
7. `[HW2-VERIFY]` complete repeated Open and Obstacle tests;
8. `[HW2-TBD]` replace Hardware V1 media with final Hardware V2 media.
