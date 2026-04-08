# Chassis Design

## Chassis Goal

The chassis must keep the robot rigid enough for accurate steering while still leaving space for electronics, sensors, and wiring.

## Structural Material

The frame is made from laser-cut plywood.
Two plywood layers are used around the steering assembly so bearings can be fitted accurately.
Those bearings support the bolts that form the steering pivots and hold the steering assembly in place.

## Structural Considerations

- minimize flex around the steering mounts;
- increase stiffness around the steering assembly by using a double plywood layer;
- provide enough clearance for wheel movement;
- secure the battery and computing boards safely;
- allow easy access for maintenance and inspection.

## Component Layout Logic

- the `MG90S` should be placed where the steering linkage stays short and direct;
- the steering assembly should ride on bearings so the bolts and steering pivots move accurately with less play;
- the `N20` and `L298N` should be mounted so the drivetrain path stays mechanically clean;
- the `ESP32` and `Raspberry Pi Zero` should be positioned as far as practical from the noisiest power branch;
- the `BNO085` must be mounted firmly and, as much as possible, away from vibration sources;
- the 2 `VL53L5CX` matrix ToF modules must have a clear field of view toward the areas they are meant to observe.

## Why This Matters

If the chassis flexes too much, the steering geometry and sensor alignment begin to change while the robot is moving.
The double plywood layer around the steering area and the use of bearings help preserve more accurate steering geometry.
