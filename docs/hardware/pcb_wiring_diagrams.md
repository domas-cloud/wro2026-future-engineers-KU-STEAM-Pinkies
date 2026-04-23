# PCB And Wiring Diagrams

Our electronics are organized around a perfboard-based distribution layout. The goal was not visual perfection. The goal was wiring that stayed understandable, serviceable, and stable during testing.

## Main Power Branches

From the battery pack, power is split into:

- logic branch;
- motor branch;
- steering branch;
- sensor branch.

The `ESP32` and `Raspberry Pi Zero` both receive regulated power rather than raw battery voltage.

## Main Connections

The main signal and power paths are:

- battery holder -> perfboard distribution;
- perfboard -> step-down regulator;
- step-down regulator -> `Raspberry Pi Zero`;
- step-down regulator -> `ESP32`;
- `ESP32` -> `BNO085`;
- `ESP32` -> three `VL53L4CD` sensors;
- `Raspberry Pi Zero` -> camera;
- `ESP32` -> `MG90S` servo;
- `ESP32` -> `L298N`;
- `L298N` -> `N20` motor.

## Pin And Address Table

The controller code in `src/src/main.cpp` confirms these pin assignments:

| Board / module | Signal | Pin / address |
| --- | --- | --- |
| `ESP32` | start button input | `GPIO13` |
| `ESP32` | motor PWM / enable | `GPIO32` |
| `ESP32` | motor direction 1 | `GPIO26` |
| `ESP32` | motor direction 2 | `GPIO25` |
| `ESP32` | steering servo PWM | `GPIO33` |
| `ESP32` | distance-sensor shutdown lines | `GPIO15`, `GPIO5`, `GPIO18` |
| `ESP32` I2C bus | clock speed | `400 kHz` |
| `ESP32` UART RX/TX for Pi link | controller bridge | `GPIO16` / `GPIO17` |
| `BNO085` | IMU I2C address | `0x4A`, fallback `0x4B` |
| front distance sensor | configured address | `0x30` |
| left distance sensor | configured address | `0x31` |
| right distance sensor | configured address | `0x32` |

## Wiring Diagram In Text Form

```text
2x 18650 Li-ion pack
  -> perfboard main input
     -> motor branch -> L298N -> N20 drive motor
     -> logic regulator -> Raspberry Pi Zero
     -> logic regulator -> ESP32
     -> sensor branch -> BNO085
     -> sensor branch -> VL53L4CD front (0x30)
     -> sensor branch -> VL53L4CD left (0x31)
     -> sensor branch -> VL53L4CD right (0x32)
     -> steering branch -> MG90S servo

Raspberry Pi Zero
  -> camera module
  -> UART perception packet to ESP32 (`115200 baud`, `3.3 V` TTL)

ESP32
  -> reads BNO085 and all three VL53L4CD sensors
  -> drives MG90S steering servo
  -> drives L298N motor controller
  -> reads start button
```

## About The Schematic PDF

The schematic PDF shows the broader electrical design of the robot. The low-level controller details are easiest to confirm in `src/src/main.cpp`, while the PDF is better for understanding the whole layout.

Main related files:

- [Custom Electronics Schematic](../../schemes/Wro_customPCBs.pdf)
- [Custom Electronics Schematic Description](../../schemes/custom_pcb_description.md)
- [Wiring Overview](../../schemes/wiring_overview.md)

## Preview Images

### Main System View

![Main component schematic](../../schemes/images/schematic-overview.png)

This image gives the quickest overview of the boards, motor driver, servo, and main power branches.

### Sensor Wiring View

![Sensor bus detail](../../schemes/images/sensor-bus-detail.png)

This detail shows the shared sensor bus and the separate shutdown handling for identical ToF modules.

### Power Conversion Reference

![Power regulator reference](../../schemes/images/power-regulator-reference.jpg)

This figure shows the step-down idea used to derive `5 V` logic power from the battery pack.

## How To Read This Section

The important takeaways are:

- the drive motor is isolated behind the `L298N`;
- the servo is driven directly by the control side;
- the sensor bus is structured, not improvised;
- logic power is regulated;
- the design is meant to be rebuilt, not only looked at.
