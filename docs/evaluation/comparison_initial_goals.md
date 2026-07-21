# Comparison With Initial Goals And Current Redesign

## Status

The previous final-outcome table was archived at [`archivo/hardware-v1-esp32-250rpm/docs/evaluation/comparison_initial_goals.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/evaluation/comparison_initial_goals.md).

This table separates the verified Hardware V1 outcome from the incomplete Hardware V2 target.

| Area | Initial goal | Hardware V1 evidence | Hardware V2 direction | V2 evidence still required |
|---|---|---|---|---|
| steering | compact, controllable front steering | MG90S, corrected geometry, bearings and silicone wheels | retain the working mechanical concept unless testing requires change | final dimensions, load and faster-speed validation |
| drivetrain | usable speed with enough torque | 50/250/1000 rpm N20 comparison; 250 rpm retained for V1 | select a faster motor | exact model, current, torque, loaded speed and repeated runs |
| differential | smooth rear-axle turning | LEGO differential reduced binding | currently retained | final motor/differential compatibility test |
| perception | detect obstacle colour | Raspberry Pi camera/OpenCV development | first-generation PixyCam with onboard processing | signatures, SPI code, detection matrix and videos |
| controller | stable real-time control | ESP32 low-level controller | ESP32-WROOM-32 remains central | final PCB pin map and verified firmware |
| distance/orientation | heading plus local spacing | BNO085, front VL53L1X and side ToF | BNO085 + VL53L1X + 2x VL53L4CD | mounting, addresses, startup and reliability results |
| power | stable supply for logic and actuators | 2x18650 and module/perfboard architecture | LiPo and custom PCB | exact pack, regulators, current budget and protection |
| documentation | rebuildable GitHub record | V1 code, media, CAD, wiring and measurements | complete V2 manufacturing and validation package | final BOM, PCB files, code, calibration and final media |

## Current conclusion

Hardware V1 proved several mechanical and control ideas. Hardware V2 is not simply renamed V1: it changes perception, power, drive and electronics integration. The remaining work must be shown with real artifacts and measurements rather than rewritten as if already complete.
