# Mechanical and Software Testing

## Why Testing Was Important

Our robot was not created in one final version. Both the mechanical system and the software improved through repeated testing.

Testing was important because many decisions that looked reasonable in theory did not work equally well in practice. The real robot behaviour on the field showed us which solutions were actually better.

## Main Testing Philosophy

We evaluated changes based on practical driving quality, not only on appearance or theory.

For us, a better version was the one that gave:

- more stable turning,
- better straight driving,
- less slipping,
- lower steering resistance,
- and more repeatable behaviour.

This testing philosophy helped us avoid choosing solutions that only looked stronger or more complicated.

## Mechanical Testing

A major part of our testing was focused on the drivetrain and steering system.

We compared several key mechanical choices:

- N20 motors with **300 rpm**, **600 rpm**, and **1000 rpm**,
- steering **Version 1**, **Version 2**, and **Version 3**,
- earlier front wheel solutions versus **silicone front wheels**,
- and a previous differential solution versus the **LEGO differential**.

## Main Mechanical Test Criteria

The two most important practical criteria were:

1. **how much area the robot needed to complete a 90-degree turn**,
2. **how much the robot drifted over a 3-meter straight drive**.

These criteria were useful because they measured the exact behaviours that mattered most in competition:

- turning precision,
- straight-driving stability,
- and repeatability.

## Motor Comparison

We tested three N20 motors.

### 300 rpm
This motor was too slow and did not meet our speed expectations.

### 1000 rpm
This motor was faster, but did not provide enough torque.

### 600 rpm
This motor gave the best overall balance of speed and usable torque, so it became the final choice.

## Steering Testing

### Steering Version 1
Version 1 had a large force arm in the wheel support system. Because of that, the servo had to work much harder.

### Steering Version 2
In Version 2, we removed the large lever arm and made the wheels rotate more directly in place.

This was the biggest steering improvement because the servo could turn the system much more easily.

### Steering Version 3
Version 3 improved the V2 concept further by adding:

- bearings in the frame,
- silicone front wheels.

This gave better smoothness, better grip, and better repeatability.

## Differential Testing Result

From earlier experience, we already knew that a differential was necessary. However, the differential type still mattered.

After changing from a metal differential to a LEGO differential, the robot became:

- more precise,
- less likely to bind or jam,
- and smoother in turning.

## Front Wheel Testing Result

Before the final version, the front wheels could slip.

After switching to silicone front wheels:

- the front wheels no longer slipped,
- the robot could make stronger useful turns,
- and steering became more effective on the track.

## Straight Driving Result

At different stages, the robot could drift slightly to either side.

The biggest improvements for straight driving came from:

- better steering geometry,
- better wheel mounting,
- improved front-wheel grip,
- and the improved differential solution.

After the final changes, the robot still drifted only minimally, which was a significant improvement compared to earlier versions.

## Software Testing

Software testing followed the same practical philosophy as mechanical testing.

The goal was not to build the most complicated logic, but to build a navigation strategy that remained understandable, stable, and repeatable.

We improved the software in stages:

### Early software stage
The robot could already drive, but turning behaviour was more reactive and less refined.

### Intermediate software stage
The obstacle logic was integrated into the line-following system by changing the target path instead of replacing the whole controller.

This made the transitions smoother and the overall control easier to tune.

### Later software stage
The software architecture became clearer and more modular, with a cleaner separation between perception and control.

This improved maintainability and reduced the risk that image processing delays would directly affect steering stability.

## Approximate Testing Effort

We performed approximately **10 test runs** while comparing mechanical versions.

Even though this was not a laboratory-style measurement process, it was enough to reveal clear practical differences between the versions.

## Most Important Testing Conclusion

The most important improvement found through testing was:

**the transition from steering Version 1 to Version 2**

This change reduced steering resistance the most and improved the behaviour of the whole front system.

## Engineering Lesson from Testing

The biggest lesson from testing was that real performance depends on the interaction of multiple systems.

For example, straight driving did not improve because of one single change. It improved because several changes worked together:

- steering geometry,
- wheel grip,
- differential precision,
- and assembly quality.

This is why testing was essential. It allowed us to evaluate the robot as one connected system instead of only as separate parts.

## Final Conclusion

Testing was one of the most important parts of our engineering process.

It helped us:

- reject weak ideas,
- confirm strong design decisions,
- compare versions in practice,
- and select the final robot based on repeatable behaviour instead of assumptions.

The final robot is therefore not only a designed robot, but a **tested and iterated robot**.
