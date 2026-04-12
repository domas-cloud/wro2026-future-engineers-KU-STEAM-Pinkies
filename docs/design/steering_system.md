# Steering System

## Steering Concept

The robot uses a servo-based front steering mechanism built around a three-gear layout.  
All three gears have **26 teeth**, so the transmission ratio is **1:1**.  
The servo drives the center gear, and the center gear transfers motion symmetrically to the two side gears.

This arrangement was selected because it allows both steering sides to move together with the same angular relationship, which improves left-right consistency and makes the steering response easier to predict.

## Servo Choice

We use an **MG90** servo for steering.  
This servo was chosen because it is one of the most common and widely used compact servos, which made it easy to integrate, replace, and test during development.

Although the servo itself can rotate through a large range, in the robot the steering range is **mechanically limited**.  
This was necessary because allowing the full servo range would create unstable driving behavior and excessive wheel angles.  
In practice, the steering system is limited to a range that still allows stable lane following and controlled cornering.

## Mechanical Layout

The two front steering sides move equally through the three-gear system.  
In the final version, the steering legs are mounted on **bearings**, which reduces friction and improves smoothness.  
This also reduces unwanted resistance that would otherwise increase the load on the servo.

A key design goal was to make both sides behave as equally as possible.  
If one side had more play or resistance than the other, the robot would not hold a straight line reliably and would show inconsistent turning behavior.

## Steering Iterations

### Version 1

The first version used the same three-gear principle, but the side steering attachments were mounted in a way that created a **large turning lever arm**.  
As a result, the servo had to overcome a much larger mechanical load.

This version proved that the concept worked, but it required too much force and was not efficient enough for reliable competition driving.

### Version 2

In the second version, we kept the three-gear steering concept but changed the wheel support structure to a layout with **legs**, which reduced the effective turning lever arm almost to zero.

This significantly reduced the force required from the servo and improved the steering efficiency.

### Version 3

In the third version, we kept the same basic layout but improved it further by mounting the steering legs on **bearings** and using **custom silicone wheels**.

This final version improved the steering system in several practical ways:

- better grip;
- lower friction;
- lower servo load;
- more precise and repeatable steering response.

## Main Mechanical Challenge

The biggest steering-related challenge was creating the conditions for **perfect straight driving**.

This required more than simply making the wheels turn.  
The steering system had to be symmetric, smooth, and stable enough that the robot would not drift unnecessarily while driving forward.

To improve straight driving, we focused on:

- making both steering sides move equally;
- reducing friction in the steering system;
- lowering servo load;
- improving wheel grip;
- increasing precision of the final assembly.

## Practical Result

After the final steering improvements, the system produced **lower mechanical load** on the servo and a **more precise result** in practice.

That improvement was important because lower steering resistance directly supports more stable lane following and more repeatable cornering behavior during the run.
