# Sensor Placement Strategy

## Placement Logic

The camera, `BNO085`, and `VL53L5CX` should be placed according to what they need to observe.

- Camera: positioned to see the lane and relevant obstacles.
- `BNO085`: mounted rigidly near the robot's center of motion.
- `VL53L5CX`: placed to cover the expected obstacle zones and blind spots.

## What To Explain

- why the placement supports the field geometry;
- what blind spots are still possible;
- how placement changed during iteration.
