# Electronics Overview

## System Architecture

The robot uses a split electronics architecture with two main computing boards:

- **Raspberry Pi Zero** for camera input and vision processing;
- **ESP32** for control, decision-making, and fast response tasks.

We selected this split because the two boards are better suited to different jobs.  
The Raspberry Pi Zero handles camera-side perception, while the ESP32 is responsible for the main robot behavior.

## Why We Split The System

We did not want one board to do everything.

The Raspberry Pi Zero is useful for camera-related work, while the **ESP32 performs control tasks faster and is easier to use for actuator control and time-sensitive robot behavior**.  
For this reason, the ESP32 was chosen as the main control unit.

In practice, this means:

- the **Pi Zero** handles visual input and vision processing;
- the **ESP32** handles robot logic, steering, motor output, and sensor-based reactions.

This separation also keeps the software architecture easier to understand and maintain.

## Main Electrical Components

The main electronics system includes:

- **Raspberry Pi Zero**
- **ESP32**
- **OV5647 5 MP wide-angle camera**
- **BNO085 9-DOF IMU**
- **2 VL53L5CX matrix ToF sensors**
- **MG90S steering servo**
- **N20 6 V 600 rpm motor**
- **L298N H-bridge**
- **perfboard-based power and signal distribution**
- **step-down voltage regulation**
- **2 Li-ion batteries in one battery holder**

## Power Distribution

The robot is powered from **2 Li-ion batteries** mounted in a single holder.  
The electrical power is distributed on a **perfboard**, where the supply is split into the required branches.

A **step-down regulator** is used to provide the correct voltage to the logic systems.  
Both the **Raspberry Pi Zero** and the **ESP32** are powered through step-down regulation rather than directly from the battery source.

This was necessary because the robot contains boards with different voltage requirements, and stable regulated logic power is important for reliable operation.

## Design Power Budget

We did not use a laboratory power analyzer during every test session, but we still planned the power system with a conservative engineering budget. The table below is the **design budget** we used to make sure the regulators and wiring were not undersized.

| Subsystem | Main parts | Nominal rail | Design current assumption | Why we budgeted it this way |
| --- | --- | --- | --- | --- |
| Logic compute | `Raspberry Pi Zero`, `ESP32` | regulated logic rail | `0.8 A` continuous budget | Enough margin for camera-side compute peaks plus ESP32 control loop activity |
| Sensors | `BNO085`, `2x VL53L5CX` | regulated sensor rail | `0.25 A` continuous budget | Keeps I2C sensors on a cleaner branch and leaves margin for startup/current spikes |
| Steering | `MG90S` servo | dedicated steering branch | `1.0 A` peak budget | Steering current rises sharply near end-stop or under friction, so this branch needs headroom |
| Drive | `N20` motor through `L298N` | battery / motor branch | `1.5 A` peak budget | Covers acceleration, restart, and corner-exit loading better than a no-margin estimate |
| Total system | all branches together | battery source | about `3.5 A` peak budget | Gives practical headroom instead of sizing the wiring only for average load |

This table is intentionally conservative. We preferred to document a safe branch-sizing assumption rather than claim a more precise number that we did not measure with dedicated bench instrumentation.

## Why We Used Regulated Power

The robot combines logic electronics, sensors, steering actuation, and motor driving.  
These parts do not all behave the same electrically.

Using step-down regulation gave us a cleaner and more controlled supply for the computing boards.  
That is especially important because unstable logic power could cause poor communication, sensor problems, or unstable robot behavior.

The perfboard distribution also made the wiring layout easier to organize and easier to reproduce.

## Sensor Integration

The robot uses three main sensing sources:

- **camera** for forward scene observation;
- **BNO085 IMU** for motion and orientation awareness;
- **2 VL53L5CX matrix ToF sensors** for local distance information.

The sensors are mounted on the **perfboard assembly**, while the **camera is mounted at the front of the robot**.

This placement was chosen because it provided the **best visibility** and made it easier to select the most useful matrix region or matrix point for the sensing algorithm.

## Placement Reasoning Using Field Geometry

We did not place the sensors only where they physically fit. We placed them according to what each sensor needed to see on the WRO field.

- the **camera** is mounted at the front so the robot can observe the lane direction, obstacle color, and approach geometry early enough to plan the target path;
- the **ToF sensors** are used for short-range corridor and side-distance information, so they are placed where their 8x8 grids can sample the near side regions rather than only the far front view;
- the **IMU** is mounted rigidly near the main structure because yaw stability is only useful if the board itself is not wobbling or flexing relative to the chassis.

In practice, this means each sensor covers a different distance scale:

- camera: early interpretation of the scene;
- ToF: short-range geometric confirmation;
- IMU: heading correction and motion consistency.

## Why Sensor Placement Matters

We learned that sensor position affects the quality of the usable data.

The camera had to be placed where it could see the field clearly in front of the robot.  
The distance sensors had to be mounted where their matrix readings could be interpreted consistently and where the selected matrix area would provide the most useful result for the algorithm.

So sensor placement was not random.  
It was chosen for visibility, usable geometry, and better algorithm performance.

## Calibration And Tuning Approach

Our calibration approach was practical and result-based.

Instead of relying only on a theoretical setup, we checked the real robot results and passed the sensor information through the algorithm, then tuned the system according to actual behavior.

This means calibration was performed by observing real output quality and adjusting the processing until the robot behavior improved.

In other words, we tuned the sensing system based on:

- observed field results;
- sensor output behavior;
- algorithm response;
- practical driving quality.

## Practical Calibration Workflow

The sensor calibration workflow that we actually used during development was:

1. mount the `BNO085` rigidly and verify that the reported yaw does not jump while the chassis is standing still;
2. initialize the two `VL53L5CX` sensors one by one and assign unique I2C addresses so both modules remain stable on the same bus;
3. check that the selected ToF zones produce consistent left-right readings when the robot is placed approximately centered in a corridor;
4. set the current heading as `targetAngle` at start, then verify that straight driving keeps the heading error small instead of drifting immediately;
5. re-check all of the above after any change to wheel grip, steering geometry, or sensor mounting.

This workflow mattered because software tuning became unreliable whenever the mechanical mounting changed first and the sensing alignment was not re-checked afterward.

## Failure Points And Mitigations

The power and sensing system was also documented as a risk area, not only as a parts list.

| Failure point | Likely effect | Mitigation used in the robot |
| --- | --- | --- |
| Motor current spikes on the same rail as logic | ESP32 or Pi instability, bad sensor data | separate regulated logic branch and separate motor branch |
| Servo current spikes during hard steering | voltage sag and steering inconsistency | dedicated steering branch with current headroom |
| ToF bus conflicts from two identical sensors | random sensor failure or no readings | wake sensors one by one and reassign I2C addresses |
| IMU vibration or flexible mounting | unstable yaw estimate | rigid mounting and repeated straight-line verification |
| Sensor wires near high-current motor wiring | noisy or inconsistent readings | keep logic/sensor routing separate from motor path as much as practical |

## Design Goal

The main goal of the electronics architecture was to create a system that is:

- fast enough for control;
- clear in function separation;
- electrically organized;
- easy to reproduce;
- suitable for sensor fusion between camera, IMU, and distance sensors.

The final architecture reflects this goal: the camera is handled on the Pi Zero side, the ESP32 performs the main control work, and power is distributed through a regulated and structured layout.
