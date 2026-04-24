# KU STEAM Pinkies - WRO 2026 Future Engineers

We are **KU STEAM Pinkies**, a WRO 2026 Future Engineers team building a compact autonomous self-driving car. This repository is our engineering story: how we moved from an earlier robot that was too complicated to control consistently, toward a smaller and more reliable robot where mechanics, electronics, sensing, software, testing, and documentation were developed as one connected system.

The goal of this README is not only to list parts. It explains why the robot became the way it is, what we changed after testing, and where another team or judge can find the evidence needed to understand or reproduce the vehicle.

## Table Of Contents

- [1. Starting Point: What The Previous Robot Taught Us](#1-starting-point-what-the-previous-robot-taught-us)
- [2. Main Design Goal For The New Robot](#2-main-design-goal-for-the-new-robot)
- [3. Final Robot At A Glance](#3-final-robot-at-a-glance)
- [4. Team Roles](#4-team-roles)
- [5. Visual Overview](#5-visual-overview)
- [6. Mobility And Mechanical Design Story](#6-mobility-and-mechanical-design-story)
- [7. Electronics, Power, And Sensors](#7-electronics-power-and-sensors)
- [8. Software Architecture And Obstacle Strategy](#8-software-architecture-and-obstacle-strategy)
- [9. Testing And Iteration Results](#9-testing-and-iteration-results)
- [10. Systems Thinking: How The Subsystems Affect Each Other](#10-systems-thinking-how-the-subsystems-affect-each-other)
- [11. Risk And Failure Mitigation](#11-risk-and-failure-mitigation)
- [12. Build, Compile, And Upload](#12-build-compile-and-upload)
- [13. Reproducibility And Evidence Map](#13-reproducibility-and-evidence-map)
- [14. Photos, Video, And Submission Media](#14-photos-video-and-submission-media)
- [15. Repository Layout](#15-repository-layout)
- [16. Final Engineering Conclusion](#16-final-engineering-conclusion)

## 1. Starting Point: What The Previous Robot Taught Us

Our development did not start from the final vehicle. Before this version, we had a previous robot that was larger and used a more complex steering idea. On paper, that older robot looked more advanced, but in practice it created several problems:

- the steering system had more friction and more mechanical resistance;
- the robot was harder to tune because small mechanical issues changed the software behaviour;
- the larger structure made the vehicle less predictable in corners;
- the steering servo had to fight the mechanism instead of only positioning the wheels;
- testing one change at a time was difficult because many weaknesses affected each other.

The biggest lesson from the previous robot was that a complicated mechanism is not automatically better. In WRO Future Engineers, the vehicle must repeat the same behaviour under changing field layouts. Because of that, we decided that the new robot should be simpler, lower-friction, easier to tune, and more reproducible.

### Previous Prototype Evidence

The photos below show the earlier mechanical direction and the drivetrain/steering ideas that influenced the final redesign.

<table>
  <tr>
    <td align="center"><strong>Earlier Differential Version</strong></td>
    <td align="center"><strong>Final Differential Version</strong></td>
    <td align="center"><strong>Final Steering Version</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="docs/design/images/metal-differential.jpg" alt="Earlier metal differential version" width="260"></td>
    <td align="center"><img src="docs/design/images/lego-differential.png" alt="Final LEGO differential version" width="260"></td>
    <td align="center"><img src="docs/design/images/steering-v3-final.png" alt="Final steering version" width="260"></td>
  </tr>
  <tr>
    <td align="center">The earlier drivetrain direction looked stronger, but it introduced more binding and less repeatable corner behaviour.</td>
    <td align="center">The final differential was smoother and made corner exits more predictable.</td>
    <td align="center">The final steering geometry reduced load and made servo movement more useful.</td>
  </tr>
</table>

This visual comparison is important because it shows why we did not simply keep the most complicated-looking mechanism. We kept the version that behaved better during driving.

So the new design direction became:

> build a smaller autonomous car where every subsystem helps consistency instead of adding unnecessary complexity.

## 2. Main Design Goal For The New Robot

For the new robot, our target was not maximum speed alone. The target was **controlled repeatability**.

That meant the robot had to:

- drive straight without drifting too much;
- turn corners cleanly;
- recover after corrections without wobbling;
- keep the steering load low;
- use sensors that are useful for the field geometry;
- separate perception and low-level control so timing stays predictable;
- be documented clearly enough that another team can understand how it works.

This design goal shaped every major decision: motor choice, differential choice, steering geometry, power layout, sensor placement, and software structure.

## 3. Final Robot At A Glance

Our final robot is a compact self-driving car with:

- rear-wheel drive;
- front-wheel steering;
- an `ESP32` for low-level real-time control;
- a `Raspberry Pi Zero` and camera for perception;
- a `BNO085` IMU for yaw feedback;
- three `VL53L4CD` distance sensors for front and side feedback;
- an `MG90S` steering servo;
- an `N20 6 V 600 rpm` drive motor;
- an `L298N` motor driver;
- a `2x 18650` Li-ion battery pack;
- a mechanical rear differential;
- custom steering and mounting parts.

The high-level idea is simple:

1. the camera/perception layer decides the driving reference or obstacle side;
2. the `ESP32` keeps the robot stable using IMU and ToF feedback;
3. the mechanical system makes those commands physically repeatable.

## 4. Team Roles

### Marius

- software development;
- mechanical design;
- controller refinement and integration work.

### Domas

- project coordination;
- testing and iteration tracking;
- documentation structure and submission preparation.

### Jonas

- electronics and hardware design;
- wiring, component layout, and implementation support.

We divided responsibilities, but the final robot was developed and tested as one shared engineering project. Most improvements required cooperation between mechanical, electrical, and software work.

## 5. Visual Overview

<table>
  <tr>
    <td align="center"><strong>Final Steering Layout</strong></td>
    <td align="center"><strong>Rear Drivetrain</strong></td>
    <td align="center"><strong>Electronics Structure</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="docs/design/images/steering-v3-final.png" alt="Final steering geometry" width="300"></td>
    <td align="center"><img src="docs/design/images/lego-differential.png" alt="LEGO differential" width="300"></td>
    <td align="center"><img src="schemes/images/schematic-overview.png" alt="Main schematic overview" width="300"></td>
  </tr>
  <tr>
    <td align="center">Version 3 steering geometry with lower resistance and better repeatability.</td>
    <td align="center">Rear drivetrain using the selected differential solution.</td>
    <td align="center">Main power and control structure.</td>
  </tr>
</table>

## 6. Mobility And Mechanical Design Story

### 6.1 Why We Changed The Mechanical Philosophy

The previous robot made us focus on a key question:

> Do we want a mechanism that looks complex, or a mechanism that gives repeatable control?

We chose repeatable control. That is why the final robot uses a simpler front-steering layout, rear-wheel drive, and a differential that turns smoothly instead of fighting the controller.

### 6.2 Drive Motor Selection

We tested three `N20` motor options:

| Motor option | Practical strength | Practical weakness | Decision |
|---|---|---|---|
| `300 rpm` | easy to control slowly | too slow for our target behaviour | rejected |
| `600 rpm` | best speed/torque balance | still required controller tuning | selected |
| `1000 rpm` | higher theoretical speed | weaker usable torque and less stable under load | rejected |

The `600 rpm` motor became the final choice because it gave enough speed while still having usable torque. For our robot size, the extreme options were worse: `300 rpm` was too slow, while `1000 rpm` made control less predictable.

### 6.3 Differential Choice

We also compared differential behaviour. The earlier metal differential looked stronger, but the final `LEGO` differential gave smoother and more repeatable cornering.

The final choice was based on practical behaviour:

- less binding in turns;
- smoother corner exits;
- more repeatable behaviour between runs;
- easier software tuning.

This was a good example of our engineering approach: the part that works better on the field is more important than the part that looks stronger by itself.

### 6.4 Steering Iterations

The steering system went through three main versions.

| Version | Problem or improvement | Result |
|---|---|---|
| `V1` | large lever arm and high steering load | servo worked too hard and steering was less repeatable |
| `V2` | bad lever arm reduced | steering became easier to move and more predictable |
| `V3` | bearings and silicone front wheels added | best precision, lower friction, better grip |

The largest improvement came from `V1` to `V2`, because reducing the bad lever arm lowered the force required from the servo. Instead of solving the problem with a heavier servo, we improved the mechanism itself.

### 6.5 Steering Range Trade-Off

The servo can physically rotate further, but we intentionally limited the useful steering range to about `60` degrees.

The trade-off was:

- larger steering angle can make tighter turns possible;
- too much steering angle can reduce stability and increase aggressive corrections;
- a controlled range made the robot more predictable.

So the final steering range was chosen for stability, not for maximum mechanical movement.

### 6.6 Front And Rear Wheel Roles

We treated the front and rear wheels differently because they do different jobs.

Front wheels must transfer steering commands into real movement. After switching to silicone front wheels:

- front slip decreased;
- the steering command had a stronger real effect;
- turn behaviour became more repeatable.

Rear wheels must provide stable drive through the differential. The rear setup therefore stayed focused on dependable traction and smooth cornering.

## 7. Electronics, Power, And Sensors

### 7.1 Split Control Architecture

The robot uses a split electronics system:

- `Raspberry Pi Zero` + camera: perception and obstacle/lane interpretation;
- `ESP32`: real-time control, sensors, servo output, and motor output.

We chose this architecture because perception and low-level control have different timing needs. The camera side can interpret the scene, while the `ESP32` keeps fast and predictable control over the vehicle.

### 7.2 Main Electronic Parts

| Subsystem | Main parts | Purpose |
|---|---|---|
| perception | `Raspberry Pi Zero`, camera | wider scene, lane and obstacle interpretation |
| low-level control | `ESP32-WROOM-32` | control loop, motor, servo, sensors |
| orientation | `BNO085` IMU | yaw feedback and heading reference |
| distance sensing | `3x VL53L4CD` | front trigger and side-distance feedback |
| drive | `N20 600 rpm`, `L298N` | vehicle movement |
| steering | `MG90S` servo | front-wheel steering |
| power | `2x 18650`, regulators, wiring branches | stable supply for logic, sensors, motor, and servo |

### 7.3 Power Budget

We used a conservative design budget so the system would have headroom instead of barely working on paper.

| Subsystem | Main parts | Design assumption |
|---|---|---|
| logic compute | `Raspberry Pi Zero`, `ESP32` | `0.8 A` continuous |
| sensors | `BNO085`, `3x VL53L4CD` | `0.35 A` continuous |
| steering | `MG90S` servo | `1.0 A` peak |
| drive | `N20` + `L298N` | `1.5 A` peak |
| total | all branches together | about `3.7 A` peak |

The main reason for separating power branches was reliability. Motors and servos can create voltage drops and noise, so the logic and sensors should not depend on the same unstable path.

### 7.4 Sensor Placement Reasoning

The sensor placement follows the job of each sensor:

- the camera looks ahead and supports higher-level decisions;
- the front `VL53L4CD` helps trigger turns and detect close boundaries;
- the left and right `VL53L4CD` sensors help keep local wall or obstacle spacing;
- the `BNO085` is mounted rigidly so yaw follows the chassis instead of a flexible bracket.

We also tried richer ToF sensing with `VL53L5CX`, but for the final robot `VL53L4CD` modules were easier to integrate, easier to tune, and more practical for repeatable close-range sensing.

## 8. Software Architecture And Obstacle Strategy

### 8.1 Why The Software Is Split

The software follows the same logic as the electronics:

- the `Raspberry Pi Zero` can decide what the robot should aim for;
- the `ESP32` executes the real-time driving behaviour.

The low-level controller does not need to understand the whole world. It needs reliable references and local sensor feedback.

### 8.2 Main Runtime Behaviour

The active low-level controller in `src/src/main.cpp` shows this sequence:

1. wait for the physical start button;
2. store current yaw as the heading reference;
3. start the drive motor;
4. read front, left, and right ToF sensors;
5. read yaw from the IMU;
6. apply heading and wall-distance correction;
7. trigger a hard turn when the front distance becomes small;
8. update the target angle after a turn;
9. count sectors and stop after the required sequence.

This structure supports predictable autonomous movement without manual input during the run.

### 8.3 State Machine Summary

| State | Main inputs | Main output | Exit condition |
|---|---|---|---|
| `Idle` | start button | motor off, steering centered | button press |
| `StraightControl` | yaw, front ToF, side ToF | heading hold and wall-offset correction | obstacle packet or corner trigger |
| `ObstacleDecision` | camera result, confidence, packet age | choose legal passing side | enter left/right avoidance or fallback |
| `AvoidLeft` | camera command, IMU, ToF | shift reference left while checking clearance | obstacle cleared or fallback |
| `AvoidRight` | camera command, IMU, ToF | shift reference right while checking clearance | obstacle cleared or fallback |
| `HardTurn` | front ToF, side ToF, yaw | full-lock turn and target angle update | open space detected ahead |
| `Finish` | sector count and steering error | stop motor and center steering | wait for restart |

### 8.4 Obstacle Rule Logic

The obstacle strategy follows the WRO pillar rule:

- red pillar -> pass on the right side;
- green pillar -> pass on the left side.

The intended full-system data path is:

1. the camera detects the obstacle and preferred side;
2. the Pi sends a vision packet to the `ESP32`;
3. the `ESP32` checks packet age and confidence;
4. if the data is fresh enough, the controller shifts the driving reference;
5. if the data is stale or weak, the robot falls back to neutral wall/heading control.

Important fallback thresholds in the documented architecture:

- `age_ms > 250` -> ignore obstacle guidance;
- `confidence < 0.40` -> treat obstacle guidance as weak;
- front turn trigger around `400 mm` -> switch to hard-turn behaviour.

This fallback design matters because the robot should fail safely instead of following old or uncertain perception data.

## 9. Testing And Iteration Results

We tested mechanics and software together because they affected each other. A steering change changed controller tuning. Better wheel grip changed how much correction was needed. A smoother differential made corner exits easier to control.

### 9.1 Main Comparison Areas

We compared:

- `300 rpm`, `600 rpm`, and `1000 rpm` `N20` motors;
- steering `V1`, `V2`, and `V3`;
- earlier front wheels versus silicone front wheels;
- earlier differential solution versus the final `LEGO` differential;
- sensor mounting and wiring stability;
- software tuning before and after mechanical improvements.

### 9.2 Test Method

For major changes, we used this pattern:

1. change one part or subsystem;
2. run the same scenario several times;
3. watch whether the same weakness repeats;
4. compare the result with the previous version;
5. keep the version that improves repeatability, not just one lucky run.

For steering comparisons, we used about `10` practical runs while deciding between the main versions.

### 9.3 Key Software Tuning Results

| Test case | Before change | After change | Sample size | Why it mattered |
|---|---:|---:|---:|---|
| straight corridor drift after `2 m` | `9 cm` | `4 cm` | `10` runs | better lane stability |
| corner overshoot | `14 cm` | `6 cm` | `10` runs | lower wall-contact risk |
| successful `3`-lap runs | `6/10` | `9/10` | `10` runs | higher consistency |
| recovery after obstacle correction | `1.2 s` | `0.6 s` | `10` runs | faster return to target line |

The most important result was not one perfect run. The important result was consistency: successful `3`-lap completion improved from `60%` to `90%` across the measured runs.

## 10. Systems Thinking: How The Subsystems Affect Each Other

The robot improved because we stopped treating subsystems separately.

Examples:

- when steering friction was high, the controller looked unstable even if the software logic was reasonable;
- when front wheels slipped, steering commands did not become real movement;
- when the differential bound during turns, the robot exited corners inconsistently;
- when power was not separated clearly, sensor and control reliability could suffer;
- when sensor placement changed, the control thresholds had to be rechecked.

This is why our final design is not only a list of components. It is a set of choices that support each other:

- lower-friction steering helps the servo;
- better front grip helps the controller;
- smoother differential behaviour helps cornering;
- split electronics keeps perception and control responsibilities clear;
- regulated power branches reduce electrical instability;
- state-machine logic makes robot behaviour easier to understand and debug.

## 11. Risk And Failure Mitigation

| Risk or failure mode | Likely effect | Mitigation |
|---|---|---|
| steering mechanism has too much resistance | servo load increases and steering becomes inconsistent | redesigned steering geometry from `V1` to `V2/V3` |
| front wheels slip | steering command does not translate into movement | silicone front wheels |
| motor too slow or too weak under load | poor lap time or unstable acceleration | selected `600 rpm` motor after comparing `300/600/1000 rpm` |
| differential binds | rough corner exits and unpredictable turns | selected smoother final differential solution |
| servo or motor causes voltage sag | unstable electronics or sensor readings | separated power branches and regulator planning |
| ToF sensors conflict on bus | missing or incorrect distance readings | staged startup and address assignment |
| camera data is stale or low-confidence | wrong obstacle action | packet age/confidence fallback |
| IMU mounted flexibly | yaw estimate does not match chassis motion | rigid IMU mounting and repeated checks |

## 12. Build, Compile, And Upload

The active embedded controller project is inside [`src/`](src/).

### Environment

- project folder: `src/`
- build configuration: `src/platformio.ini`
- target controller: `ESP32`

### Basic Steps

1. Open the `src/` folder as a PlatformIO project.
2. Install the libraries defined in `platformio.ini`.
3. Build the firmware.
4. Connect the `ESP32` board by USB.
5. Upload the firmware.
6. Place the robot on the field switched off.
7. Switch the robot on.
8. Press the physical start button when the round begins.

### Main Software Files

- [`src/src/main.cpp`](src/src/main.cpp) - main runtime loop
- [`src/lib/Compass/Compass.h`](src/lib/Compass/Compass.h) - yaw heading support
- [`src/lib/Lidar/Lidar.h`](src/lib/Lidar/Lidar.h) - distance sensor handling
- [`src/lib/Engine/Engine.h`](src/lib/Engine/Engine.h) - motor control wrapper
- [`src/lib/Lights/`](src/lib/Lights/) - status lights
- [`src/platformio.ini`](src/platformio.ini) - PlatformIO configuration
- [`docs/code/vision_interface.md`](docs/code/vision_interface.md) - Pi-to-ESP32 interface definition

## 13. Reproducibility And Evidence Map

The repository is organized so that judges can quickly verify the five main documentation criteria.

| Criterion | Main evidence files |
|---|---|
| Mobility and mechanical design | [`docs/design/drivetrain_and_steering.md`](docs/design/drivetrain_and_steering.md), [`docs/design/chassis_design_improved.md`](docs/design/chassis_design_improved.md), [`models/README.md`](models/README.md) |
| Power and sensor architecture | [`docs/hardware/electronics_overview.md`](docs/hardware/electronics_overview.md), [`docs/hardware/pcb_wiring_diagrams.md`](docs/hardware/pcb_wiring_diagrams.md), [`schemes/wiring_overview.md`](schemes/wiring_overview.md) |
| Software architecture and obstacle strategy | [`docs/code/software_state_machine_and_obstacle_flow.md`](docs/code/software_state_machine_and_obstacle_flow.md), [`docs/code/control_algorithms.md`](docs/code/control_algorithms.md), [`src/README.md`](src/README.md) |
| Systems thinking and engineering decisions | [`docs/design/engineering_decisions.md`](docs/design/engineering_decisions.md), [`docs/design/risk_and_failures.md`](docs/design/risk_and_failures.md), [`docs/evaluation/what_worked.md`](docs/evaluation/what_worked.md) |
| Reproducibility and GitHub quality | [`START_HERE.md`](START_HERE.md), [`docs/reproducibility/evidence_map.md`](docs/reproducibility/evidence_map.md), [`docs/reproducibility/submission_checklist.md`](docs/reproducibility/submission_checklist.md) |

### Fast Rebuild Path

For another team trying to understand or reproduce the robot, we recommend this order:

1. [`README.md`](README.md)
2. [`START_HERE.md`](START_HERE.md)
3. [`docs/hardware/parts_list.md`](docs/hardware/parts_list.md)
4. [`docs/hardware/pcb_wiring_diagrams.md`](docs/hardware/pcb_wiring_diagrams.md)
5. [`schemes/Wro_customPCBs.pdf`](schemes/Wro_customPCBs.pdf)
6. [`docs/design/drivetrain_and_steering.md`](docs/design/drivetrain_and_steering.md)
7. [`models/README.md`](models/README.md)
8. [`src/README.md`](src/README.md)

## 14. Photos, Video, And Submission Media

### Team Photo

<table>
  <tr>
    <td align="center"><strong>Official Team Photo</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="t-photos/team.jpg" alt="Official team photo" width="720"></td>
  </tr>
</table>

### Robot Photos

<table>
  <tr>
    <td align="center"><strong>Front View</strong></td>
    <td align="center"><strong>Right View</strong></td>
    <td align="center"><strong>Back View</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="v-photos/front.jpg" alt="Robot front view" width="240"></td>
    <td align="center"><img src="v-photos/right.jpg" alt="Robot right view" width="240"></td>
    <td align="center"><img src="v-photos/back.jpg" alt="Robot back view" width="240"></td>
  </tr>
  <tr>
    <td align="center"><strong>Left View</strong></td>
    <td align="center"><strong>Top View</strong></td>
    <td align="center"><strong>Bottom View</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="v-photos/left.jpg" alt="Robot left view" width="240"></td>
    <td align="center"><img src="v-photos/top.jpg" alt="Robot top view" width="240"></td>
    <td align="center"><img src="v-photos/bottom.jpg" alt="Robot bottom view" width="240"></td>
  </tr>
</table>

### Video

The driving video information is documented in [`video/video.md`](video/video.md).

Current published link:

- Open Challenge: [YouTube video](https://www.youtube.com/watch?v=PdYDFbR_HfI)

## 15. Repository Layout

- `docs/design/` - mechanical design, trade-offs, risk, and system-level decisions
- `docs/hardware/` - electronics, sensors, wiring, power, and parts
- `docs/code/` - software logic, state flow, control algorithms, and obstacle strategy
- `docs/testing/` - practical testing and tuning evidence
- `docs/evaluation/` - what worked, what did not, and comparison to goals
- `docs/reproducibility/` - evidence map, checklist, and rebuild support
- `schemes/` - schematic material and wiring overview
- `models/` - CAD and custom part evidence
- `src/` - embedded controller and software material
- `t-photos/` - team photo
- `v-photos/` - robot photos
- `video/` - video submission information
- `output/doc/` - continuous DOCX report version

## 16. Final Engineering Conclusion

The final robot is simpler than our earlier direction, but it is better engineered for the WRO task. The previous robot showed us that complexity can create friction, tuning difficulty, and inconsistent behaviour. The final robot focuses on controlled repeatability:

- a balanced `600 rpm` motor instead of the slowest or fastest option;
- a smoother differential instead of a rougher drivetrain;
- improved steering geometry instead of forcing the servo to overcome bad mechanics;
- silicone front wheels instead of accepting steering slip;
- split perception and control instead of one overloaded system;
- regulated power branches instead of unstable shared supply paths;
- state-machine logic instead of unclear behaviour;
- documented test results instead of only final claims.

The most important measured improvement was consistency: after mechanical changes and controller tuning, straight drift improved from `9 cm` to `4 cm`, corner overshoot from `14 cm` to `6 cm`, successful `3`-lap runs from `60%` to `90%`, and recovery time from `1.2 s` to `0.6 s`.

That is the core story of this project: we used the problems from the previous robot to build a smaller, cleaner, more controllable, and better documented autonomous vehicle.
