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

## Pin Assignment Table

The exact pin responsibilities that are already visible in the repository code are listed below.

| Board / module | Signal | Pin / address | Evidence in repo |
| --- | --- | --- | --- |
| `ESP32` | start button input | `GPIO13` | `BUTTON_PIN = 13` in `src/src/main.cpp` |
| `ESP32` | motor PWM / enable | `GPIO32` | `ENABLE_MOTOR = 32` |
| `ESP32` | motor direction 1 | `GPIO26` | `MOTOR_1 = 26` |
| `ESP32` | motor direction 2 | `GPIO25` | `MOTOR_2 = 25` |
| `ESP32` | steering servo PWM | `GPIO33` | `myservo.attach(33)` |
| `ESP32` | ToF LP / shutdown lines | `GPIO4`, `GPIO5` | `lpPins[NUM_SENSORS] = {4, 5}` in `src/lib/Lidar/Lidar.cpp` |
| `ESP32` I2C bus | clock speed | `400 kHz` | `Wire.setClock(400000)` |
| `BNO085` | IMU I2C address | `0x4A`, fallback `0x4B` | `Compass::begin()` |
| `VL53L5CX` left | reassigned I2C address | `0x30` | `baseAddress + (0 * 2)` |
| `VL53L5CX` right | reassigned I2C address | `0x32` | `baseAddress + (1 * 2)` |

## Wiring Diagram In Text Form

```text
2x 18650 Li-ion pack
  -> perfboard main input
     -> motor branch -> L298N -> N20 drive motor
     -> logic regulator -> ESP32
     -> logic regulator -> Raspberry Pi Zero
     -> sensor branch -> BNO085
     -> sensor branch -> VL53L5CX left (0x30)
     -> sensor branch -> VL53L5CX right (0x32)
     -> steering branch -> MG90S servo

Raspberry Pi Zero
  -> camera module
  -> navigation result / command link to ESP32

ESP32
  -> reads BNO085 and both VL53L5CX sensors
  -> drives MG90S steering servo
  -> drives L298N motor controller
  -> reads start button
```

## Why This Layout Was Chosen

This layout was selected for three main reasons:

1. **clear separation of functions**  
   The camera system, control system, sensors, and actuators are easy to identify.

2. **more stable logic power**  
   The computing boards are not powered directly from the raw battery line.

3. **easier debugging and reproducibility**  
   A structured perfboard layout is easier to inspect and reproduce than an unstructured wire bundle.

## Rebuild Notes For Another Team

If another team rebuilds this electrical layout, the most important practical points are:

1. power up the two `VL53L5CX` sensors one at a time so they can receive different I2C addresses;
2. keep the motor-current path away from the sensor and logic wiring wherever possible;
3. share a common ground across all branches even though the rails are functionally separated;
4. verify the servo center mechanically before tuning software gains;
5. label every branch on the perfboard so faults can be isolated quickly during testing.

## Engineering Note

For WRO documentation, the purpose of this section is not only to list connections, but to show that the robot was electrically planned as a system.

The wiring structure shows that:

- regulated power was considered;
- the boards have defined roles;
- the sensors are connected to the control unit intentionally;
- the system can be rebuilt by another team with reasonable effort.
