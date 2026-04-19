# Embedded Controller README

This folder contains the `PlatformIO` project for the robot's embedded controller.

The purpose of this README is reproducibility. Another team or judge should be able to understand:

- which project in the repository is the active embedded project;
- which board is expected;
- where the main control file is;
- how the controller is built and uploaded;
- which hardware connections are important when reproducing the robot.

## Main Files

- `platformio.ini` - PlatformIO environment and library definition
- `main.cpp` / `src/main.cpp` - controller entry points present in the repository
- `lib/Lidar/` - distance-sensor handling
- `lib/IMU/` - IMU integration
- `lib/Engine/` - motor-drive abstraction
- `lib/utils/` - helper logic used by the controller

## Expected Hardware Context

This embedded project is documented as the controller for:

- `ESP32`
- steering servo
- drive motor through `L298N`
- `BNO085` IMU
- two distance sensors
- physical start button

The wider system architecture is documented in:

- [Electronics Overview](../docs/hardware/electronics_overview.md)
- [PCB And Wiring Diagrams](../docs/hardware/pcb_wiring_diagrams.md)
- [Wiring Overview](../schemes/wiring_overview.md)

## Build And Upload

1. install `PlatformIO`
2. open this `src/` folder as the PlatformIO project
3. check `platformio.ini` and use the defined environment
4. connect the `ESP32` board used in the robot
5. build the firmware
6. upload the firmware
7. open serial monitoring to confirm that the controller starts correctly
8. verify that the start button, steering servo, IMU, and distance sensors respond as expected

## Rebuild Notes

When reproducing the robot, the most important points are:

1. use the wiring information from the hardware documentation, not this file alone
2. keep the sensor wiring and motor wiring organized as shown in the schemes
3. verify the steering center mechanically before tuning behavior on the track
4. confirm that the start button workflow matches the competition start procedure
5. treat this folder as the embedded-controller part of the robot, not as the full two-board perception stack

## Repository Note

The repository documents the robot at engineering level, not only as a code dump. For that reason, this folder should be read together with the design, hardware, testing, and reproducibility documentation.
