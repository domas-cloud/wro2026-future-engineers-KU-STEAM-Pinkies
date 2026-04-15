# Software Architecture

## Overview

Our software is designed as a **two-layer system**:

- **Raspberry Pi Zero** handles camera-based perception,
- **ESP32** handles control, actuation, and fast reactions.

We chose this architecture because perception and motion control have different requirements. Camera processing needs more flexible computation, while steering and motor control require fast and predictable execution.

Instead of forcing one board to do everything, we separated the tasks and gave each controller a clear role.

## Why We Split the System

The most important reason for splitting the software was **stability**.

If image processing directly delays motion control, the robot can react too late and steering can become inconsistent. By separating the vision side from the real-time control side, we reduced the risk that perception delays would directly disturb driving behaviour.

This architecture also made the project easier to debug and improve:

- visual logic could be improved separately,
- motion control could be tuned separately,
- and sensor / actuator reactions could stay fast and simple.

## High-Level Layer: Perception

The Raspberry Pi Zero is responsible for the camera-side logic.

Its main tasks are:

- reading the camera image,
- detecting the relevant track information,
- identifying obstacle colour,
- estimating the target driving line,
- sending simplified driving information to the ESP32.

A key design decision was that the Pi does **not** send raw image data to the ESP32. Instead, it sends a simplified result that is easier for the controller to use in real time.

This makes the overall system cleaner and reduces unnecessary data handling on the control side.

## Low-Level Layer: Control and Actuation

The ESP32 is responsible for the main control behaviour.

Its main tasks are:

- receiving the processed visual result,
- calculating steering output,
- controlling the drive motor,
- handling short-range corrective behaviour,
- and executing the final motion commands.

This role division matches the strengths of the board. The ESP32 is better suited for fast control work and direct actuator handling, so it became the main execution controller.

## Modular Software Structure

Our software is organised into several logical modules.

### 1. Vision module

This module processes the camera image and extracts the information needed for navigation.

### 2. Obstacle interpretation module

This module determines how the target path should change depending on obstacle colour.

### 3. Motion control module

This module converts the target path into steering and drive output.

### 4. Recovery / correction module

This module handles situations where the robot needs to correct its position or recover from a less stable state.

### 5. Parking logic

This module is responsible for the final parking behaviour after the required laps are completed.

This modular structure was chosen because it makes the robot behaviour easier to explain, easier to tune, and easier to extend.

## Why We Did Not Use One Huge Control Loop

A simpler-looking alternative would have been to put everything into one large control loop.

We rejected that idea because it would make the project:

- harder to debug,
- harder to tune,
- and harder to document clearly.

A modular system gave us better engineering clarity and helped us improve one part of the robot without breaking everything else.

## State-Based Behaviour

Although the robot keeps one main navigation principle, its behaviour can still be understood through a set of practical operating states, for example:

- normal lane following,
- obstacle handling,
- correction / recovery,
- parking.

This state-oriented view helped us structure the logic and explain the robot behaviour more clearly in documentation.

## Main Benefit of This Architecture

The most important improvement from this architecture was that the robot became:

- more stable,
- easier to tune,
- easier to maintain,
- and easier to justify as an engineering solution.

## Final Conclusion

Our final software architecture was selected because it matched the physical structure of the robot and supported more reliable autonomous driving.

The core idea was simple:

- perception should stay on the Pi,
- control should stay on the ESP32,
- and the communication between them should contain only the information needed for driving.

This gave us a software structure that was clear, modular, and practical for repeated testing and improvement.
