# Hardware V2 Custom PCB Description

## Status

The previous text describing the Hardware V1 perfboard/Raspberry Pi schematic was copied to [`archivo/hardware-v1-esp32-250rpm/schemes/custom_pcb_description.md`](../archivo/hardware-v1-esp32-250rpm/schemes/custom_pcb_description.md).

The existing `Wro_customPCBs.pdf` is Hardware V1 evidence. This document defines what the real Hardware V2 PCB package must contain once it is designed.

## Confirmed architecture

- main controller: `ESP32-WROOM-32`;
- perception: first-generation PixyCam / CMUcam5;
- PixyCam link: wired SPI;
- IMU: `BNO085`;
- front ToF: `VL53L1X`;
- side ToF: `2x VL53L4CD`;
- steering: `MG90S`;
- power source: LiPo, exact pack `TBD`;
- motor: faster geared DC motor, exact part `TBD`;
- motor driver: PCB H-bridge, exact IC `TBD`.

## Required schematic blocks

### Battery input and protection

The final schematic must show the exact LiPo connector, main switch, reverse-polarity protection, fuse or resettable protection, bulk capacitance and battery test point.

### Regulation

The final design must state each rail voltage, regulator part, continuous rating, transient headroom, efficiency assumptions and measurement points. The PixyCam, ESP32, sensors, servo and motor requirements must be checked against the selected LiPo.

### ESP32 implementation

The schematic must show:

- exact ESP32-WROOM-32 implementation;
- programming connection;
- boot and reset circuit;
- required decoupling;
- antenna keep-out where applicable;
- status outputs;
- start-button circuit;
- labelled test points.

Whether the module is soldered directly or connected through a carrier remains `TBD`.

### PixyCam SPI

The design must show power, ground, clock, both data directions, chip select, connector pin order and verified logic-level compatibility. The final firmware GPIOs and stable SPI rate must match the schematic.

### I2C sensors

The design must show the BNO085, front VL53L1X and both VL53L4CD modules, including voltage, pull-ups, runtime addresses, XSHUT/startup-control lines, BNO reset if used and connector labels by physical position.

### Steering

The MG90S connector, PWM signal, supply rail, local capacitance and common-ground path must be documented. Servo current must not flow through sensitive sensor return paths.

### Motor stage

The H-bridge must be chosen after motor current measurements. The schematic and layout must document PWM/direction control, current and voltage margin, thermal copper, protection, suppression, motor connector and test procedure.

## Required PCB evidence

- source files and revision identifier;
- board dimensions, layers and mounting holes;
- placement and routing explanation;
- separation of high-current and sensitive paths;
- Gerber/drill package;
- BOM;
- assembly photographs;
- first-power-up log;
- measured voltages, current and temperatures;
- list of any PCB errors and the correction made in the next revision.

## Release condition

This document may describe the PCB as final only after the exact components, schematic, board files, assembled hardware, matching firmware and validation evidence are present in the repository.
