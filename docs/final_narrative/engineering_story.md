# Our Engineering Decisions Story

## Why We Wrote This Section

In this section, we want to explain not only what we built, but also why we built it that way.

A large part of our project was not about randomly choosing parts. It was about making trade-offs, testing them, and then keeping the options that gave us better real results.

## Our Biggest Mechanical Trade-off

The single biggest trade-off in our robot was:

**steering angle vs stability**.

At first, a large steering angle looked attractive because it suggested sharper turning. But in practice we saw that too much steering angle made the robot less stable.

Because of that, even though our servo can rotate about **90 degrees**, we limited the robot to about **60 degrees** of usable steering angle.

This was one of the clearest examples where the best practical solution was not the biggest possible one.

## Why We Chose a Smaller Robot

Our previous robot was larger, used a stronger motor and gearbox, and had a more complicated steering system.

However, in practice it was:

- harder to turn,
- more complicated mechanically,
- and less practical for the kind of repeatable autonomous behaviour we wanted.

That is why we deliberately moved to a smaller final robot with dimensions of about **21 × 10 × 8 cm**.

For us, the smaller robot gave a better balance between:

- turning ability,
- parking suitability,
- and controllability.

## Why We Chose the 600 rpm Motor

We tested three N20 motors:

- **300 rpm**,
- **600 rpm**,
- **1000 rpm**.

The 300 rpm version was too slow. The 1000 rpm version did not give enough torque. The 600 rpm version gave the best overall balance, so we selected it.

This was not a theoretical decision. It came directly from comparing how the robot behaved in practice.

## Why the Differential Was a Must for Us

From our previous experience, we already knew that integrating a differential was necessary.

Without a good differential solution, the robot became harder to turn and less controlled in corners. Later, when we changed from a metal differential to a **LEGO differential**, we saw that the robot became:

- more precise,
- less likely to jam,
- and less resistant while turning.

That confirmed that the differential was one of the key parts affecting the whole driving result.

## Why We Fixed the Steering Geometry Instead of Choosing a Stronger Servo

One obvious reaction to steering difficulty would have been to install a stronger servo.

We did not choose that path first, because we understood that the real problem was in the mechanics, not only in the actuator.

In steering V1, the wheel support created a large lever arm, so the servo had to work too hard. In steering V2, we removed that large force arm and made the wheels rotate more directly in place.

That change was more important than simply increasing servo strength.

So our decision was:

- first reduce the mechanical resistance,
- then keep the servo solution efficient.

That is why the **MG90S** remained enough for our final robot.

## Why We Used Silicone Front Wheels

Earlier front wheels could slip. That meant the steering command was not always translated into real movement on the track.

After changing to silicone front wheels, the wheels no longer slipped and the robot could turn more effectively.

This showed us that grip at the steering axle was critical.

## Why We Chose a Split Software Architecture

We also made an important architectural decision in software.

We chose:

- **Raspberry Pi Zero** for perception,
- **ESP32** for control and actuation.

We chose this split because perception and actuation require different behaviour. Camera processing is more computational, while steering and motor control need fast and predictable reactions.

This decision made the overall system cleaner and more stable.

## Why We Kept One Main Navigation Principle

Instead of building many different disconnected behaviours, we based our navigation on one main idea:

**PD line following remains the main behaviour, and obstacle colour changes the target path.**

We chose this because it gave us:

- smoother transitions,
- easier tuning,
- and more repeatable behaviour.

## How Testing Guided Our Decisions

We did not make our final decisions only from theory.

We compared versions using practical criteria such as:

- how much space the robot needed to make a 90-degree turn,
- and how much it drifted over a 3-meter straight drive.

We did about **10 test runs** while comparing mechanical versions, and the clearest improvement was the change from **steering V1 to V2**.

## Our Main Engineering Lesson

The strongest lesson from this season was that the best solution is usually the one that gives the best total system behaviour, not the one with the most impressive individual specification.

In our robot, this meant that we repeatedly chose:

- balance over extremes,
- repeatability over complexity,
- and mechanical efficiency over brute force.

## Final Conclusion

Our final robot is the result of many connected decisions. We chose:

- a smaller chassis instead of a larger complicated one,
- a balanced motor instead of an extreme motor,
- a limited steering range instead of a maximum steering range,
- better steering geometry instead of a stronger servo,
- silicone front wheels instead of slipping wheels,
- and a LEGO differential instead of a less suitable differential solution.

We selected these solutions because they worked better together as one system.
