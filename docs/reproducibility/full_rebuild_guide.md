# Rebuild Guide And Current Reproducibility Status

## Status

The earlier Hardware V1 rebuild guide was archived at [`archivo/hardware-v1-esp32-250rpm/docs/reproducibility/full_rebuild_guide.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/reproducibility/full_rebuild_guide.md).

Hardware V1 remains the only complete historical rebuild baseline. Hardware V2 cannot yet be rebuilt exactly because several required parts and design files are `TBD`.

## Hardware V1 historical rebuild

Use the archived Hardware V1 documentation and current historical source when the purpose is to inspect or reproduce the earlier working robot. That baseline includes Raspberry Pi Zero, perfboard, `L298N`, `N20 250 rpm` and `2x 18650` power.

Hardware V1 is not the current competition target.

## Hardware V2 confirmed starting list

- ESP32-WROOM-32;
- first-generation PixyCam / CMUcam5 over SPI;
- BNO085;
- front VL53L1X;
- two side VL53L4CD;
- MG90S;
- retained mechanical baseline unless later testing records a change;
- custom PCB;
- LiPo, motor, H-bridge and regulators still `TBD`.

## Information required before exact rebuilding is possible

### Parts

- exact LiPo and connector;
- exact drive motor and gearbox;
- exact motor-driver IC;
- exact regulator and protection parts;
- exact connectors and fasteners;
- final PCB BOM.

### Mechanical dimensions

- chassis length, width and height after V2 assembly;
- mass;
- wheelbase;
- front and rear track widths;
- wheel diameters;
- ground clearance;
- sensor and camera mounting coordinates;
- PCB and battery mounting points.

### Electronics files

- schematic and editable source;
- PCB source;
- Gerbers and drills;
- pin map;
- connector drawing;
- assembly drawing;
- top/bottom photographs;
- measured power and thermal results.

### Software

- final PlatformIO environment;
- PixyCam SPI implementation;
- selected motor-driver implementation;
- final pin definitions;
- dependencies and versions;
- build/upload command;
- calibration values;
- start, stop and fault behaviour.

## Required rebuild sequence once data exists

1. manufacture or obtain the final mechanical parts;
2. assemble chassis, drivetrain and steering;
3. manufacture and inspect the PCB;
4. verify all power rails with high-current loads disconnected;
5. program the ESP32;
6. bring up BNO085 and ToF sensors;
7. bring up PixyCam SPI;
8. connect and calibrate MG90S;
9. connect the motor stage and test safely;
10. install all subsystems and verify cable retention;
11. run the startup checklist;
12. complete the Hardware V2 validation tables.

## Rebuild acceptance rule

A second person should be able to reproduce the same wiring, firmware and calibration without asking the team for missing private information. Until that is possible, this guide remains a structured list of required content rather than a false exact rebuild claim.
