# Wheel Mounting And Suspension Choices

## Wheel Mounting Strategy

Wheel mounting was treated as a precision problem, not only as a structural problem.  
If the wheel support is not rigid enough, small amounts of wobble or friction turn directly into steering error and unstable straight driving.

The robot uses different wheel solutions on the front and rear axles because those axles have different roles.

- The **front wheels** are used only for **steering**.
- The **rear axle** is the **driven axle**.

This means the front wheels had to prioritize steering precision and grip, while the rear axle had to prioritize reliable power transmission.

## Front Wheel Choice

The front axle uses **custom silicone wheels**.

We selected silicone wheels because they gave us better **grip** than the earlier solution.  
That improvement was important because the front axle is responsible for steering only.  
If the front wheels lose grip, the robot does not follow the commanded steering angle accurately, especially in corners and during correction movements.

In practice, the silicone front wheels improved:

- grip on the field surface;
- steering precision;
- consistency of turning behavior;
- reduction of unnecessary servo load.

The improved grip made the steering response more precise and helped reduce wasted motion caused by slipping.

## Rear Wheel And Differential Mounting

The rear axle uses **LEGO wheels** connected to an **original LEGO Technic mechanical differential**.

This differential is part of the drivetrain because the inner and outer rear wheels travel different path lengths during a turn.  
Without this differential effect, the robot experiences greater turning resistance, which makes the motion less smooth and increases mechanical stress.

The motor does not drive the rear wheels directly.  
Instead, the **N20 motor drives a gear**, and that gear drives the **rear differential**.  
This gave us a compact and mechanically simple way to transfer power to both rear wheels.

## Steering Support Evolution

The front steering system went through multiple versions.

In an earlier version, the steering assembly sometimes **stuck** and did not always behave with enough precision.  
That directly affected straight driving and repeatability.

In the final version, the steering legs were mounted on **bearings**.  
This change was made for two reasons:

1. to reduce friction and sticking;
2. to increase steering precision.

This improved the smoothness of the steering movement and reduced the chance that one side would resist more than the other.

## Suspension Philosophy

We did **not** prioritize a complex suspension system.

Instead, we prioritized a **rigid and predictable wheel geometry**.  
For this challenge, that was the better engineering choice because extra suspension movement would add mechanical play and reduce steering consistency.

Our design goal was not maximum mechanical softness, but maximum repeatability.

## Main Practical Outcome

The final wheel and steering support arrangement gave us:

- better front grip;
- less friction in the steering system;
- lower servo load;
- fewer sticking problems;
- more precise and repeatable motion.

These changes were especially important because one of our biggest mechanical goals during development was achieving stable and reliable straight driving.
