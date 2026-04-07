# Power Instability

## What To Log

- brownouts;
- resets under load;
- noisy sensor readings caused by power drops;
- voltage rail problems.

## Build-Specific Suspects

- `N20` startup current pulling down the battery rail;
- `L298N` voltage drop reducing available motor headroom;
- shared power rail noise affecting `BNO085`, `VL53L5CX`, or the camera.

## Why It Matters

Power instability is one of the fastest ways to make a robot look like it has unrelated mechanical or software failures.
