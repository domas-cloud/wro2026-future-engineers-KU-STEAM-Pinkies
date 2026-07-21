# Drivetrain And Steering

Our robot uses rear-wheel drive, a mechanical rear differential, and servo-based front steering.

We chose that combination because it gave the best overall control on the field. The robot needed to turn cleanly, recover after turns, and stay predictable on straights.

## Motor Testing

Before choosing the final motor, we tested three `N20` options:

- `50 rpm`
- `250 rpm`
- `1000 rpm`

All three were small enough for the robot, but they behaved differently on the track.

### `50 rpm`

This option was too slow for the performance we wanted.

### `1000 rpm`

This option was faster, but its usable torque was weaker in practice.

### `250 rpm`

The `250 rpm` motor gave the best balance between speed and torque, so it became the final choice.

## Why The Motor Choice Mattered

For this robot, speed alone was not enough. It also needed predictable motion and reliable response during turning and correction.

| Motor option | Practical strength | Practical weakness | Final decision |
| --- | --- | --- | --- |
| `50 rpm` | easy to control slowly | too slow for our target driving speed | rejected |
| `250 rpm` | balanced speed and usable torque | normal tuning still required | selected |
| `1000 rpm` | high theoretical speed | less stable under load | rejected |

## Differential Choice

From earlier experience, we already knew that the rear axle needed a good differential. Without it, the robot became harder to turn and less predictable in corners.

In the final robot, we used a `LEGO` differential.

### Differential Comparison

![Metal differential version](images/metal-differential.jpg)

Earlier drivetrain version with the metal differential.

![LEGO differential version](images/lego-differential.png)

Final drivetrain version with the `LEGO` differential.

### Why The `LEGO` Differential Stayed

Compared with the earlier metal differential, the `LEGO` version gave:

- smoother cornering;
- less binding;
- more repeatable behavior between runs.

That made it the better choice for this robot, even if it looked simpler.

## Steering Overview

The steering is based on a servo-driven three-gear layout. The servo turns the center gear, and that motion is transferred symmetrically to the two steering sides.

We wanted the steering to be:

- smooth;
- repeatable;
- mechanically efficient;
- stable in straight driving.

## Steering Angle

The servo itself can rotate further, but on the robot we intentionally limit the useful steering range to about `60` degrees.

This was one of the most important trade-offs in the whole robot:

- more steering angle looked attractive in theory;
- too much angle reduced stability in practice.

So we kept the range that gave the most controlled driving.

## Why We Used `MG90S`

We selected an `MG90S` servo because it was compact, simple to integrate, and strong enough once the steering geometry was improved.

Instead of solving the problem by installing a heavier servo, we reduced steering resistance and improved the mechanism itself.

## Steering Iterations

The steering went through three main versions.

### Version 1

The first version used the same main idea, but the wheel support created a large lever arm. That made the servo work much harder than it should.

### Version 2

The biggest improvement from `V1` to `V2` was removing that bad lever arm. This made the steering much easier to move and lowered the servo load significantly.

### Version 3

The final version kept the improved geometry and added:

- bearings in the frame;
- custom silicone front wheels.

That combination improved grip, reduced friction, and made the steering more repeatable.

## Front And Rear Wheel Roles

We did not try to make every wheel do the same job.

### Front Wheels

The front axle needed grip, because the steering command only matters if the wheels actually follow it. After switching to silicone front wheels:

- slip decreased;
- steering effect increased;
- turning became more reliable.

### Rear Wheels

The rear axle needed stable drive transmission through the differential, so the rear setup stayed simpler and more focused on dependable traction.

## Straight-Driving Challenge

One of the main steering-related problems was straight driving. The robot could drift slightly to either side until the steering geometry, wheel grip, and differential behavior improved enough to work together.

The biggest improvements came from:

- better steering geometry;
- better front-wheel grip;
- better wheel mounting;
- a better differential.

## How We Compared Versions

We did not compare steering versions only by looking at them. We compared them by driving.

The most useful checks were:

- how much space the robot needed to complete a `90` degree turn;
- how much it drifted over a `3 m` straight drive.

## Mechanical Validation Matrix

| Mechanical area | Weak result | Acceptable result | Strong result |
| --- | --- | --- | --- |
| motor choice | robot too slow or obviously under torque stress | completes turns and straights reliably | keeps pace while remaining controllable |
| differential behavior | binding, rough corner exits, inconsistent wheel behavior | cornering works with minor resistance | smooth cornering with low resistance and repeatable exits |
| steering geometry | heavy servo load, visible sticking, poor symmetry | mostly usable with some correction cost | low resistance, symmetric response, stable straight driving |
| front-wheel grip | wheels slip before command is transferred | steering works with occasional slip | steering command translates directly into real movement |

## Testing Effort

We did about `10` practical comparison runs while deciding between the main mechanical versions.

The most important result was clear: the jump from steering `V1` to `V2` gave the largest improvement.

## Summary Table

| Element | Tested options | Final choice | Why |
| --- | --- | --- | --- |
| drive motor | `50 / 250 / 1000 rpm` `N20` | `250 rpm` `N20` | best balance of speed and torque |
| differential | earlier metal differential vs `LEGO` differential | `LEGO` differential | smoother and more repeatable turning |
| steering geometry | `V1`, `V2`, `V3` | `V3` | best precision, lowest resistance, best grip |
| front wheels | earlier wheels vs silicone wheels | silicone wheels | less slip, stronger steering effect |
| steering range | larger possible range vs limited useful range | about `60` degrees | better stability |

## Final Conclusion

The final drivetrain and steering system were chosen because they gave the best practical result on the field.

The biggest lessons were:

- the middle motor option was better than the extreme options;
- differential quality strongly affected turning precision;
- a larger steering angle was not automatically better;
- reducing steering load was more effective than simply choosing a stronger servo.
