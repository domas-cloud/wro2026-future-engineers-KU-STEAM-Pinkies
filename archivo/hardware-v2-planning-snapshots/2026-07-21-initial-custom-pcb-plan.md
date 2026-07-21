# Hardware V2: Custom PCB Migration Plan

## Status

Hardware V2 is the active redesign direction. The previous ESP32 development-board/perfboard implementation remains preserved as Hardware V1 evidence in `archivo/hardware-v1-esp32-250rpm/` and in the existing historical documentation.

## Confirmed direction

- remove the ESP development board from the final electronics stack;
- replace module/perfboard integration with a purpose-built custom PCB;
- replace the current 250 rpm drive motor with a faster motor;
- preserve the Raspberry Pi/camera role unless testing later proves that another architecture is better;
- keep all changes compatible with WRO rules: wired communication only during runs, one driving axle, one steering actuator, maximum 1.5 kg and 300 x 200 x 300 mm dimensions.

## Decisions that are not locked yet

The following values must not be presented as final until measured and tested:

- exact microcontroller or processor integrated on the custom PCB;
- exact motor model, rated voltage, no-load rpm, stall current and gearbox ratio;
- motor driver IC and thermal design;
- battery chemistry and nominal voltage;
- regulator topology and current headroom;
- final connector families and pinout;
- PCB dimensions, layer count and mounting-hole positions.

## Required PCB blocks

The custom PCB should be divided into clearly reviewable functional blocks:

1. **Power entry and protection**
   - keyed battery connector;
   - reverse-polarity protection;
   - fuse or resettable protection;
   - bulk capacitance close to the motor-driver supply;
   - accessible power switch connection.

2. **Logic power**
   - regulated rail for the control MCU;
   - separate regulated rail or filtered branch for sensors;
   - test points for battery, logic rail, sensor rail and ground;
   - voltage margins documented against the real battery range.

3. **Drive stage**
   - H-bridge sized from measured motor stall current, not only normal running current;
   - PWM and direction interface;
   - thermal copper area and temperature-test procedure;
   - motor connector with strain relief;
   - suppression strategy for motor noise.

4. **Steering stage**
   - servo power connector;
   - PWM signal routing;
   - sufficient current headroom for steering peaks;
   - grounding arranged so servo current does not corrupt sensor readings.

5. **Sensor interfaces**
   - I2C connections for IMU and ToF sensors;
   - separate shutdown/address-control lines for sensors sharing a default address;
   - optional pull-up configuration documented;
   - connectors labelled by physical robot position, not only channel number.

6. **Perception interface**
   - wired UART or another allowed wired link to the Raspberry Pi/perception unit;
   - clear logic-level compatibility;
   - packet timeout/failsafe behaviour retained in software.

7. **Competition controls**
   - one power switch path;
   - one start-button input;
   - status LEDs that do not require additional operator interaction.

## Verification gates

The PCB must pass these gates before it replaces Hardware V1 in the main documentation:

| Gate | Minimum evidence |
|---|---|
| schematic review | complete schematic, labelled nets, power-tree explanation and peer review notes |
| power validation | measured idle, normal-driving and peak current; rail voltage during motor and steering transients |
| motor-driver validation | forward/reverse test, PWM sweep, temperature after repeated full-load runs |
| sensor validation | all sensors start repeatedly, no address conflicts, stable readings while motor is active |
| communication validation | packet-loss and stale-data fallback test |
| field validation | repeated straight, corner and three-lap tests compared with Hardware V1 |
| reproducibility | BOM, Gerbers, source schematic/PCB files, assembly drawing, pinout and bring-up checklist |

## Documentation evidence to collect

- schematic PDF and editable source;
- PCB layout screenshots showing power and signal separation;
- Gerber and drill files;
- assembled top and bottom photos;
- labelled connector map;
- measured current and voltage table;
- thermal observations for the motor driver and regulators;
- failure log from first power-up;
- comparison table: Hardware V1 versus Hardware V2;
- final reason for choosing the exact controller and motor.

## Safety rule

The first power-up should use a current-limited bench supply or an inline fuse. The drive motor and servo should initially be disconnected. Power rails must be checked before inserting expensive controllers or sensors.
