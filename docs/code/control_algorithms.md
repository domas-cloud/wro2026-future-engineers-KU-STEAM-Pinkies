# Control Algorithms

## Purpose

This file explains how our robot converts perception results into steering and speed commands.

Our software does not use many disconnected driving behaviours for normal movement.  
Instead, the robot keeps one main control principle and adjusts its target depending on the situation.

The main idea is:

- use the camera as the primary source for track interpretation;
- estimate a navigation error relative to the desired path;
- apply PD steering correction;
- modify the target path when obstacle colour requires a different passing side;
- apply safety limits when the robot becomes uncertain or too close to a wall.

This approach was chosen because it keeps the robot behaviour smooth, easier to tune, and easier to reproduce.

---

## Control Architecture

The control system is split into two parts:

### Raspberry Pi Zero
The Raspberry Pi Zero is responsible for:
- capturing camera data;
- running the vision algorithm;
- extracting simplified navigation information from the image;
- sending the processed result to the ESP32.

### ESP32
The ESP32 is responsible for:
- receiving the processed vision result;
- reading supporting sensor data;
- calculating steering correction;
- applying speed logic;
- handling safety and recovery states;
- commanding the steering servo and drive motor.

This division was selected because perception and actuation have different timing and processing requirements.

---

## Main Inputs

Our control decisions are based on several sources of information.

### 1. Camera result
The camera is the main source for:
- lane position;
- path geometry;
- obstacle colour interpretation;
- obstacle-related target shifting.

### 2. IMU support
The `BNO085` is used to support heading stability.  
Its role is not to replace vision, but to improve consistency when visual information changes quickly or when the robot is turning.

### 3. Short-range ToF confirmation
The 2 `VL53L4CD` distance sensors are used as supporting short-range inputs.  
They help confirm close-range wall or obstacle situations and improve safety decisions.

---

## Lane-Following Control

The base driving behaviour of our robot is **PD line following**.

This means the controller constantly calculates how far the robot is from the desired path and then applies a steering correction.

### Control idea
The controller uses:

- a **proportional term** to react to the current position error;
- a **derivative term** to react to how quickly that error is changing.

In simplified form:

`steering_output = Kp * error + Kd * error_change`

Where:

- `error` means the difference between the desired path and the current detected path position;
- `error_change` means how quickly that error is changing between control cycles.

We selected PD control because:

- it is simpler than a larger state-heavy approach;
- it gives continuous steering correction;
- it is fast to compute;
- it can be tuned practically through repeated track testing;
- it produces smoother behaviour than a simple threshold-based controller.

---

## Path Target Strategy

The robot does not only ask:
"Is there an obstacle or not?"

Instead, it asks:
"Which target path should I follow right now?"

This is one of the most important control decisions in our project.

### Normal mode
In normal driving, the robot follows its default target path through the corridor.

### Obstacle mode
When a coloured obstacle is detected, the target path is changed according to obstacle meaning:

- a **red pillar** causes the robot to bias its path so that it passes on the correct side;
- a **green pillar** causes the robot to bias its path in the opposite direction.

So the obstacle does not replace the line-following controller.  
It changes the reference that the same PD controller follows.

This gave us several engineering advantages:

- smoother transitions;
- less aggressive switching;
- easier tuning;
- simpler debugging;
- better consistency between normal driving and obstacle driving.

---

## Steering Output Logic

After the navigation error is calculated, the robot converts it into a steering command for the front wheels.

The steering command is not allowed to change without limits.  
We intentionally constrain steering behaviour to reduce oscillation and protect stability.

The steering stage therefore includes:

- error-based correction;
- output limiting;
- smoothing of rapid changes when necessary;
- return toward centre in uncertain cases.

This was important because large instantaneous steering changes made the robot less stable in testing.

---

## Speed Control Logic

Steering and speed are not treated as fully independent.

The drive output is reduced when:
- the robot is in a more uncertain situation;
- the path geometry becomes harder to follow;
- obstacle passing requires more control accuracy;
- recovery or safety logic becomes active.

This is an important engineering decision because maximum speed is not always the fastest strategy over a full run.  
A slightly slower but more stable robot usually performs better over repeated laps.

---

## Safety Overrides

Safety logic can temporarily override ideal navigation behaviour.

Examples include:
- reducing speed when sensor confidence is low;
- suppressing stale commands;
- stopping when communication is invalid;
- entering a recovery state when the robot is too close to a wall or loses stable alignment.

This means our controller is not only an optimisation system.  
It is also a protection system for maintaining stable autonomous behaviour.

---

## Recovery Logic

We included recovery behaviour because a real competition robot cannot assume that every frame and every position will be perfect.

When the robot detects that it has entered a poor situation, it may:
- stop;
- reduce speed;
- apply a short reverse action;
- re-centre steering;
- re-enter the normal lane-following state.

This was added after practical testing showed that recovery logic improves robustness more than trying to eliminate every possible driving error in advance.

---

## Why We Chose This Algorithm Structure

We considered more fragmented control approaches, but we preferred one main continuous controller with target adjustment.

We chose this structure because it gave:
- one clear base behaviour;
- simpler software organisation;
- better reproducibility in documentation;
- easier practical tuning;
- smoother behaviour under random field layouts.

The final result is a control system where:
- PD lane following remains the core driving behaviour;
- obstacle colour changes the target path;
- supporting sensors improve confidence and safety;
- safety and recovery logic protect the robot from unstable situations.

---

## Practical Tuning Philosophy

Our control tuning was based on repeated real track testing.

In general, we adjusted the control system to achieve:
- lower oscillation;
- more repeatable straight driving;
- smoother obstacle transitions;
- fewer strong corrections near walls;
- more stable behaviour over multiple laps.

The most important lesson from tuning was that a robot with smoother and more controlled reactions performed better than a robot with more aggressive but less stable behaviour.

---

## Summary

Our control algorithm is based on one central principle:

**keep one main PD-based driving behaviour and adapt its target instead of replacing the whole controller for each situation.**

This made our robot:
- easier to tune;
- easier to explain;
- more stable in practice;
- more suitable for repeated autonomous runs.
