# Wiring Overview

## System Blocks

```text
2x 18650 Li-ion
  -> main power path
  -> L298N H-bridge -> N20 drive motor
  -> regulated logic rail -> ESP32
  -> regulated logic rail -> Raspberry Pi Zero
-> regulated sensor rail -> BNO085 + 2x VL53L5CX
  -> steering supply rail -> MG90S
```

## Power Domains

- `motor domain`: battery -> `L298N` -> `N20`, the highest-current branch;
- `logic domain`: regulated rail for the `ESP32` and `Raspberry Pi Zero`;
- `sensor domain`: the `BNO085` and 2 `VL53L5CX` matrix ToF modules on a separate clean logic rail;
- `servo domain`: the `MG90S` on a separate branch that can handle steering-current spikes.

## Grounding Strategy

- use one common ground reference point for all subsystems;
- keep the motor return path as far as practical from sensitive signal wires;
- avoid routing sensor wires next to the high-current motor branch over long distances;
- keep the shared return point near the power input or regulator section.

## Signal Paths

- the `Raspberry Pi Zero` handles camera capture only;
- the `Raspberry Pi Zero` forwards camera data to the `ESP32`;
- the `ESP32` performs the calculations and generates behavior or steering decisions;
- the `ESP32` drives the `MG90S` steering servo with PWM;
- the `ESP32` controls the `L298N` input pins for the `N20` drive motor;
- the `BNO085` and 2 `VL53L5CX` modules communicate through their sensor bus, typically I2C on the `ESP32`.

## Control Responsibilities

- the Pi Zero is responsible only for camera capture;
- the `ESP32` is responsible for state evaluation, decision selection, real-time output generation, PWM, and drive enable;
- the battery and regulators provide power, but do not perform any control logic;
- the scheme should clearly show which board generates each control signal.

## Connection Table

| Subsystem | Connection Type | Notes |
| --- | --- | --- |
| Pi Zero camera | CSI / camera interface | Camera capture only |
| Pi Zero to ESP32 | Camera data link | Carries frames or camera observations |
| BNO085 | I2C | Must be mounted rigidly and calibrated |
| 2x VL53L5CX | I2C | Placement must match obstacle coverage |
| ESP32 to MG90S | PWM | Steering output |
| ESP32 to L298N | Digital control + enable/PWM | Drive direction and speed |
| Battery to L298N | Power input | Motor current path |
| Battery to regulators | Power input | Logic and sensor rails |

## Notes For The Final Schematic

- the final schematic should show the exact pin numbers for the board version in use;
- ground should be shown as a common reference even if the power rails are separated;
- the schematic should clearly separate high-current motor wires from the low-current logic section;
- if connectors or terminal blocks are used, they should be labeled.
