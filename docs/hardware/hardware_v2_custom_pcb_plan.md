# Hardware V2: Custom PCB Migration Plan

## Status

Hardware V2 is the active redesign direction. The verified Hardware V1 implementation remains preserved in `archivo/hardware-v1-esp32-250rpm/` and in the repository history. No Hardware V1 evidence is deleted when an active document is updated.

This document separates three evidence levels:

- **confirmed** — the team has selected the component or architecture;
- **TBD** — the team has not selected the exact specification yet;
- **verified** — the final assembled Hardware V2 system has passed measured bench and field tests.

Hardware V2 is currently **confirmed in architecture but not yet fully verified**.

## Confirmed Hardware V2 architecture

| Subsystem | Confirmed Hardware V2 decision | Interface / role | Evidence state |
|---|---|---|---|
| main controller | Espressif `ESP32-WROOM-32` | central real-time controller | confirmed |
| perception | first-generation `PixyCam` / CMUcam5 | camera performs onboard colour-object processing | confirmed |
| camera link | wired `SPI` | PixyCam sends detected block information to the ESP32 | confirmed |
| front distance | `1x VL53L1X` | front-distance and turn-trigger sensing over I2C | confirmed |
| side distance | `2x VL53L4CD` | left and right local-distance sensing over I2C | confirmed |
| orientation | `BNO085` | fused yaw / heading feedback | confirmed |
| steering | `MG90S` | PWM-controlled front steering servo | confirmed |
| power source | LiPo battery | exact cell count, voltage, capacity, C-rating and connector not selected | partially confirmed / TBD |
| drive motor | faster replacement for the Hardware V1 `250 rpm` motor | exact model, voltage, speed, torque and current not selected | TBD |
| motor driver | custom-PCB drive stage | exact IC and thermal design depend on the selected motor | TBD |

## Architecture change from Hardware V1

Hardware V1 used a Raspberry Pi Zero and camera for perception together with an ESP32 low-level controller. Hardware V2 removes the Raspberry Pi Zero from the active robot.

The new data path is:

```text
first-generation PixyCam
  -> onboard colour-signature processing
  -> SPI block data
  -> ESP32-WROOM-32
  -> navigation decision
  -> motor and MG90S steering commands
```

This reduces the compute stack and removes the Pi boot process, Pi camera interface, Pi-to-ESP32 UART packet layer and the Pi power branch. The old architecture remains archived as development evidence.

## PixyCam role

The first-generation PixyCam is intended to be trained in its own software for the WRO traffic pillars:

- colour signature for the red pillar;
- colour signature for the green pillar.

The camera performs image processing on its own processor. The ESP32 should receive compact object information such as the detected signature, object centre position and object size. The final documentation must not claim detection reliability until it is measured on the real field under different lighting conditions.

Required PixyCam validation:

- red and green pillars detected separately;
- no repeated confusion between field colours and pillars;
- object position remains usable at approach speed;
- SPI data remains stable while the motor and servo are active;
- stale or missing camera data produces a safe fallback;
- detection and reaction distance are tested with the final faster motor.

## Correct sensor set

The Hardware V2 sensor set is:

- front: `VL53L1X`;
- left: `VL53L4CD`;
- right: `VL53L4CD`;
- orientation: `BNO085`.

Older active documents that state `VL53L1CD` must be treated as Hardware V1 documentation errors and corrected only after their previous text is copied into `archivo/`.

The three ToF sensors share I2C resources, so the schematic and firmware must document:

- XSHUT or equivalent startup control for sensors that require address assignment;
- final runtime addresses;
- pull-up placement and voltage level;
- connector labels by physical location: `FRONT`, `LEFT`, `RIGHT`;
- startup failure handling and sensor timeout behaviour.

## Custom PCB requirements

### 1. Controller block

- `ESP32-WROOM-32` based control system;
- exact physical implementation — module soldered directly or board-level carrier — remains TBD until the schematic is available;
- programming and debugging connection;
- boot/reset access;
- labelled test points for critical signals.

