# IMU and Encoder Integration

## Purpose

The IMU helps the robot understand heading and motion changes.
If encoders are used, they provide additional feedback for motion estimation and consistency.

## Integration Goal

The key is not just reading the values, but combining them with steering and driving logic so the robot behaves more predictably.

## Documentation Focus

- where the IMU is mounted;
- how it is calibrated;
- what the software does with the readings;
- whether encoder data is used for feedback, speed estimation, or both.
