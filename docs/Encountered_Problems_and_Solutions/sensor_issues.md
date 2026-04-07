# Sensor Issues

## What To Log

- blind spots;
- noisy readings;
- miscalibration;
- physical placement problems;
- interference from the environment or other hardware.

## Build-Specific Examples

- `BNO085` fusion drift before calibration;
- `VL53L5CX` distance jumps caused by reflective surfaces;
- camera framing that misses the lane edge;
- sensor reads affected by vibration or cable routing.

## Why It Matters

Sensor problems often appear as software faults, so the fix log must explain what was actually changed.
