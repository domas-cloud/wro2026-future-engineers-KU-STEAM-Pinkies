# KU STEAM Pinkies - WRO 2026 Future Engineers

We are **KU STEAM Pinkies**, a WRO 2026 Future Engineers team building a compact autonomous self-driving car. This README tells the engineering story of our robot: we started from a previous larger rack/gearbox-style robot, identified what made it hard to control, and redesigned the new robot around repeatability, lower friction, clearer sensing, and easier tuning.

This repository contains our design reasoning, hardware documentation, software structure, testing evidence, CAD/model references, wiring information, photos, and video submission material.

## Table Of Contents

- [1. Starting Point: Previous Rack Robot](#1-starting-point-previous-rack-robot)
- [2. Main Goal For The New Robot](#2-main-goal-for-the-new-robot)
- [3. Final Robot At A Glance](#3-final-robot-at-a-glance)
- [4. Team Roles](#4-team-roles)
- [5. Mechanical Design Story](#5-mechanical-design-story)
- [6. Power, Electronics, And Sensors](#6-power-electronics-and-sensors)
- [7. Software Architecture And Obstacle Strategy](#7-software-architecture-and-obstacle-strategy)
- [8. Testing And Tuning Evidence](#8-testing-and-tuning-evidence)
- [9. Systems Thinking And Risk Mitigation](#9-systems-thinking-and-risk-mitigation)
- [10. Build, Compile, And Upload](#10-build-compile-and-upload)
- [11. Reproducibility Map](#11-reproducibility-map)
- [12. Photos And Video](#12-photos-and-video)
- [13. Repository Layout](#13-repository-layout)
- [14. Final Conclusion](#14-final-conclusion)

## 1. Starting Point: Previous Rack Robot

Our final robot did not appear immediately. Before this version, we used a larger and mechanically more complicated robot with a rack/gearbox-style mechanical direction. It looked more advanced, but it taught us that more complicated mechanics are not automatically better for autonomous driving.

<table>
  <tr>
    <td align="center"><strong>Previous Robot Overall View</strong></td>
    <td align="center"><strong>Previous Robot Drivetrain / Steering Area</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="docs/design/images/previous-robot-overall.jpg" alt="Previous robot overall view" width="520"></td>
    <td align="center"><img src="docs/design/images/previous-robot-drivetrain.jpg" alt="Previous robot drivetrain and steering area" width="520"></td>
  </tr>
  <tr>
    <td align="center">The older robot was larger and mechanically more complex.</td>
    <td align="center">The drivetrain and steering area helped us identify friction, resistance, and tuning problems.</td>
  </tr>
</table>

The previous robot created several practical problems:

- the steering system had more friction and mechanical resistance;
- the robot was harder to tune because mechanical behaviour changed the software result;
- the larger structure made turns less predictable;
- the servo had to fight the steering mechanism instead of simply positioning the wheels;
- one mechanical weakness could make the whole controller look worse than it really was.

The key lesson was clear: for WRO Future Engineers, **repeatable control is more valuable than mechanical complexity**.

That is why our new design direction became:

> build a smaller autonomous car where every subsystem helps consistency instead of adding unnecessary complexity.

## 2. Main Goal For The New Robot

The main goal of the final robot was not maximum speed alone. We wanted **controlled repeatability**.

The new robot had to:

- drive straight with less drift;
- turn corners cleanly;
- recover after corrections without wobbling;
- keep the steering load low;
- use sensors that match the field geometry;
- separate camera perception from real-time motor control;
- be documented clearly enough that another team could rebuild the system.

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

<table>
  <tr>
    <td align="center"><strong>Final Steering Layout</strong></td>
    <td align="center"><strong>Rear Drivetrain</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="docs/design/images/steering-v3-final.png" alt="Final steering geometry" width="520"></td>
    <td align="center"><img src="docs/design/images/lego-differential.png" alt="LEGO differential" width="520"></td>
  </tr>
  <tr>
    <td align="center">The final steering geometry became lower-friction and easier for the servo to control.</td>
    <td align="center">The selected differential gave smoother and more repeatable cornering.</td>
  </tr>
</table>

<table>
  <tr>
    <td align="center"><strong>Electronics Structure</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="schemes/images/schematic-overview.png" alt="Main schematic overview" width="800"></td>
  </tr>
</table>

The high-level architecture is simple:

1. the camera/perception layer chooses the driving reference or obstacle side;
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

Although responsibilities were divided, the robot was developed as one shared engineering system.

## 5. Mechanical Design Story

### 5.1 From Complex Rack Robot To Compact Steering

The previous rack/gearbox-style robot showed that a larger and more complex mechanism was harder to control. For the final robot, we moved toward a compact front-steering layout with less friction and more predictable steering response.

The final mechanical philosophy was:

- reduce steering resistance before increasing servo power;
- choose a motor that is controllable, not only fast;
- use a differential that gives smooth cornering;
- improve front-wheel grip so steering commands become real movement;
- keep the robot small enough for easier turning and parking.

### 5.2 Mechanical Comparison Photos

These additional photos show the drivetrain and steering evidence used during the design comparison.

<table>
  <tr>
    <td align="center"><strong>Earlier Metal Differential</strong></td>
    <td align="center"><strong>Final LEGO Differential</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="docs/design/images/metal-differential.jpg" alt="Earlier metal differential" width="520"></td>
    <td align="center"><img src="docs/design/images/lego-differential.png" alt="Final LEGO differential" width="520"></td>
  </tr>
  <tr>
    <td align="center">The metal differential looked stronger, but it was not the best practical choice for smooth turning.</td>
    <td align="center">The LEGO differential stayed because it gave smoother, more repeatable corner exits.</td>
  </tr>
</table>

<table>
  <tr>
    <td align="center"><strong>Final Steering Detail</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="docs/design/images/steering-v3-final.png" alt="Final steering detail" width="760"></td>
  </tr>
  <tr>
    <td align="center">The final steering version reduced mechanical load and improved real steering response.</td>
  </tr>
</table>

### 5.3 Motor Choice

We tested three `N20` motor options:

| Motor option | Practical strength | Practical weakness | Decision |
|---|---|---|---|
| `300 rpm` | easy to control slowly | too slow | rejected |
| `600 rpm` | best speed/torque balance | still required tuning | selected |
| `1000 rpm` | high theoretical speed | weaker usable torque and less stable under load | rejected |

The `600 rpm` motor became the final choice because it gave the best practical balance between speed and torque.

### 5.4 Differential Choice

We compared differential behaviour because cornering consistency depended strongly on drivetrain resistance. The earlier metal differential looked stronger, but the final `LEGO` differential gave smoother and more repeatable cornering.

The final differential helped with:

- less binding in turns;
- smoother corner exits;
- more repeatable behaviour between runs;
- easier controller tuning.

### 5.5 Steering Iterations

The steering system went through three main versions:

| Version | Problem or improvement | Result |
|---|---|---|
| `V1` | large lever arm and high steering load | servo worked too hard |
| `V2` | bad lever arm reduced | steering became easier and more predictable |
| `V3` | bearings and silicone front wheels added | best precision, lower friction, better grip |

Instead of buying a stronger servo, we improved the steering geometry. That fixed the real cause of the problem: excessive mechanical load.

### 5.6 Steering Range

The servo can rotate further, but we limited the useful steering range to about `60` degrees. Too much steering angle made the robot less stable, while a controlled steering range made behaviour more predictable.

## 6. Power, Electronics, And Sensors

The robot uses a split control system:

- `Raspberry Pi Zero` + camera for perception;
- `ESP32` for low-level real-time control.

This split lets the camera side focus on scene interpretation, while the `ESP32` handles timing-critical control tasks.

| Subsystem | Main parts | Purpose |
|---|---|---|
| perception | `Raspberry Pi Zero`, camera | lane and obstacle interpretation |
| low-level control | `ESP32-WROOM-32` | control loop, motor, servo, sensors |
| orientation | `BNO085` IMU | yaw feedback and heading reference |
| distance sensing | `3x VL53L4CD` | front trigger and side-distance feedback |
| drive | `N20 600 rpm`, `L298N` | vehicle movement |
| steering | `MG90S` servo | front-wheel steering |
| power | `2x 18650`, regulators | stable supply branches |

### Power Budget

| Subsystem | Design assumption |
|---|---:|
| logic compute | `0.8 A` continuous |
| sensors | `0.35 A` continuous |
| steering | `1.0 A` peak |
| drive | `1.5 A` peak |
| total | about `3.7 A` peak |

We separated power branches because motors and servos can create voltage sag and noise. Stable logic and sensor power made the robot easier to debug and more reliable.

### Sensor Placement

- camera: wider scene ahead;
- front `VL53L4CD`: turn timing and close boundary detection;
- left/right `VL53L4CD`: local wall or obstacle spacing;
- `BNO085`: rigidly mounted yaw feedback.

We tried richer ToF sensing with `VL53L5CX`, but `VL53L4CD` was more practical for the final system because it was easier to integrate and tune.

## 7. Software Architecture And Obstacle Strategy

The low-level controller in [`src/src/main.cpp`](src/src/main.cpp) follows this pattern:

1. wait for the start button;
2. store current yaw as target heading;
3. start motor output;
4. read front, left, and right ToF sensors;
5. read IMU yaw;
6. apply heading and wall-distance correction;
7. trigger a hard turn when the front distance becomes small;
8. update the target angle after the turn;
9. count sectors and stop after the required sequence.

### State Machine Summary

| State | Main inputs | Main output | Exit condition |
|---|---|---|---|
| `Idle` | start button | motor off, steering centered | button press |
| `StraightControl` | yaw, front ToF, side ToF | heading hold and wall-offset correction | obstacle packet or corner trigger |
| `ObstacleDecision` | camera result, confidence, packet age | choose legal side | left/right avoidance or fallback |
| `AvoidLeft` | camera command, IMU, ToF | shift reference left | obstacle cleared or fallback |
| `AvoidRight` | camera command, IMU, ToF | shift reference right | obstacle cleared or fallback |
| `HardTurn` | front ToF, side ToF, yaw | full-lock turn and target angle update | open space ahead |
| `Finish` | sector count | stop motor and center steering | wait for restart |

### Obstacle Rule Logic

The obstacle rule is:

- red pillar -> pass on the right side;
- green pillar -> pass on the left side.

The intended full-system data path is:

1. camera detects obstacle and side;
2. Pi sends a vision packet to the `ESP32`;
3. `ESP32` checks packet age and confidence;
4. fresh data shifts the driving reference;
5. stale or weak data falls back to neutral wall/heading control.

Important fallback thresholds:

- `age_ms > 250` -> ignore obstacle guidance;
- `confidence < 0.40` -> treat guidance as weak;
- `frontDistance <= 400 mm` -> hard-turn trigger.

## 8. Testing And Tuning Evidence

We tested mechanics and software together because they affected each other. A steering change changed controller tuning, and better wheel grip changed how much correction was needed.

### Testing Method

1. change one part or subsystem;
2. run the same scenario several times;
3. check if the same weakness repeats;
4. compare with the previous version;
5. keep the version that improves repeatability, not one lucky run.

### Main Results

| Test case | Before | After | Sample size | Why it mattered |
|---|---:|---:|---:|---|
| straight corridor drift after `2 m` | `9 cm` | `4 cm` | `10` runs | better lane stability |
| corner overshoot | `14 cm` | `6 cm` | `10` runs | lower wall-contact risk |
| successful `3`-lap runs | `6/10` | `9/10` | `10` runs | higher consistency |
| recovery after obstacle correction | `1.2 s` | `0.6 s` | `10` runs | faster return to target line |

The key improvement was consistency: successful `3`-lap runs improved from `60%` to `90%`.

## 9. Systems Thinking And Risk Mitigation

The final robot worked better because mechanics, electronics, sensing, and software were treated as one connected system.

| Risk / failure mode | Likely effect | Mitigation |
|---|---|---|
| steering resistance | servo load and inconsistent steering | redesigned steering geometry |
| front wheel slip | weak real steering effect | silicone front wheels |
| wrong motor speed | too slow or unstable under load | selected `600 rpm` after comparison |
| differential binding | rough corner exits | selected smoother final differential |
| servo/motor voltage sag | unstable sensors or controller | separated power branches |
| ToF address conflict | missing readings | staged startup and address assignment |
| stale camera data | wrong obstacle reaction | age/confidence fallback |
| flexible IMU mounting | bad yaw estimate | rigid mounting and checks |

## 10. Build, Compile, And Upload

The active embedded controller project is inside [`src/`](src/).

1. Open `src/` as a PlatformIO project.
2. Use [`src/platformio.ini`](src/platformio.ini) as the build configuration.
3. Build the firmware for the `ESP32`.
4. Connect the `ESP32` by USB.
5. Upload the firmware.
6. Place the robot on the field switched off.
7. Switch the robot on.
8. Press the physical start button when the round begins.

Main software files:

- [`src/src/main.cpp`](src/src/main.cpp)
- [`src/lib/Compass/Compass.h`](src/lib/Compass/Compass.h)
- [`src/lib/Lidar/Lidar.h`](src/lib/Lidar/Lidar.h)
- [`src/lib/Engine/Engine.h`](src/lib/Engine/Engine.h)
- [`src/platformio.ini`](src/platformio.ini)
- [`docs/code/vision_interface.md`](docs/code/vision_interface.md)

## 11. Reproducibility Map

| Criterion | Main evidence files |
|---|---|
| Mobility and mechanical design | [`docs/design/chassis_design_improved.md`](docs/design/chassis_design_improved.md), [`docs/design/drivetrain_and_steering.md`](docs/design/drivetrain_and_steering.md), [`models/README.md`](models/README.md) |
| Power and sensor architecture | [`docs/hardware/electronics_overview.md`](docs/hardware/electronics_overview.md), [`docs/hardware/pcb_wiring_diagrams.md`](docs/hardware/pcb_wiring_diagrams.md), [`schemes/wiring_overview.md`](schemes/wiring_overview.md) |
| Software and obstacle strategy | [`docs/code/software_state_machine_and_obstacle_flow.md`](docs/code/software_state_machine_and_obstacle_flow.md), [`docs/code/control_algorithms.md`](docs/code/control_algorithms.md), [`src/README.md`](src/README.md) |
| Systems thinking | [`docs/design/engineering_decisions.md`](docs/design/engineering_decisions.md), [`docs/design/risk_and_failures.md`](docs/design/risk_and_failures.md), [`docs/evaluation/what_worked.md`](docs/evaluation/what_worked.md) |
| GitHub quality | [`START_HERE.md`](START_HERE.md), [`docs/reproducibility/evidence_map.md`](docs/reproducibility/evidence_map.md), [`docs/reproducibility/submission_checklist.md`](docs/reproducibility/submission_checklist.md) |

Fast rebuild path:

1. [`README.md`](README.md)
2. [`START_HERE.md`](START_HERE.md)
3. [`docs/hardware/parts_list.md`](docs/hardware/parts_list.md)
4. [`docs/hardware/pcb_wiring_diagrams.md`](docs/hardware/pcb_wiring_diagrams.md)
5. [`schemes/Wro_customPCBs.pdf`](schemes/Wro_customPCBs.pdf)
6. [`docs/design/drivetrain_and_steering.md`](docs/design/drivetrain_and_steering.md)
7. [`models/README.md`](models/README.md)
8. [`src/README.md`](src/README.md)

## 12. Photos And Video

### Team Photo

<table>
  <tr>
    <td align="center"><img src="t-photos/team.jpg" alt="Official team photo" width="900"></td>
  </tr>
</table>

### Robot Photos

<table>
  <tr>
    <td align="center"><strong>Front</strong></td>
    <td align="center"><strong>Right</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="v-photos/front.jpg" alt="Robot front view" width="520"></td>
    <td align="center"><img src="v-photos/right.jpg" alt="Robot right view" width="520"></td>
  </tr>
  <tr>
    <td align="center"><strong>Back</strong></td>
    <td align="center"><strong>Left</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="v-photos/back.jpg" alt="Robot back view" width="520"></td>
    <td align="center"><img src="v-photos/left.jpg" alt="Robot left view" width="520"></td>
  </tr>
  <tr>
    <td align="center"><strong>Top</strong></td>
    <td align="center"><strong>Bottom</strong></td>
  </tr>
  <tr>
    <td align="center"><img src="v-photos/top.jpg" alt="Robot top view" width="520"></td>
    <td align="center"><img src="v-photos/bottom.jpg" alt="Robot bottom view" width="520"></td>
  </tr>
</table>

Video information is documented in [`video/video.md`](video/video.md).

Current published link:

- Open Challenge: [YouTube video](https://www.youtube.com/watch?v=PdYDFbR_HfI)

## 13. Repository Layout

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

## 14. Final Conclusion

The final robot is simpler than the previous rack/gearbox-style robot, but it is better suited to WRO autonomous driving. The previous robot taught us that complexity can create friction, tuning difficulty, and inconsistent behaviour. The final robot focuses on controlled repeatability:

- balanced `600 rpm` motor instead of extreme motor choices;
- smoother differential instead of rougher drivetrain behaviour;
- improved steering geometry instead of forcing the servo to overcome bad mechanics;
- silicone front wheels instead of accepting steering slip;
- split perception and control instead of one overloaded system;
- regulated power branches instead of unstable shared power;
- state-machine logic instead of unclear behaviour;
- measured testing evidence instead of only final claims.

The core result: straight drift improved from `9 cm` to `4 cm`, corner overshoot from `14 cm` to `6 cm`, successful `3`-lap runs from `60%` to `90%`, and recovery time from `1.2 s` to `0.6 s`.

That is the story of this project: we used the weaknesses of the previous robot to build a smaller, cleaner, more controllable, and better documented autonomous vehicle.
