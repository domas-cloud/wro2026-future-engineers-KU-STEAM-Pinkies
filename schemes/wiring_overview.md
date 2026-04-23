# Wiring Overview

## System Blocks

```text
2x 18650 Li-ion
  -> main power path
  -> L298N H-bridge -> N20 drive motor
  -> regulated logic rail -> ESP32
  -> regulated logic rail -> Raspberry Pi Zero
  -> regulated sensor rail -> BNO085 + distance sensors
  -> steering supply rail -> MG90S
```

## Power Domains

- `motor domain`: battery -> `L298N` -> `N20`, the highest-current branch;
- `logic domain`: regulated rail for the `ESP32` and `Raspberry Pi Zero`;
- `sensor domain`: the `BNO085` and distance sensor modules on a clean logic rail;
- `servo domain`: the `MG90S` on a separate branch that can handle steering-current spikes.

## Grounding Strategy

- use one common ground reference point for all subsystems;
- keep the motor return path as far as practical from sensitive signal wires;
- avoid routing sensor wires next to the high-current motor branch over long distances;
- keep the shared return point near the power input or regulator section.

## Signal Paths

- the `Raspberry Pi Zero` handles camera capture and higher-level perception;
- the `ESP32` reads the `BNO085` and distance sensors for real-time control;
- the `ESP32` performs the low-level control calculations and generates steering decisions;
- the `ESP32` drives the `MG90S` steering servo with PWM;
- the `ESP32` controls the `L298N` input pins for the `N20` drive motor;
- the sensors communicate through the controller sensor bus, typically I2C on the `ESP32`.

## Control Responsibilities

- the `ESP32` is responsible for state evaluation, decision selection, real-time output generation, PWM, and drive enable;
- the `Raspberry Pi Zero` is responsible for the camera-side perception layer;
- the battery and regulators provide power, but do not perform any control logic;
- the scheme should clearly show which subsystem generates each control signal.

## Connection Table

| Subsystem | Connection Type | Notes |
| --- | --- | --- |
| Pi Zero camera | CSI / camera interface | Camera capture and perception input |
| Pi Zero to `ESP32` | Data link | Carries higher-level perception results |
| `BNO085` | I2C | Must be mounted rigidly and calibrated |
| `front`, `left`, `right` distance sensors | I2C + shutdown control | Published `ESP32` code uses three modules for local coverage |
| `ESP32` to `MG90S` | PWM | Steering output |
| `ESP32` to `L298N` | Digital control + enable/PWM | Drive direction and speed |
| battery to `L298N` | Power input | Motor current path |
| battery to regulators | Power input | Logic and sensor rails |

## Consistency Note

The schematic PDF shows the full electrical layout of the robot. `src/src/main.cpp` is the easiest place to confirm the low-level `ESP32` controller behavior and the active three-sensor setup.

## Notes For The Final Schematic

- the final schematic should show the exact pin numbers for the board version in use;
- ground should be shown as a common reference even if the power rails are separated;
- the schematic should clearly separate high-current motor wires from the low-current logic section;
- if connectors or terminal blocks are used, they should be labeled.

## Current Repository Reference

The current repository already includes a schematic export:

- [Custom Electronics Schematic PDF](Wro_customPCBs.pdf)
- [Custom Electronics Schematic Description](custom_pcb_description.md)

Use this overview together with those files and with the controller code under `src/`.
