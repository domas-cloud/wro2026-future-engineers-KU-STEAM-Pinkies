# Engineering Decisions

These were the main trade-offs that shaped the final robot.

## The Main Idea

During development, the best solution was usually not the most powerful or the most complex one. The best solution was the one that made the robot more stable, more repeatable, and easier to control on the field.

## 1. Steering Angle Versus Stability

At first, a larger steering angle looked attractive because it suggested tighter turns. In practice, too much steering angle made the robot less stable.

So even though the servo itself could rotate further, we limited the useful steering range to about `60` degrees on the robot.

This was one of the clearest lessons of the season: the maximum possible movement was not the best movement.

## 2. Smaller Robot Instead Of A Larger One

Our previous robot was larger and mechanically more complicated. It taught us an important lesson: when the whole system becomes too complex, it becomes harder to make the robot stable and repeatable.

That is why we chose a smaller final robot, about:

- `21 cm` long
- `10 cm` wide
- `8 cm` high

The smaller robot was easier to package, easier to turn, and easier to control.

## 3. The `250 rpm` Motor Instead Of Extreme Options

We tested three N20 motor options:

- `50 rpm`
- `250 rpm`
- `1000 rpm`

The `50 rpm` option was useful for slow testing, but it was too slow for the final driving behaviour. The `1000 rpm` option did not give enough torque. The `250 rpm` motor gave the best balance between speed and usable torque, so that became the final choice.

## 4. Differential As A Required Part

From earlier work, we already knew that a differential was not optional for this kind of robot.

Without a good differential, the robot became:

- harder to turn;
- less smooth in corners;
- less predictable.

We also compared a metal differential with the final `LEGO` differential. The `LEGO` version was more reliable and gave smoother, more repeatable cornering in practice.

## 5. Fixing Steering Geometry Instead Of Buying A Stronger Servo

We used an `MG90S` servo. A stronger servo was possible, but that would have treated the symptom instead of the cause.

The real problem in steering `Version 1` was geometry. A holder and screw arrangement created a large force arm, so the servo had to work much harder than it should.

In `Version 2`, we removed that force arm. The wheels turned more directly, the mechanism became lighter to move, and the servo could do its job much more easily.

So the right fix was not "buy a stronger servo". The right fix was to improve the mechanical geometry first.

## 6. Front Grip Was More Important Than Matching Wheel Types

We intentionally used different wheel strategies on the front and rear axles.

At the front, the main goal was steering grip. Earlier front wheels could slip, which reduced the real effect of the steering command. After switching to silicone front wheels:

- front slip decreased;
- useful steering effect increased;
- turning became more effective.

The lesson here was simple: wheel choice should match the job of the axle.

## 7. Precision Was More Valuable Than Complexity

Several final decisions followed the same pattern:

- we moved from a larger robot to a smaller one;
- we rejected the weakest and fastest motor extremes;
- we limited steering angle;
- we improved steering geometry instead of increasing servo power;
- we changed to a better differential;
- we improved front-wheel grip.

All of these choices favored precision and repeatability over complexity.

## How We Compared Versions

We compared versions through practical testing, not only by looking at parts on the table.

The main checks were:

- how much space the robot needed to complete a `90` degree turn;
- how much it drifted over a `3 m` straight drive.

We performed about `10` test runs while comparing versions. The change from steering `V1` to `V2` produced the clearest improvement.

## Trade-Off Summary

| Decision | Option A | Option B | Chosen | Evidence |
| --- | --- | --- | --- | --- |
| Drive motor speed | `50 rpm` | `250 rpm` | `250 rpm` | `50 rpm` was too slow in long sections; `250 rpm` kept enough speed while remaining controllable |
| Steering concept | complex custom steering | simplified low-friction steering | simplified steering | More repeatable, less friction, easier servo load |
| Front wheel tires | low-grip wheels | silicone wheels | silicone wheels | Better corner hold and less random slip |
| Sensor role | distance-only | fused distance + `IMU` + camera | fused | More robust against single-sensor error |

We did not select parts only by availability.

We compared alternatives and kept the solution that gave the best balance between speed, stability, and repeatability.

In most cases, we preferred the option that reduced random behavior, even if it was not the fastest on a single run.

## Main Risks And How We Answered Them

| Risk / weakness | Effect on robot | Mitigation |
| --- | --- | --- |
| Large steering lever arm | servo overload, weak steering efficiency | redesigned steering geometry in `V2` |
| Too much steering angle | unstable behavior | limited steering range to about `60` degrees |
| Front wheel slip | weak real steering effect | switched to silicone front wheels |
| Poor differential behavior | rougher, less precise turning | switched to `LEGO` differential |
| Extreme motor choice | too fast or not enough usable torque margin | selected `250 rpm` N20 |

## Failure Modes, Mitigation, And Evidence

| Failure mode | Cause | Mitigation | Result after fix |
| --- | --- | --- | --- |
| Robot drifts to one side | steering asymmetry / wheel grip difference | steering neutral recalibration + `PD` retune | straighter lane holding |
| Servo jitter near center | friction + unstable small corrections | reduced mechanical resistance + deadband tuning | smoother steering |
| False wall/obstacle reaction | noisy distance readings | filtering + confidence threshold | fewer unnecessary corrections |
| Unstable heading after turn | aggressive exit correction | turn-exit damping | less oscillation after corners |

We used this risk-based approach during iteration.

Instead of only reacting to failures, we tried to identify likely failure points early and document how each change affected behavior.

This helped us improve reproducibility and reduced random performance drops between runs.

## Final Summary

The final robot is the result of repeated trade-offs, not one big idea.

The most important ones were:

- smaller chassis instead of a larger, heavier one;
- balanced motor instead of an extreme option;
- useful steering range instead of maximum steering range;
- better geometry instead of a stronger servo;
- more front grip instead of matching wheel type everywhere;
- a better differential instead of a less reliable one.

In the end, the final design was chosen because it was easier to control, more repeatable, and more suitable for real competition driving.
