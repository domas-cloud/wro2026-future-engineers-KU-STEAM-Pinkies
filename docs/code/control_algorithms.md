# Control Algorithms

## Architecture

The control logic separates perception from execution:

- the `Raspberry Pi Zero` captures and forwards `OV5647` camera data;
- the `ESP32` interprets camera and sensor information and controls the hardware;
- the `ESP32` performs error calculation, state logic, safety checks, and low-level hardware control.

## Relationship To The Older Robot Model

The core algorithm idea comes from an earlier KU STEAM Pinkies robot: error calculation, corrective control, steering and motor output, and obstacle logic.
The difference is that in the new robot all computation has been moved to the `ESP32`, while the `Raspberry Pi Zero` is used only for camera capture.
What is transferred is the control philosophy, not the same sensor-reading layer or the same hardware modules.

## Main Control Responsibilities

- extract lane position or lane error from camera input;
- combine camera input with supporting signals from the `BNO085` and the 2 `VL53L5CX` matrix ToF modules;
- estimate the forward situation from camera and short-range inputs;
- convert the current error into a steering command;
- limit steering changes so the robot does not oscillate;
- reduce drive output when confidence is low or when the robot is in a recovery state.

## Algorithm Types

- lane-following control;
- steering correction;
- obstacle response;
- safety overrides when sensor input appears invalid.

## Active Control Model

- the camera is the main input for lane geometry and forward-scene estimation;
- the `BNO085` supports heading stability;
- the 2 matrix `VL53L5CX` modules are used for short-range obstacle confirmation;
- the state logic decides whether to follow the lane, avoid, slow down, or stop.
