# Track Testing

## Purpose

Track testing validates the complete robot in conditions closer to the competition.

## What To Observe

- lane following consistency;
- obstacle handling behavior;
- steering stability across turns;
- repeatability across multiple runs.

## Build-Specific Observations

- whether the `MG90S` returns to center consistently;
- whether the `N20` drive motor and `L298N` keep acceleration repeatable;
- whether `VL53L5CX` readings remain usable near obstacles and reflective surfaces;
- whether the `BNO085` helps stabilize heading after repeated turns.

## Track Test Scenarios

- straight lane follow on a clear segment;
- left and right turns with repeated steering correction;
- obstacle appearance and recovery on a short segment;
- a full lap where the robot must repeat the same behavior several times.

## Evidence To Keep

- track layout or a short description of the course;
- number of laps or repeats;
- what failed or improved;
- photos or video timestamp if available.

## Documentation Rule

Record the test setup, the conditions, and the observed behavior even when the robot still needs improvement.
