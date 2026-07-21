# Hardware V2: Faster Drive Motor Plan

## Goal

Increase vehicle speed without losing the repeatability that the current 250 rpm motor provided. The new motor must be selected from measured robot performance, not from rpm alone.

## Why the previous decision is being reopened

Hardware V1 selected the N20 6 V 250 rpm motor because it was the best balance among the tested 50, 250 and 1000 rpm options. Hardware V2 changes the electrical architecture and creates an opportunity to use a stronger motor driver, cleaner power distribution and a motor that provides more usable speed under load.

This does not make the old choice wrong. It creates a new design point with different constraints.

## Candidate data required

For every candidate motor record:

- manufacturer and exact model;
- rated voltage;
- no-load rpm;
- no-load current;
- rated current and torque, if published;
- stall current and stall torque;
- gearbox ratio;
- mass;
- shaft diameter and mounting dimensions;
- wheel diameter used in the test;
- measured loaded speed on the actual robot.

## Speed calculation

Estimate theoretical linear speed using:

`vehicle speed = motor output rpm × wheel circumference / 60`

This is only a starting estimate. Real speed must be measured because gearbox losses, battery sag, wheel slip, robot mass and cornering load reduce the usable result.

## Test matrix

| Test | What to record | Acceptance direction |
|---|---|---|
| free-wheel test | rpm/current with axle lifted | confirms wiring and approximate speed |
| launch test | peak current and time to stable speed | no brownout, no uncontrolled wheelspin |
| 3 m straight | time, drift and controller correction | faster than V1 without major drift increase |
| repeated 90 degree turns | overshoot, recovery time and motor temperature | controllable corner exit |
| three-lap run | completion rate and total time | faster median time with acceptable reliability |
| blocked/stall protection | driver response and current limit | no PCB or wiring damage |
| battery sag | minimum battery and logic rail voltage | logic remains stable during peaks |

## Selection rule

Do not choose the candidate with the highest unloaded rpm. Choose the fastest candidate that:

- completes repeated turns without unstable overshoot;
- remains inside the motor-driver and battery current limits;
- does not cause controller resets or sensor dropouts;
- maintains reliable three-lap completion;
- fits the chassis and weight budget;
- leaves tuning margin for both Open and Obstacle challenges.

## Software consequences

A faster motor will require retesting:

- PWM operating range and acceleration ramp;
- turn-trigger distance;
- steering gains;
- derivative filtering;
- obstacle reaction distance;
- braking or coast behaviour;
- finish-section stopping logic;
- stale-camera-data fallback at the higher approach speed.

## Mechanical consequences

Check:

- differential and gear durability;
- shaft coupler and wheel retention;
- rear-wheel grip and slip;
- chassis vibration;
- steering response at higher speed;
- stopping distance;
- mass distribution and rollover tendency.

## Final evidence table

The final documentation should contain a table comparing Hardware V1 and each serious Hardware V2 candidate with measured current, loaded straight speed, lap time, corner overshoot, temperature and successful-run rate.
