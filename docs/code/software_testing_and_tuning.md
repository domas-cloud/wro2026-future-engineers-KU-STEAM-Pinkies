# Software Testing and Tuning

## Why Software Testing Was Important for Us

Our software was not finished in one version. We improved it step by step by watching how the robot behaved on the track and then changing the control logic when the result was not stable enough.

For us, software testing was closely connected to mechanical testing. A controller can look correct in theory, but the real question is whether the robot drives well on the actual field.

## What We Wanted from the Software

When testing software, we mainly wanted the robot to be:

- stable in straight driving,
- smooth in turning,
- reliable in obstacle obedience,
- and repeatable over multiple runs.

We were not looking only for one fast attempt. We wanted behaviour that stayed understandable and controllable over repeated runs.

## Main Tuning Philosophy

Our most important software decision was to keep **one main navigation principle**:

- PD line following stays the base behaviour,
- obstacle information changes the target path,
- but the main controller remains the same.

This made tuning easier because we did not need to tune many disconnected controllers. Instead, we could improve one main control method and then observe how it behaved in different situations.

## What We Observed During Testing

When we tested the software, we paid attention to practical driving behaviour, such as:

- whether the robot returned to the target line smoothly,
- whether it oscillated too much,
- whether it turned too weakly or too aggressively,
- whether obstacle transitions were smooth,
- and whether the robot stayed predictable over repeated runs.

## PD Tuning Logic

### If the robot reacted too weakly
That usually meant the steering correction was not strong enough. In this type of situation, the robot could stay away from the target path for too long.

### If the robot reacted too aggressively
That usually meant the steering became too sharp and the robot could start oscillating left and right.

### If the robot recovered badly after a turn
That usually meant the damping effect was not good enough, and the steering response needed to become smoother.

These observations helped us understand whether the controller needed stronger proportional response or better damping.

## Why Obstacle Logic Was Easier to Tune This Way

Because we kept the same main controller and only changed the target path, obstacle behaviour became easier to tune than if we had used a completely separate obstacle routine.

This gave us several practical advantages:

- fewer abrupt transitions,
- easier debugging,
- more understandable behaviour,
- and a clearer connection between normal driving and obstacle driving.

## Split Architecture and Testing

Our split architecture also helped the tuning process.

- The **Pi Zero** handled perception,
- the **ESP32** handled control and final actuation.

This made it easier for us to think about the system in two layers:

1. is the perception result correct?
2. is the control reaction correct?

That separation made debugging and tuning more structured.

## What a Better Software Version Meant for Us

When we said that a software version was better, we did not mean only that it worked once.

For us, a better version meant that the robot:

- followed the path more smoothly,
- reacted more predictably,
- handled obstacle situations with less instability,
- and stayed easier to tune after other changes.

## Relation Between Software and Mechanics

One important lesson from testing was that software and mechanics had to support each other.

For example, if the steering mechanics had too much friction or if the front wheels slipped, the controller could not behave as well as expected. That means software tuning only became truly effective after the mechanics became more repeatable.

Because of that, we treated software testing and mechanical testing as connected parts of the same engineering process.

## What Should Still Be Added from the Final Code

This documentation explains our tuning logic clearly, but it can still be improved further by inserting the final code-specific details such as:

- the actual variable name used for the line error,
- the actual variable names for `Kp` and `Kd`,
- the exact module or file where steering output is calculated,
- and the exact obstacle-decision function names.

Once those names are inserted, this section will match the real implementation even more strongly.

## Final Conclusion

Software testing helped us keep the robot understandable and stable.

Instead of creating many separate behaviours, we focused on improving one main navigation idea and tuning it until the robot became smoother, more repeatable, and easier to control.

For us, that was one of the most important reasons why the final software became stronger than the earlier versions.
