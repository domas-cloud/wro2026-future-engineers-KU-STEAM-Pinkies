# Idea Generation

## Concepts We Considered

We explored several steering and navigation ideas before settling on the current layout:

- direct differential drive only;
- servo-based front steering;
- gear-linked steering with synchronized left and right motion;
- camera-only navigation versus camera plus extra sensors.

## Reasoning

Differential drive is simple, but for this track concept we wanted more explicit steering control and a more car-like motion model.
Camera-only navigation is possible, but we wanted additional sensing for robustness around obstacles and edge cases.

## Direction Chosen

The strongest concept combined:

- servo-driven steering;
- a gear transmission that keeps the front steering mechanism synchronized;
- `Raspberry Pi Zero` for perception and planning;
- `ESP32` for lower-level control and actuator handling;
- camera, `BNO085 9-DOF IMU`, and `VL53L5CX` for complementary sensing.

## Why This Was Promising

This combination gave us a clear split between perception and control, while keeping the mechanics understandable and documentable.
It also gave us a structure that can be iterated without redesigning the whole robot.
