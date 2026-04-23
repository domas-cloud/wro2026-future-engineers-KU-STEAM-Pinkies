# Performance Measurements

This section records the metrics we used while comparing different versions of the robot.

We did not build a full laboratory-style dataset. Instead, we kept the measurements that were actually useful during development:

- repeated observations across several runs;
- direct comparisons between older and newer versions;
- a few simple numerical checks that helped us decide what to keep.

## Main Metrics We Used

| Metric | How we checked it | Why it matters in competition |
| --- | --- | --- |
| 3 m straight-drive drift | compare whether one version drifts more than another over the same distance | this is a direct stability check relevant to lane following |
| 90-degree turn space | compare how much floor area the robot needs in the same corner type | more efficient turning helps obstacles and parking |
| steering center repeatability | cycle steering left/right and check whether the robot returns close to the same center behavior | poor center repeatability creates drift that is not caused by software alone |
| left-right symmetry | compare left and right turn response under similar steering commands | asymmetric steering makes path-following inconsistent |
| repeated-run consistency | repeat the same run pattern several times | WRO rewards repeatability, not one lucky result |

## Evidence Types We Used

To keep the measurements honest, we used these evidence levels:

| Evidence type | What it means |
| --- | --- |
| repeated observation | the same result was seen several times during comparison |
| structured comparison | one version was clearly better or worse than another using the same criteria |
| simple count-based note | the number of comparison attempts was small but still recorded or estimated |

## Current Observed Results

The current engineering conclusions supported by repeated testing are:

- after the steering-geometry correction, the servo worked with less load and the center position remained more stable;
- keeping the differential reduced slip and turning resistance in corners;
- the 3 `VL53L4CD` modules gave enough short-range information for front and side control;
- a more rigidly mounted `BNO085` improved heading-stability estimation;
- the `600 rpm` motor gave a better balance than the slower and faster alternatives.

## Comparison-Oriented Measurement Table

| Subsystem | Older situation | Final situation | Result of comparison |
| --- | --- | --- | --- |
| drive motor | too slow or too weak under load | `600 rpm` N20 | better balance of speed and usable torque |
| steering geometry | large lever arm | corrected geometry | lower servo load and more repeatable steering |
| front wheels | more slip on the floor | silicone front wheels | stronger conversion of steering command into real motion |
| differential | less suitable earlier solution | `LEGO` differential | smoother turning and less resistance |
| IMU mounting | less rigid mounting | more rigid mounting | more stable heading behavior across runs |

## What We Still Did Not Claim

To keep the documentation honest, we do not claim:

- laboratory-grade current or force measurements;
- precise drift values for every version;
- exact success percentages where we did not keep a strict counted dataset.

Instead, we document only the results that were clear enough to affect real design decisions.

## What Could Still Improve This Section

If more time remains before final submission, the strongest additions would be:

- one short numeric table for repeated straight-drive drift;
- one short numeric table for repeated obstacle runs;
- one counted success-rate table for the final version on one consistent test layout.

## Engineering Conclusion

Even without a large numeric dataset, these measurements still support the main design decisions:

- steering geometry correction reduced servo load and improved center repeatability;
- the `LEGO` differential reduced cornering resistance;
- silicone front wheels improved the effect of steering on the track surface;
- rigid `BNO085` mounting improved heading stability;
- the final selected combination was the one that behaved more repeatably across repeated tests.
