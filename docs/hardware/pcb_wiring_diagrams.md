# Hardware V2 PCB And Wiring Status

## Document status

This file no longer presents the Hardware V1 perfboard wiring as the active robot. The previous text was copied to [`archivo/hardware-v1-esp32-250rpm/docs/hardware/pcb_wiring_diagrams.md`](../../archivo/hardware-v1-esp32-250rpm/docs/hardware/pcb_wiring_diagrams.md).

The final Hardware V2 schematic and pin map do not exist yet. This page records the confirmed connection structure and the information that must be added when the PCB is designed.

## Confirmed block diagram

```text
LiPo battery — exact pack TBD
  -> protected power input
     -> motor branch -> H-bridge TBD -> faster geared DC motor TBD
     -> servo branch -> MG90S
     -> logic regulation -> ESP32-WROOM-32
     -> camera supply -> first-generation PixyCam
     -> sensor supply -> BNO085 + VL53L1X + 2x VL53L4CD

PixyCam
  -> wired SPI -> ESP32-WROOM-32

ESP32-WROOM-32
  -> I2C -> BNO085
  -> I2C + startup control -> front VL53L1X
  -> I2C + startup control -> left VL53L4CD
  -> I2C + startup control -> right VL53L4CD
  -> PWM -> MG90S
  -> PWM / direction -> H-bridge TBD
  -> GPIO -> physical start button and status indication
```

## Confirmed interfaces

| Connection | Confirmed | Still required |
|---|---|---|
| PixyCam to ESP32 | wired SPI | exact GPIOs, SPI rate, connector pin order, voltage compatibility |
| BNO085 to ESP32 | I2C | exact pins, pull-ups, address and reset connection |
| ToF sensors to ESP32 | I2C with separate startup control where required | exact pins, addresses and initialization sequence |
| MG90S to controller | PWM plus suitable power branch | exact pin, connector and measured rail transient |
| motor stage | ESP32 PWM/direction to H-bridge | exact IC, pins, protection and current rating |
| start control | physical wired button | exact GPIO and electrical circuit |

## Pin-map rule

Hardware V1 documentation contained specific pins, including conflicting start-button values. Those pins must not be copied into Hardware V2 as final. The Hardware V2 table must be completed from the approved schematic and matching firmware.

| Function | Hardware V2 pin |
|---|---|
| start button | `TBD` |
| status LED(s) | `TBD` |
| steering PWM | `TBD` |
| motor PWM | `TBD` |
| motor direction | `TBD` |
| I2C SDA / SCL | `TBD` |
| front / left / right ToF startup control | `TBD` |
| BNO085 reset, if used | `TBD` |
| PixyCam SCK / data / select | `TBD` |
| programming, boot and reset | `TBD` |

## Power information required

The final wiring document must show:

1. exact LiPo nominal and maximum voltage;
2. main connector, switch, fuse or resettable protection;
3. reverse-polarity protection;
4. regulator part numbers and output rails;
5. continuous and peak current margins;
6. bulk and local decoupling;
7. motor-noise suppression;
8. common-ground strategy and high-current return routing;
9. test points for battery and regulated rails.

## Required final files

- editable schematic source;
- schematic PDF;
- PCB source and layout screenshots;
- Gerber and drill files;
- BOM with exact manufacturer part numbers;
- connector map and pin-1 markings;
- assembled PCB top/bottom photos;
- measured voltage, current and thermal results;
- firmware pin definitions matching this document.

## Historical schematic notice

The existing [`schemes/Wro_customPCBs.pdf`](../../schemes/Wro_customPCBs.pdf), perfboard photo and old diagram images describe Hardware V1. They remain evidence of the previous working robot and are not the final Hardware V2 PCB.
