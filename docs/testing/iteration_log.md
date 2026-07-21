# Engineering Iteration Log

## Status

The previous log was archived at [`archivo/hardware-v1-esp32-250rpm/docs/testing/iteration_log.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/testing/iteration_log.md).

## Documented Hardware V1 iterations

| Iteration | Problem | Change | Evidence | Result status |
|---|---|---|---|---|
| smaller chassis direction | larger mechanism was difficult to control | simplified and reduced the robot | README, system overview | supported qualitatively |
| differential | turning resistance and binding | retained LEGO differential over metal alternative | drivetrain document and photos | supported by tests/observations |
| steering geometry | high servo load and weak centring | reduced the lever arm and added later refinements | drivetrain document and CAD | supported by repeated practical comparison |
| front wheels | steering command lost through slip | used custom silicone front wheels | photos and mechanical documents | supported qualitatively |
| V1 motor selection | speed/torque balance | compared `50`, `250` and `1000 rpm` N20 options | drivetrain and performance files | `250 rpm` retained for Hardware V1 |
| heading/local sensing | straight and corner consistency | used BNO085 and three ToF sensors | source and measurement documents | supported by Hardware V1 operation |
| V1 perception | colour/obstacle development | Raspberry Pi/OpenCV and UART experiments | legacy source | archived; not active V2 architecture |

## Hardware V2 migration decisions

| Date | Decision | Reason | Current state | Evidence still required |
|---|---|---|---|---|
| 2026-07-21 | keep ESP32-WROOM-32 | retain known real-time control platform | confirmed | final PCB implementation |
| 2026-07-21 | remove Raspberry Pi Zero | simplify compute/power stack | confirmed | final Pixy-based operation |
| 2026-07-21 | use first-generation PixyCam over SPI | onboard colour processing | confirmed | code, settings and detection tests |
| 2026-07-21 | use VL53L1X + 2x VL53L4CD + BNO085 | retain local sensing and correct side-sensor designation | confirmed | mounting/startup reliability |
| 2026-07-21 | move to LiPo | new power direction | partial | exact pack and power validation |
| 2026-07-21 | select a faster motor | increase speed beyond V1 baseline | open | candidate comparison and final choice |
| 2026-07-21 | create custom PCB | improve integration and reproducibility | in design | complete PCB package and bring-up |

## Required entry format for future work

| Date | Commit | Physical revision | Problem | Change | Test method | Measured result | Keep/reject | Evidence link |
|---|---|---|---|---|---|---|---|---|
| `TBD` | `TBD` | `TBD` | observed issue | one controlled change | repeated scenario | measured/count result | decision | photo/video/file |

Only measured or directly observed results should be entered as final evidence.
