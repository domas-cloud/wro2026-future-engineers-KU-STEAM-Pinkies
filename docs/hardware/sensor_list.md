# Sensor List

This page summarizes the sensors we used, why we chose them, and how they were placed on the robot.

## Sensors In Use

- camera system used for the perception layer;
- `BNO085 9-DOF IMU`;
- one front `VL53L1X` ToF sensor;
- `2x VL53L4CD` distance sensors used as `left` and `right`.

## Sensor Selection And Role

| Sensor | Main role in the robot | Why we selected it |
| --- | --- | --- |
| camera system | wider scene interpretation and obstacle/lane perception | it sees farther ahead than short-range sensors and supports higher-level driving decisions |
| `BNO085` IMU | heading awareness, straight-line stability, turn consistency | a steering robot benefits from yaw feedback even when distance readings momentarily change |
| `front VL53L1X` | close approach and turn triggering | it gives direct information about the boundary ahead of the robot |
| `left VL53L4CD` | side-distance awareness | it supports wall-offset control on one side of the robot |
| `right VL53L4CD` | opposite side-distance awareness | it allows the same control model to be used when the reference side changes |

## Tested Alternative And Why We Rejected It

We also tested `VL53L5CX` matrix sensors during development. We rejected that option in the final hardware documentation because:

- the matrix output made the sensing pipeline more complex;
- we had to decide which zones to trust and how to filter them;
- in our tests, that added complexity did not give a strong enough improvement in real driving.

For our published controller, simpler distance sensing was a better engineering choice than a more complex matrix sensor that did not improve practical performance enough.

## Placement Reasoning

The sensors were placed according to track geometry, not only according to free space inside the robot.

- the camera is used for the wider forward scene;
- the front distance sensor is used for the approach area where close boundary detection must be confirmed;
- the left distance sensor is used for side-distance awareness on one side of the robot;
- the right distance sensor is used for side-distance awareness on the opposite side;
- the IMU is mounted rigidly near the main structure so heading data reflects the chassis and not a flexible bracket.

This combination supports the full robot behavior because the robot needs both:

- wider scene interpretation;
- direct front-boundary detection;
- side-spacing feedback together with heading stabilization.

## Mounting Notes

- The `BNO085` must be mounted rigidly so sensor fusion reflects robot motion rather than board flex.
- The camera must be mounted so its field of view is stable and useful for the perception layer.
- The front `VL53L1X` and the two `VL53L4CD` modules should be positioned so their view is not blocked by wheels, chassis walls, or servo parts.
- The distance sensors must be documented together because they solve different geometric parts of the same control problem.
- Using camera perception together with compact distance sensors keeps the sensing architecture broader without losing local geometric feedback.

## Calibration Notes

The minimum calibration workflow used in development is:

1. verify stable IMU yaw while the robot is stationary;
2. verify that the camera view is aligned with the intended driving direction;
3. start the distance sensors in a controlled sequence so they can operate reliably on one communication bus;
4. verify repeatable distance readings against a known wall position;
5. re-check sensor alignment after any mechanical change that affects angle, height, or vibration.

## Documentation Requirements

- List the exact modules used.
- Explain where each sensor is mounted.
- Describe how each sensor contributes to the robot's decision cycle.
- Mention any calibration or alignment requirements.
