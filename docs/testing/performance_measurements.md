# Performance Measurements

This section records the metrics that can be used to compare different versions of the robot.
The project does not yet include a full bench-measurement dataset, so this file separates three kinds of evidence:

- direct observations repeated across multiple runs;
- structured pass/fail or weak/strong comparisons;
- future numeric data that could still be added before final submission.

## Main Metrics To Observe

- steering center repeatability after several cycles;
- left-right turning symmetry;
- robot stability while following the lane;
- obstacle-handling reliability;
- robot behavior after a sharper turn or correction.

## Comparison Template We Actually Used

| Metric | How we checked it | Why it matters |
| --- | --- | --- |
| steering center repeatability | cycle steering left/right repeatedly and return to center | poor center repeatability creates software drift that is not caused by the controller |
| left-right symmetry | compare left and right turn response under similar steering commands | asymmetric steering makes path-following inconsistent |
| 3 m straight-drive drift | observe whether one version drifts more than another over the same distance | this is a direct competition-relevant stability check |
| 90-degree turn space | compare how much floor area the robot uses in the same corner type | better turning efficiency improves obstacle and parking behavior |
| repeated-run consistency | repeat the same run pattern several times | WRO rewards repeatability, not one lucky result |

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

## Current Engineering Conclusion

Even before a larger numeric dataset is added, the current measurement structure already supports the major decisions documented elsewhere in the repository:

- steering geometry correction reduced servo load and improved center repeatability;
- the `LEGO` differential reduced cornering resistance;
- silicone front wheels improved the conversion of steering command into real floor motion;
- rigid `BNO085` mounting improved heading stability;
- a simpler and calmer controller produced more repeatable runs than a more aggressive one.

## Measurement Note

Until a full quantitative table is available, this section includes only observations that were consistently seen across multiple iterations.
That keeps the documentation honest and avoids inventing numbers that were not actually measured.
