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

- `motor domain`: baterija -> `L298N` -> `N20`, didžiausios srovės šaka;
- `logic domain`: reguliuota šaka `ESP32` ir `Raspberry Pi Zero`;
- `sensor domain`: `BNO085` ir 2 `VL53L5CX` matriciniai ToF moduliai atskiroje švarioje loginėje šakoje;
- `servo domain`: `MG90S` atskiroje šakoje, kuri atlaiko vairo srovės šuolius.

## Grounding Strategy

- naudoti vieną bendrą žemės atskaitos tašką visoms posistemėms;
- variklio grįžtamąją šaką laikyti kuo toliau nuo jautrių signalinių laidų;
- jutiklių laidų nevesti greta didelės srovės variklio šakos per ilgus ruožus;
- bendrą grįžtamąjį tašką laikyti prie maitinimo įėjimo arba reguliatorių mazgo.

## Signal Paths

- `Raspberry Pi Zero` handles camera capture only.
- `Raspberry Pi Zero` forwards camera data to the `ESP32`.
- `ESP32` performs the calculations and generates behavior or steering decisions.
- `ESP32` drives the `MG90S` steering servo with PWM.
- `ESP32` controls the `L298N` input pins for the `N20` drive motor.
- `BNO085` and 2 `VL53L5CX` modules communicate through their sensor bus, typically I2C on the `ESP32`.

## Valdymo Atsakomybės

- Pi Zero atsakingas tik už kameros gavimą;
- `ESP32` atsakingas už būsenos vertinimą, sprendimų pasirinkimą, realaus laiko išėjimų formavimą, PWM ir pavaros įjungimą;
- baterija ir reguliatoriai tiekia energiją, bet nevykdo jokios valdymo logikos;
- schema turi aiškiai parodyti, kuri plokštė generuoja kiekvieną valdymo signalą.

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

## Galutinės Schemos Pastabos

- galutinėje schemoje reikia nurodyti tikslius pin numerius pagal naudojamą plokštės versiją;
- žemė turi būti pavaizduota kaip bendra atskaita net ir atskyrus maitinimo šakas;
- schemoje reikia aiškiai atskirti didelės srovės variklio laidus nuo žemos srovės loginės dalies;
- jei naudojami konektoriai arba gnybtų blokai, jie turi būti pažymėti.
