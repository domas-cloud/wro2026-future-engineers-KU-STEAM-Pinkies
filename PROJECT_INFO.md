# Project Info

- Team: KU STEAM Pinkies
- Competition: WRO 2026 Future Engineers
- Main repository purpose: engineering documentation and robot reproducibility
- Core hardware: `ESP32`, `Raspberry Pi Zero`, `MG90S`, `N20`, `L298N`, `BNO085`, `VL53L4CD`, `2x 18650 Li-ion`
- Main repo: public GitHub repository for documentation, reproducibility, and build evidence

## Notes

Keep this file in sync with the top-level README if the hardware stack changes.
Use this as a quick reference for the current build baseline.

## Current Consistency Baseline

- Steering servo: `MG90S`
- Drive motor: `N20`
- Drive motor rating: `6 V 600 rpm`
- Main architecture:
  - `Raspberry Pi Zero` = camera input and vision processing
  - `ESP32` = control, decision-making, steering, and motor output
