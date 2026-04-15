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
