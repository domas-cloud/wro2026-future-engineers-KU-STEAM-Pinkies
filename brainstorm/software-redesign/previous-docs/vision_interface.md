# Hardware V2 Vision Interface

## Status

The previous Raspberry Pi Zero UART interface was archived at [`archivo/hardware-v1-esp32-250rpm/docs/code/vision_interface.md`](../../archivo/hardware-v1-esp32-250rpm/docs/code/vision_interface.md).

Hardware V2 uses a first-generation PixyCam / CMUcam5 connected to the ESP32-WROOM-32 through wired SPI. The final SPI source code and pin map are not yet published, so this page defines the required interface contract without pretending that implementation is complete.

## Responsibility split

### PixyCam

- capture the forward scene;
- apply trained colour signatures;
- identify candidate red or green traffic-pillar blocks;
- expose block signature, position and size through its supported SPI interface.

### ESP32

- initialize and poll the camera;
- reject missing, stale, too-small or ambiguous results;
- map the trusted colour signature to the required passing side;
- combine that decision with BNO085 and ToF control;
- command steering and drive outputs;
- enter a documented fallback or safe state after camera failure.

## Minimum data required from a valid block

The final implementation must document which Pixy fields it uses. At minimum the control decision is expected to require:

- signature ID;
- centre `x` coordinate;
- block width;
- block height or area;
- a local timestamp or age value maintained by the ESP32;
- a validity flag.

No ASCII UART packet is part of the active Hardware V2 interface.

## Decision mapping

The final code must explicitly map the trained signatures to WRO behaviour:

| Detected class | Required path decision |
|---|---|
| red traffic pillar | pass on the rule-compliant right side |
| green traffic pillar | pass on the rule-compliant left side |
| no trusted block | continue the documented neutral/local-control behaviour |
| ambiguous or stale result | reject the camera decision and use the documented fallback |

Exact signature numbers remain `TBD` until they are recorded from the real Pixy software setup.

## Electrical details still required

- camera supply voltage and measured current;
- verified SPI logic-level compatibility;
- ESP32 `SCK`, data and chip-select pins;
- connector pin order and pin-1 marking;
- stable SPI rate;
- startup timing;
- behaviour if camera initialization fails;
- test results while motor and servo are active.

## Software acceptance tests

1. camera initialization succeeds repeatedly;
2. red and green signatures are read correctly;
3. no-block and ambiguous cases are rejected;
4. stale information stops affecting navigation within the measured timeout;
5. motor and servo electrical noise do not corrupt SPI data;
6. the published source, schematic and this document use the same pins and thresholds;
7. repeated Obstacle Challenge runs confirm the intended decisions.

See [`pixycam_spi_integration_plan.md`](pixycam_spi_integration_plan.md) for the full validation matrix.
