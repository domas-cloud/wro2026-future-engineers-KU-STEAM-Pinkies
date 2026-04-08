# Sensor Placement Strategy

## Placement Logic

The camera, `BNO085`, and 2 `VL53L5CX` matrix ToF modules should be positioned according to what they need to observe.

- Camera: aimed so it can see the lane and relevant obstacles.
- `BNO085`: mounted rigidly near the robot's motion center.
- 2 `VL53L5CX` matrix ToF modules: placed to cover expected obstacle zones and blind areas.

## What Should Be Explained

- why the placement fits the track geometry;
- which blind spots may still remain;
- how the placement changed during iteration.
