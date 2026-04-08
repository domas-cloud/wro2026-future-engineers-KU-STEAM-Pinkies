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

- `motor domain`: battery to `L298N` to `N20`, with the highest current draw;
- `logic domain`: regulated rail for `ESP32` and `Raspberry Pi Zero`;
- `sensor domain`: `BNO085` and 2 `VL53L5CX` matrix ToF modules, preferably kept on a clean logic supply;
- `servo domain`: `MG90S`, powered from a rail that can handle transient steering current.

## Grounding Strategy

- use one common ground reference for every subsystem;
- keep the motor return path physically separate from sensitive signal wiring where possible;
- avoid routing sensor wires alongside the high-current motor branch for long distances;
- place the common return point near the power entry or regulator cluster.

## Signal Paths

- `Raspberry Pi Zero` handles camera capture only.
- `Raspberry Pi Zero` forwards camera data to the `ESP32`.
- `ESP32` performs the calculations and generates behavior or steering decisions.
- `ESP32` drives the `MG90S` steering servo with PWM.
- `ESP32` controls the `L298N` input pins for the `N20` drive motor.
- `BNO085` and 2 `VL53L5CX` modules communicate through their sensor bus, typically I2C on the `ESP32`.

## Recommended Control Responsibilities

- Pi Zero owns camera capture only;
- ESP32 owns state estimation, decision selection, real-time output shaping, PWM, and drive enable control;
- the battery and regulators only provide power, not behavior;
- the wiring diagram should make it obvious which board is the source of each control signal.

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

## Notes For Final Diagram

- Final pin numbers should be filled in on the electrical drawing for the exact board revision.
- Grounds must be shown as a common reference even if power rails are separated.
- The diagram should distinguish high-current motor wiring from low-current logic wiring.
- If connector housings or terminal blocks are used, they should be labeled in the final drawing.
