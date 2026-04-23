# Safety And Failsafes

The safety goal is simple: the robot should not keep driving when the basic control assumptions are no longer trustworthy.

## Main Safety Priorities

Our priorities were:

1. do not move before the system is ready;
2. do not trust clearly bad sensor data;
3. keep steering inside a safe mechanical range;
4. stop cleanly when the run is finished.

## Startup Safety

Startup is treated as critical. If any main sensor fails to initialize, the robot halts in `while(1)`.

That applies to:

- `frontSensor`
- `leftSensor`
- `rightSensor`
- `robotCompass`

So the robot never starts a run with missing core sensors.

## Sensor Trust Windows

The code already uses a few simple validity windows:

- side-distance correction is used only in a limited range;
- front distance decides when the robot should enter the turn routine;
- steering is always clamped to the allowed servo range.

These are simple checks, but they matter. They stop random raw readings from being treated as equally reliable all the time.

## Main Failure Cases

### Bad Heading Data

If the yaw reading is wrong, heading correction becomes wrong immediately. That means the robot should never depend blindly on unstable heading data.

### Bad Side-Distance Data

If the side reading is outside the trusted range, the wall correction should not dominate the steering.

### Bad Front-Distance Timing

The front sensor is especially important because it can switch the robot from normal control into a forced turn. If that trigger happens at the wrong time, the whole motion changes.

### Steering Saturation

Even if the computed steering grows large, the servo command is clamped. That protects the mechanics from impossible commands.

## What Is Already Visible In Code

The code already includes these practical protections:

- no driving while `started == false`;
- halt on startup if a critical sensor fails;
- limited side-distance correction window;
- constrained servo output;
- stop and restart after the finish condition.

## Camera-Layer Safety

If the perception layer shifts the driving line, the same principle should stay in place:

- the camera may suggest a line;
- the `ESP32` should still decide whether it is safe to execute.

So stale or low-confidence perception should never bypass the local controller safeguards.

## Practical Safety Checks

Useful checks for this robot are:

- confirm the motor stays off before the start button is pressed;
- confirm the robot halts if a main sensor fails at startup;
- confirm the steering stays inside the intended range;
- confirm noisy front readings do not create obviously unstable turning;
- confirm bad side readings do not dominate steering.

## Summary

The safety model is intentionally modest:

- no start before the system is ready;
- no trust in obviously bad readings;
- no steering outside the allowed range;
- no endless driving after the run is complete.
