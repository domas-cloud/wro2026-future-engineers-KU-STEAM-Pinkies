# Navigation Strategy

## Core Idea

We built our navigation strategy around one main principle:

- keep one continuous steering controller;
- change the target path when the situation changes.

This is stronger than using a different hard-coded maneuver for each case because the robot can still adapt to its actual position and heading.

## What Is Already Visible in Code

Our repository already shows the low-level version of this idea in `src/src/main.cpp`.

Real variables and functions:

- `read_lidar_data()`
- `robotCompass.getYaw()`
- `track_buffer`
- `get_dominant_cluster_average(...)`
- `error`
- `Kp`
- `Kd`
- `final_servo_angle`
- `engine.drive(255)`
- `myservo.write(final_servo_angle)`

At the moment, our code implements corridor-centering with ToF and IMU data. The same control structure is the base for our wider final navigation architecture.

## Normal Line Following

In normal conditions, the robot tries to stay on the default target path through the drivable corridor.

In the current `ESP32` implementation, that target is the center of the measured corridor:

```text
error = track / 2 - distance
```

where:

- `track` is the filtered estimate of corridor width;
- `distance` is the measured robot position relative to one side.

The steering command is then calculated from this error with the PD equation.

## How the Target Line Is Calculated

The implemented low-level target calculation is:

1. read left and right distances into `SENSOR_DISTANCE[0]` and `SENSOR_DISTANCE[1]`;
2. compensate for heading using `rad_angle = radians(angle)`;
3. compute the current width estimate in `width`;
4. store repeated width estimates in `track_buffer`;
5. use `get_dominant_cluster_average(...)` to obtain `track`;
6. define the nominal target as the center of that corridor, `track / 2`.

This is useful because it avoids reacting to one noisy reading and instead follows the dominant stable width measurement.

## Obstacle Strategy

In our final architecture, obstacle handling follows the same controller idea.

Sequence:

1. the `Pi Zero` detects an object ahead;
2. the object is classified as red or green;
3. color determines which passing side is legal;
4. the target path is shifted left or right;
5. the same PD controller follows this new target;
6. after the obstacle is cleared, the target path returns to normal.

## How Red and Green Change the Target

- a `red` obstacle shifts the target path so the robot passes on the required side;
- a `green` obstacle shifts the target in the opposite direction.

The important point is not the color alone. The important point is that color changes the reference path, not the whole steering algorithm.

## Why This Is Better Than Fixed Maneuvers

We considered the alternative of using fixed obstacle turns, but we decided that approach was weaker because:

- the robot will not always approach from the same angle;
- the robot may already be slightly offset before the obstacle;
- fixed turns are harder to tune across different field layouts.

A target-shift approach is better because the controller still uses real-time error feedback. The robot adapts to where it actually is, not where we assumed it would be.

## Why Obstacle Logic Is Not a Separate Controller

We deliberately treat obstacle logic as a target modification inside the same steering framework.

That gives several engineering benefits:

- smoother transitions;
- less mode switching;
- easier tuning because one controller remains active;
- easier explanation in documentation;
- easier recovery after the obstacle because the robot simply returns to the normal target.

If obstacle logic became a fully separate controller, we would need to re-tune two unrelated behaviors and also manage unstable switching between them.

## Short Detection-to-Steering Sequence

```text
camera / sensors
  -> detect line and obstacle
  -> choose normal or shifted target path
  -> calculate error from target path
  -> PD steering correction
  -> servo angle and drive output
  -> repeat
```

## Relation to the Current Repository State

Our current repository contains the low-level centering controller and its real code references. We describe the camera-side obstacle classifier architecturally, but we do not yet include it as source code in this repository. For documentation quality, we should explain that clearly instead of pretending the missing modules are already visible in code.
