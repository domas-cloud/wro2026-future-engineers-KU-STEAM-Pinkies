# PD Controller Explanation

## Why We Used PD Control

In our robot, the main navigation method is based on **PD control**. We chose this approach because we wanted steering that would be:

- simple enough to tune,
- smooth in normal driving,
- and adaptable to different track situations.

Instead of using many fixed turning commands, we wanted the robot to continuously correct its steering depending on how far it was from the target path.

## Main Idea

The PD controller uses the current driving error and the change of that error over time.

In simple words:

- **P (proportional)** tells us how far the robot is from the desired line,
- **D (derivative)** tells us how quickly that error is changing.

The steering output is then calculated from both of these terms.

## What the P Term Does

The proportional part reacts to the current error.

If the robot is far from the target line, the proportional term creates a larger steering correction. If the robot is already close to the target line, the correction becomes smaller.

This is the main reason the robot can move back toward the desired path instead of continuing to drift away from it.

## What the D Term Does

The derivative part reacts to how quickly the error is changing.

This is important because the robot does not only need to return to the line. It also needs to avoid overreacting.

Without the D term, the robot can become too aggressive and start oscillating left and right. The derivative term helps reduce that effect by damping the steering response.

## Why We Did Not Rely on P Only

Using only proportional control would make the robot simpler, but in practice it would often create more oscillation, especially during faster corrections or when exiting turns.

We wanted the steering to be more stable, so adding the derivative term was a practical improvement.

## Simplified Formula

The controller can be written in the simplified form:

`steering_output = Kp * error + Kd * error_change`

Where:

- `error` is the current offset from the target path,
- `error_change` is how much that error changed since the previous step,
- `Kp` is the proportional gain,
- `Kd` is the derivative gain.

## What Error Means in Our Robot

In our robot, the error represents how far the robot is from the path we want it to follow.

Under normal conditions, this path is the standard driving line. When we detect an obstacle, we do not replace the whole controller. Instead, we change the **target path** that the same PD controller follows.

This is one of the most important parts of our software design:

- the controller stays the same,
- but the reference line changes depending on the situation.

## How PD Fits Our Obstacle Strategy

When we detect a red or green obstacle, we change the lane target according to the correct passing side.

That means PD control still remains the main steering method. We do not switch to a completely separate obstacle controller. We only change the target that the PD controller tries to follow.

This gave us several benefits:

- smoother transitions,
- easier tuning,
- simpler software structure,
- and better repeatability.

## Practical Tuning Logic

When tuning the controller, we looked for the following behaviours:

### If Kp is too low
- the robot reacts too weakly,
- returns to the line too slowly,
- may drift too much.

### If Kp is too high
- the robot reacts too aggressively,
- steering becomes sharp,
- oscillation becomes more likely.

### If Kd is too low
- damping is too weak,
- corrections can become unstable,
- the robot may wobble after a turn.

### If Kd is too high
- steering can become too conservative,
- the robot may react too slowly,
- and turning can become less effective.

## Why PD Was a Good Choice for Us

We chose PD control because it matched our robot well.

Our robot needed a controller that was:

- clear enough to explain,
- effective enough for repeated autonomous runs,
- and flexible enough to work both in normal lane following and obstacle obedience.

PD control gave us exactly that balance.

## Final Conclusion

For us, PD control was not just a theoretical control method. It became the main steering principle of the whole robot.

The most important idea is simple:

**we keep the same controller, but we change the target path depending on the track situation.**

That made the software easier to tune, easier to document, and more stable in practice.
