# Software Redesign Brainstorm

## Status

This folder is **engineering history and brainstorming material**, not the active Hardware V2 software submission.

On **2026-08-12** we deliberately reset the active software documentation because the software will be redesigned around the real Hardware V2 robot instead of continuing to extend assumptions from Hardware V1.

The exact pre-reset material is preserved here:

- `previous-docs/` — the software architecture, state-machine, vision-interface, calibration and PixyCam planning pages that were active before the reset;
- `previous-source/` — the complete source tree that was present before the reset.

Nothing here should be read as the final Hardware V2 algorithm, pin map, state machine, threshold set or controller implementation.

## Why the reset was necessary

Hardware V1 used a Raspberry Pi Zero camera layer, ESP32 controller and UART communication. Hardware V2 changed several assumptions at the same time:

- Raspberry Pi Zero was removed from the active robot;
- first-generation PixyCam / CMUcam5 became the perception device;
- PixyCam communication moved to wired SPI;
- electronics moved from development-board/perfboard integration toward a custom PCB;
- power moved toward LiPo;
- the drive motor and motor-driver stage were reopened for a faster final system.

Because those changes affect timing, GPIO, communication, failure handling, control limits and tuning, we decided not to keep an old software architecture in the active judge-facing path just because it already existed.

## What the previous software work still proves

The previous work is still useful engineering evidence. It shows that the team explored and implemented ideas including:

- separating perception from low-level control;
- using IMU heading and ToF distance feedback;
- transmitting compact obstacle guidance rather than raw images;
- thinking about stale perception data and fallback behaviour;
- using a state-based approach for autonomous driving;
- testing and tuning the robot as mechanics and software changed together.

These are lessons, not automatically final design choices.

## Questions for the new software design

The next software version should be designed from the final Hardware V2 constraints and real tests. The main questions are:

1. What is the smallest reliable state machine needed for Open and Obstacle Challenge runs?
2. Which PixyCam block data are actually useful: signature, x/y position, width/height, repeated-frame confidence, or a smaller subset?
3. How should red/green detections interact with IMU and ToF feedback?
4. What should happen when PixyCam data are missing, ambiguous or stale?
5. How should corner detection work at the final motor speed?
6. Which controller structure gives the most repeatable straight driving and turn exit?
7. How should parking be represented in the state machine?
8. What startup checks are required before the start button can arm motion?
9. What failure should cause a safe stop versus a degraded fallback?
10. Which measurements will be used to tune and validate the final code?

## Promotion rule

A software idea moves out of `brainstorm/` only when:

1. the relevant hardware interface is known;
2. the code is implemented in the active `src/` tree;
3. the implementation builds on the published configuration;
4. it is tested on the physical robot;
5. thresholds and behaviour are backed by recorded observations or measurements;
6. the active documentation is updated to match the tested code.

## Engineering Journal use

This folder is intentionally preserved because the abandoned and reconsidered software approaches are part of the engineering process. The journal entry for this reset is in:

- `engineering-journal/2026-08-12-software-redesign.md`

Future software experiments should be added here first, then summarized in the Engineering Journal when they lead to a decision.