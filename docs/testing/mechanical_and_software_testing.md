# Mechanical and Software Testing

## Overview

Our development process depended on repeated testing of the whole robot, not only isolated parts. Mechanical changes often changed our software behavior, and software tuning often revealed mechanical weaknesses.

This is why we evaluate the robot as one connected system.

## Mechanical Testing Summary

The main mechanical comparison areas were:

- `300 rpm`, `600 rpm`, and `1000 rpm` `N20` motors;
- steering `Version 1`, `Version 2`, and `Version 3`;
- earlier front wheels versus silicone front wheels;
- earlier differential solution versus the final `LEGO` differential.

Main practical criteria:

- space needed for a 90-degree turn;
- drift over a 3-meter straight drive;
- steering smoothness;
- repeatability between runs.

## Comparison Table Used For Final Selection

We used the following comparison structure when choosing between major versions. The ratings are not laboratory measurements; they are condensed engineering observations from repeated side-by-side testing under the same goals.

| Comparison area | Earlier version | Final version | What changed in practice |
| --- | --- | --- | --- |
| motor choice | `300 rpm` or `1000 rpm` options | `600 rpm` N20 | better balance of usable speed and torque |
| steering geometry | Version 1 with larger lever arm | Version 2/3 with reduced load | servo load dropped and steering became more repeatable |
| front wheel material | earlier wheels with more slip | silicone front wheels | stronger real steering effect on the floor |
| rear differential | earlier less suitable differential solution | `LEGO` differential | smoother cornering and less binding |
| sensor mounting | less rigid IMU / less refined placement | rigid IMU plus cleaner sensor layout | heading estimate and repeated behavior became more stable |

## Software Testing Summary

We judged the software side by what our robot actually did on track:

- did it wobble;
- did it return to the target line;
- did it overshoot after correction;
- did obstacle transitions stay smooth;
- did it return cleanly to the normal line after a turn or obstacle.

The main low-level controller references are documented in:

- `docs/code/pd_controller_explanation.md`
- `docs/code/software_flow_and_state_logic.md`
- `docs/code/software_testing_and_tuning.md`
- `docs/code/navigation_strategy_improved.md`

## Software Criteria We Used

We used simple but useful criteria:

- wobble present or not;
- correction too weak or too aggressive;
- stable return to target line or repeated overshoot;
- smooth obstacle pass or abrupt path change;
- stable recovery after a turn or disturbance.

These criteria were practical because they directly matched competition behavior.

## Run-to-Run Evaluation Method

For the most important comparisons, we did not judge one lucky run. We repeated the same scenario several times and looked for:

- whether the result stayed similar across repeated attempts;
- whether one version failed in the same way more than once;
- whether a mechanical change made software tuning easier instead of harder;
- whether the robot became easier to explain as a system, not only easier to drive once.

This was important because WRO rewards repeatable engineering, not only one successful demonstration.

## Why Mechanical and Software Testing Were Linked

The controller could only be tuned well if the mechanics were predictable.

For example:

- high steering friction made the software look weaker than it really was;
- front-wheel slip reduced the effect of a correct steering command;
- better grip and better steering symmetry made PD tuning easier and more repeatable.

So testing was not split into completely separate worlds. Software and mechanics influenced each other in every iteration.

## Main Conclusion

The final robot improved because both areas were tuned together:

- mechanics made the robot easier to control;
- software made the robot use the improved mechanics more effectively.

That combined testing process was one of the main reasons the final robot became more stable and more repeatable.

## Short Judge-Facing Summary

If we had to summarize our testing in one sentence, it would be:

> we selected the final robot version by comparing repeated runs and keeping the combination that reduced drift, reduced steering load, and made the controller more repeatable instead of simply more aggressive.
