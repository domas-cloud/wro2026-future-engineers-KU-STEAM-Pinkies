# Track Testing

Track tests record real runs under conditions similar to competition.

Our track testing was not only a final demonstration stage. It was the place where we decided whether a version was actually better.

## What We Checked On Track

- lane-following consistency;
- behavior while handling obstacles;
- steering stability in turns;
- repeatability across multiple runs;
- `MG90S` return-to-center behavior;
- repeatable acceleration from the `N20` and `L298N`;
- useful readings from the distance sensors near obstacles and reflective surfaces;
- the effect of the `BNO085` on heading stability after several turns.

## Core Track-Test Scenarios

| Scenario | Main thing we checked | Why it mattered |
| --- | --- | --- |
| straight section | drift and heading stability | straight driving is one of the easiest ways to see steering asymmetry |
| repeated corner entry | steering smoothness and return after turning | weak steering or poor differential behavior becomes visible quickly |
| obstacle approach | whether the robot keeps a usable path near an obstacle | this tests sensing and path behavior together |
| repeated lap pattern | whether one good run can be repeated | WRO performance must be repeatable, not accidental |
| disturbed or imperfect run | whether the robot recovers after a correction | recovery quality is often more important than ideal-case behavior |

## What Counted As A Good Track Result

A track result was considered good if it showed:

- low visible wobble;
- small straight-line drift compared to older versions;
- smooth turning without obvious binding;
- no repeated front-wheel slipping;
- stable return after a correction;
- similar behavior across repeated attempts.

## How We Recorded The Result

For each important track test, we tried to keep at least these notes:

- track description or scenario type;
- number of repetitions;
- what improved or failed;
- which subsystem probably caused the observed behavior;
- a photo or video reference, if available.

## Why Track Testing Was Important

Some versions looked acceptable on the workbench but became clearly worse on the track.

For example:

- a steering design could move, but still overload the servo during repeated turns;
- a sensor placement could work once, but become inconsistent near reflective or awkward geometry;
- a controller could look sharp, but become less repeatable over several runs.

This is why competition-like testing mattered more than appearance.

## Judge-Facing Summary

Our track tests were mainly used to answer one question:

> does this version make the robot more repeatable on the real field?

If the answer was no, we did not keep that version even if it looked promising in theory.
