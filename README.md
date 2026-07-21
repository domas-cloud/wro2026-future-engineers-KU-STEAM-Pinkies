# KU STEAM Pinkies — WRO 2026 Future Engineers

We are Marius, Domas and Jonas from KU STEAM. Our 2026 car is a small autonomous vehicle built for the WRO Future Engineers Open and Obstacle Challenges.

This repository is our engineering record. It contains the code and build files, but it also shows how the car changed after testing. We have tried to keep the main story on this page. Detailed drawings, measurements and setup instructions are linked only where they are useful.

## The car at a glance

| Part | Current solution |
| --- | --- |
| Drive | one N20 6 V, 250 rpm motor and a rear mechanical differential |
| Steering | MG90S servo with custom front steering parts |
| Main controller | ESP32 |
| Perception | Raspberry Pi Zero and camera |
| Orientation | BNO085 IMU |
| Distance sensing | one front and two side ToF sensors |
| Motor driver | L298N |
| Battery | two 18650 Li-ion cells with regulated power branches |
| Chassis size | approximately 21 × 10 × 8 cm |

The ESP32 handles the time-critical work: motor output, steering, heading control and distance measurements. The Pi Zero handles camera processing and sends short guidance messages to the ESP32. We chose this split because camera processing and motor control have very different timing requirements.

## Where this design came from

Our first car was larger and mechanically more complicated. It was useful, but not because it became the final robot. It showed us what was making the car inconsistent.

The old steering placed too much load on the servo. The drivetrain had more resistance, the car needed more room to turn, and small mechanical problems looked like software problems. We could keep changing controller gains, but tuning could not remove friction or wheel slip.

For the new car we set a simpler goal: make every command produce the same physical response as often as possible.

That led to a smaller chassis, a simpler steering mechanism, a different differential and better front-wheel grip. The final robot is less impressive as a pile of parts, but it is much easier to understand and tune.

![Previous robot](docs/design/images/previous-robot-overall.jpg)

## Mechanical development

### Choosing the drive motor

We tested 50, 250 and 1000 rpm N20 motors.

The 50 rpm motor was useful for slow experiments but was too slow for full runs. The 1000 rpm motor looked attractive on paper, but the car became harder to control and had less useful torque under load. The 250 rpm version gave us the best practical compromise, so it stayed on the robot.

This is still a practical comparison rather than a complete motor model. Before the final submission we want to add measured vehicle speed, wheel diameter and the drivetrain ratio so that the result can be checked from numbers as well as observations.

### Steering versions

The steering went through three main versions.

- V1 had an unnecessarily large lever arm. The servo had to fight the mechanism.
- V2 removed most of that load and produced the largest improvement.
- V3 added bearings and custom silicone front wheels.

The silicone wheels matter because a steering angle is only useful if the front tyres transfer it to the floor. With the earlier wheels, part of the servo movement was lost as slip. The new wheels made turns more repeatable and reduced the amount of correction needed from the controller.

We also limited the useful steering range to about 60 degrees. More movement was possible, but the largest angle was not the most stable one.

### Differential

We compared an earlier metal differential with the LEGO differential used now. The LEGO part was simpler, but it turned more freely and gave smoother corner exits. We kept the part that behaved better rather than the one that looked stronger.

The mechanical details and comparison photos are in [drivetrain and steering](docs/design/drivetrain_and_steering.md). Printable parts are indexed in [models/README.md](models/README.md).

## Electronics and sensors

The two-cell battery feeds separate regulated branches for logic, sensors, steering and drive. We separated them after seeing how servo and motor loads can disturb the controller and sensor readings.

Our design budget is approximately:

| Load | Working assumption |
| --- | ---: |
| Pi Zero and ESP32 | 720 mA continuous |
| IMU and distance sensors | 132.3 mA continuous |
| Steering servo | 800 mA peak |
| Drive motor and driver | 670 mA peak |
| Combined design budget | about 2.32 A peak |

The camera looks further ahead and identifies coloured pillars. The BNO085 supplies yaw for straight driving and repeatable turns. The three ToF sensors give short-range front and side geometry. We tested a VL53L5CX matrix sensor as well, but its extra data did not improve the car enough to justify the more complicated pipeline.

