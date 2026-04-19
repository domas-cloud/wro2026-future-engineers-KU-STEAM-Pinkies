# Electronics Overview

This section was written to match the expectations in the WRO 2026 documentation rubric for **Power and Sensor Architecture** and the general rules for **Future Engineers Self-Driving Cars**.

The rubric expects more than a component list. It asks for:

- power system architecture;
- current draw reasoning and distribution;
- sensor selection and placement justification;
- calibration method;
- wiring diagrams;
- failure-point considerations;
- documentation that another team can reproduce.

The `WRO-2026-Future-Engineers-Documentation-Rubric.pdf` and `WRO-2026-Future-Engineers-Self-Driving-Cars-General-Rules.pdf` both point toward the same idea: electronics must be explained as an engineering system, not only shown as a finished assembly.

## Documentation Consistency Note

The electronics schematic PDF included in this repository labels the two distance sensors as `VL53L4CD`. Some older software-side files in the repository still refer to `VL53L5CX` from an earlier documentation branch. For the electronics documentation in this section, we follow the actual schematic file that is provided as evidence in the repository.

## Architecture Goal

Our robot uses a split electronics architecture with two computing boards:

- `Raspberry Pi Zero` for camera input and vision processing;
- `ESP32` for fast control, sensor reading, and actuator output.

We selected this architecture because the robot needs both:

- image-based interpretation of the field and obstacles;
- deterministic real-time control of steering, motor output, and sensor polling.

The WRO rules describe a typical Future Engineers architecture as a single-board computer together with a microcontroller or motor-control board, a wide-angle camera, two distance sensors, a steering servo, a DC motor, an IMU, batteries, and stabilized power. Our electronics follow that same structure, even though our exact implementation uses `ESP32`, `Raspberry Pi Zero`, sensor breakout boards, and a perfboard-based distribution board rather than a manufactured custom PCB.

## Main Electronic Components

The final electronics system includes:

- `Raspberry Pi Zero`;
- `ESP32-WROOM-32`;
- `OV5647 5 MP wide-angle camera`;
- `BNO085 9-DOF IMU`;
- `2x VL53L4CD` distance sensors;
- `MG90S` steering servo;
- `N20 6 V 600 rpm` DC drive motor;
- `L298N` H-bridge motor driver;
- `2x 18650 Li-ion` battery supply;
- step-down regulation and perfboard-based power distribution;
- start button and power switching.

## Why We Split The System

We did not want a single board to do everything.

The `Raspberry Pi Zero` is more suitable for camera-side processing, while the `ESP32` is more suitable for:

- reading I2C sensors reliably;
- generating steering PWM;
- controlling the motor driver;
- reacting quickly to changing vehicle state.

This division reduces software complexity on the control side and makes the robot easier to debug. If camera processing is changed, the actuator-control side can remain stable.

## Power Architecture

The robot is powered from a 2-cell `18650` battery pack. In the schematic and documentation this source is treated as approximately `7.5 V` nominal input under normal use.

From this source, power is split into separate functional branches:

- a motor branch for the DC drive motor through the `L298N`;
- a regulated logic branch for the `ESP32`;
- a regulated logic branch for the `Raspberry Pi Zero`;
- a regulated sensor branch for the `BNO085` and both distance sensors;
- a steering branch for the `MG90S` servo.

We used branch separation because the drive motor, servo, logic boards, and sensors do not create the same electrical disturbances. In practical robot development, high-current motor loads and servo spikes can disturb low-voltage logic if everything is treated as one undivided power line.

## Current Draw Reasoning And Power Budget

We did not claim a laboratory-grade current measurement for every subsystem. Instead, we documented a conservative engineering budget so that the wiring and regulators would not be undersized.

| Subsystem | Main parts | Rail type | Design current assumption | Engineering reason |
| --- | --- | --- | --- | --- |
| Logic compute | `Raspberry Pi Zero`, `ESP32` | regulated logic rail | `0.8 A` continuous | headroom for camera-side compute and control-loop activity |
| Sensors | `BNO085`, `2x VL53L4CD` | regulated sensor rail | `0.25 A` continuous | allows stable sensor startup and margin for bus activity |
| Steering | `MG90S` servo | dedicated steering branch | `1.0 A` peak | servo current rises sharply near hard steering or friction |
| Drive | `N20` + `L298N` | battery / motor branch | `1.5 A` peak | covers acceleration and restart load better than average-current sizing |
| Total | all branches together | battery input | about `3.5 A` peak | practical system headroom for combined transient loads |

This budget exists because the rubric explicitly asks for current-draw reasoning, not only a battery name. Our design goal was to make sure:

- regulators were not selected too close to average load;
- logic power stayed stable during drive and steering transients;
- the system remained reproducible for another team.

## Why We Used Regulated Power

The WRO documentation guidance expects evidence that the team planned power distribution instead of just connecting parts. Our regulated power strategy addresses that requirement directly.

We used regulated power because:

- the `ESP32` and `Raspberry Pi Zero` should not be fed from raw battery voltage;
- sensor readings become less trustworthy when the logic rail is noisy;
- the servo and drive motor can create voltage drops during dynamic movement;
- a separated power structure is easier to troubleshoot and rebuild.

The schematic in [Wro_customPCBs.pdf](../../schemes/Wro_customPCBs.pdf) and the explanation in [custom_pcb_description.md](../../schemes/custom_pcb_description.md) document this structure.

## Sensor Selection Strategy

The WRO rubric asks for sensor choice justification, not just a list. Our sensor set was selected so that each sensor solves a different part of the navigation problem.

### Camera

We use an `OV5647` wide-angle camera because the robot needs early information from farther ahead on the field. The camera is responsible for:

- observing lane direction;
- seeing obstacle color;
- seeing the approach geometry before the robot reaches the obstacle.

