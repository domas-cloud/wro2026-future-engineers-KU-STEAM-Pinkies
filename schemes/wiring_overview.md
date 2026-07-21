# Wiring Overview

## Version status

The previous Raspberry Pi, perfboard, `L298N`, `N20 250 rpm` and `2x 18650` wiring overview was copied to [`archivo/hardware-v1-esp32-250rpm/schemes/wiring_overview.md`](../archivo/hardware-v1-esp32-250rpm/schemes/wiring_overview.md).

This active page describes the confirmed Hardware V2 structure. Exact parts and pins remain `TBD` where the team has not selected them.

## Hardware V2 system blocks

```text
LiPo — exact specification TBD
  -> protected PCB power input
     -> motor power -> H-bridge TBD -> faster motor TBD
     -> servo power -> MG90S
     -> ESP32 logic regulation
     -> PixyCam supply
     -> BNO085 and ToF sensor supply

PixyCam (first generation)
  -> SPI -> ESP32-WROOM-32

ESP32-WROOM-32
  -> I2C -> BNO085
  -> I2C / startup control -> VL53L1X + 2x VL53L4CD
  -> PWM -> MG90S
  -> PWM / direction -> motor H-bridge
```

## Power domains to document

- battery input and protection;
- motor branch;
- servo branch;
- ESP32 logic branch;
- PixyCam branch;
- sensor branch;
- common reference and controlled high-current returns.

The final overview must name the exact regulator outputs, current margins, connector types and protection parts.

## Signal paths

- PixyCam processes trained colour signatures and sends block information over wired SPI;
- ESP32 combines camera data with yaw and distance measurements;
- BNO085 and the three ToF sensors use the sensor bus;
- ESP32 generates steering PWM and motor-driver control;
- a physical start button starts the autonomous round.

## Missing information required for the final diagram

- exact LiPo;
- exact H-bridge and motor;
- ESP32 physical implementation;
- complete GPIO map;
- I2C pull-ups, addresses and startup lines;
- PixyCam voltage compatibility and SPI pin order;
- regulator topology and part numbers;
- connector family and pin-1 orientation;
- PCB dimensions and mounting points;
- measured current and rail stability.

## Historical files

The existing PDF and preview images in this folder show Hardware V1. They remain engineering evidence but must not be used as the final Hardware V2 wiring reference.
