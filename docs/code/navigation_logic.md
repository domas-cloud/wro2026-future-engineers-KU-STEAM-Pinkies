# Navigation Logic

## Core Navigation Principle

The core navigation method of our robot is **PD line following**.

This means the robot does not rely on a large number of separate driving modes for normal behavior.  
Instead, the main control loop continuously follows the selected driving line using a proportional-derivative style correction.

This was an intentional design choice because a stable PD-based line-following system is simpler, faster, and easier to tune than a more complicated behavior tree for every situation.

## Main Idea

The most important behavior is:

- follow the line using **PD control**;
- if an obstacle is detected, **change which lane or line reference the PD controller follows**.

So obstacle handling is not treated as a completely separate driving system.  
It is treated as a **modification of the line-following target**.

That was an important engineering decision because it allowed us to keep one main control strategy and adapt it depending on the field situation.

## Obstacle Handling Logic

When the robot sees an obstacle, it changes the selected PD lane depending on the **obstacle color**.

The obstacle color tells the robot whether it should drive:

- **closer to the wall**, or
- **further from the wall**.

In other words, the color changes the target path that the PD controller follows.

This is more efficient than abandoning line following completely, because the same controller can still be used while only the reference path changes.

## Why This Strategy Was Chosen

We selected this strategy because it keeps the control logic more consistent.

Instead of switching from one full driving algorithm to another, the robot keeps the same main driving principle and only updates the path reference.

This gave several advantages:

- simpler control structure;
- easier tuning;
- smoother transitions;
- more predictable behavior;
- less risk of unstable mode switching.

## Practical Interpretation

The robot first uses camera-based processing to determine the relevant visual information.  
The Raspberry Pi Zero runs the camera algorithm and produces the result needed for navigation.

The ESP32 then uses that information to apply PD steering correction.

Under normal conditions, the robot follows its normal line target.  
When an obstacle is seen, the target is shifted according to the obstacle color so that the robot passes on the correct side.

## Functional Logic

The behavior can be described in the following simplified sequence:

1. detect the line and compute the current line-following error;
2. run PD control to generate steering correction;
3. monitor obstacle information from the vision result;
4. if no relevant obstacle is present, continue following the normal lane target;
5. if a relevant obstacle is present, change the lane target according to obstacle color;
6. continue PD control using the updated target;
7. return to the default target when the obstacle situation is finished.

## Color-Based Path Decision

The obstacle color determines the path bias.

The control system does not simply react to “obstacle yes/no”.  
It reacts to the meaning of the obstacle.

This is important because the robot must not only avoid objects physically, but also obey the challenge rule about which side to pass.

Therefore, the controller changes the target line depending on whether the robot must move:

- closer to the wall, or
- further away from the wall.

## Engineering Benefit

This navigation strategy combines two important strengths:

- the stability of PD line following;
- the flexibility of color-based obstacle obedience.

Instead of creating a disconnected obstacle-avoidance routine, we integrated obstacle logic directly into the line-following architecture.

That made the overall system easier to understand and easier to reproduce in documentation.

## Summary

Our navigation logic is built around one main principle:  
**PD line following remains the base behavior at all times.**

Obstacle handling does not replace that behavior.  
It changes the lane target that the PD controller follows.

This gave us a control system that is simpler, more elegant, and more stable in practice than a heavily fragmented state-based approach.
