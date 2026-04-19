# Mechanical and Software Testing

## Why This Section Matters

Our development process depended on repeated testing of the whole robot, not only isolated parts. Mechanical changes often changed software behavior, and software tuning often revealed mechanical weaknesses.

For that reason, we tested the robot as one connected system.

This file is written in a judge-facing way. The goal is to show:

- what we compared;
- how we judged one version against another;
- which criteria mattered in competition-like conditions;
- why the final version was selected.

## Testing Philosophy

We did not accept a version just because it completed one successful run.

For important decisions, we looked for:

- repeated behavior across multiple runs;
- lower drift, not only higher aggressiveness;
- easier tuning after a mechanical change;
- fewer failure patterns that repeated in the same way.

That approach fits WRO well because the competition rewards reproducible engineering, not one lucky attempt.

## Main Test Categories

| Test category | What we were checking | Why it mattered |
| --- | --- | --- |
| motor comparison | speed versus usable torque | the robot needed both movement and controllability |
| steering geometry comparison | servo load, turning quality, straight driving | weak steering mechanics make all later tuning worse |
| wheel-grip comparison | whether the front wheels really followed the steering command | slipping reduces the value of good control logic |
| differential comparison | cornering resistance and smoothness | poor rear-wheel behavior makes turns less repeatable |
| sensor-mounting checks | heading stability and short-range sensing consistency | unstable sensing makes tuning misleading |

## Mechanical Testing Summary

The main mechanical comparison areas were:

- `300 rpm`, `600 rpm`, and `1000 rpm` `N20` motors;
- steering `Version 1`, `Version 2`, and `Version 3`;
- earlier front wheels versus silicone front wheels;
- earlier differential solution versus the final `LEGO` differential.

For the differential comparison specifically, the key practical result was clear: the `LEGO` differential was more stable than the earlier metal differential.

Main practical criteria:

- space needed for a 90-degree turn;
- drift over a 3-meter straight drive;
- steering smoothness;
- repeatability between runs.

## Repeated Comparison Method

For major comparisons, we reused the same evaluation pattern:

1. prepare one version of the robot or one changed subsystem;
2. run the same basic scenario several times;
3. observe whether the same weakness appears again;
4. compare the result to the previous version using the same criteria;
5. keep the version that improved repeatability, not only peak behavior.

We documented the steering comparison especially carefully. In that area, we performed about `10` practical comparison runs while deciding between major versions.

## Comparison Table Used For Final Selection

The ratings below are not laboratory measurements. They are condensed engineering observations from repeated side-by-side testing under the same goals.

| Comparison area | Earlier version | Final version | What changed in practice |
| --- | --- | --- | --- |
| motor choice | `300 rpm` or `1000 rpm` options | `600 rpm` N20 | better balance of usable speed and torque |
| steering geometry | Version 1 with larger lever arm | Version 2/3 with reduced load | servo load dropped and steering became more repeatable |
| front wheel material | earlier wheels with more slip | silicone front wheels | stronger real steering effect on the floor |
| rear differential | earlier less suitable differential solution | `LEGO` differential | smoother cornering and less binding |
| sensor mounting | less rigid IMU / less refined placement | rigid IMU plus cleaner sensor layout | heading estimate and repeated behavior became more stable |

### Differential Comparison Evidence

![Metal differential version](../design/images/metal-differential.jpg)

Earlier version with the metal differential.

![LEGO differential version](../design/images/lego-differential.png)

Final version with the LEGO differential that gave the more stable result in repeated testing.

## What Counted As A Better Version

For us, a version was considered better if it improved several of these at once:

- lower drift on straight driving;
- less visible steering overload;
- more stable return after a turn;
- smoother cornering;
- fewer repeated failures in the same scenario;
- easier tuning after installation.

This matters because some changes can improve one behavior while making the robot harder to control overall. We kept only the changes that improved the system as a whole.

## Software Testing Summary

We judged the software side by what the robot actually did on track:

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

We used simple but competition-relevant criteria:

- wobble present or not;
- correction too weak or too aggressive;
- stable return to target line or repeated overshoot;
- smooth obstacle pass or abrupt path change;
- stable recovery after a turn or disturbance.

These criteria were practical because they directly matched what we wanted on the track.

## Why Mechanical and Software Testing Were Linked

The controller could only be tuned well if the mechanics were predictable.

For example:

- high steering friction made the software look weaker than it really was;
- front-wheel slip reduced the effect of a correct steering command;
- better grip and better steering symmetry made PD tuning easier and more repeatable.

So testing was not split into completely separate worlds. Software and mechanics influenced each other in every iteration.

## Judge-Facing Evidence Summary

If a judge wants the short testing conclusion, it is this:

- the final motor was chosen because it gave the best speed-torque balance in practical use;
- the steering geometry was kept only after repeatability improved and servo load dropped;
- the silicone front wheels were kept because they improved real steering effect on the floor;
- the `LEGO` differential was kept because it was more stable than the metal differential, and turning became smoother and less resistant;
- the final robot was selected through repeated comparison, not by one successful run.

## Main Conclusion

The final robot improved because both areas were tuned together:

- mechanics made the robot easier to control;
- software made the robot use the improved mechanics more effectively.

That combined testing process was one of the main reasons the final robot became more stable and more repeatable.
