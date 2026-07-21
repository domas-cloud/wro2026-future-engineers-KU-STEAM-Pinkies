# Bill Of Materials (BOM)

## Documentation status

This is the active Hardware V2 BOM. The complete pre-migration Hardware V1 BOM was copied before this update to:

[`archivo/hardware-v1-esp32-250rpm/docs/hardware/parts_list.md`](../../archivo/hardware-v1-esp32-250rpm/docs/hardware/parts_list.md)

Hardware V2 is still under development. A part marked `TBD` is intentionally not guessed and must not be treated as final until the exact component or measurement is available.

## Confirmed Hardware V2 BOM

| Category | Exact part / decision | Qty | Interface or key specification | Status | Purpose |
|---|---|---:|---|---|---|
| main controller | Espressif `ESP32-WROOM-32` | 1 | `3.3 V` logic; I2C, SPI, PWM and GPIO capability | confirmed | central real-time control, sensing, navigation decisions and actuator output |
| perception camera | first-generation `PixyCam` / CMUcam5 | 1 | onboard colour-object processing | confirmed | detect red and green WRO traffic pillars |
| camera interface | wired `SPI` connection between PixyCam and ESP32 | 1 | clock, controller-to-camera data, camera-to-controller data, chip select, power and ground | confirmed | transfer detected block information without Raspberry Pi |
| IMU | `BNO085` breakout | 1 | I2C, fused yaw / heading output | confirmed | heading reference and turn control |
| front ToF | `VL53L1X` breakout | 1 | I2C | confirmed | front-distance measurement and turn triggering |
| side ToF | `VL53L4CD` breakout | 2 | I2C, left and right positions | confirmed | local wall and obstacle spacing |
| steering servo | Tower Pro `MG90S` or the already documented equivalent unit | 1 | PWM, nominal 5 V class supply | confirmed | front-wheel steering |
| power source | LiPo battery | 1 | cell count, nominal voltage, maximum voltage, capacity, C-rating and connector `TBD` | partially confirmed | main robot energy source |
| drive motor | faster geared DC motor replacing Hardware V1 `N20 250 rpm` | 1 | exact model, voltage, rpm, torque, gearbox and current `TBD` | TBD | rear-axle propulsion |
| motor driver | H-bridge stage for custom PCB | 1 | exact IC and current/thermal rating `TBD` | TBD | PWM and direction control for the selected motor |
| custom PCB | Hardware V2 control and power board | 1 | ESP32 control, PixyCam SPI, I2C sensors, servo, motor stage and protected power input | in design | replaces the Hardware V1 development-board/perfboard integration |
| power regulation | regulated logic, camera, sensor and servo power branches | as required | topology and ratings depend on final LiPo and load measurements | TBD | stable power distribution |
| main switch and start input | wired competition controls | 1 each | exact connector and pinout `TBD` | required | legal startup and round control |

## Mechanical parts currently retained from the documented robot

These parts remain the current mechanical baseline unless later testing records a replacement:

| Category | Part | Qty | Status / role |
|---|---|---:|---|
| chassis | custom wood frame and mounting structure | 1 set | current compact chassis baseline |
| rear differential | LEGO differential element | 1 | rear driven axle and smoother cornering |
| rear wheels | matching LEGO wheels | 2 | driven-wheel pair |
| front wheels | custom silicone wheels | 2 | steering grip and repeatable response |
| steering transmission | custom 3D-printed parts from `models/` | 1 set | matched to the MG90S steering layout |
| brackets and mounts | custom printed / fabricated parts | 1 set | maintain sensor, camera, PCB and steering alignment |

## Components removed from the active Hardware V2 BOM

The following items remain documented only as Hardware V1 development evidence:

- `Raspberry Pi Zero`;
- Raspberry Pi CSI camera;
- Pi-to-ESP32 UART perception architecture;
- `2x 18650 Li-ion` battery holder and cells;
- Hardware V1 perfboard distribution;
- Hardware V1 `L298N` module as the assumed final driver;
- Hardware V1 `N20 6 V 250 rpm` motor as the assumed final motor.

They were not deleted. Their earlier BOM is preserved in the archive link above.

## Sensor and bus notes

- The correct active side-sensor model is `VL53L4CD`, not `VL53L1CD`.
- The front `VL53L1X`, both side `VL53L4CD` sensors and the `BNO085` use the I2C side of the architecture.
- The final schematic and firmware must document runtime I2C addresses, XSHUT/startup sequencing where required, pull-ups and timeout handling.
- The first-generation PixyCam uses a separate wired SPI link to the ESP32.
- Connectors should be labelled by physical role: `PIXy`, `FRONT_TOF`, `LEFT_TOF`, `RIGHT_TOF`, `IMU`, `SERVO`, `MOTOR`, `START` and power input.

## Data still required before this becomes a final rebuild BOM

1. Exact drive-motor model and datasheet.
2. Loaded motor speed, running current and stall current on the robot.
3. Exact motor-driver IC and thermal design.
4. LiPo cell count, voltage, capacity, C-rating and connector.
5. Final regulator parts and current headroom.
6. ESP32 physical PCB implementation and complete pin map.
7. Custom PCB dimensions, mounting holes, layer count and fabrication files.
8. Verified PixyCam power requirement and final SPI pin assignment.
9. Final measured robot mass and dimensions after Hardware V2 assembly.

## Rebuild rule

Another team should only use the active Hardware V2 table as a final shopping list after every `TBD` field has been replaced with a verified exact value. Until then, Hardware V1 remains the reproducible complete baseline and Hardware V2 remains the documented migration target.
