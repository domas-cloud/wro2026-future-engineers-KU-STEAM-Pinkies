# Hardware V2 Decision Register

This page records what is confirmed, what is still open and what evidence is required before a decision can be presented as final.

## Decision states

- `CONFIRMED` — selected by the team.
- `TBD` — not selected yet; no value should be invented.
- `VERIFY` — selected in principle but still requires measured validation.
- `ARCHIVED` — no longer active, but preserved as development evidence.

## Current register

| ID | Decision | Current state | Reason / context | Evidence still required |
|---|---|---|---|---|
| HW2-CTRL-01 | use `ESP32-WROOM-32` as the main controller | CONFIRMED | keeps the known real-time control platform while simplifying the compute stack | exact PCB implementation, GPIO map and bring-up test |
| HW2-VISION-01 | remove Raspberry Pi Zero from the active robot | CONFIRMED | perception will be handled by a camera with onboard processing | archive completeness and final architecture diagram |
| HW2-VISION-02 | use first-generation `PixyCam` / CMUcam5 | CONFIRMED | camera processes colour signatures using its own processor | exact hardware revision photo, power requirement and field detection tests |
| HW2-VISION-03 | connect PixyCam to ESP32 through wired `SPI` | CONFIRMED | compact direct interface without Pi-to-ESP32 UART layer | logic-level check, pin map, packet timing and motor-on stability test |
| HW2-SENSOR-01 | use `VL53L1X` as the front ToF sensor | CONFIRMED | retained front-distance and turn-trigger role | final mounting position, runtime settings and measured repeatability |
| HW2-SENSOR-02 | use `2x VL53L4CD` as left/right ToF sensors | CONFIRMED | corrects the older `VL53L1CD` documentation error | physical sensor-label photo, address plan and motor-on stability test |
| HW2-SENSOR-03 | retain `BNO085` IMU | CONFIRMED | known fused-yaw source for heading control | final mounting and calibration log |
| HW2-STEER-01 | retain `MG90S` steering servo | CONFIRMED | remains matched to the current steering mechanism | peak current and higher-speed steering validation |
| HW2-POWER-01 | move from `2x 18650` to LiPo | CONFIRMED / VERIFY | selected chemistry class, exact pack not yet known | cell count, voltage, capacity, C-rating, connector and safety process |
| HW2-MOTOR-01 | replace `250 rpm` motor with a faster motor | CONFIRMED / TBD | speed target is higher, but exact motor is not selected | candidate table, datasheets, loaded speed, current and repeated-run tests |
| HW2-DRIVER-01 | replace the final assumption of `L298N` with a custom-PCB drive stage | TBD | driver depends on the selected motor and LiPo | IC selection, current margin, losses and temperature test |
| HW2-PCB-01 | replace development-board/perfboard integration with custom PCB | CONFIRMED / VERIFY | cleaner wiring, smaller packaging and stronger reproducibility | schematic, source files, Gerbers, BOM, assembly photos and bring-up log |

## Archived Hardware V1 decisions

The following remain valid as evidence of the previous working baseline:

- Raspberry Pi Zero perception layer;
- Pi CSI camera;
- Pi-to-ESP32 UART architecture;
- ESP32 development board and perfboard integration;
- `N20 6 V 250 rpm` motor;
- `L298N` module;
- `2x 18650` Li-ion pack.

Archived material is stored under [`archivo/hardware-v1-esp32-250rpm/`](../../archivo/hardware-v1-esp32-250rpm/).

## Change-control rule

When a current active file is changed because a Hardware V2 decision becomes final:

1. copy the previous active version into `archivo/`;
2. update the active file;
3. record the reason and evidence here;
4. add the date and change to `CHANGELOG.md`;
5. avoid claiming test results that were not measured.

## Next decisions needed

1. Exact LiPo pack.
2. Exact faster motor.
3. Exact H-bridge / motor-driver IC.
4. ESP32 physical implementation on the PCB.
5. Full pin map and connector family.
6. PixyCam signature numbers and tuning values.
7. Final PCB dimensions and mounting positions.
