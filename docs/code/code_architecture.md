# Software Architecture

Our software is designed as a **two-layer control system** to separate high-level perception from low-level motion control.

## 1. High-level layer
The high-level layer is responsible for:
- reading camera data,
- detecting track borders and lane position,
- recognising obstacle colour and side,
- estimating the target driving line,
- sending simplified steering and movement commands to the low-level controller.

This layer is intended to handle the more computationally expensive tasks such as image processing and scene interpretation.

## 2. Low-level layer
The low-level layer is responsible for:
- receiving processed commands from the high-level layer,
- controlling the steering servo,
- controlling the drive motor,
- reading distance sensors,
- applying immediate safety reactions,
- executing recovery logic when the robot gets too close to a wall or loses stable alignment.

This separation makes the system more reliable, easier to debug, and easier to improve during testing.

## Why we chose this architecture
We decided to separate perception and actuation because these two tasks have different requirements.

- **Perception** requires more processing power and flexible logic.
- **Actuation and safety** require predictable and fast responses.

By splitting the software into layers, we reduce the risk that image processing delays would directly affect steering stability. This also allows us to tune the motion controller independently from the vision algorithm.

---

# Main Software Modules

Our final software is divided into several logical modules.

## Vision module
The vision module analyses the camera image and estimates:
- the centre of the lane,
- the relative position of the robot inside the corridor,
- the visible obstacle colour,
- the preferred passing side.

The output of this module is not raw image data, but simplified driving information that can be used by the controller.

## Obstacle interpretation module
This module determines how the robot should react to coloured obstacles:
- **red pillar** means the robot should pass it on the right side,
- **green pillar** means the robot should pass it on the left side.

Instead of treating obstacles as isolated objects, the system modifies the target path of the vehicle depending on the obstacle colour and position.

## Motion control module
The motion control module converts the target path into:
- steering angle,
- drive speed,
- emergency stop or recovery actions.

The steering is adjusted continuously during driving. The goal is not only to follow the lane, but to do so smoothly enough to remain stable at speed.

## Sensor safety module
The safety module monitors short-range sensor readings and checks whether the robot is:
- too close to the wall,
- badly aligned,
- entering a risky collision state.

If necessary, the robot can reduce speed, stop, or perform a short corrective manoeuvre.

## State logic module
The behaviour of the vehicle is organised as a set of operating states, for example:
- lane following,
- obstacle passing,
- wall correction,
- recovery,
- parking.

This makes the behaviour easier to explain, test, and modify.

---

# Driving Logic

The robot does not simply “follow a line”.  
Instead, it tries to maintain a **target trajectory** through the corridor.

## Normal lane following
In normal conditions, the robot estimates the centre of the drivable space and steers toward that centre. This reduces unnecessary oscillation and improves consistency over multiple laps.

## Obstacle handling
When a coloured pillar is detected, the target trajectory is shifted:
- for a **red pillar**, the robot keeps the pillar on its left and passes on the right side,
- for a **green pillar**, the robot keeps the pillar on its right and passes on the left side.

This method is more robust than using a separate hard-coded turn for every obstacle because the robot still adapts to its current position and angle.

## Wall correction
If the robot gets too close to a wall, the software temporarily prioritises collision avoidance over ideal lane following.  
This prevents small tracking errors from turning into full crashes.

## Recovery behaviour
If the robot loses good alignment or becomes trapped in an unstable position, it can perform a short recovery sequence.  
This may include:
- stopping,
- slight reverse movement,
- steering correction,
- re-entering the lane following state.

We included this logic because in testing we found that recovery behaviour improves robustness more than trying to make the robot perfect in every situation.

---

# Steering Strategy

Our steering strategy is based on **continuous correction** rather than fixed-angle turns.

The controller compares:
- the desired path,
- the current robot position,
- the heading error.

Based on this, it calculates a steering adjustment for the front wheels.

This approach was chosen because:
- the track width can vary,
- obstacle positions are random,
- fixed manoeuvres are less reliable across different rounds.

Smooth steering corrections gave us better repeatability than aggressive turning.

---

# Design Trade-offs

During development, we considered multiple software strategies.

## Option 1: all logic in one control loop
This would be simpler to implement, but harder to debug and scale.

## Option 2: split perception and control
We chose this approach because it improves modularity and allows independent tuning of:
- image processing,
- obstacle interpretation,
- motion control,
- safety logic.

## Option 3: fixed manoeuvres for obstacles
This approach would be easier at first, but less adaptable when the robot approaches an obstacle from a slightly different angle or offset.

## Final decision
We chose a **modular adaptive approach** because it is more stable under random field configurations and better matches the competition requirement for repeated autonomous performance.

---

# Testing and Iteration

Our software was not developed in one version.  
We improved it through repeated testing cycles.

## Early version
The early version focused mainly on keeping the robot inside the corridor.  
It could drive, but its turning was too reactive and obstacle passing was inconsistent.

## Intermediate version
We added obstacle-based path shifting and improved steering smoothness.  
This reduced sharp corrections and improved repeatability.

## Later version
We introduced additional safety and recovery logic.  
This made the system more tolerant to imperfect positioning and sensor noise.

## Main lesson
A robot that is slightly less aggressive but more stable performs better over multiple laps than a robot that is fast but inconsistent.

---

# Reproducibility Notes

To make the software easier to reproduce, we structured the project around clear functional blocks:
- perception,
- obstacle interpretation,
- control,
- safety,
- parking.

This means another team can understand:
1. where sensor data enters the system,
2. how decisions are made,
3. how those decisions affect steering and speed.

The software design was documented in this way so that the engineering logic is understandable even without reading every line of code.

---

# Why this software architecture improved our robot

This architecture improved our robot in three important ways:

## 1. Stability
Separating perception from actuation reduced unstable steering behaviour caused by noisy or delayed visual data.

## 2. Obstacle handling
Instead of reacting with fixed turns, the robot changes its target path depending on obstacle colour and position, which is more reliable across random track layouts.

## 3. Maintainability
Because the software is modular, we can improve one part of the system without rewriting the whole robot logic. This was especially useful during testing and iteration.
