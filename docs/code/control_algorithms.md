# Control Algorithms

This file describes the low-level steering and turn logic that can be seen in `src/src/main.cpp`.

## Main Idea

The controller keeps two things under control at the same time:

- the heading reference;
- the side distance to the wall or boundary.

That steering command is built from three terms:

- `Kg * heading`
- `Kp * dist_err`
- `Kd * derivative`

In simplified form:

```text
angle = Kg * heading
angle += Kp * dist_err
angle -= Kd * err_rate
servo = constrain(STRAIGHT_ANGLE + round(angle), MIN_ANGLE, MAX_ANGLE)
```

## Inputs Used By The Controller

### Yaw

The compass gives the current yaw. The controller compares it with `targetAngle`, which is the reference direction for the current sector.

### Front Distance

The front sensor decides when the robot should leave straight control and start a hard turn.

### Side Distance

The side sensors provide the wall-distance correction used to keep the robot near `TARGET_DISTANCE`.

## Normal Driving

During a straight segment, the controller:

1. reads yaw and distance sensors;
2. computes heading error;
3. adds side-distance correction;
4. adds damping;
5. clamps the result into the allowed servo range.

So the robot behaves like a heading-guided wall follower, not like a purely visual line follower.

## Corner Handling

When the front sensor reaches `TURN_DISTANCE`, the robot switches into a different mode:

1. decide turn direction;
2. force the steering to one extreme;
3. stay in the turn loop until open space appears again;
4. rotate `targetAngle` by `90` degrees;
5. increment `edge`.

This is the key structural split in the controller:

- continuous correction on straights;
- discrete hard turns at corners.

## Where Camera Guidance Fits

If the perception layer changes the driving line, it should do it by shifting the reference line, not by replacing the low-level controller.

That means:

- the camera decides which line should be followed;
- the low-level controller still does heading hold, side-distance correction, and corner execution.

## Obstacle Rule

For obstacle driving, the high-level rule is direct:

- `red pillar -> pass right`
- `green pillar -> pass left`

The clean way to connect that with the current controller is:

- perception identifies the pillar color;
- the color decides the legal side;
- the reference line shifts accordingly;
- the same low-level controller executes that line.

## Important Current Detail

There is one implementation detail worth documenting honestly: the code currently measures `rightDistance`, but the distance-correction branch still uses `leftDistance` in both cases.

So the controller is closest to a left-wall-based regulator in its present form, even though the intended logic suggests a wider use of both side sensors.
