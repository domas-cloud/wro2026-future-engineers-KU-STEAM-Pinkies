# Sensor List

## Sensors In Use

- `OV5647 5Mpx wide-angle` camera (`Waveshare 14037`) for lane observation, obstacle detection, and forward distance estimation.
- `BNO085 9-DOF IMU` for orientation tracking and motion stability.
- 2 `VL53L5CX` matrix ToF modules for short-range distance sensing and obstacle confirmation.

## Role Of Each Sensor

- The camera provides the general track view and helps estimate the situation in front of the robot.
- The IMU helps stabilize motion and detect heading changes.
- The 2 matrix ToF modules provide close-range distance data and confirm obstacles when camera-based estimation alone is not enough.

## Mounting Notes

- The `BNO085` must be mounted rigidly so sensor fusion reflects robot motion rather than board flex.
- The `VL53L5CX` modules should be positioned to match the obstacle-zone geometry without blocking their field of view.
- The camera and the 2 matrix ToF modules should be documented together because they solve different parts of the same navigation problem.
- Using only 2 ToF modules reduces power consumption and keeps the electronics architecture simpler.

## Documentation Requirements

- List the exact modules used.
- Explain where each sensor is mounted.
- Describe how each sensor contributes to the robot's decision cycle.
- Mention any calibration or alignment requirements.
