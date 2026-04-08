# Steering System

## Mechanism

The robot uses servo-based steering with a gear-coupled front axle.
The goal is to turn servo motion into symmetric wheel movement with predictable angle changes.
The steering mechanism consists of three gears. The servo rotates the middle gear, which simultaneously transfers motion to both side gears.
Steering arms are attached to the two side gears, and the wheels are mounted to those arms, so both front wheels turn together.

## First Iteration

The first version of this robot's steering system was an early prototype in which the central gear transferred motion to two side assemblies.
In earlier experiments, one problem was a large wheel lever arm, so the servo had to overcome a much higher load.
In this version, the side assemblies rotated around their own axis, which removed that large lever arm and transferred torque more efficiently.
This layout reduced the load on the servo and allowed motion to be delivered to the wheels more effectively.
In later iterations, the same idea was refined further to make the steering system stiffer and more reliable.

## Differential

The differential was used in the prototype and kept in the later robot version because it proved to be an important part of the drivetrain.
Its purpose is to let the left and right wheels rotate at different speeds during a turn, since the inner and outer wheels travel different path lengths.
One of the previous robot's mistakes was not using a differential, which made turning resistance much higher in corners, in practice almost up to triple.
As a result, the mechanical load increased, turning accuracy worsened, and the wheels were more likely to slip.
Keeping the differential reduced those loads, improved turning behavior, and made the robot drive more smoothly.

## Engineering Notes

- keep the steering path as compact as possible;
- minimize play wherever possible;
- avoid interference between the gear train and the chassis;
- ensure the servo returns to center consistently;
- keep both side gears working evenly so the wheel angles stay matched.

## Integration Notes

Steering angle is directly affected by mounting height, linkage length, and the alignment of the three gears.
Because of that, the steering geometry must match the real chassis and wheel layout.
