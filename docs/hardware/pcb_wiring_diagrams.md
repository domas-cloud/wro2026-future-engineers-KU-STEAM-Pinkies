# PCB And Wiring Diagrams

## Why This Matters

The wiring diagram is important not only for assembly, but also for showing that the system can actually be reproduced.
It is also the clearest way to demonstrate that the team considered current flow and signal integrity.

## Practical Wiring Structure

The wiring layout is organized as follows:

- the `2x 18650 Li-ion` battery pack powers the main input;
- the drive branch goes through the `L298N H-bridge` to the `N20` motor;
- the logic branch powers the `ESP32` and `Raspberry Pi Zero` through regulated rails;
- the main logic connections are assembled on perfboard;
- the `MG90S` servo receives a stable supply suitable for steering load;
- the `BNO085` and 2 `VL53L5CX` matrix ToF modules connect to the `ESP32` through their sensor bus;
- the `Raspberry Pi Zero` provides camera data to the `ESP32`;
- all grounds are tied together at one controlled common point.
