# Performance Measurements

This section records the metrics that can be used to compare different versions of the robot.
At the moment, most conclusions are still qualitative, but the measurement structure is already defined and used during testing.

## Main Metrics To Observe

- steering center repeatability after several cycles;
- left-right turning symmetry;
- robot stability while following the lane;
- obstacle-handling reliability;
- robot behavior after a sharper turn or correction.

## Qualitative Conclusions From Current Tests

- After the steering-geometry correction, the servo worked with less load and the center position remained more stable.
- Keeping the differential reduced slip and turning resistance in corners.
- The 2 `VL53L5CX` modules were sufficient for short-range confirmation when camera information alone was not enough.
- A more rigidly mounted `BNO085` improved heading-stability estimation.

## What Still Needs To Be Collected

To make the documentation stronger, this section should later include numerical data collected under consistent conditions:

- how many times in a row the steering returns to the same neutral position;
- how many successful runs in a row the robot completes on the same track;
- how often obstacle confirmation requires intervention from a ToF module;
- how often slipping or excessive correction appears in turns.

## Measurement Note

Until a full quantitative table is available, this section includes only observations that were consistently seen across multiple iterations.
That keeps the documentation honest and avoids inventing numbers that were not actually measured.
