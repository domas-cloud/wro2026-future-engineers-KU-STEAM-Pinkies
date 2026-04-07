# PID Tuning

## Why PID Matters

If the robot uses PID for steering or motion correction, the tuning should be documented because it directly affects track consistency.

## What To Record

- what variable is controlled;
- what gains were adjusted;
- what changed after tuning;
- what symptoms indicated overcorrection or sluggish behavior.

## Tuning Workflow

1. Set a safe baseline with conservative gains.
2. Tune steering response first, because it affects lane tracking most directly.
3. Check for overshoot, delay, and oscillation.
4. Adjust drive-related corrections only after steering is stable.
5. Repeat the test on the same track section so comparisons stay meaningful.

## Current Status

If numeric tuning results are not yet available, the document should still describe the tuning method and the order in which parameters were changed.
