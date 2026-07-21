# Iteration Log

This page summarizes the engineering decisions that are already supported by the repository. It avoids invented dates or unlogged measurements.

## Decision Timeline

| Iteration | Problem observed | Change made | Evidence location | Result |
| --- | --- | --- | --- | --- |
| older robot comparison | larger, more complicated mechanism was harder to control | new robot made smaller and mechanically simpler | [README.md](../../README.md), [engineering_decisions.md](../design/engineering_decisions.md) | lower-friction platform that was easier to tune |
| drivetrain choice | cornering resistance hurt repeatability | kept rear differential | [drivetrain_and_steering.md](../design/drivetrain_and_steering.md), [performance_measurements.md](performance_measurements.md) | smoother turning and less resistance |
| steering geometry | steering load and center repeatability limited accuracy | simplified steering geometry and custom steering parts | [models/README.md](../../models/README.md), [drivetrain_and_steering.md](../design/drivetrain_and_steering.md) | more stable center behavior |
| motor selection | motor speed/torque balance affected control | selected `N20 6 V 250 rpm` motor | [motor_servo_selection.md](../hardware/motor_servo_selection.md), [performance_measurements.md](performance_measurements.md) | better balance than slower/faster alternatives |
| distance sensing | robot needed front and side distance information | used front, left, and right ToF sensors | [sensor_list.md](../hardware/sensor_list.md), [pcb_wiring_diagrams.md](../hardware/pcb_wiring_diagrams.md) | enough short-range information for control |
| heading stability | loose IMU readings can create steering error | mounted `BNO085` more rigidly | [sensor_list.md](../hardware/sensor_list.md), [performance_measurements.md](performance_measurements.md) | more stable heading behavior |
| controller split | camera/perception and real-time motor control have different timing needs | separated Pi Zero perception from ESP32 low-level control | [software_architecture_improved.md](../code/software_architecture_improved.md), [vision_interface.md](../code/vision_interface.md) | clearer runtime responsibilities |

## How To Extend This Log

| Date | Commit | Problem | Change | Test | Result | Keep / reject |
| --- | --- | --- | --- | --- | --- | --- |
| `YYYY-MM-DD` | `commit hash` | real observed issue | one meaningful change | repeated test scenario | measured or counted result | decision |

## Evidence Rule

Only add a result as final evidence if it is backed by one of these:

- a counted run table;
- a measurement table;
- a photo or video;
- a code commit;
- a documented hardware change that matches the final robot.

