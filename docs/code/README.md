# Hardware V2 Software Status

## Active status

`[HW2-TBD]` The final Hardware V2 software architecture is being redesigned.

On **2026-08-12** the previous active software documentation was moved out of the judge-facing path so that untested assumptions are not presented as the final robot software.

Previous documentation and source are preserved under:

- [`../../brainstorm/software-redesign/`](../../brainstorm/software-redesign/)

The reset and its engineering reasoning are recorded in:

- [`../../engineering-journal/2026-08-12-software-redesign.md`](../../engineering-journal/2026-08-12-software-redesign.md)

## Confirmed hardware interfaces

The software must ultimately work with the confirmed Hardware V2 hardware:

- `ESP32-WROOM-32` main controller;
- first-generation `PixyCam` / CMUcam5;
- wired SPI between PixyCam and ESP32;
- `BNO085` IMU;
- front `VL53L1X`;
- `2x VL53L4CD` side sensors;
- `MG90S` steering servo;
- custom PCB;
- final LiPo, motor and H-bridge once those parts are locked.

## Not final yet

The repository currently makes **no final Hardware V2 claim** about:

- state-machine structure;
- control algorithm or gains;
- obstacle thresholds;
- PixyCam filtering or block-selection rules;
- parking logic;
- GPIO assignments;
- motor-driver control mode;
- fault and fallback behaviour;
- final PlatformIO configuration.

These items must be implemented and tested before they return to the active documentation.

## Completion gate

Software becomes active Hardware V2 evidence only when:

1. the code is published under `src/`;
2. it builds from the repository configuration;
3. its GPIO and interfaces match the final PCB;
4. PixyCam, IMU and ToF behaviour are tested on the physical robot;
5. Open and Obstacle behaviour is demonstrated in repeated runs;
6. the documentation matches the tested implementation.
