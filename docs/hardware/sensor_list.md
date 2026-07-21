# Hardware V2 Sensor List

## Status

This is the active Hardware V2 sensor summary. The previous version was copied to [`archivo/hardware-v1-esp32-250rpm/docs/hardware/sensor_list.md`](../../archivo/hardware-v1-esp32-250rpm/docs/hardware/sensor_list.md) before this rewrite.

## Confirmed sensors

| Sensor | Quantity | Interface | Confirmed role | Evidence still required |
|---|---:|---|---|---|
| first-generation `PixyCam` / CMUcam5 | 1 | wired SPI | onboard red/green traffic-pillar detection | exact revision photo, power requirement, trained signatures and field tests |
| `BNO085` | 1 | I2C | fused yaw / heading feedback | final mounting orientation and calibration log |
| `VL53L1X` | 1 | I2C | front-distance measurement and corner approach sensing | final position, settings, address and repeatability |
| `VL53L4CD` | 2 | I2C | left/right local spacing | final positions, addresses, startup sequence and repeatability |

The correct active side-sensor model is `VL53L4CD`. Earlier text that said `VL53L1CD` is retained only in archived historical snapshots.

## Sensor responsibilities

### PixyCam

The PixyCam performs colour-signature processing on its own processor. Hardware V2 intends to use it for red and green WRO traffic pillars and transfer compact block data to the ESP32 over SPI.

The final documentation must record:

- exact signature numbers;
- training screenshots or exported settings;
- minimum accepted block size;
- selection rule when several blocks are visible;
- rejection of ambiguous or stale data;
- first reliable detection distance at final driving speed;
- false-positive and false-negative observations under different lighting.

### BNO085

The BNO085 provides heading feedback. It must be mounted rigidly and its coordinate orientation must be documented. The final runtime must state the report type, update rate, address and failure behaviour.

### ToF sensors

The front sensor and both side sensors serve different geometric roles. The final documentation must include:

- physical height, angle and distance from the robot centre lines;
- connector labels `FRONT_TOF`, `LEFT_TOF`, `RIGHT_TOF`;
- I2C voltage and pull-ups;
- runtime addresses;
- XSHUT or startup-control sequence;
- filtering and timeout behaviour;
- tests with the motor and servo active.

## Placement status

Exact Hardware V2 mounting measurements are not yet available. They must be added after the final PCB, camera bracket and chassis layout are assembled. Until then, this file records sensor roles, not invented positions.

## Rejected or historical options

Earlier development included Raspberry Pi camera processing and investigation of other distance-sensor arrangements. Those are Hardware V1 development evidence and do not define the active Hardware V2 sensor architecture.
