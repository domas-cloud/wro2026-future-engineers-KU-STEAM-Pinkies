# Parts List

## Main Electronics

- `ESP32` for main control and the decision loop;
- `Raspberry Pi Zero` for camera data processing;
- `BNO085 9-DOF IMU` for orientation and motion stability;
- 2 `VL53L5CX` matrix ToF modules for short-range distance sensing and obstacle confirmation;
- `OV5647 5Mpx wide-angle` camera (`Waveshare 14037`) for track and obstacle observation.

## Drive And Steering

- `MG90S` steering servo;
- `N20` drive motor;
- `L298N H-bridge` for motor control;
- three-gear steering mechanism;
- side steering assemblies with wheel mounting hardware.

## Power

- `2x 18650 Li-ion` battery pack;
- regulated logic power rail;
- power and signal wiring connections.

## Mechanics

- chassis structure;
- gear set from `models/`;
- rear axle differential;
- rear `LEGO` wheels;
- front custom-cast silicone wheels;
- wheel axles, brackets, and fastening hardware.

## Note

This list includes the main robot components that directly affect driving, sensing, and control.
If a full manufacturing specification is prepared later, this document should also include quantities, voltages, gear ratios, and exact connector details.
