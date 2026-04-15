# PD Controller Explanation

## Where the PD Controller Appears in Code

Our real low-level controller is visible in `src/src/main.cpp`.

Main variables:

- `Kp`
- `Kd`
- `last_error`
- `last_time`
- `error`
- `derivative_delta`
- `turning_angle`
- `final_servo_angle`
- `STRAIGHT_ANGLE`

The implemented formula is:

```text
turning_angle = STRAIGHT_ANGLE + Kp * error + Kd * derivative_delta
```

and the final steering command is limited with:

```text
final_servo_angle = constrain(turning_angle, STRAIGHT_ANGLE - 45, STRAIGHT_ANGLE + 45)
```

## What the Error Means on Our Robot

In our current `ESP32` implementation, the robot estimates the corridor width and its own lateral position using two `VL53L5CX` sensors plus heading compensation from the `BNO085`.

The key calculations are:

```text
width = (SENSOR_DISTANCE[0] + SENSOR_DISTANCE[1]) * cos(rad_angle)
track = get_dominant_cluster_average(buffer_size, track_buffer, 20)
distance = SENSOR_DISTANCE[0] * cos(rad_angle)
error = track / 2 - distance
```

So in this robot, `error` means:

- how far the robot is from the desired center of the measured corridor;
- after compensating for heading angle with `cos(rad_angle)`.

If `error` is close to zero, the robot is near the intended center. If `error` becomes larger in magnitude, the robot has drifted away from that target line.

## What P Does

The proportional part is `Kp * error`.

Its job is simple:

- if the robot is far from the target line, steering correction should be larger;
- if the robot is close to the target line, correction should be smaller.

This is the main steering force that pushes the robot back toward the desired path.

## What D Does

The derivative part is `Kd * derivative_delta`, where:

```text
derivative_delta = (error - last_error) / delta_t
```

Its job is to react to how quickly the error is changing.

- if the robot is moving away from the target very quickly, the derivative term increases the correction;
- if the robot is already correcting too fast, the derivative term can damp the movement and reduce oscillation.

In our current file, `Kd = 0`, so the visible implementation is effectively using only the proportional part at the moment. The code structure is still PD-ready because we already have the derivative calculation and variable names in place.

## Why We Chose PD Instead of a Simpler Method

A simple fixed steering rule is easier to write, but weaker in practice.

We chose the PD structure because it gives:

- continuous correction instead of fixed-angle maneuvers;
- better stability when the robot approaches the wall or target line at different offsets;
- a cleaner path to tuning than many hard-coded cases.

Even when the derivative term is small or temporarily zero, the PD structure is still valuable because it keeps the controller logic consistent and makes it easy to add damping when the mechanics become more responsive.

## What Too Large or Too Small Kp Means

If `Kp` is too small:

- the robot reacts too weakly;
- it drifts longer before returning to the target line;
- turns look lazy and late;
- recovery after disturbance is slow.

If `Kp` is too large:

- the robot oversteers;
- it can wobble from side to side;
- it may overshoot the target line;
- steering becomes nervous and less repeatable.

## What Too Large or Too Small Kd Means

If `Kd` is too small:

- oscillation is less controlled;
- the robot may keep swinging after a correction;
- fast approaches to the target line are less damped.

If `Kd` is too large:

- steering can feel hesitant or overly damped;
- the robot may resist turning enough;
- noise in the error signal can create unstable correction spikes.

Because derivative action reacts to change, it is especially sensitive to noisy measurements and inconsistent mechanics.

## How Steering Output Is Produced

The full steering path in our current code is:

1. Read `SENSOR_DISTANCE[0]` and `SENSOR_DISTANCE[1]`.
2. Read `newHeading = robotCompass.getYaw()`.
3. Compute heading difference `angle = targetAngle - newHeading`.
4. Estimate the corrected corridor width in `width`.
5. Filter repeated width estimates into `track`.
6. Estimate lateral position as `distance`.
7. Compute `error = track / 2 - distance`.
8. Compute `derivative_delta`.
9. Compute `turning_angle = STRAIGHT_ANGLE + Kp * error + Kd * derivative_delta`.
10. Clamp to `final_servo_angle`.
11. Send to `myservo.write(final_servo_angle)`.

## Relation to Obstacle Avoidance

The most important software idea in our project is that we do not want obstacle logic to become a completely separate steering controller. Instead, we let obstacle logic change the target path that the same controller follows.

In practical terms, this means the PD controller stays the same:

- the meaning of `error` stays "distance from the current target line";
- obstacle color changes where that target line should be.

So the steering law does not need to switch to a completely different mode. The same PD structure can still generate the steering angle, but from a shifted target.

This is better than fixed obstacle maneuvers because the robot still adapts to its real position and heading. If it approaches the obstacle with a slightly different angle, the controller still computes a continuous correction instead of replaying the same rigid turn every time.
