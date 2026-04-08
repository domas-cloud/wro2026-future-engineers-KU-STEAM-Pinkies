# Iterations And Adjustments

This section describes how the robot changed through several key mechanical and sensor iterations.

## Iteration 1: Early Steering Prototype

The first version tested an early steering solution with a central gear and side assemblies.
Before the current geometry, there was still a large wheel lever-arm problem, which placed too much load on the servo.
This stage showed that working mechanics alone were not enough if they overloaded the servo and reduced repeatability.

## Iteration 2: Steering Geometry Correction

Later, the side assemblies were redesigned to rotate around their own axis in place.
This removed the large lever arm, reduced servo load, and improved force transfer to the wheels.
After that change, the steering system became more stable and more suitable for further testing.

## Iteration 3: Keeping The Differential

One of the most important decisions was to keep the differential on the rear axle.
Previous experience with a robot without a differential showed that turning resistance increased strongly in corners.
Keeping the differential reduced slipping, drivetrain load, and improved track behavior.

## Iteration 4: Clear Separation Of Sensor Roles

The sensor system was simplified and divided more clearly by function.
The camera remained responsible for the overall track view, the 2 `VL53L5CX` modules handled short-range confirmation, and the `BNO085` supported heading stability.
This reduced ambiguity in the system and made it easier to understand which sensor was responsible for what.

## Iteration 5: Improved Mounting And Stability

Additional attention was given to more rigid mounting of the `BNO085` and cleaner sensor placement.
This reduced the influence of vibration and structural flex on the readings.
After those changes, the robot's motion estimation became more consistent across repeated tests.
