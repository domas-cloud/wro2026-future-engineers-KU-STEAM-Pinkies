# KU STEAM Pinkies — WRO 2026 Release Notes

This file records reproducible documentation snapshots of the WRO 2026 Future Engineers robot. It is a versioning record for the repository; it is not a claim that a GitHub binary release was published.

## 2026-10-01 — Competition documentation snapshot

### Final documented hardware

- ESP32-WROOM-32, 30-pin DevKit V1 form factor
- BNO085 heading sensor
- 3 × VL53L1X distance sensors in Long mode
- Pixy2 / Pixy2.1 vision
- N20 6 V motor, nominal 600 rpm
- LEGO-compatible gearing and rear differential
- MG90S positional steering servo
- 2S LiPo, 7.4 V, 2500 mAh, 30C
- custom PCB
- approximate overall size: 165 × 145 × 70 mm
- documented mass: 332.4 g

### Firmware configurations

The repository uses one source tree with two explicit PlatformIO environments:

```bash
platformio run -d src -e open_challenge
platformio run -d src -e obstacle_challenge
```

- `open_challenge` uses `WRO_CHALLENGE_MODE=0`.
- `obstacle_challenge` uses `WRO_CHALLENGE_MODE=1`.

Build verification is manual. This repository intentionally does not include GitHub Actions CI or a `scripts/` verification directory.

### Reproducibility material included

- `README.md` — engineering decisions, architecture, tuning and rebuild instructions
- `src/` — ESP32 PlatformIO firmware
- `models/` — final STL/CAD files and `case.ai`
- `schemes/` — PCB documentation, Gerbers, drill files and schematic images
- `docs/testing/validation-summary.csv` — saved validation summary
- `docs/testing/raw/run-template.csv` — template for future per-run evidence
- `v-photos/` — final robot photographs
- `t-photos/` — team photograph
- `videos/` — competition run recordings

### Manual verification workflow

For a documented firmware revision:

1. record the Git commit SHA used for the test;
2. build both PlatformIO environments with the commands above;
3. perform the calibration checks described in README section 2.6;
4. perform the final acceptance checks in README section 8;
5. for new physical runs, copy `docs/testing/raw/run-template.csv` and record challenge mode, firmware SHA, battery state, changed variable, result and measured error/failure where available;
6. update `docs/testing/validation-summary.csv` only from retained evidence.

A field should remain blank when it was not measured. No result should be reconstructed from memory and presented as a measured value.

### Known limitations at this snapshot

The repository intentionally documents unresolved or unmeasured items rather than hiding them:

- the current `Kd` calculation uses a stale previous-error value and has not been validated as a normal discrete derivative;
- the `TURNING` loop has no timeout if the front range sensor never reports a clear corner;
- the return value of `pixy.init()` is not checked;
- measured peak current and logic-rail voltage sag are not saved;
- wheelbase and track width were not recorded;
- exact installed ToF offsets/angles and calibrated field readings remain unverified;
- some historical test observations do not have raw per-run logs or firmware/date metadata.

These limitations describe the evidence available in the repository; they are not new measurements.

## Versioning policy

When a material robot revision is made, add a new dated entry here. Record:

- the affected subsystem;
- the relevant Git commit SHA;
- what changed and why;
- which calibration/build/field tests were repeated;
- which evidence files were updated.

Changes to pinout, sensor type, wheel size, steering geometry, camera interface or challenge-control behaviour should be treated as a new robot revision and retested before its results are used as final evidence.
