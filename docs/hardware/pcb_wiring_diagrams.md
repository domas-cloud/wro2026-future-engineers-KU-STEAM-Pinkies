# PCB and Wiring Diagrams

## What This Section Must Show

- how battery power is distributed;
- which parts are powered directly and which go through regulators;
- how the ESP32, Pi Zero, sensors, servo, and drive motor are connected;
- where the signal and power grounds meet.

## Why It Matters

A wiring diagram is required not only for assembly, but also for judging whether the system can actually be reproduced.
It is also the easiest way to show that the team thought through current flow and signal integrity.

## Repository Placement

All diagrams should live in `schemes/` and be referenced from this document.
See also: [Wiring Overview](../../schemes/wiring_overview.md)

## Practical Wiring Structure

The expected wiring structure is:

- `2x 18650 Li-ion` battery pack feeds the main power input;
- the drive branch goes through the `L298N H-bridge` to the `N20` motor;
- the logic branch feeds the `ESP32` and `Raspberry Pi Zero` through regulated rails;
- the `MG90S` servo receives a stable supply rail sized for steering load;
- the `BNO085` and `VL53L5CX` connect to the compute side through their sensor bus;
- all grounds are tied together at a controlled common point.

## Documentation Expectation

The final diagram should label:

- connector names;
- rail voltages;
- signal directions;
- which board generates the control signal;
- which board consumes the signal;
- where the power separation happens between motor and logic.

## Diagram Checklist

- show battery entry point;
- show regulator outputs;
- show the `L298N` motor path separately from logic wiring;
- show `ESP32` and `Raspberry Pi Zero` as separate compute nodes;
- show `BNO085` and `VL53L5CX` as sensor inputs, not as power blocks;
- show `MG90S` as the steering actuator.
