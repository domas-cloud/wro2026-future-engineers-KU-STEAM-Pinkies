# Software Testing and Tuning

## Why Software Testing Mattered

We did not treat software as something that can be judged only by reading code. We evaluated it by what the robot actually did on the track.

The main software question was always:

- does the robot return to the target line smoothly and repeatably?

That is more useful than asking whether the algorithm looks complicated.

## What We Tested

We focused on the behaviors that were most visible during driving:

- straight tracking stability;
- how quickly the robot returned to the target line;
- whether steering oscillated or wobble appeared;
- whether the robot oversteered after a correction;
- whether obstacle transitions were smooth;
- whether the robot returned cleanly to the normal target after an obstacle;
- whether software remained stable when mechanics were imperfect.

## Real Software References Used During Tuning

Our current low-level tuning references in code are in `src/src/main.cpp`:

- `Kp`
- `Kd`
- `last_error`
- `derivative_delta`
- `turning_angle`
- `final_servo_angle`
- `track_buffer`
- `get_dominant_cluster_average(...)`

Useful sensor-side references:

- `SENSOR_DISTANCE[0]`
- `SENSOR_DISTANCE[1]`
- `target_status[...]` checks in `src/lib/Lidar/Lidar.cpp`

Useful debug output:

```text
Serial.printf("Proportional: %.2f | Error: %.2f | Derivative: %.2f | Angle: %.2f | Width: %.2f \n", ...)
```

This is important because we tuned best when we observed actual `error`, proportional contribution, derivative contribution, and final steering angle instead of relying only on visual impressions.

## How We Judged Whether the Controller Was Good

We used simple practical criteria.

### Good behavior

- the robot stays near the target line;
- corrections are smooth;
- it returns after a disturbance without large overshoot;
- steering does not keep swinging after the first correction;
- obstacle passing transitions do not create a second unnecessary turn.

### Bad behavior

- visible wobble on straights;
- late return to the target line;
- strong overshoot after each correction;
- repeated servo saturation near the steering limit;
- unstable behavior when a sensor reading is briefly poor.

## How We Tuned PD

Our tuning logic was iterative:

1. Start from a safe and conservative steering gain.
2. Increase `Kp` until the robot returns to the target line fast enough.
3. Stop increasing `Kp` when wobble or oversteer becomes visible.
4. Add or reserve `Kd` only if the robot needs more damping.
5. Re-test after any mechanical change because software and mechanics are strongly linked.

This matters because our controller can look weak only because the front wheels slip, the steering sticks, or the geometry is asymmetric.

## How We Recognized Aggressive vs Weak Tuning

### Too aggressive

We judged the controller as too aggressive when:

- the robot oscillated around the target line;
- the front wheels made large visible corrections;
- after one correction the robot immediately needed a correction in the opposite direction;
- steering hit its allowed range too often.

### Too weak

We judged the controller as too weak when:

- the robot drifted for too long before correcting;
- it stayed off-center after a disturbance;
- turns and recovery looked delayed;
- obstacle-shifted path following looked too slow to re-center.

## How We Evaluated Obstacle Transitions

In the final architecture, obstacle handling is judged by transition quality, not only by "did it miss the obstacle".

The main criteria are:

- does the robot shift target path early enough;
- is the shift smooth rather than a sudden snap turn;
- does it clear the obstacle without scraping the wall;
- does it return to the normal line cleanly after the pass.

This is one reason we preferred target shifting inside the same controller instead of fixed maneuvers.

## Edge Cases We Considered

### Unclear obstacle detection

If obstacle meaning is uncertain, the safer behavior is to avoid rapid switching between left and right interpretations.

### Lost line or weak corridor estimate

The robot should reduce speed or enter recovery instead of continuing with blind aggressive steering.

### Too close to the wall

Collision avoidance must temporarily become more important than ideal line centering.

### Steering output too large

Our current code already limits output with `constrain(...)`, which prevents impossible commands and helps show when the controller has left its comfortable region.

### Pre-parking transition

Before parking, the robot should stop behaving like it is still optimizing lap speed. Stable final positioning becomes more important than aggressive correction.

## Metrics and Practical Evaluation Criteria

We did not rely on laboratory-grade metrics, but we still used clear evaluation criteria:

- wobble present or not present;
- return to target line fast or slow;
- overshoot strong or mild;
- obstacle pass smooth or abrupt;
- after-turn recovery stable or unstable;
- steering angle frequently saturated or mostly within comfortable range.

These are simple metrics, but they are directly relevant to WRO driving quality.

## Relation Between Software and Mechanics

Software tuning was never independent from the mechanical system.

The controller depended strongly on:

- steering friction;
- front-wheel grip;
- symmetry of left-right steering;
- differential smoothness;
- sensor mounting stability.

This means a gain value that works on one mechanical version may become wrong after changing wheels, steering geometry, or grip.

## What Improved After Tuning and Iteration

The main improvements were:

- cleaner return toward the target line;
- less visible oscillation;
- more repeatable steering response;
- easier recovery from small disturbances;
- better match between actuator command and actual vehicle movement.

The biggest software lesson was that good tuning is not only about finding larger or smaller gains. It is about matching the controller to the real mechanical behavior of the robot.