This is difficult to replace using only short-range sensors.

### IMU

We use a `BNO085` because steering robots benefit from heading awareness. The IMU helps us:

- maintain straight driving;
- detect heading drift;
- support repeatable turns.

Without IMU feedback, the robot would depend too much on momentary vision or distance readings.

### Two Distance Sensors

We use `2x VL53L4CD` modules as short-range distance sensors. This matches the general rules appendix, which presents two distance sensors as part of a typical Future Engineers hardware set.

We selected two distance sensors because they provide:

- short-range confirmation near the robot;
- left-right geometry information that the camera alone cannot guarantee at close range;
- simpler wiring and lower power demand than adding many more modules.

We did not try to solve the full navigation task with distance sensors alone. Their role is local geometric confirmation, not whole-track interpretation.

## Why We Moved Away From `VL53L5CX`

During development, we also considered and tested `VL53L5CX` matrix sensors. In theory, the matrix output gives more spatial information, but in our robot this advantage did not justify the extra complexity.

In our tests, the `VL53L5CX` option was weaker for our final design for two main reasons:

- the matrix-based data was more complex to process consistently in a small fast robot;
- the practical results were not better enough to justify that added complexity.

For our task, we did not need a dense matrix as much as we needed repeatable short-range confirmation. The simpler `VL53L4CD` modules were easier to integrate, easier to explain, and more practical for stable obstacle-side confirmation in the final robot.

This is an example of an engineering trade-off that matches the WRO rubric: a technically richer sensor is not automatically the better choice if it makes the system harder to tune without improving real driving performance enough.

## Sensor Trade-Offs

The rubric expects trade-offs, so our final sensor architecture can be summarized as follows:

- camera gives long-range scene understanding but depends more on lighting and perspective;
- ToF sensors give local distance information but only over a limited physical region;
- IMU gives heading stability but cannot identify field objects by itself.

The final robot uses all three because the field changes between rounds and no single sensor type gives enough reliability on its own.

## Sensor Placement Justified By Field Geometry

The rubric explicitly asks for placement justification using field geometry. Our sensor positions were chosen according to what happens on the WRO self-driving track:

- straight sections require early lane and obstacle interpretation;
- corners require stable heading control;
- obstacle challenge sections require side obedience around red and green pillars;
- parking and approach maneuvers require short-range confirmation near the robot.

Based on that geometry:

- the camera is mounted at the front to see the lane and obstacle arrangement before the robot reaches the decision area;
- one distance sensor looks toward the front interaction area for short-range obstacle approach information;
- one distance sensor looks toward the side region for local wall or obstacle spacing;
- the IMU is mounted rigidly near the main structure so yaw measurements reflect the chassis, not a vibrating bracket.

This placement was not chosen because the components only fit there physically. It was chosen because each sensor had to cover a different part of the track geometry.

## Calibration Method

The rubric also asks for calibration, so we documented the actual procedure we use when preparing the robot:

1. mount the `BNO085` rigidly and verify that yaw is stable while the robot is standing still;
2. initialize the two distance sensors one by one so identical modules can coexist reliably on the same bus;
3. verify that both distance sensors produce repeatable readings when the robot is placed in a controlled position relative to a wall or corridor;
4. set the robot heading reference at startup and verify that straight driving does not drift immediately;
5. re-check the sensing system after any change to wheel grip, steering geometry, sensor mount position, or wiring layout.

This process matters because the sensing system is only useful if mechanical and electrical changes are reflected in calibration.

## Wiring And Reproducibility

The repository includes the following reproducibility files for the electronics:

- [PCB And Wiring Diagrams](pcb_wiring_diagrams.md);
- [Wiring Overview](../../schemes/wiring_overview.md);
- [Custom Electronics Schematic PDF](../../schemes/Wro_customPCBs.pdf);
- [Custom Electronics Schematic Description](../../schemes/custom_pcb_description.md).

These files show:

- board responsibilities;
- power branches;
- actuator connections;
- sensor bus structure;
- the actual documented schematic for the robot.

This supports the rubric requirement that another team should be able to rebuild the electronics with reasonable effort.

## Failure Points And Mitigation

The rubric asks for failure-point considerations, so we documented the main electrical and sensing risks:

| Failure point | Likely effect | Mitigation |
| --- | --- | --- |
| Motor and logic sharing one noisy rail | control instability or sensor errors | split motor and regulated logic branches |
| Servo current spike during hard steering | voltage sag and steering inconsistency | separate steering branch with current headroom |
| Two identical distance sensors on one bus | address conflict or no readings | staged startup and software address assignment |
| IMU mounted on flexible structure | unstable heading estimate | rigid mounting and repeated straight-line checks |
| Sensor wires routed near motor current path | noisy or inconsistent readings | keep sensor and logic wiring away from high-current path as much as practical |

## Iteration Evidence

The WRO evaluation pages ask for evidence that the team iterated rather than only listed the final hardware. In electronics, our iterations were mainly about stability and usability:

- we moved away from `VL53L5CX` matrix sensing because the matrix processing was more complex while test results were not better enough for our final robot;
- we refined the sensor startup process so two identical distance modules could be used reliably on the same bus;
- we treated sensor mounting as part of calibration rather than a one-time placement decision;
- we documented separate power branches because unstable mixed wiring would make software tuning less reliable;
- we updated the repository to include both the wiring overview and the actual schematic PDF so the design is more reproducible.

## Engineering Conclusion

Our electronics were designed as a system with four goals:

- reliable power distribution;
- complementary sensing rather than duplicated sensing;
- fast and stable actuator control;
- documentation that judges and other teams can follow.

That is why this section includes architecture, power budget, sensor trade-offs, field-based placement reasoning, calibration, wiring references, and failure analysis instead of only a parts list.
