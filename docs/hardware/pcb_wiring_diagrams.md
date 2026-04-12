# PCB And Wiring Diagrams

## Wiring Philosophy

Our wiring was designed to be simple, structured, and reproducible.

The robot uses a **perfboard** as the main electrical distribution point.  
This allowed us to organize power and signal routing more cleanly than using loose point-to-point wiring only.

## Power Source

The robot uses **2 Li-ion batteries** mounted in a single holder.

From this battery source, electrical power is distributed on the perfboard into the required branches.

## Main Power Branches

The system is divided into separate functional branches:

- logic and computing branch;
- motor drive branch;
- steering branch;
- sensor branch.

The **Raspberry Pi Zero** and **ESP32** are powered through **step-down regulation**.  
This ensures that the logic boards receive a stable voltage supply instead of direct battery voltage.

The drive motor is controlled through the **L298N H-bridge**, which receives control commands from the main control system.

## Main Connections

The main functional wiring connections are:

- battery holder -> perfboard distribution;
- perfboard -> step-down regulator;
- step-down regulator -> Raspberry Pi Zero;
- step-down regulator -> ESP32;
- ESP32 -> BNO085;
- ESP32 -> 2 VL53L5CX sensors;
- Raspberry Pi Zero -> camera;
- ESP32 -> MG90 servo;
- ESP32 / control output -> L298N;
- L298N -> N20 motor.

## Why This Layout Was Chosen

This layout was selected for three main reasons:

1. **clear separation of functions**  
   The camera system, control system, sensors, and actuators are easy to identify.

2. **more stable logic power**  
   The computing boards are not powered directly from the raw battery line.

3. **easier debugging and reproducibility**  
   A structured perfboard layout is easier to inspect and reproduce than an unstructured wire bundle.

## Engineering Note

For WRO documentation, the purpose of this section is not only to list connections, but to show that the robot was electrically planned as a system.

The wiring structure shows that:

- regulated power was considered;
- the boards have defined roles;
- the sensors are connected to the control unit intentionally;
- the system can be rebuilt by another team with reasonable effort.
