# Steering System Concept Selection

## Selected Concept

We selected a servo-controlled front axle based on a three-gear synchronization mechanism.
The central gear receives the steering input and transfers motion to the left and right sides so both sides move together.
The servo is coupled to the middle gear, while steering arms are attached to the two side gears and carry the wheel mounts.

## Why We Selected It

- The steering motion is symmetric, which makes it easier to keep the front axle aligned.
- The gear transmission converts servo motion into a predictable wheel angle in a compact layout.
- The two outer gears allow direct control of both steering sides without a more complicated linkage-only design.
- The concept is easier to document and reproduce than a loose multi-link arrangement.
- It supports our goal of building a car-style robot with controlled turning instead of skid-based steering.

## Early Concept Evaluation

An early CAD concept showed the three interlinked gears as the core steering idea.
In that concept, the central gear acted as the steering input element and transferred rotation evenly to the two outer gears.
This arrangement was considered promising because it could provide:

- smooth mechanical movement;
- equal rotation on both sides;
- low backlash in the steering path;
- stable and accurate steering control.

## Conceptual Operating Principle

The steering input rotates the central gear, which simultaneously drives the two outer gears.
Through the attached steering arms, this motion adjusts the angle of the front wheel assembly.
This allows the robot to:

- make precise turns;
- correct its direction smoothly;
- stay stable even with small steering adjustments.

## Preliminary Conclusion

This three-gear steering concept was suitable for further exploration and prototyping.
It had the potential to deliver accurate, stable, and reliable steering control, which is essential for effective maneuvering on the WRO track.
