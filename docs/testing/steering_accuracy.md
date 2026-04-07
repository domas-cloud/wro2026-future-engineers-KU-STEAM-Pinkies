# Steering Accuracy Tests

## Why This Test Exists

The steering system is one of the most important mechanical subsystems on the robot.
If steering is not accurate, the rest of the software has to compensate for a physical problem.

## What To Check

- repeatable center position;
- left and right symmetry;
- range of motion;
- backlash or binding;
- behavior under load.

## Test Procedure

1. Center the steering and record the neutral position.
2. Command small left and right offsets.
3. Compare the visual wheel angle on both sides.
4. Repeat the test with the chassis loaded and unloaded.
5. Check whether the steering returns to center after several cycles.

## Pass Conditions

- the servo returns close to the same center position each time;
- left and right movement stays visually symmetric;
- no obvious binding appears across the usable range;
- the steering remains stable when the robot is moved or lightly loaded.