The wiring, power branches and calibration checks are described in [electronics overview](docs/hardware/electronics_overview.md) and [wiring diagrams](docs/hardware/pcb_wiring_diagrams.md). The exact final component names should be checked against the [parts list](docs/hardware/parts_list.md).

## Software

The car starts in a waiting state. After the physical start button is pressed, the ESP32 stores the current yaw as its heading reference and starts the motor.

On a straight section, steering combines:

- heading error from the IMU;
- distance error from the selected side sensor;
- a damping term to reduce oscillation.

When the front sensor detects the next wall, the controller enters a hard turn. After the car sees open space again, the target heading is changed by 90 degrees.

For the Obstacle Challenge, the Pi Zero uses HSV colour masks to detect red and green pillars and sends a compact serial packet. Green means that the car must pass on the left; red means that it must pass on the right. Old or low-confidence packets are ignored.

The Open Challenge controller is the most tested part of the current snapshot. The Pi-to-ESP32 interface and colour detector are present, but the final obstacle-line behaviour and parking sequence still need full field validation before the October competition. We prefer to show that honestly instead of describing unfinished work as final.

Start with [software state and obstacle flow](docs/code/software_state_machine_and_obstacle_flow.md). The actual programs are in [src/src/main.cpp](src/src/main.cpp) and [src/pi-zero/main.py](src/pi-zero/main.py).

## Testing

We normally change one meaningful thing, repeat the same scenario and compare it with the last stable version. A single good run is not enough.

Current recorded results include:

| Test | Earlier version | Current recorded result |
| --- | ---: | ---: |
| Average drift over 3 m | 10.6 cm | 4.0 cm |
| Space used for a 90° turn | about 46 cm | about 39 cm |
| Open straight test | — | 5/5 clean runs |
| Obstacle slalom | — | 4/5 clean runs |
| Full practice route | — | 4/5 clean runs |

These are development measurements, not the final October validation set. The final tables deliberately remain separate so that estimated results are not presented as measured ones.

See [performance measurements](docs/testing/performance_measurements.md), [testing method](docs/testing/tests.md) and [final validation results](docs/testing/final_validation_results.md).

## Build and run

### ESP32

1. Open the [src](src/) directory as a PlatformIO project.
2. Build using [src/platformio.ini](src/platformio.ini).
3. Upload the firmware to the ESP32.
4. Switch on the car and wait for the ready state.
5. Press the physical start button when the run begins.

### Raspberry Pi Zero

1. Open [src/pi-zero/README.md](src/pi-zero/README.md).
2. Install the listed Python dependencies.
3. Connect the 3.3 V UART link to the ESP32.
4. Run the perception process with the configured serial port.
5. Test the packet link in mock mode before using the camera.

The complete wiring, upload and calibration sequence is in the [rebuild guide](docs/reproducibility/full_rebuild_guide.md).

## Team

- **Marius** — software, controller tuning and mechanical design
- **Domas** — project coordination, testing records and documentation
- **Jonas** — electronics, wiring and hardware implementation

The roles help us organise the work, but decisions that affect the whole car are tested together.

## Photos and video

The repository contains the required [team photo](t-photos/team.jpg) and robot views from the [front](v-photos/front.jpg), [back](v-photos/back.jpg), [left](v-photos/left.jpg), [right](v-photos/right.jpg), [top](v-photos/top.jpg) and [bottom](v-photos/bottom.jpg).

The current [video page](video/video.md) links the Open Challenge demonstration. A separate Obstacle Challenge video will be added after the obstacle and parking behaviour has completed final validation.

## Five useful places to continue

A judge or another team should not need to open every Markdown file. These five links cover the main evidence:

1. [Mechanical design](docs/design/drivetrain_and_steering.md)
2. [Electronics and sensors](docs/hardware/electronics_overview.md)
3. [Software flow](docs/code/software_state_machine_and_obstacle_flow.md)
4. [Testing results](docs/testing/performance_measurements.md)
5. [Rebuild guide](docs/reproducibility/full_rebuild_guide.md)

The full technical index is available in [docs/README.md](docs/README.md). Supporting documents remain in the repository as evidence and working notes; they are not all required reading.
