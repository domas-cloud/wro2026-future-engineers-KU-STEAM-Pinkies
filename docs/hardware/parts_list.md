# Bill Of Materials (BOM)

This BOM is written as a rebuild guide, not only as a summary of what we used.
Another team should be able to use this page as a shopping and fabrication checklist for a functionally equivalent robot.

## How To Read This BOM

- `Exact part name` is the preferred item to buy or fabricate.
- `Manufacturer / model` uses the exact vendor when it is known from the final build documentation.
- `Generic` means the repository documents the part class and key specification, but not a single locked vendor.
- `Custom` means the part must be made from the files in `models/` or by matching the documented geometry.
- If an alternative is used, the team should re-check mounting, power budget, and control tuning.

## Rebuild BOM

| Category | Exact part name | Manufacturer / model | Qty | Key specification | Used for | Alternative |
| --- | --- | --- | --- | --- | --- | --- |
| compute board | Low-level controller board | Espressif `ESP32-WROOM-32` development board | 1 | `3.3 V` logic, I2C, UART, PWM-capable GPIO | Real-time control, sensor polling, servo PWM, motor-driver control | Another `ESP32` dev board with the same voltage level and a remapped pinout |
| compute board | Perception board | Raspberry Pi `Raspberry Pi Zero` | 1 | `5 V` SBC, CSI camera connector, UART link to controller | Camera processing and high-level lane / obstacle decisions | `Raspberry Pi Zero 2 W` if power budget and thermal behavior are re-checked |
| camera | Wide-angle camera module | Generic `OV5647 5 MP` Pi camera | 1 | CSI interface, wide field of view, Pi-compatible | Forward scene perception for lane and obstacle interpretation | Another Pi-compatible wide-angle CSI camera with recalibrated vision parameters |
| IMU | 9-DOF inertial measurement unit | CEVA / Hillcrest Labs `BNO085` breakout | 1 | I2C IMU with fused yaw output, address `0x4A` or `0x4B` | Heading reference and straight-line stabilization | `BNO086` with matching firmware support and the same rigid mounting quality |
| ToF sensor | Front distance sensor | STMicroelectronics `VL53L1X` breakout | 1 | ToF sensor, I2C, used as the forward trigger sensor | Front wall detection and turn trigger | Equivalent front ToF only after retuning thresholds and startup sequence |
| ToF sensor | Left distance sensor | STMicroelectronics `VL53L4CD` breakout | 1 | Short-range ToF, I2C, unique runtime address after XSHUT setup | Left-side wall distance correction | Equivalent short-range ToF only after retuning thresholds and startup sequence |
| ToF sensor | Right distance sensor | STMicroelectronics `VL53L4CD` breakout | 1 | Short-range ToF, I2C, unique runtime address after XSHUT setup | Right-side wall distance correction | Equivalent short-range ToF only after retuning thresholds and startup sequence |
| motor driver | DC motor driver module | Generic `L298N` module | 1 | H-bridge driver, PWM + direction control, battery motor rail input | Drives the rear DC motor | Smaller H-bridge module only if stall current, voltage drop, and cooling are still acceptable |
| motor | Rear drive motor | Generic `N20 6 V 250 rpm` geared DC motor | 1 | `6 V`, about `250 rpm`, metal gearbox form factor | Rear-wheel propulsion | Another `N20`-format motor near the same speed/torque range, followed by control retuning |
| servo | Steering servo | Tower Pro `MG90S` metal-gear micro servo | 1 | `5 V` micro servo, metal gears, PWM control | Front-wheel steering actuation | Higher-torque micro servo if the steering geometry or wheel load changes |
| batteries | Main battery pack | Generic `2x 18650 Li-ion` holder + 2 matched cells | 1 | 2-cell pack, about `7.4 V` nominal, sized for about `2.32 A` system peak budget | Main robot power source | Protected 2-cell Li-ion or LiPo pack with similar voltage and equal or better current margin |
| regulators | Logic / sensor step-down regulator | Generic buck regulator module | 2 | `5 V` regulated output, enough margin for logic and sensor rails | Stable supply for `ESP32`, `Raspberry Pi Zero`, IMU, and ToF sensors | Equivalent buck converter modules with verified current headroom and low-noise output |
| connectors | Perfboard power / signal distribution set | Generic perfboard, pin headers, Dupont leads, JST-style leads, screw terminals | 1 set | Common-ground distribution, separate logic / sensor / motor / servo branches | Interconnects and power distribution between all modules | Any equivalent connector set if wire gauge, labeling, and strain relief remain clear |
| structural part | Main chassis plate and mounting structure | Custom wood frame | 1 set | Approx. `21 x 10 x 8 cm` robot package, supports compact rear-drive layout | Holds drivetrain, electronics, sensors, and camera in final geometry | Another rigid chassis with the same wheelbase and mounting geometry, followed by mechanical retuning |
| structural part | Rear differential | LEGO differential element | 1 | Mechanical differential for rear axle | Reduces drag in turns and improves handling consistency | Fixed rear axle only with major handling tradeoffs and controller retuning |
| structural part | Rear wheels | LEGO wheels | 2 | Matching rear-wheel diameter and width for the published drivetrain | Rear traction on the driven axle | Equivalent wheels with similar diameter and grip, followed by tuning updates |
| structural part | Front wheels | Custom silicone wheels | 2 | Lightweight steering wheels with stable grip and matching steering geometry | Front steering contact and grip | Recast wheels from the same mold or equivalent wheels with matching diameter and scrub behavior |
| custom printed part | Steering gear set | Custom 3D-printed parts from `models/` | 1 set | STL-based steering transmission geometry matched to `MG90S` servo output | Transfers servo motion to the front steering system | Reprint from the provided CAD files or regenerate matching geometry if the servo horn or linkage changes |
| custom printed part | Brackets and sensor / board mounts | Custom 3D-printed parts from `models/` | 1 set | Mounts for steering-related geometry and supporting structure | Keeps boards, sensors, and steering parts aligned in the documented layout | Reprint from the provided CAD files or redesign with the same sensor positions and stiffness |

## Notes For Rebuild Teams

- The two `VL53L4CD` modules and the front `VL53L1X` share one I2C bus, so the shutdown / startup sequence still matters during initialization.
- Keep the motor-current path separate from sensor and logic wiring, then join all subsystems at a common ground point.
- The repository documents a perfboard-based implementation, so teams do not need a fabricated PCB to reproduce the electrical architecture.
- Custom printed parts should be taken from `models/` and checked together with `docs/design/drivetrain_and_steering.md` and `docs/design/chassis_design_improved.md`.
- If a substitute part is used in compute, sensing, steering, or drivetrain hardware, expect to recalibrate software thresholds and steering / speed gains.
