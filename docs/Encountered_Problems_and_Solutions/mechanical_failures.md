# Mechanical Failures

This section describes the main mechanical weaknesses observed during robot development and their significance for later iterations.

## 1. Excessive Steering Load

In early tests, one of the main problems was excessive load in the steering mechanism.
It came from the large wheel lever arm, which forced the servo to deliver too much force.
This problem directly led to a redesign of the steering geometry.

## 2. Increased Turning Resistance Without A Differential

Previous experience showed that without a rear-axle differential, the robot experienced much higher resistance in turns.
That reduced trajectory accuracy, increased the risk of slipping, and added load to the drivetrain.
Because of that, the differential was treated not as an optional addition, but as a necessary mechanical solution.

## 3. Play In Gears And Mounts

It is especially important to reduce unnecessary play in the mechanics.
If too much free movement appears in the gear train or mounting chain, the steering motion becomes less precise and harder to repeat.
Because of that, the design aimed for a compact and rigid force-transfer path.

## 4. Effect Of Structural Stiffness

Even if individual parts work correctly, insufficient overall structural stiffness can still degrade performance.
This matters especially for the steering system and sensor mounts, because flex can distort both mechanics and measurements.
As a result, later iterations focused more on stiffness and more accurate mounting.