### 2. PixyCam SPI interface

The PCB must provide a documented wired SPI connection for the first-generation PixyCam:

- camera supply and ground;
- `SCK`;
- controller-to-camera data line;
- camera-to-controller data line;
- chip-select line;
- verified logic-level compatibility;
- connector orientation and pin-1 marking;
- cable strain relief.

Exact pin numbers must remain TBD until the PCB pin map and firmware configuration are locked.

### 3. Power entry and protection

- LiPo-compatible battery input;
- keyed connector after the exact battery is selected;
- reverse-polarity protection;
- fuse or resettable protection;
- accessible main power switch path;
- bulk capacitance close to high-current loads;
- test points for battery voltage and regulated rails.

The PCB must not be finalized before the LiPo cell count and maximum charged voltage are known.

### 4. Logic and sensor power

- regulated rail for the ESP32;
- suitable supply for the PixyCam;
- regulated or filtered sensor branch;
- current headroom for the `BNO085`, `VL53L1X` and `2x VL53L4CD`;
- grounding arranged so motor and servo current do not corrupt sensor data.

### 5. Drive stage

- H-bridge selected from measured motor stall current, not only unloaded current;
- PWM and direction control from the ESP32;
- thermal copper area and temperature-test procedure;
- motor connector with strain relief;
- suppression strategy for motor noise;
- current and voltage margins documented against the final LiPo and motor.

### 6. Steering stage

- `MG90S` connector and PWM routing;
- servo supply with transient-current headroom;
- local bulk capacitance where required;
- common ground without routing servo current through sensitive sensor return paths.

### 7. Competition controls

- one main power-switch path;
- one physical start-button input;
- status LEDs that do not require extra interaction during a round;
- wired communication only while the robot operates.

## Decisions still open

The following values must not be presented as final yet:

- whether the ESP32-WROOM-32 module is soldered directly onto the PCB or connected through another carrier arrangement;
- exact drive-motor model, rated voltage, loaded speed, gearbox ratio, stall current and stall torque;
- motor-driver IC and thermal design;
- LiPo cell count, nominal and maximum voltage, capacity, C-rating and connector;
- regulator topology and current headroom;
- final connector families and complete pinout;
- PCB dimensions, layer count and mounting-hole positions;
- final PixyCam colour signatures, thresholds and measured detection limits.

## Verification gates

The PCB must pass these gates before Hardware V2 is described as the final robot:

| Gate | Minimum evidence |
|---|---|
| architecture review | block diagram matches the confirmed ESP32 + PixyCam SPI architecture |
| schematic review | complete schematic, labelled nets, power-tree explanation and review notes |
| power validation | measured idle, normal-driving and peak current; rail voltage during motor and steering transients |
| PixyCam validation | red/green detection tests, SPI stability and stale-data fallback |
| motor-driver validation | forward/reverse test, PWM sweep, stall-protection behaviour and temperature after repeated load |
| sensor validation | all ToF sensors and BNO085 start repeatedly and remain stable with motor active |
| field validation | repeated straight, corner, Open and Obstacle runs compared with Hardware V1 |
| reproducibility | BOM, Gerbers, editable PCB files, assembly drawing, pinout and bring-up checklist |

## Evidence still to collect

- schematic PDF and editable source;
- PCB layout screenshots;
- Gerber and drill files;
- assembled PCB top and bottom photos;
- labelled connector map and full pinout;
- exact LiPo label or datasheet;
- exact motor and motor-driver datasheets;
- measured current, voltage and temperature tables;
- PixyCam training screenshots and field-test images;
- first-power-up and failure log;
- Hardware V1 versus Hardware V2 comparison table;
- final reason for choosing the exact motor, driver and battery.

## Safety rule

The first power-up should use a current-limited bench supply or an inline fuse. Initially disconnect the motor and servo, verify every power rail, then connect loads one subsystem at a time. A LiPo must be charged, stored and handled using equipment suitable for its exact cell count and chemistry.
