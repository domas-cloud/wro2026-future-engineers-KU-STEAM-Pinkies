# KU STEAM Pinkies — WRO 2026 Future Engineers

We are building an autonomous car for the WRO 2026 Future Engineers category. This repository is our engineering record: mechanical parts, electronics, test notes, old versions and, when it is ready, the final software.

The robot is currently going through its second major hardware version. The first version worked and gave us useful test data, but during the summer we decided to rebuild the electronics around a custom PCB, remove the Raspberry Pi Zero, use a PixyCam for colour detection, move to a LiPo battery and try a faster drive motor.

The old robot has not been deleted. We keep it under [`archivo/hardware-v1-esp32-250rpm/`](archivo/hardware-v1-esp32-250rpm/) because it shows how the design developed and why several parts were changed.

## Team

- **Marius** — software and mechanical design
- **Domas** — project coordination, testing and documentation
- **Jonas** — electronics and PCB work

## Where the project is now

The mechanical layout is mostly based on the working first robot. The biggest changes are in electronics, power and vision.

| Part | Previous robot | Hardware V2 |
|---|---|---|
| main controller | ESP32 development board | ESP32-WROOM-32 in the custom-PCB design |
| camera processing | Raspberry Pi Zero + camera | first-generation PixyCam / CMUcam5 |
| camera link | UART from Pi to ESP32 | wired SPI from PixyCam to ESP32 |
| front distance sensor | VL53L1X | VL53L1X |
| side distance sensors | two VL53L4CD | two VL53L4CD |
| IMU | BNO085 | BNO085 |
| steering | MG90S | MG90S |
| battery | 2x 18650 Li-ion | LiPo; exact pack still being selected |
| drive motor | N20 6 V 250 rpm | faster motor; exact model still being tested/selected |
| motor driver | L298N module | H-bridge on the custom PCB; final IC follows the motor choice |
| wiring | modules + perfboard | custom PCB |

The new software is also being rebuilt. We cleared the active software folder on 12 August because the old program still assumed the Pi/UART architecture. The old code and software notes are in [`brainstorm/software-redesign/`](brainstorm/software-redesign/) so we can reuse useful ideas without pretending that the old program already matches the new robot.

## Mechanical development

Our first versions were larger and harder to tune. The current chassis is compact, with rear-wheel drive and front steering. The working V1 chassis was about **21 cm long, 10 cm wide and 8 cm high**. Those measurements will be taken again after the V2 electronics and battery are mounted.

### Steering

Steering went through several versions. The early mechanism put too much load on the servo because of the lever geometry. We shortened the lever arm and corrected the linkage instead of solving the problem by fitting a stronger servo. This made the centre position more repeatable and reduced unnecessary servo load.

We kept the `MG90S` because the steering mechanism worked reliably after the geometry was corrected. Final centre repeatability and steering limits still need to be checked again at the higher V2 speed.

### Wheels and differential

The front wheels use custom silicone tyres. They gave noticeably better grip than the earlier wheels, so more of the servo movement became real steering instead of tyre slip.

At the rear we use a LEGO differential. An earlier metal differential created more binding in corners. The LEGO unit gave smoother turns on the first robot and is being kept as the baseline for V2. We will still check it again with the faster motor.

### Motor testing from the first robot

For Hardware V1 we compared `50 rpm`, `250 rpm` and `1000 rpm` N20 motors. The 50 rpm motor was too slow for the way we wanted the car to drive. The 1000 rpm option was fast but gave too little useful control and torque for that build. The 250 rpm motor was the best compromise and became the V1 motor.

That result does not automatically decide the V2 motor. The new PCB and power system allow us to revisit the choice. For V2 we want more speed, but we will choose the motor from loaded speed, current, temperature and repeated track runs rather than from the rpm printed on the listing.

More detail: [`docs/design/drivetrain_and_steering.md`](docs/design/drivetrain_and_steering.md) and [`docs/design/hardware_v2_motor_upgrade_plan.md`](docs/design/hardware_v2_motor_upgrade_plan.md).

## Electronics

The main controller remains an `ESP32-WROOM-32`. We chose to keep the ESP32 because it is already familiar to us and is capable of handling the IMU, ToF sensors, PixyCam data, steering and motor control without a second computer.

