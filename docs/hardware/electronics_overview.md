# Electronics Overview

## Active architecture

Hardware V2 uses one central `ESP32-WROOM-32` control system together with a first-generation `PixyCam` that performs colour-object processing on its own processor.

The previous Raspberry Pi Zero architecture was copied before this update to:

[`archivo/hardware-v1-esp32-250rpm/docs/hardware/electronics_overview.md`](../../archivo/hardware-v1-esp32-250rpm/docs/hardware/electronics_overview.md)

The Raspberry Pi Zero is not part of the active Hardware V2 robot. It remains preserved as Hardware V1 development history.

## System data flow

```text
red / green traffic pillar
        |
        v
first-generation PixyCam
(onboard colour-signature processing)
        |
        | wired SPI block data
        v
ESP32-WROOM-32
        |
        +--> heading and distance control
        +--> obstacle-side decision
        +--> MG90S steering output
        +--> motor-driver PWM / direction output
```

The PixyCam is not intended to stream full images to the ESP32. It should provide compact detection results such as the colour signature, object centre position and object size. The ESP32 combines that information with IMU and ToF measurements.

## Confirmed electronic parts

- `ESP32-WROOM-32` main controller;
- first-generation `PixyCam` / CMUcam5;
- wired `SPI` connection between PixyCam and ESP32;
- `BNO085` IMU;
- one front `VL53L1X` ToF sensor;
- two side `VL53L4CD` ToF sensors;
- `MG90S` steering servo;
- LiPo battery architecture, exact specification still `TBD`;
- faster drive motor, exact model still `TBD`;
- custom PCB motor-driver stage, exact driver IC still `TBD`.

## Controller responsibilities

The `ESP32-WROOM-32` is responsible for:

- initializing and reading the `BNO085`;
- initializing and reading the front and side ToF sensors;
- receiving PixyCam object information over SPI;
- deciding the legal obstacle-passing side from the colour signature;
- holding the heading target;
- applying wall-distance and obstacle-line corrections;
- controlling the `MG90S` steering servo;
- controlling the drive motor through the selected H-bridge;
- handling timeouts, missing sensor data and safe-stop behaviour.

## PixyCam responsibilities

The first-generation PixyCam is responsible for:

- acquiring the forward camera image;
- applying its trained colour signatures;
- identifying red and green WRO traffic pillars;
- returning detected block information to the ESP32.

The intended training setup is:

| Pixy signature | Intended object | Robot action after validation |
|---|---|---|
| red-pillar signature | red traffic pillar | select a path that passes on the required side |
| green-pillar signature | green traffic pillar | select the opposite required passing path |

The exact signature numbers, thresholds, lighting settings and reliable detection distances remain `TBD` until recorded from the real camera and field.

## Sensor architecture

### Orientation

The `BNO085` supplies fused yaw / heading feedback. It should be mounted rigidly so that its orientation follows the chassis rather than a flexible cable or bracket.

### Distance sensing

The confirmed ToF set is:

- front `VL53L1X` — front-distance measurement and turn trigger;
- left `VL53L4CD` — left-side spacing;
- right `VL53L4CD` — right-side spacing.

The older `VL53L1CD` name in some Hardware V1 documents was incorrect for the side sensors. Archived files remain unchanged as historical snapshots; active Hardware V2 documents use `VL53L4CD`.

### I2C requirements

The final schematic and firmware must document:

- the I2C voltage level;
- pull-up values and where they are installed;
- XSHUT or startup-control lines used to avoid address conflicts;
- final runtime addresses;
- initialization order;
- timeout and missing-sensor behaviour;
- connector labels matching physical positions.

## SPI requirements for PixyCam

The custom PCB must provide:

- camera power and ground;
- SPI clock;
- controller-to-camera data;
- camera-to-controller data;
- chip-select;
- verified logic-level compatibility;
- clear connector orientation and pin-1 marking;
- a cable arrangement that cannot be pulled loose during testing.

Exact ESP32 GPIO numbers remain `TBD` until the final PCB pin map is approved.

## Power architecture

Hardware V2 will use a LiPo battery, but the following are not yet known:

- cell count;
- nominal and fully charged voltage;
- capacity;
- C-rating;
- connector type;
- maximum expected current.

Because these values are unknown, the final power budget and regulator selections are not yet valid. Hardware V1 values such as the `2x 18650` pack and approximately `2.32 A` peak budget must not be copied into Hardware V2 as final values.

The custom PCB should separate or carefully filter these current paths:

1. battery input and protection;
2. motor power;
3. servo power;
4. ESP32 logic power;
5. PixyCam power;
6. IMU and ToF sensor power.

All branches need a common electrical reference, but high motor and servo return current should not be routed through sensitive sensor-ground paths.

## Power budget that must be measured

| Load | Required measurement | Status |
|---|---|---|
| ESP32 control system | idle and active current | TBD |
| first-generation PixyCam | normal detection current and startup peak | TBD |
| BNO085 + ToF sensors | combined continuous current | TBD |
| MG90S | typical steering and peak / near-stall current | TBD |
| selected motor | free-run, loaded, launch and stall current | TBD |
| regulators and driver | conversion loss and temperature | TBD |
| complete robot | idle, normal run and worst observed transient | TBD |

The motor driver, LiPo, connectors, copper width, protection and regulators must be selected from these measurements rather than from rpm alone.

## Main electrical risks

| Risk | Likely effect | Required mitigation / evidence |
|---|---|---|
| unknown LiPo voltage | damaged regulators or insufficient motor voltage | lock exact battery specification before schematic release |
| underestimated motor stall current | overheated or damaged H-bridge | measure stall current and document design margin |
| servo transient current | ESP32 reset or sensor disturbance | separate supply path, bulk capacitance and rail-sag test |
| motor noise | unstable SPI/I2C or false sensor readings | suppression, layout separation and motor-on communication test |
| PixyCam lighting sensitivity | incorrect red/green decision | signature training and repeated field tests under varied lighting |
| I2C address conflict | missing ToF data | controlled startup, documented addresses and failure handling |
| wrong SPI voltage or pinout | unreliable camera data or damage | verify levels and publish complete pin map |
| loose connectors | intermittent failures | keyed / retained connectors and strain relief |

## Verification sequence

1. Approve the block diagram and exact component list.
2. Select the LiPo, motor and motor driver.
3. Calculate voltage and current margins.
4. Review the schematic and PCB layout.
5. Power the board from a current-limited supply with motor and servo disconnected.
6. Verify each rail and test point.
7. Bring up the ESP32, IMU and ToF sensors.
8. Bring up PixyCam SPI communication.
9. Connect servo and measure transients.
10. Connect the motor and validate the H-bridge under load.
11. Test all communication while motor and servo are active.
12. Complete repeated Open and Obstacle field runs.

## Evidence required for final documentation

- final schematic and editable source;
- PCB layout and Gerbers;
- connector and ESP32 pin map;
- exact LiPo, motor and driver datasheets;
- current, voltage and temperature measurements;
- PixyCam training screenshots;
- red / green detection test table;
- oscilloscope or multimeter evidence of rail stability where available;
- assembled PCB top and bottom photos;
- first-power-up and failure log;
- Hardware V1 versus Hardware V2 comparison.

Until this evidence exists, Hardware V2 should be described as the active confirmed design direction, not as a completed final electronics system.
