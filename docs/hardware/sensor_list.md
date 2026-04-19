# Sensor List

## Why This File Exists

The WRO 2026 rubric for **Power and Sensor Architecture** does not only ask for sensor names. It asks for:

- sensor selection justification;
- sensor placement justification;
- calibration method;
- reproducible explanation of how the sensors support the robot.

This file summarizes those points in a compact form.

## Sensors In Use

- `OV5647 5 MP wide-angle` camera (`Waveshare 14037`);
- `BNO085 9-DOF IMU`;
- `2x VL53L4CD` distance sensors.

## Sensor Selection And Role

| Sensor | Main role in the robot | Why we selected it |
| --- | --- | --- |
| `OV5647` wide-angle camera | lane view, obstacle color detection, early scene interpretation | it sees farther ahead than short-range sensors and supports obstacle-side decisions before the robot reaches the obstacle |
| `BNO085` IMU | heading awareness, straight-line stability, turn consistency | a steering robot benefits from yaw feedback even when camera or distance readings momentarily change |
| `2x VL53L4CD` | short-range geometric confirmation near the robot | two modules give local distance information without making the wiring and power system unnecessarily complex |

## Tested Alternative And Why We Rejected It

We also tested `VL53L5CX` matrix sensors during development. We rejected that option in the final hardware documentation because:

- the matrix output made the sensing pipeline more complex;
- we had to decide which zones to trust and how to filter them;
- in our tests, that added complexity did not give a strong enough improvement in real driving.

For our final robot, simpler short-range distance sensing was a better engineering choice than a more complex matrix sensor that did not improve practical performance enough.

## Placement Reasoning

The sensors were placed according to track geometry, not only according to free space inside the robot.

- the camera is mounted at the front so it can see lane direction and obstacle arrangement early in straight sections;
- one distance sensor is used for the front interaction area where close obstacle approach must be confirmed;
- one distance sensor is used for side-distance awareness where local spacing matters more than long-range view;
- the IMU is mounted rigidly near the main structure so heading data reflects the chassis and not a flexible bracket.

This combination supports the obstacle challenge because the robot needs both:

- early interpretation of the field;
- short-range confirmation when it comes near walls or pillars.

## Mounting Notes

- The `BNO085` must be mounted rigidly so sensor fusion reflects robot motion rather than board flex.
- The `VL53L4CD` modules should be positioned so their view is not blocked by wheels, chassis walls, or servo parts.
- The camera and the 2 distance sensors must be documented together because they solve different distance scales of the same navigation problem.
- Using only 2 distance sensors keeps the power and wiring architecture simpler than a larger sensor array.

## Calibration Notes

The minimum calibration workflow used in development is:

1. verify stable IMU yaw while the robot is stationary;
2. start the two distance sensors one by one so they can operate reliably on one communication bus;
3. verify repeatable distance readings against a known wall position;
4. re-check sensor alignment after any mechanical change that affects angle, height, or vibration.

## Documentation Requirements

- List the exact modules used.
- Explain where each sensor is mounted.
- Describe how each sensor contributes to the robot's decision cycle.
- Mention any calibration or alignment requirements.
