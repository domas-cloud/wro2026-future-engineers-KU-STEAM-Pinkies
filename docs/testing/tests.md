# Testing Workflow

This file explains how we test the robot, how we decide that a version is stable, and how we connect each change to a measured result.

The goal is not to collect random test runs. The goal is to make sure that each accepted version is repeatable on competition-like tasks.

## Test Environment

We use a physical track setup close to the WRO Future Engineers conditions and keep the setup as similar as possible between comparisons.

For each structured test session, we record:

- date;
- software version or branch name;
- mechanical version if hardware changed;
- battery condition;
- track layout used;
- challenge mode: open challenge or obstacle challenge;
- short note about lighting or surface conditions if they changed.

## General Workflow

We use the same decision flow for both challenge types:

1. make one meaningful change in hardware, tuning, or software;
2. define the scenario that should improve;
3. run the same scenario repeatedly;
4. record passes, failures, and visible behavior;
5. compare the result against the previous stable version;
6. keep the new version only if it improves repeatability, not just one best run.

## Open Challenge Testing

For open challenge testing, we focus on stable lane following, heading control, and smooth repeated laps.

### Open Challenge Setup

- standard open track layout;
- same start position for each repetition;
- same battery condition for comparison runs;
- repeated lap pattern with no manual intervention.

### Open Challenge Metrics

- straight-drive drift;
- heading stability after turns;
- lap completion consistency;
- visible wobble or steering oscillation;
- recovery quality after a small disturbance;
- clean-run count out of total repetitions.

### Open Challenge Repetitions

For a structured comparison, we usually run at least `5` repetitions per version on the same layout.

If the result is close or uncertain, we extend the comparison to `10` runs before making a final decision.

### Open Challenge Fail Criteria

A run is marked as failed if one or more of these happen:

- the robot leaves the intended lane or wall offset in a way that would likely lose points;
- the robot shows repeated strong wobble;
- the robot cannot recover after a turn;
- the robot stops, stalls, or requires manual correction;
- the behavior is clearly worse than the current stable version.

### Open Challenge Pass Criteria

A version passes open challenge validation when:

- most runs are clean and repeatable;
- straight sections show low drift;
- turns are smooth and consistent;
- recovery after minor disturbance is acceptable;
- the result is at least as stable as the previous version and preferably better.

## Obstacle Challenge Testing

For obstacle challenge testing, we focus on obstacle approach, path choice, clearance, and recovery after obstacle-related corrections.

### Obstacle Challenge Setup

- obstacle layout placed on the practice track;
- same obstacle positions during one comparison block;
- same start position and driving direction for repeated runs;
- repeated runs without changing tuning between attempts.

### Obstacle Challenge Metrics

- clean pass rate through the obstacle section;
- wall or obstacle clearance margin;
- late-correction frequency;
- alignment quality after passing an obstacle;
- full-route completion count;
- number of interventions or resets.

### Obstacle Challenge Repetitions

For obstacle comparisons, we normally use at least `5` repetitions on the same layout.

If one version fails in a way that repeats, we usually reject it immediately and record the reason. If two versions are close, we increase the run count.

### Obstacle Challenge Fail Criteria

A run is marked as failed if:

- the robot touches or would realistically hit an obstacle;
- obstacle avoidance starts too late and creates an unstable path;
- the robot loses alignment after the obstacle and cannot recover;
- a full route cannot be completed;
- the behavior repeats the same weakness across several runs.

### Obstacle Challenge Pass Criteria

A version passes obstacle validation when:

- obstacle sections are completed cleanly in repeated runs;
- the robot keeps usable clearance and path control;
- the robot returns to a stable line after the obstacle;
- failures are rare and not systematic;
- the version performs at least as well as the previous stable version.

## Acceptance Criteria For A New Version

We accept a new version only if all of these are true:

- it solves the target problem or makes it clearly smaller;
- it does not create a new repeated failure in another part of the run;
- it matches or improves the clean-run rate of the previous stable version;
- the result is repeatable across several runs in the same setup;
- the team can explain why the version is better using notes, measurements, or video evidence.

## When We Mark A Version As Stable

We mark a version as `stable` when:

- it passes both the relevant open challenge and obstacle challenge checks for that change;
- it behaves consistently across repeated runs;
- no major new failure appears during the same test session;
- the team agrees that the version is safer to continue building on than the previous one.

A stable version becomes the new comparison baseline for later tests.

## Change To Result Logging

Each meaningful change should be recorded in a simple change-to-result note.

We keep the log in a practical format with:

- version identifier;
- change summary;
- reason for the change;
- test scenario used;
- number of repetitions;
- pass/fail count;
- main observed metrics;
- decision: rejected, needs more testing, or stable;
- link to photo, video, or related document if available.

## Version Notes Template

We use the following lightweight structure for version notes:

| Field | Example |
| --- | --- |
| version | `v0.8-steering-v2` |
| change | corrected steering geometry |
| challenge tested | open + obstacle |
| repetitions | `5` open, `5` obstacle |
| result | `4/5` clean obstacle runs, lower drift on open track |
| main issue seen | one late correction near second obstacle |
| decision | stable |

## Judge-Facing Summary

Our testing workflow is based on repeatability.

We do not call a version better because of one impressive run. We call it better only when the same improvement appears several times under the same track conditions and does not reduce performance in another important scenario.
