# Power Instability

## What To Record

- voltage drops;
- resets under load;
- noisy sensor readings caused by power dips;
- problems in the power rails.

## Specific Suspects

- `N20` startup current pulling down the battery rail;
- `L298N` voltage drop reducing available motor headroom;
- shared power-rail noise affecting the `BNO085`, the 2 `VL53L5CX` matrix ToF modules, or the camera.

## Why This Matters

Power instability is one of the fastest ways to make the robot look as if it has unrelated mechanical or software faults.
