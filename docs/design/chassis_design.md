# Chassis Design

## Chassis Goal

The chassis must keep the robot rigid enough for steering accuracy while leaving enough room for electronics, sensors, and wiring.

## Design Considerations

- low flex around the steering mount;
- enough clearance for wheel travel;
- secure mounting for batteries and compute boards;
- easy access for maintenance and inspection.

## Component Placement Logic

- the `MG90S` should sit where the steering linkage stays short and direct;
- the `N20` and `L298N` should be mounted so the drive path stays mechanically clean;
- the `ESP32` and `Raspberry Pi Zero` should be positioned away from the highest-noise power path if possible;
- the `BNO085` should be mounted rigidly and away from vibration sources where practical;
- the `VL53L5CX` should have a clear line of sight toward the area it must observe.

## Why This Matters

If the chassis flexes too much, the steering geometry and sensor alignment drift during movement.
The documentation should therefore explain both structure and rigidity, not just appearance.
