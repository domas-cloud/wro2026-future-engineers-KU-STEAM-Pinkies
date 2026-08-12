# Custom Electronics Schematic Description

This file explains what is shown in `Wro_customPCBs.pdf` in plain engineering language.

Even though the robot is assembled on perfboard, the schematic is still useful because it shows the electrical structure clearly: power branches, board roles, sensors, actuators, and the links between them.

## Main Blocks In The Schematic

The drawing includes:

- `ESP32-WROOM-32` as the low-level control board;
- `Raspberry Pi Zero` as the camera-side board;
- `BNO085` IMU;
- one front `VL53L1X` ToF sensor;
- `2x VL53L1CD` side-distance sensors;
- `L298N` motor driver;
- steering servo;
- DC drive motor;
- 2-cell `18650` battery supply and step-down regulation.

## What The Code Confirms

The controller code in `src/src/main.cpp` makes a few things very clear:

- the `ESP32` runs the low-level control loop;
- it reads front, left, and right distance sensors;
- it reads yaw from the `BNO085`;
- it drives the servo and motor output.

So the schematic should be read together with the code: the PDF shows the full electrical layout, while `main.cpp` shows the control side directly.

## Power Structure

The battery pack feeds several branches:

- raw battery voltage to the `L298N` and drive motor;
- regulated `5 V` for the `ESP32`;
- regulated `5 V` for the `Raspberry Pi Zero`;
- regulated power for the sensing hardware.

That separation matters because the motor path and the logic path do not behave the same electrically.

## Board Responsibilities

The intended split is straightforward:

- the `Raspberry Pi Zero` handles camera-side perception;
- the `ESP32` handles real-time control;
- the `ESP32` reads the IMU and distance sensors;
- the `ESP32` drives the steering servo and the motor driver.

## Sensor Bus

The `BNO085` and the ToF sensors share the main sensor bus. The distance sensors also use separate shutdown lines so the front `VL53L1X` and the two side `VL53L1CD` modules can be started in the intended sequence and assigned different addresses.

That is one of the most practical details in the whole design, because without it the ToF sensors would conflict on the bus.

## Actuation Path

The actuator side is split into two very different outputs:

- PWM steering control from the `ESP32` to the servo;
- drive-control signals from the `ESP32` to the `L298N`, then to the motor.

This is why the schematic should not be read as a random wiring map. It reflects the fact that steering and drive actuation need different handling.

## Why The Schematic Matters

The PDF helps for three reasons:

- it shows the planned electrical structure in one place;
- it makes the power and signal layout easier to follow than a photo alone;
- it gives another team a realistic starting point for rebuilding the system.

## Practical Rebuild Notes

If another team wanted to follow this layout, the most important points would be:

1. keep the motor-current path away from logic and sensor wiring;
2. use regulated power for the control and perception boards;
3. initialize the ToF sensors in the intended startup sequence;
4. keep a common ground across the whole system;
5. treat the PDF as the electrical reference and the perfboard as the physical implementation.
