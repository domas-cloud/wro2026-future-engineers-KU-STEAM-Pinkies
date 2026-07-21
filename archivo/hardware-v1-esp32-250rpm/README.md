# Archived Hardware V1 Baseline

> **[HW1-HISTORY] Frozen historical evidence:** files in this folder preserve the older working robot and earlier documentation states. They are not active Hardware V2 instructions. Their technical content may intentionally differ from the current target.

This folder preserves the repository state before the 2026 hardware redesign. Old information is retained because it demonstrates real engineering iterations, failures, measurements and the reasons for improvement.

For the current missing-information tracker and next-review instructions, open [`../../NEXT_REVIEW.md`](../../NEXT_REVIEW.md).

## Baseline being preserved

- ESP32 development board as the low-level controller;
- perfboard/module-based electronics;
- L298N motor-driver module;
- N20 6 V 250 rpm drive motor;
- Raspberry Pi Zero perception layer;
- Pi camera and Pi-to-ESP32 UART communication;
- `2x 18650` Li-ion supply;
- previous sensor, steering, power, firmware, media and measurement assumptions.

## [HW2-IMPROVEMENT] What changed after this baseline

| Hardware V1 history | Hardware V2 improvement | Current state |
|---|---|---|
| Raspberry Pi Zero performs image processing | first-generation PixyCam performs colour processing onboard | confirmed, field validation pending |
| Pi sends UART packets to ESP32 | PixyCam sends block data directly through wired SPI | confirmed, firmware and electrical verification pending |
| ESP32 development board and perfboard | purpose-built custom PCB using ESP32-WROOM-32 | design direction confirmed, PCB incomplete |
| `2x 18650` supply | LiPo power architecture | chemistry confirmed, exact pack TBD |
| `N20 250 rpm` motor | faster geared DC motor | direction confirmed, exact motor TBD |
| `L298N` module | custom-PCB H-bridge selected from real motor current | exact IC TBD |
| some old text says `VL53L1CD` | active side sensors documented as `2x VL53L4CD` | corrected in active V2 documents |
| Hardware V1 source and media | new V2 source, photos and both challenge videos | still required |

The newer design does not make the old robot meaningless. Hardware V1 remains the verified baseline used to show what the team built, what worked, what failed and why the V2 redesign was started.

## How to interpret archived files

When an archived file mentions Raspberry Pi Zero, UART, L298N, 18650 batteries, 250 rpm or the old wiring:

1. treat it as `[HW1-HISTORY]`;
2. do not use it as the final Hardware V2 build instruction;
3. open the active file at the corresponding repository path;
4. open [`../../NEXT_REVIEW.md`](../../NEXT_REVIEW.md) to see the improvement and remaining evidence;
5. do not edit the historical snapshot merely to make it look current.

## Archive policy

Whenever an existing file must be rewritten for Hardware V2, its previous version should first be copied into this folder or into `archivo/hardware-v2-planning-snapshots/` while preserving a clear path or filename.

This makes the engineering evolution visible and prevents loss of working reference material. Source code, CAD, schematics, photos, videos and measured history must not be deleted merely because a newer design exists.

## Why this matters

The WRO documentation rubric rewards design trade-offs, iteration evidence, failure analysis and reproducibility. Keeping the earlier implementation gives direct evidence for why the team changed:

- the controller architecture;
- the camera and communication path;
- PCB integration;
- power distribution;
- motor driver;
- drive motor;
- testing and reproducibility requirements.

The active repository should always state both parts of the engineering story: **what the older solution was** and **how Hardware V2 improves it**.
