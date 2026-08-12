# Hardware V2 Software Architecture

## Version status

The previous two-controller Raspberry Pi Zero + ESP32 architecture was archived at [`archivo/hardware-v1-esp32-250rpm/docs/code/software_architecture_improved.md`](../../archivo/hardware-v1-esp32-250rpm/docs/code/software_architecture_improved.md).

Hardware V2 keeps the ESP32 as the central real-time controller and replaces Raspberry Pi image processing with a first-generation PixyCam that performs colour processing on its own processor.

## Target architecture

```text
PixyCam colour processing
        ↓ SPI block data
ESP32 input validation
        ↓
obstacle-side decision
        + BNO085 heading
        + front/side ToF distances
        ↓
steering reference and corner logic
        ↓
MG90S PWM + motor-driver commands
```

## ESP32 responsibilities

- start and monitor the BNO085 and all three ToF sensors;
- initialize and read PixyCam over SPI;
- maintain a local age for the latest valid camera result;
- select red/green obstacle behaviour;
- hold heading and local spacing;
- execute corner transitions;
- drive the steering servo and selected motor driver;
- detect missing sensors or communication faults;
- stop or fall back according to the final safety strategy.

## PixyCam responsibilities

- acquire the camera image;
- apply trained red and green signatures;
- return detected block information;
- avoid transferring full images to the ESP32.

## Published-code status

The current [`src/src/main.cpp`](../../src/src/main.cpp) is Hardware V1 controller code. It includes:

- ESP32 sensor initialization;
- BNO085 and ToF control;
- steering and motor control;
- legacy UART vision parsing;
- a compile-time obstacle-round flag.

It does **not** yet implement the confirmed Hardware V2 PixyCam SPI interface. The `src/pi-zero/` and `src/python/` directories are legacy Raspberry Pi development evidence and are not active Hardware V2 runtime components.

## Known alignment work before Hardware V2 firmware is final

1. implement PixyCam SPI access;
2. remove or isolate obsolete Pi/UART code from the active build;
3. replace pin assumptions with the approved PCB pin map;
4. confirm the start-button pin from hardware and code;
5. make the front/side sensor type explicit instead of inferring it from a GPIO number;
6. align corner-trigger documentation with the actual formula used in code;
7. define final stop behaviour and steering-centre behaviour;
8. verify derivative/error-state handling in the controller;
9. add camera, sensor and motor-driver fault handling;
10. publish testable configuration values and calibration steps.

These are required tasks, not claims that the code has already been corrected.

## Required final source structure

The final repository should make it obvious which files are built for Hardware V2. It should include:

- one documented PlatformIO environment for the final ESP32 hardware;
- PixyCam interface module;
- explicit sensor modules for `VL53L1X`, `VL53L4CD` and `BNO085`;
- motor-driver abstraction matching the selected H-bridge;
- configuration or constants matching the PCB pin map;
- comments explaining state transitions and safety behaviour;
- build and upload instructions verified on the real board.

## Architecture acceptance condition

Hardware V2 software may be described as final only when the source code, custom PCB, wiring tables, calibration procedure and repeated Open/Obstacle tests all describe the same implementation.
