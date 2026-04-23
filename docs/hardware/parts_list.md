# Parts List

## Main Electronics

- `ESP32` for main control and the decision loop;
- `Raspberry Pi Zero` for camera-side perception;
- camera module for scene interpretation;
- `BNO085 9-DOF IMU` for orientation and motion stability;
- 3 `VL53L4CD` distance sensors for front and side distance sensing;

## Drive And Steering

- `MG90S` steering servo;
- `N20` drive motor;
- `L298N H-bridge` for motor control;
- three-gear steering mechanism;
- side steering assemblies with wheel mounting hardware.

## Power

- `2x 18650 Li-ion` battery pack;
- regulated logic rail for the `ESP32` and `Raspberry Pi Zero`;
- regulated sensor rail;
- separated motor power path through the `L298N`;
- steering power branch sized for servo current spikes;
- step-down voltage regulation;
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
If a full manufacturing specification is prepared later, this document should also include quantities, voltages, gear ratios, connector details, and replacement-compatible part variants.
