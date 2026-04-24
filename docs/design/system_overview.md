# System Overview

## Purpose of the System

Our robot was designed as a **complete autonomous driving system**, not as a collection of unrelated parts.

To perform well in WRO Future Engineers, it is not enough to have good mechanics or good code alone. The robot only works reliably when the chassis, drivetrain, steering, sensors, and software support each other.

For this reason, our development process increasingly focused on **how subsystems interact**.

## Main Subsystems

The robot can be understood as five main subsystems:

1. **Chassis and frame**  
   Provides structure, mounting precision, and mechanical stability.

2. **Drivetrain**  
   Converts motor power into forward motion through the rear axle and differential.

3. **Steering system**  
   Controls the front-wheel direction and determines how precisely the robot can turn and recover.

4. **Perception and control system**  
   Interprets the environment and converts that information into steering and speed output.

5. **Wheel-ground interaction**  
   Transfers the mechanical command into real motion through grip and rolling behaviour.

## Why Subsystem Interaction Matters

A robot can fail even when each separate part seems acceptable.

For example:

- good software cannot fully compensate for slipping front wheels,
- a strong servo cannot fix poor steering geometry,
- a good motor cannot guarantee precise turning if the differential behaviour is poor,
- and a compact chassis is only helpful if its geometry stays aligned.

This is why we treated the robot as one connected system.

## Interaction 1: Chassis and Steering

The chassis and steering system are directly linked.

The steering system needs:

- stable mounting,
- low friction,
- and good geometric precision.

If the chassis allows too much play, bending, or asymmetry, straight driving becomes worse. That means the frame does not only hold the steering system - it also affects the quality of the steering result.

This was one of the reasons why better wheel mounting and better steering geometry improved straight driving.

## Interaction 2: Steering and Front-Wheel Grip

Steering is only effective if the front wheels can actually follow the commanded direction.

Earlier front-wheel versions could slip. Even if the servo turned correctly, the real motion on the field was weaker than expected. After switching to silicone front wheels, the steering command translated into more reliable real movement.

This is a clear systems-thinking example:

- the servo alone was not the problem,
- the steering concept alone was not the problem,
- the wheel-floor interaction was also part of the steering performance.

## Interaction 3: Drivetrain and Turning Behaviour

The drivetrain affects more than speed.

The motor choice and the differential both influenced:

- turning smoothness,
- resistance in corners,
- and overall controllability.

The 250 rpm motor worked best because it balanced speed and torque. The LEGO differential improved precision and reduced binding. These decisions made the robot easier to control, not just faster or slower.

## Interaction 4: Software and Mechanics

Software performance depended on mechanical quality.

For example, sensor-regulated navigation works best when the robot responds predictably to steering commands. If the mechanics introduce slipping, sticking, or asymmetry, then the controller has to fight unstable behaviour.

So software quality depended partly on:

- steering smoothness,
- wheel grip,
- and differential behaviour.

Likewise, improved mechanics made the software easier to tune.

## Interaction 5: Compact Size and Parking Performance

The compact chassis helped with:

- easier turning,
- a more suitable geometry for parking,
- and better fit to the challenge conditions.

However, compact size also created a packaging challenge. The robot had to stay small while still fitting the main functional systems.

This is another trade-off example:

- smaller size improved manoeuvrability,
- but made layout and integration more demanding.

## Main Constraint Areas

During development, the most important constraints were:

- **stability during straight driving**,
- **turning precision**,
- **suitable speed without losing torque**,
- **parking suitability**,
- **mechanical simplicity**,
- and **repeatability across runs**.

Most of our design decisions came from balancing these constraints against each other.

## System Summary

If we had to summarize the robot as one engineering system, the key relationships are:

- chassis precision determines whether steering geometry can work as intended;
- steering quality determines whether the controller can produce repeatable motion;
- wheel grip determines whether steering commands become real movement;
- drivetrain smoothness determines whether turns remain controllable;
- sensing quality determines whether the controller is correcting the right problem;
- software logic determines how safely and consistently all of these subsystems are used together.

This summary is important because it makes the subsystem interaction visible in one place instead of spreading it only across separate documents.

## Example of Whole-System Improvement

One of the best examples of systems thinking in our project was improving straight driving.

Straight driving did not improve because of one isolated change. It improved because several changes worked together:

- better steering geometry,
- better front-wheel grip,
- better wheel mounting,
- improved differential behaviour.

Only after these parts supported each other did the overall result improve significantly.

## Engineering Lesson

One of the most important lessons from our project was that a robot should be evaluated as a **system**, not as separate parts.

A part can look strong in isolation but still reduce the performance of the whole robot. That is why many of our final design decisions were based on practical system behaviour rather than only on theoretical advantages.

## Final Conclusion

Our final robot performs better than the earlier versions because the subsystems work together more effectively.

The final design is not just:

- a smaller chassis,
- a better steering system,
- a better motor,
- or a better differential.

It is the combination of these elements into a more balanced and repeatable autonomous driving system.