The Raspberry Pi Zero was useful on the first robot, but it added another boot process, another power branch and a UART link between two computers. In V2 the PixyCam does the colour-signature processing itself and sends object information directly to the ESP32 over SPI.

The sensor set is:

- front `VL53L1X` for forward distance and turn timing;
- left and right `VL53L4CD` sensors for local side distance;
- `BNO085` for fused heading/yaw;
- first-generation PixyCam for red/green traffic pillars.

The custom PCB is still being finished. Before calling it final we need the exact battery, motor, H-bridge, regulators, connector pinout, ESP32 GPIO map, schematic/PCB production files and bench measurements. The current electronics notes are in [`docs/hardware/`](docs/hardware/) and the schematic material is in [`schemes/`](schemes/).

## Vision

The PixyCam will be trained for the red and green WRO traffic pillars. It performs colour processing on the camera, so the ESP32 does not need to receive full camera frames. We expect to use block data such as signature, position and size, but the final filtering rules will come from tests on the actual field.

We still need to record the final Pixy signature numbers, camera mounting angle, useful detection distance and behaviour under bright, dark and side lighting. SPI communication also has to stay reliable with the motor and servo running.

## Software

There is intentionally no final V2 program in `src/` yet. We do not want to publish the old Pi/UART program as if it were the code for the custom-PCB robot.

The next program will be built from the hardware upwards: first sensor and actuator bring-up, then driving and cornering, then PixyCam obstacle handling, and finally tuning from repeated runs. Old source and software ideas are preserved in [`brainstorm/software-redesign/`](brainstorm/software-redesign/).

See [`src/README.md`](src/README.md) for the current source status.

## What we learned from Hardware V1

The most useful measurements we kept from the first robot were:

| Test | Earlier version | Hardware V1 result |
|---|---:|---:|
| average drift over 3 m | 10.6 cm | 4.0 cm |
| space used for a 90° turn | about 46 cm | about 39 cm |
| open straight test | — | 5/5 clean runs |
| obstacle slalom | — | 4/5 clean runs |
| full practice route | — | 4/5 completed runs |

These are **V1 results**, not results for the current rebuild. They are useful because they give us a baseline for deciding whether V2 is actually better.

The full V1 measurement notes are in [`docs/testing/performance_measurements.md`](docs/testing/performance_measurements.md).

## What still has to be finished

The main unfinished jobs are practical rather than documentation work: choose the exact LiPo and motor, lock the motor driver and regulators, finish the PCB and pin map, test PixyCam SPI, write the new software, measure power and temperatures, and then run repeated Open and Obstacle Challenge tests.

We keep the current working list in [`NEXT_REVIEW.md`](NEXT_REVIEW.md). It is just our project checklist; completed results are moved into the relevant technical pages.

## Files in this repository

- [`docs/design/`](docs/design/) — chassis, steering, drivetrain and design decisions
- [`docs/hardware/`](docs/hardware/) — electronics, sensors, PCB and parts
- [`docs/testing/`](docs/testing/) — V1 measurements and V2 test sheets
- [`docs/reproducibility/`](docs/reproducibility/) — rebuild and submission notes
- [`models/`](models/) — CAD/STL files
- [`schemes/`](schemes/) — wiring and PCB material
- [`src/`](src/) — active V2 source when it is ready
- [`brainstorm/`](brainstorm/) — unfinished software work and previous code
- [`engineering-journal/`](engineering-journal/) — dated engineering decisions
- [`archivo/`](archivo/) — older documentation kept as development history
- [`v-photos/`](v-photos/) — vehicle photographs
- [`t-photos/`](t-photos/) — team photograph
- [`video/`](video/) — challenge video links/status

## Current media

The six vehicle photos and the current Open Challenge video show the working Hardware V1 robot. We are keeping them because they are real development evidence, but they will be replaced by V2 photos and new Open/Obstacle videos once the rebuilt robot is finished.

## Rebuilding the final robot

The final repository needs to be enough for another technically competent person to reproduce the car. For V2 that means publishing the exact BOM, mechanical files, PCB source and manufacturing files, connector/pin map, source code, build/upload instructions, calibration/start procedure and measured validation results.

The structure for that is already in [`docs/reproducibility/`](docs/reproducibility/), but several details cannot be filled in honestly until the final hardware exists.
