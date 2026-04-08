# Sensor Issues

## What To Record

- blind spots;
- noisy readings;
- incorrect calibration;
- physical placement problems;
- interference from the environment or other hardware.

## Specific Examples

- `BNO085` fusion drift before calibration;
- distance spikes from the 2 `VL53L5CX` matrix ToF modules caused by reflective surfaces;
- a camera frame that does not include the lane edge;
- sensor readings affected by vibration or cable routing.

## Why This Matters

Sensor issues often look like software bugs, so the fix log needs to explain clearly what was actually changed.
