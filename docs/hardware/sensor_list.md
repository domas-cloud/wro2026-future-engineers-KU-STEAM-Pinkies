# Sensor List

## Sensors In Use

- Camera for lane and obstacle perception.
- `BNO085 9-DOF IMU` for orientation and motion stability.
- `VL53L5CX` matrix ToF lidar for distance and obstacle awareness.

## Why These Sensors

- The camera gives global track context.
- The IMU helps stabilize motion and detect heading changes.
- The ToF sensors provide short-range distance information that complements vision.

## Build Notes

- `BNO085` must be mounted rigidly so the fusion output reflects robot motion rather than board flex.
- `VL53L5CX` placement must match the obstacle zone geometry and avoid blocked sight lines.
- Camera framing and ToF coverage should be documented together because they solve different parts of the same navigation problem.

## Documentation Requirements

- list the exact modules used;
- explain where each sensor is mounted;
- explain what each sensor contributes to the robot decision loop;
- note any calibration or alignment requirements.
