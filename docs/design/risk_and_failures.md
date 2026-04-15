# Risk and Failure Analysis

## Why Risk Analysis Matters

In an autonomous robot, good performance depends not only on what works, but also on what can go wrong.

During development, we identified several practical failure modes that could reduce performance or make the robot less repeatable. Instead of treating these as random problems, we used them to guide design improvements.

This is an important part of engineering: understanding risks and reducing them through design changes.

## Main Risks We Identified

The most important risks in our robot were:

- unstable steering behaviour,
- front-wheel slipping,
- excessive steering load on the servo,
- weak turning precision,
- poor differential behaviour,
- wrong motor balance between speed and torque,
- and reduced straight-driving repeatability.

## Risk 1: Large Steering Lever Arm

### Problem
In steering Version 1, the wheel support was attached in a way that created a large force arm.

### Risk
This made the servo work harder and increased the mechanical resistance of the steering system.

### Effect on performance
The robot became less efficient in steering and the servo had more difficulty turning the wheels.

### Mitigation
In Version 2, we removed the large lever arm and redesigned the steering so that the wheels rotated more directly in place.

### Result
This was the biggest steering improvement in the project. The servo could turn the wheels much more easily.

## Risk 2: Too Much Steering Angle

### Problem
A large steering range seemed useful at first.

### Risk
In practice, too much steering angle reduced stability.

### Effect on performance
The robot became harder to control consistently.

### Mitigation
Although the servo itself could rotate about 90 degrees, we limited the usable robot steering angle to about 60 degrees.

### Result
The driving behaviour became more stable.

## Risk 3: Front-Wheel Slipping

### Problem
Earlier front-wheel solutions could slip on the field surface.

### Risk
Even if the steering command was correct, the front wheels would not always transfer that command effectively into real motion.

### Effect on performance
Turning became weaker and less repeatable.

### Mitigation
We switched to silicone front wheels.

### Result
The front wheels no longer slipped, and the robot could turn more effectively.

## Risk 4: Poor Differential Precision

### Problem
The behaviour of the differential strongly affected turning quality.

### Risk
An unsuitable differential solution increased the chance of less precise turning and mechanical binding.

### Effect on performance
The robot became less precise and more likely to feel resistant in turning.

### Mitigation
We changed from a metal differential to a LEGO differential.

### Result
The robot became more precise and less likely to jam or bind.

## Risk 5: Wrong Motor Selection

### Problem
The drive motor had to balance speed and torque.

### Risk
A slow motor could limit performance, while a very fast motor could reduce usable torque.

### Effect on performance
The robot would either become too slow or lose too much practical drive strength.

### Mitigation
We tested three N20 motors:

- 300 rpm,
- 600 rpm,
- 1000 rpm.

### Result
We selected the 600 rpm motor because it gave the best balance of speed and torque.

## Risk 6: Straight-Driving Drift

### Problem
At different stages, the robot could drift slightly to either side.

### Risk
Reduced straight-driving repeatability makes lap performance less stable and increases correction demands on the software.

### Effect on performance
The robot became less predictable during long straight sections.

### Mitigation
We improved several connected parts:

- wheel mounting,
- steering geometry,
- front-wheel grip,
- differential behaviour.

### Result
Straight-driving drift was reduced to a minimal level.

## Risk 7: Solving Problems by Only Increasing Power

### Problem
One possible reaction to steering difficulty would have been to use a stronger servo.

### Risk
That would increase energy demand without solving the real mechanical weakness.

### Effect on performance
The robot might use more energy while still keeping a weak geometry.

### Mitigation
Instead of increasing servo power, we improved the steering mechanics.

### Result
The chosen MG90S servo became sufficient once the steering geometry was corrected.

## Summary Risk Table

| Risk | Why it mattered | Mitigation | Final result |
|------|-----------------|------------|--------------|
| Large steering lever arm | High servo load, weak steering efficiency | Redesigned steering in V2 | Servo turned more easily |
| Too much steering angle | Lower stability | Limited to ~60° | More controlled behaviour |
| Front-wheel slipping | Weak real steering effect | Silicone front wheels | Better grip, stronger turning |
| Unsuitable differential | Lower precision, more binding | LEGO differential | More precise, less jamming |
| Wrong motor choice | Too slow or too weak | Tested 300 / 600 / 1000 rpm | 600 rpm chosen |
| Straight-driving drift | Lower repeatability | Multiple mechanical improvements | Minimal drift |
| Stronger-servo-only solution | More energy use without geometry fix | Improved mechanics first | MG90S became sufficient |

## Main Engineering Lesson from Failure Analysis

The most important lesson from our risk analysis was that many problems came from **interaction between parts**, not from only one isolated component.

For example:

- slipping wheels reduced steering effectiveness,
- poor steering geometry overloaded the servo,
- differential behaviour affected turning precision,
- and drift depended on multiple parts together.

This means the robot had to be improved as a system.

## Final Conclusion

Risk and failure analysis helped us move from early versions to a more reliable final design.

Instead of only adding stronger components, we focused on reducing the root causes of weak performance. This made the robot:

- more stable,
- more precise,
- less mechanically resistant,
- and more repeatable across runs.
