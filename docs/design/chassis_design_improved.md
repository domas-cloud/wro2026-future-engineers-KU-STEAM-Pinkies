# Chassis Design

## Overview

Our final robot was designed as a **compact rear-wheel-drive vehicle with front-wheel steering**.  
The main goal of the chassis was not to make the robot mechanically complicated, but to make it **stable, predictable, and easier to control** during autonomous driving.

The final outer dimensions of the robot are approximately:

- **Length:** 21 cm  
- **Width:** 10 cm  
- **Height:** 8 cm  

These dimensions were selected intentionally. In our opinion, this size was close to ideal for our robot because it was:

- small enough to turn more easily,
- compact enough to package the main systems inside the body,
- and well suited for the parking area requirements in the WRO challenge.

## Why We Moved Away from the Previous Robot

Before building the final robot, we had an older and larger robot with a more powerful motor and gearbox.

Although that robot was mechanically impressive, in practice it had important disadvantages:

- it was harder to turn,
- the engineering solution was more complicated,
- and the steering system was less practical for stable autonomous driving.

This was one of our most important engineering lessons: **a more complex robot is not automatically a better robot**.

For the final version, we deliberately moved toward a simpler, smaller, and more controllable chassis concept.

## Chassis Philosophy

The robot chassis was designed around four main priorities:

1. **compact size** for easier turning and better parking suitability,
2. **mechanical simplicity** to reduce unnecessary resistance and make the robot easier to tune,
3. **stable wheel alignment** for repeatable straight driving,
4. **good mounting quality** so that steering and drivetrain parts keep their geometry during driving.

In practice, our robot performance depended strongly on whether the chassis could keep the steering system aligned and moving smoothly. Even small play or friction in the front part of the chassis affected the driving result.

## Frame Material and Custom Parts

The main frame of the robot is made from **wood**.

We selected this because it was practical for building a custom structure and gave us enough freedom to place the drivetrain, steering, sensors, and camera where we needed them.

The robot also uses several custom-made parts, including:

- **3D-printed steering components**,
- **motor mount**,
- **camera mount**,
- and other custom support elements required for our final layout.

These parts are important for reproducibility because another team would need to know that the robot is not built only from standard ready-made components.

## Drive Layout

The final robot uses:

- **rear-wheel drive**,
- **front-wheel steering**,
- **mechanical rear differential**.

We chose this layout because it gave us a good balance between controllability, simplicity, and turning performance.

The rear axle is responsible for propulsion, while the front axle is responsible only for steering. This separation made the robot behaviour easier to understand and easier to optimise.

## Why Compact Size Helped

One of the main reasons for the final dimensions was turning performance.

A robot that is too large can require more space to rotate, can be harder to package cleanly, and can become less convenient for parking manoeuvres. In our testing and design thinking, a smaller chassis gave practical advantages:

- the robot could turn more easily,
- the robot geometry was better suited to the challenge,
- and the robot fit our parking goals better.

This does not mean that smaller is always better. A compact robot is harder to package internally. However, for our design, this trade-off was worth it.

## Weight Distribution

We also paid attention to component placement inside the chassis.

The goal was to avoid a badly unbalanced robot and keep the overall behaviour more predictable. A mechanically stable robot is not only about the frame itself, but also about how all components are placed inside it.

## Main Mechanical Goal: Straight Driving

One of the biggest practical mechanical challenges during development was **straight driving**.

At different stages of the project, the robot could drift slightly to either side. This was not caused by only one part. Instead, it depended on several mechanical details working together:

- steering symmetry,
- wheel mounting quality,
- grip at the front wheels,
- differential behaviour,
- and overall assembly precision.

The final robot still drifted only minimally, but compared to earlier versions the result was much better and more repeatable.

## What Improved the Chassis Performance Most

The two most important improvements for the real driving result were:

- **better wheel mounting**,
- **switching to a LEGO differential**.

These changes helped the robot become more precise and less prone to unwanted mechanical resistance.

## Iteration Summary

| Stage | Main idea | Main weakness | What we learned |
|------|-----------|---------------|-----------------|
| Previous larger robot | More powerful motor, gearbox, more complex engineering | Harder turning, more complexity | Bigger and stronger was not automatically better |
| Early compact concept | Smaller and simpler chassis | Needed steering and drivetrain refinement | Compact size gave a better foundation |
| Final chassis | Compact frame, improved wheel mounting, LEGO differential, better front grip | Only minimal remaining drift | Best overall balance of size, control, and repeatability |

## Final Conclusion

Our final chassis was selected because it gave the best practical balance between:

- turning ability,
- parking suitability,
- mechanical simplicity,
- and repeatable driving.

The most important engineering conclusion from this development was that **a robot should be designed for controllability and repeatability, not only for power or complexity**.
