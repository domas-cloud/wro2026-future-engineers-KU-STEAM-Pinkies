# Solutions And Fix Log

This log briefly records the most important real changes that were made while developing the robot.

## 1. Steering Geometry Correction

- Problem: early tests showed a large wheel lever arm, which forced the servo to overcome too much load.
- Fix: the side steering assemblies were redesigned to rotate around their own axis in place.
- Verification: after the change, the steering became lighter, more stable, and better suited for later iterations.

## 2. Returning To And Keeping The Differential

- Problem: in the earlier robot, not using a differential greatly increased turning resistance in corners.
- Fix: the differential was retained on the rear axle.
- Verification: mechanical load in turns decreased, the wheels slipped less, and driving became smoother.

## 3. Separation Of Sensor Roles

- Problem: one sensor type alone was not enough for all navigation situations.
- Fix: the camera was kept for the overall track view, while the 2 `VL53L5CX` modules were used for short-range and obstacle confirmation.
- Verification: the sensor system became easier to understand, and obstacle detection became more reliable in complex cases.

## 4. Stiffening The `BNO085` Mount

- Problem: if the IMU mount is not rigid enough, some of the motion readings may reflect board flex rather than robot motion.
- Fix: the `BNO085` was mounted rigidly and placed as close as possible to a stable part of the structure.
- Verification: heading and motion estimation became more consistent across several turns.

## 5. Simplifying The Electronics

- Problem: a larger number of sensors and branches makes the electronics more complicated and increases power consumption.
- Fix: the architecture was simplified to use 2 `VL53L5CX` modules instead of an excessive number of short-range sensors.
- Verification: the system remained simpler, easier to reproduce, and easier to test.
