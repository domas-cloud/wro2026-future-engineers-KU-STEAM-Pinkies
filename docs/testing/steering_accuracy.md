# Steering Accuracy Tests

## Why This Test Exists

The steering system is one of the most important mechanical subsystems in the robot.
If the steering is inaccurate, the rest of the software has to compensate for a physical problem.

## What To Check

- repeatable center position;
- left-right symmetry;
- motion range;
- play or jamming;
- behavior under load.

## Test Procedure

1. Set the steering to center and record the neutral position.
2. Apply small left and right steering offsets.
3. Visually compare the wheel angle on both sides.
4. Repeat the test with the chassis unloaded and loaded.
5. Check whether the steering returns to center after several cycles.

## Success Conditions

- the servo returns to nearly the same center position each time;
- left and right movement remains visually symmetric;
- no obvious jamming appears across the full usable range;
- the steering stays stable when the robot is moved or lightly loaded.
