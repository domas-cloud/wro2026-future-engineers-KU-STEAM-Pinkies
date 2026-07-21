# Archived Hardware V1 Baseline

This folder preserves the repository state before the 2026 hardware redesign.

## Baseline being preserved

- ESP32 development board as the low-level controller;
- perfboard/module-based electronics;
- L298N motor driver module;
- N20 6 V 250 rpm drive motor;
- Raspberry Pi Zero perception layer;
- existing sensor, steering, power and firmware assumptions.

The active project is now preparing a new custom-PCB-based electronics architecture and a faster drive motor. Nothing in the original implementation is being deleted. Existing files outside this folder remain available as historical engineering evidence until the new design is tested and documented.

## Archive policy

Whenever an existing file must be rewritten for Hardware V2, its previous version should first be copied into this folder while preserving a clear path or filename. This makes the engineering evolution visible and prevents loss of working reference material.

## Why this matters

The WRO documentation rubric rewards design trade-offs, iteration evidence, failure analysis and reproducibility. Keeping the earlier implementation gives direct evidence for why the team changed the controller architecture, PCB integration, power distribution, motor driver and drive motor.
