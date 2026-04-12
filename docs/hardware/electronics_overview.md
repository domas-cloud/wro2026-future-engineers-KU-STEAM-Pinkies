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
- **N20 6 V [SET_REAL_RPM] rpm motor**
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

## Design Goal

The main goal of the electronics architecture was to create a system that is:

- fast enough for control;
- clear in function separation;
- electrically organized;
- easy to reproduce;
- suitable for sensor fusion between camera, IMU, and distance sensors.

The final architecture reflects this goal: the camera is handled on the Pi Zero side, the ESP32 performs the main control work, and power is distributed through a regulated and structured layout.
