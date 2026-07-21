# PixyCam SPI Integration Plan

## Scope

Hardware V2 removes the Raspberry Pi Zero from the active perception stack. A first-generation `PixyCam` / CMUcam5 performs colour-object processing and sends detected block data to the `ESP32-WROOM-32` through wired SPI.

This page describes the intended integration and the tests required before the camera path can be described as verified.

## Intended obstacle flow

```text
PixyCam sees a traffic pillar
  -> matches a trained colour signature
  -> reports the detected block over SPI
  -> ESP32 validates freshness and size / position
  -> ESP32 selects the required passing side
  -> ESP32 combines the decision with BNO085 and ToF control
  -> steering and motor commands are generated
```

## Training target

The PixyCam should be trained in its own software for two separate WRO traffic-pillar colour classes:

- red pillar;
- green pillar.

The exact signature numbers and thresholds are not yet recorded. They remain `TBD` until screenshots or exported settings are added.

## Data required by the ESP32

At minimum, the control code should use:

- detected signature ID;
- object centre `x` coordinate;
- object centre `y` coordinate if useful;
- object width;
- object height;
- timestamp or local age of the latest valid reading;
- detection-valid flag.

The final implementation may use additional Pixy fields, but the documentation must match the real source code.

## Interface requirements

The custom PCB must provide a labelled PixyCam connection containing:

- power;
- ground;
- SPI clock;
- controller-to-camera data;
- camera-to-controller data;
- chip select.

Before finalizing the schematic, verify:

- PixyCam supply requirement;
- SPI logic voltage compatibility;
- connector pin order;
- cable orientation;
- maximum stable SPI rate on the assembled robot;
- whether another SPI peripheral shares the same bus.

## Proposed software states

| State | Camera condition | ESP32 behaviour |
|---|---|---|
| `NO_BLOCK` | no trusted pillar detected | continue neutral heading / wall control |
| `RED_BLOCK` | valid red signature | select the rule-compliant red-pillar passing path |
| `GREEN_BLOCK` | valid green signature | select the rule-compliant green-pillar passing path |
| `AMBIGUOUS` | multiple conflicting or weak blocks | reject the decision or use a documented safe fallback |
| `STALE` | last valid camera result is too old | ignore camera guidance and enter documented fallback |
| `CAMERA_FAULT` | SPI or camera initialization failure | safe stop or restricted fallback, depending on final strategy |

Exact transition thresholds remain `TBD` until they are tuned and measured.

## Detection filtering to consider

The final code should document whether it uses:

- minimum object width or area;
- object-centre position limits;
- repeated detections across multiple frames;
- nearest / largest valid block selection;
- rejection of simultaneous red and green detections;
- timeout after the last valid block;
- confidence proxy based on size and consistency.

These mechanisms should only be claimed after they exist in the published source code.

## Required test matrix

| Test | Method | Result to record |
|---|---|---|
| red-only detection | place red pillar at several distances and positions | correct / missed / false detections |
| green-only detection | repeat for green pillar | correct / missed / false detections |
| mixed scene | show both colours and field background | selected block and reason |
| lighting variation | repeat under brighter, darker and side-lit conditions | signature robustness |
| approach-speed test | drive toward pillar with final motor settings | first detection distance and stable-decision distance |
| motor-noise test | read PixyCam over SPI while motor changes PWM | dropped or corrupted reads |
| servo-noise test | move MG90S repeatedly while reading camera | dropped or corrupted reads |
| stale-data test | disconnect or block camera updates | fallback response time |
| wrong-colour background | introduce red/green non-pillar objects where practical | false-positive behaviour |
| repeated obstacle run | complete multiple full runs | success rate and failure pattern |

## Evidence required for a strong final report

- photo of the exact first-generation PixyCam;
- Pixy software screenshots showing trained signatures;
- published ESP32 Pixy interface source code;
- PCB pinout and connector photo;
- detection-distance table;
- false-positive / false-negative notes;
- measured stale-data timeout;
- video showing red and green decisions;
- explanation of at least one failed setup and how it was improved.

## Archive note

The previous Raspberry Pi Zero perception implementation is not deleted. Its source and documentation remain Hardware V1 evidence under `archivo/` and the repository history.
