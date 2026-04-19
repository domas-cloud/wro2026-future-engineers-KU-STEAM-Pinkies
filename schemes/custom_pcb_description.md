# Custom Electronics Schematic Description

This page explains the provided `Wro_customPCBs.pdf` schematic in plain engineering language.

The PDF was drawn in KiCad and documents the electronics that are used in our robot even though the real assembly is soldered on a perfboard rather than manufactured as a custom PCB. The purpose of the schematic is therefore reproducibility: it shows how power is split, which board controls which subsystem, and how the main modules are connected.

## What The Schematic Contains

The drawing shows these main electronic blocks:

- `ESP32-WROOM-32` as the main control board;
- `Raspberry Pi Zero` as the camera-side computing board;
- `BNO085` IMU;
- two `VL53L4CD` distance sensor modules, marked as `FRONT` and `SIDE`;
- `L298N` full motor-driver board;
- steering servo motor;
- DC drive motor;
- 2-cell `18650` battery supply and step-down power conversion.

## Power Architecture

The schematic shows a battery input of about `7.5 V` coming directly from two `18650` cells. From this source, the system is split into separate power branches:

- raw battery voltage goes to the `L298N` motor driver for the DC drive motor;
- a regulated `5 V` rail feeds the `ESP32`;
- the sensor modules are also supplied from `5 V` because their breakout boards include their own local regulation;
- logic communication still operates at `3.3 V` on the sensor side.

This is important because it documents that the robot was not wired as one uncontrolled battery rail. The motor path and the logic path were separated on purpose.

## Control Responsibilities

The schematic confirms the system split used across the rest of the documentation:

- the `Raspberry Pi Zero` is the companion compute board;
- the `ESP32` is the real-time control board;
- the `ESP32` reads the IMU and distance sensors;
- the `ESP32` drives the steering servo and the motor driver;
- the `Raspberry Pi Zero` is kept separate from the motor-control wiring.

## Sensor Bus Layout

The `BNO085` and both distance sensors are connected to the same `SDA` and `SCL` buses. The schematic also shows separate shutdown or enable handling for the distance modules through `GPIO4` and `GPIO5`, which matches the idea of powering up the sensors one by one and assigning unique I2C addresses in software.

In practice, this bus structure supports:

- one shared I2C-style sensor bus;
- individual startup control for the two distance sensors;
- compact wiring from the sensor area back to the `ESP32`.

## Actuator And Motor Path

The actuator side is separated into two different outputs:

- a PWM steering output from the `ESP32` to the servo motor;
- drive-control signals from the `ESP32` to the `L298N`, then from the `L298N` to the DC motor.

This matters because the steering and drive systems do not behave the same electrically. The servo is a position-controlled actuator, while the DC motor needs a dedicated H-bridge path.

## Why This Schematic Helps The Documentation

The PDF is useful for judges and rebuilders because it shows more than a component list. It shows:

- how the robot is powered;
- which board is responsible for sensing and control;
- how the sensors share the communication bus;
- how the drive motor is isolated behind a motor-driver board;
- that the real robot electronics were planned as a system, even though the final implementation uses perfboard.

## Rebuild Notes Based On The Drawing

If another team uses this schematic as a rebuild reference, the most important practical points are:

1. keep the battery-to-motor path separate from the sensitive logic and sensor wiring;
2. feed the `ESP32` and sensor boards from regulated power, not directly from the battery pack;
3. use the sensor shutdown lines so identical distance modules can be initialized one by one;
4. keep one common ground between the `ESP32`, `Raspberry Pi Zero`, sensors, servo, and motor driver;
5. treat the PDF as the electrical reference, while the perfboard layout is the physical implementation.
