# Hardware V2 Rebuild, Wiring, Upload And Start — Required Information

## Status

The old exact Hardware V1 procedure was archived at [`archivo/hardware-v1-esp32-250rpm/docs/reproducibility/exact_rebuild_wiring_upload_start.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/reproducibility/exact_rebuild_wiring_upload_start.md).

An exact Hardware V2 procedure cannot be completed until the final PCB, motor, motor driver, LiPo, pin map and firmware exist. This page identifies what must be written into each final section.

## 1. Hardware rebuild section must contain

- exact BOM with quantities and part numbers;
- mechanical dimensions and assembly order;
- printable/source CAD files;
- motor and differential installation;
- steering-centre geometry;
- camera, sensor, PCB and battery positions;
- photographs of critical assembly steps.

## 2. Wiring section must contain

- final schematic revision;
- battery connector and polarity;
- power tree and protection;
- regulator outputs;
- complete ESP32 GPIO table;
- PixyCam SPI pins and connector order;
- BNO085 and ToF I2C pins, addresses and startup lines;
- MG90S signal and supply;
- motor-driver control and power connections;
- programming, boot, reset, start-button and status connections.

Current Hardware V2 pins remain `TBD`. Hardware V1 GPIO values must not be copied automatically.

## 3. Upload section must contain

- required operating system/tools;
- PlatformIO version or reproducible environment;
- exact board/environment name;
- dependencies;
- programming cable/interface;
- build command;
- upload command;
- expected successful output;
- recovery procedure after failed upload.

## 4. PixyCam setup section must contain

- exact camera revision;
- Pixy software version;
- signature numbers;
- screenshots or exported settings;
- mounting angle;
- block-selection rules;
- minimum accepted size;
- timeout and fault behaviour;
- verification method for red and green pillars.

## 5. Calibration section must contain

- steering centre and limits;
- motor direction and usable PWM range;
- BNO085 orientation and heading check;
- ToF address/startup validation;
- target-distance and corner logic values;
- camera decision thresholds;
- battery-voltage acceptance range.

## 6. Start and stop section must contain

- power-on order;
- initialization indication;
- fault indication;
- required still period;
- physical start-button action;
- autonomous start condition;
- lap/finish condition;
- final motor and steering state;
- restart procedure.

## Current confirmed facts

- controller: ESP32-WROOM-32;
- perception: first-generation PixyCam over SPI;
- sensors: BNO085, front VL53L1X, two side VL53L4CD;
- steering: MG90S;
- battery class: LiPo;
- custom PCB direction confirmed;
- exact power, drive and pin details remain `TBD`.

Use [`hardware_v2_validation_template.md`](../testing/hardware_v2_validation_template.md) to replace each missing value with measured evidence.
