# Steering System

## Steering Concept

The robot uses a servo-based front steering mechanism built around a **three-gear layout**.

All three gears have **26 teeth**, so the transmission ratio is **1:1**. The servo drives the center gear, and the center gear transfers motion symmetrically to the two side gears.

This arrangement was selected because it allows both steering sides to move together with the same angular relationship, which improves left-right consistency and makes the steering response easier to predict.

## Steering Design Philosophy

Our previous robot used a more complex steering system. Although that solution was more advanced mechanically, in practice it created more friction and more resistance.

For the final robot, we intentionally selected a **simpler steering concept**. The goal was not to maximise complexity, but to achieve lower friction, lower resistance, better repeatability, and more reliable behaviour on the field.

This was an important engineering decision in our project: the simpler system worked better in practice.

## Servo Choice

We use an **MG90** servo for steering.

This servo was chosen because it is compact, widely available, easy to integrate, and easy to replace during development. It also fit well within the packaging limits of our robot.

In the final design, the servo is able to turn the steering system **without any problems**. This confirmed that the final steering geometry and friction level were suitable for reliable competition use.

A steering mechanism that works with low resistance is more repeatable and mechanically safer than one that pushes the servo close to its limits.

## Steering Range

Although the servo itself can rotate through a large range, in the robot the steering range is **mechanically limited**.

This was necessary because allowing the full servo range created unstable driving behaviour and excessive wheel angles. In practice, the steering system is limited to a range that still allows stable lane following and controlled cornering.

This is a good example of an engineering trade-off: more steering angle is not always better if it reduces stability.

## Mechanical Layout

The two front steering sides move equally through the three-gear system.

In the final version, the steering legs are mounted on **bearings**, which reduces friction and improves smoothness. This also reduces unwanted resistance that would otherwise increase the load on the servo.

A key design goal was to make both sides behave as equally as possible. If one side had more play or resistance than the other, the robot would not hold a straight line reliably and would show inconsistent turning behaviour.

## Steering Iterations

The steering system went through three main versions.

### Version 1

The first version used the same three-gear principle, but the side steering attachments were mounted in a way that created a **large turning lever arm**.

As a result, the servo had to overcome a much larger mechanical load.

This version proved that the concept worked, but it required too much force and was not efficient enough for reliable competition driving.

### Version 2

In the second version, we kept the three-gear steering concept but changed the wheel support structure to a layout with **legs**, which reduced the effective turning lever arm almost to zero.

This significantly reduced the force required from the servo and improved the steering efficiency.

### Version 3

In the third version, we kept the same basic layout but improved it further by:

- mounting the steering legs on **bearings**,
- using **custom silicone wheels**.

This final version improved the steering system in several practical ways:

- better grip,
- lower friction,
- lower servo load,
- more precise steering,
- more repeatable steering response.

## Why We Chose the Final Steering Version

A more complex steering system was not automatically a better solution for our robot.

In practice, the simpler steering concept with lower friction and lower resistance performed better and gave more repeatable behaviour. The final version was selected because it produced the most stable combination of:

- controlled turning,
- lower mechanical resistance,
- lower servo stress,
- better straight-line recovery,
- and more consistent real track behaviour.

This final version was not chosen because it looked simpler, but because repeated testing showed it worked better.

## Main Steering Challenge

The biggest steering-related challenge was creating the conditions for **stable straight driving**.

This required more than simply making the wheels turn. The steering system had to be symmetric, smooth, and stable enough that the robot would not drift unnecessarily while driving forward.

To improve straight driving, we focused on:

- making both steering sides move equally,
- reducing friction in the steering system,
- lowering servo load,
- improving wheel grip,
- increasing precision of the final assembly.

## Practical Result

After the final steering improvements, the system produced **lower mechanical load** on the servo and a **more precise result** in practice.

That improvement was important because lower steering resistance directly supports more stable lane following and more repeatable cornering behaviour during the run.

## Steering Iteration Summary

| Version | Main idea | Problem | Improvement |
|--------|-----------|---------|-------------|
| V1 | Initial three-gear steering layout | Large lever arm, higher servo load | Proved concept worked |
| V2 | Reduced effective lever arm | Earlier version required too much force | Lower resistance, better steering efficiency |
| V3 | Bearings + custom silicone wheels | Needed more precision and lower friction | Better grip, lower friction, lower servo load, more repeatable behaviour |

## Final Steering Conclusion

The most important lesson from steering development was that **repeatability mattered more than complexity**.

Our final steering solution worked best because it combined:

- symmetric movement,
- lower friction,
- lower mechanical resistance,
- reliable servo operation,
- and better wheel-floor grip.

This made the steering system more suitable for stable autonomous driving on the WRO field.
