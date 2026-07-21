# Electronics Overview

Our robot uses a split electronics system. The `Raspberry Pi Zero` and camera handle perception, while the `ESP32` handles low-level control, steering, and motor output.

That split gave us two practical benefits:

- the camera side could focus on track and obstacle interpretation;
- the controller side could stay fast and predictable.

## Main Electronic Parts

The final electronics system includes:

- `Raspberry Pi Zero`
- camera module
- `ESP32-WROOM-32`
- `BNO085` IMU
- one front `VL53L1X` ToF sensor
- `2x VL53L1CD` distance sensors
- `MG90S` steering servo
- `N20 6 V 250 rpm` drive motor
- `L298N` motor driver
- `2x 18650 Li-ion` battery pack
- step-down regulation and perfboard-based distribution

## Board Roles

The `Raspberry Pi Zero` is responsible for perception. It can decide which driving line is safer or which side should be used around an obstacle.

The `ESP32` is responsible for:

- reading the IMU and distance sensors;
- holding the heading reference;
- applying wall-distance correction;
- driving the steering servo;
- controlling the drive motor.

So the robot is not built around one giant controller that tries to do everything. It is split into a perception layer and a control layer.

## Power Layout

The robot is powered by a 2-cell `18650` pack, treated in our documentation as about `7.4 V` nominal under normal use.

From that source we separate power into several branches:

- motor branch for the `L298N` and drive motor;
- regulated logic branch for the `ESP32`;
- regulated logic branch for the `Raspberry Pi Zero`;
- regulated sensor branch for the IMU and distance sensors;
- steering branch for the servo.

We used separate branches because the drive motor and servo can disturb logic power if everything is tied together without enough isolation.

## Current Budget

The current values below are the practical design values we used in the documentation.

| Subsystem | Main parts | Rail type | Design assumption |
| --- | --- | --- | --- |
| Logic compute | `Raspberry Pi Zero`, `ESP32` | regulated logic rail | `720 mA` continuous |
| Sensors | `BNO085`, `VL53L1X`, `2x VL53L1CD` | regulated sensor rail | `132.3 mA` continuous |
| Steering | `MG90S` servo | steering branch | `800 mA` peak |
| Drive | `N20` + `L298N` | battery / motor branch | `0.67 A` peak |
| Total | all branches together | battery input | about `2.32 A` peak |

The total peak budget comes from the documented working assumptions: `0.72 A + 0.1323 A + 0.8 A + 0.67 A = 2.3223 A`.

In practice, the current demand stayed similar during normal driving because the steering linkage was built to move freely. The servo was not used near stall torque during autonomous driving, so steering did not create the kind of large current spike that would be expected from a jammed or overloaded linkage.

## Why We Kept Regulated Power

Regulated power mattered for a few reasons:

- neither the `ESP32` nor the `Raspberry Pi Zero` should be fed from raw battery voltage;
- noisy logic power makes sensor data less trustworthy;
- the servo and drive motor can cause voltage sag during aggressive movement;
- a structured power layout is easier to debug and easier to rebuild.

## Sensor Set

We used several sensor types because they solve different problems.

### Camera

The camera gives a wider view of the track. That is useful for lane interpretation and obstacle-side decisions before the robot reaches the immediate interaction zone.

### IMU

The `BNO085` helps keep the robot aligned with its heading target. Without yaw feedback, straight driving and repeatable 90-degree turns would be much harder.

### Distance Sensors

The distance sensors are used as:

- `front VL53L1X` for turn timing and close-range detection;
- `left VL53L1CD` for side-distance feedback;
- `right VL53L1CD` for the opposite side.

Together, they give the controller local geometry that the camera alone cannot guarantee at short range.

## Why We Stayed With This ToF Layout

We also tried `VL53L5CX` matrix sensors during development. They offered richer data, but the added complexity was not worth it for this robot.

For our final system, the `VL53L1X` + `VL53L1CD` layout was easier to integrate, easier to tune, and more practical for repeatable close-range sensing.

## Sensor Placement

The placement follows the job of each sensor:

- the camera watches the wider scene ahead;
- the front `VL53L1X` watches the area used for turn triggering;
- the side `VL53L1CD` sensors watch wall or obstacle spacing;
- the IMU is mounted rigidly so the yaw estimate follows the chassis, not a flexible bracket.

## Calibration Routine

Our basic setup routine is:

1. make sure the `BNO085` is mounted rigidly and gives stable yaw when the robot is still;
2. initialize the front and side distance sensors in the intended startup sequence so they can share the bus with different addresses;
3. verify repeatable distance readings against known positions;
4. check that the perception layer and the low-level controller agree on the intended driving line;
5. verify that straight driving does not drift immediately after startup;
6. repeat these checks after any meaningful mechanical or wiring change.

## Main Electrical Risks

The most important practical electrical risks were:

| Risk | Likely effect | Mitigation |
| --- | --- | --- |
| motor noise on logic rails | unstable control or noisy sensor data | split power branches |
| servo current spikes | voltage sag and steering inconsistency | separate steering branch with headroom |
| ToF sensors on one bus | address conflict or missing readings | staged startup and address assignment |
| flexible IMU mounting | unstable yaw estimate | rigid mounting and repeated checks |
| sensor wires near motor path | inconsistent readings | keep logic and sensor wiring away from high-current paths |

## Why This Layout Stayed

We kept this electronics layout because it gave us:

- stable power distribution;
- a clean separation between perception and control;
- reliable local sensing for the low-level controller;
- documentation that another team can actually follow.
