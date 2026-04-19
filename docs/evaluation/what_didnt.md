# What Did Not Work

This section lists solutions and situations that did not work well or had to be redesigned.

## Excessive Wheel Lever Arm In The Steering Mechanism

One of the most important early weaknesses was the large wheel lever arm.
Because of it, the servo had to overcome a much larger load, which made the system less efficient and harder to repeat reliably.
This solution was not kept because real tests showed that it reduced steering reliability.

## Previous Robot Without A Differential

A mistake in the previous robot was not using a differential.
In turns, that strongly increased turning resistance, worsened the trajectory, and increased the chance of slipping.
Because of that, the current robot kept the differential as a necessary drivetrain element.

## Over-Reliance On One Sensor Type

Testing showed that one sensor type alone was not enough for stable navigation in all situations.
Camera data alone or short-range sensors alone could not reliably solve all track scenarios.
Because of that, a mixed solution was chosen using the camera, `BNO085`, and 2 `VL53L4CD` modules.

## Insufficiently Rigid Mounting

If the `BNO085` or other important components are mounted without enough rigidity, the readings become less reliable.
This matters especially when the structure vibrates or flexes slightly while driving.
Because of that, weaker mounting solutions were abandoned and more attention was given to stiffness.
