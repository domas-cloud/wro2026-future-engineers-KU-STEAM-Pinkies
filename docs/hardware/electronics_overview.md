# Electronics overview

Hardware V2 removes the Raspberry Pi Zero and brings the robot back to one main controller: an `ESP32-WROOM-32`. The PixyCam does the colour processing on its own processor and sends object information to the ESP32 over wired SPI.

The previous Pi-based electronics page is kept in [`archivo/`](../../archivo/hardware-v1-esp32-250rpm/docs/hardware/electronics_overview.md).

## Main parts

- ESP32-WROOM-32
- first-generation PixyCam / CMUcam5
- BNO085 IMU
- front VL53L1X
- left and right VL53L4CD
- MG90S steering servo
- LiPo battery (exact pack still being selected)
- faster drive motor (exact model still being selected)
- custom-PCB H-bridge stage (final IC follows the motor choice)

The old `VL53L1CD` side-sensor name found in some V1 text was a documentation mistake. The side sensors used for the current design are `VL53L4CD`.

## Connections

BNO085 and the three ToF sensors share I2C resources. The final schematic/source must agree on the I2C voltage, pull-ups, XSHUT/startup lines, runtime addresses and connector labels.

PixyCam needs power, ground, SCK, controller-to-camera data, camera-to-controller data and chip select. We have not published GPIO numbers yet because they need to match the final PCB instead of an early wiring guess.

## Power

We know the V2 battery chemistry will be LiPo, but the exact pack is not locked. Because of that we are not reusing the old V1 power budget as a V2 result. The old robot used 2x18650 and had an estimated peak budget around 2.32 A; those numbers belong to V1.

For the new board we will measure the ESP32/camera/sensors, steering peak current, motor free/launch/stall current and complete-robot transients. Those measurements decide regulator headroom, connector choice, PCB copper and the motor driver.

The board will keep the high-current motor/servo paths away from sensitive sensor returns as much as practical. We also plan motor-noise suppression, bulk capacitance near high-current loads, reverse-polarity/over-current protection and accessible test points.

## Bring-up order

We will power the first PCB from a current-limited supply or protected source, check each rail with motor and servo disconnected, then bring up the ESP32 and sensors, PixyCam SPI, servo and motor driver one at a time. After that we will repeat the communication tests with the drive system running and record rail sag and temperatures.

The PCB drawings and manufacturing files belong in [`schemes/`](../../schemes/). The build checklist is [`as_built_wiring_checklist.md`](as_built_wiring_checklist.md).
