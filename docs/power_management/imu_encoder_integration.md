# IMU And Encoder Integration

## Purpose

The IMU helps the robot understand heading and motion changes.
If encoders are used, they provide additional feedback for movement estimation and consistency.

## Integration Goal

The goal is not only to read the values, but to connect them to steering and driving logic so the robot behaves more predictably.

## What The Documentation Should Cover

- where the IMU is mounted;
- how it is calibrated;
- what the software does with its readings;
- whether encoder data is used for feedback, speed estimation, or both.
