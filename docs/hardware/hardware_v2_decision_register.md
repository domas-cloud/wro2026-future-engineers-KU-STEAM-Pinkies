# Hardware V2 decisions

This is a compact record of the parts we have already chosen and the choices that are still open.

| Area | Current decision | What is left to prove/choose |
|---|---|---|
| controller | ESP32-WROOM-32 | final PCB implementation and GPIO map |
| vision computer | Raspberry Pi Zero removed | old Pi work stays in the archive |
| camera | first-generation PixyCam / CMUcam5 | final mounting and PixyMon settings |
| camera link | wired SPI | GPIOs, stable clock and motor-on test |
| front ToF | VL53L1X | final position, address/settings and repeatability |
| side ToF | 2x VL53L4CD | positions, addresses/startup and motor-on test |
| IMU | BNO085 | final orientation/mounting and calibration check |
| steering | MG90S | peak current and higher-speed repeatability |
| battery | LiPo | exact pack and protection/regulator design |
| drive motor | faster than the V1 250 rpm motor | exact model and loaded tests |
| motor driver | custom-PCB H-bridge | exact IC after motor current is known |
| integration | custom PCB | schematic, layout, manufacturing files and bring-up |
| software | clean V2 rewrite | implement after PCB interfaces are stable |
| final testing | repeat V1-style tests plus power/camera tests | collect results on the finished car |

The previous robot is still useful evidence: it used a Pi Zero, ESP32 development board, perfboard, N20 250 rpm motor, L298N and 2x18650 battery. Those are not current V2 parts unless a page explicitly discusses the old build.

When one of the open choices becomes real, we will update this page with the exact part and link to the test or file that made us keep it. We do not use separate status codes anymore; plain text should make it clear whether something is selected, being tested or still unknown.
