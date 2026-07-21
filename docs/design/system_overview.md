# System Overview

## Version status

The previous Hardware V1 system overview was archived at [`archivo/hardware-v1-esp32-250rpm/docs/design/system_overview.md`](../../archivo/hardware-v1-esp32-250rpm/docs/design/system_overview.md).

Hardware V1 remains the verified baseline. Hardware V2 is an active redesign with confirmed architecture and unresolved implementation details.

## Hardware V2 system

The robot is treated as one connected engineering system:

1. **Chassis and steering** — define geometry, grip, mechanical resistance and repeatability.
2. **Drivetrain** — converts motor output through the rear axle and differential.
3. **Power and PCB** — distribute LiPo energy while protecting logic and controlling high-current loads.
4. **Local sensing** — BNO085 and three ToF sensors provide heading and distance information.
5. **Visual perception** — first-generation PixyCam identifies trained red/green traffic-pillar signatures.
6. **Control software** — ESP32 validates inputs, selects behaviour and generates steering/motor outputs.
7. **Testing and evidence** — measurements decide whether a change becomes the new stable version.

## Confirmed Hardware V2 data flow

```text
PixyCam block data ─┐
BNO085 heading ─────┤
front/side ToF ─────┤
start input ────────┘
        ↓
ESP32-WROOM-32 decision and control
        ↓
MG90S steering + H-bridge/motor
```

## Why subsystem interaction matters

- a faster motor increases required detection and reaction distance;
- a faster motor may increase H-bridge current and power-rail noise;
- servo current spikes can reset logic or disturb sensors;
- motor noise can corrupt SPI or I2C communication;
- camera placement affects block position and therefore avoidance timing;
- steering friction changes the tuning needed from the controller;
- wheel grip determines whether the commanded angle becomes real motion;
- PCB dimensions and connector placement affect chassis packaging and sensor alignment.

The final design therefore cannot be selected one component at a time without retesting the complete robot.

## Verified Hardware V1 lessons retained

Hardware V1 showed that:

- correcting steering geometry reduced servo load;
- silicone front wheels improved useful grip;
- the LEGO differential reduced binding;
- limiting the steering range improved stability;
- repeated testing was more useful than choosing the highest theoretical motor speed.

These are historical results. The Hardware V2 motor, power system and electronics still require new validation.

## Current system risks

| Risk | Interaction | Required evidence |
|---|---|---|
| motor current underestimated | motor, H-bridge, LiPo, PCB copper and regulator stability | free-run, loaded, launch and stall measurements |
| servo transient | servo rail, ESP32 and I2C stability | voltage-sag and reset test |
| PixyCam false detection | lighting, camera mounting, speed and control timing | detection matrix and repeated track tests |
| communication noise | motor/servo switching against SPI and I2C | motor-on communication test |
| wrong pin map | PCB, firmware and rebuild documentation | reviewed schematic-to-code cross-check |
| mechanical change | steering response and software tuning | repeated before/after runs |

## Information still required

- exact LiPo, motor, driver and regulators;
- final robot mass and dimensions;
- PCB files and pin map;
- camera mounting geometry and signature settings;
- final firmware;
- measured power and thermal data;
- repeated Open and Obstacle Challenge results.

## System acceptance rule

Hardware V2 becomes the final documented system only when the physical robot, schematic, BOM, code, calibration instructions, media and measured test tables all describe the same revision.
