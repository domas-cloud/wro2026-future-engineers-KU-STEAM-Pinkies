# Runtime Setup And Calibration

## Current status

The previous Raspberry Pi Zero runtime instructions were archived at [`archivo/hardware-v1-esp32-250rpm/docs/code/runtime_setup_and_calibration.md`](../../archivo/hardware-v1-esp32-250rpm/docs/code/runtime_setup_and_calibration.md).

The repository currently contains buildable Hardware V1 ESP32 source and legacy Pi source. Hardware V2 runtime setup is incomplete because PixyCam SPI code, the final PCB pin map, motor driver and power design are not yet available.

## Current Hardware V1 code build

The current PlatformIO project is under [`src/`](../../src/):

- [`src/src/main.cpp`](../../src/src/main.cpp);
- [`src/lib/`](../../src/lib/);
- [`src/platformio.ini`](../../src/platformio.ini).

It can be used as historical controller evidence and as a starting point for the V2 port. It must not be presented as the completed PixyCam/custom-PCB firmware.

## Hardware V2 setup information still required

Before publishing final setup instructions, add verified values for:

1. exact PCB revision;
2. exact ESP32 flash/programming configuration;
3. final GPIO map;
4. PixyCam library/version and SPI pins;
5. I2C pins, addresses, pull-ups and startup sequence;
6. motor-driver type and PWM behaviour;
7. servo centre and safe limits;
8. LiPo and regulator checks;
9. build command and upload connection tested on the real board;
10. expected serial/debug output and fault indications.

## Required Hardware V2 pre-run calibration

| Check | Required record | Pass condition |
|---|---|---|
| battery | exact pack and measured voltage | inside documented operating range |
| power rails | idle and transient measurements | no unsafe voltage or reset |
| steering centre | neutral pulse/angle and physical alignment | repeatable centre without binding |
| steering limits | tested left/right mechanical clearance | no hard-stop loading |
| motor direction | command and observed direction | forward command moves forward |
| BNO085 | orientation and stationary yaw | stable and correctly signed |
| front ToF | address, range and mounting | valid response in intended approach area |
| side ToF | addresses and wall-distance checks | left/right readings match physical positions |
| PixyCam | signatures and detection test | correct red/green classification in test conditions |
| camera timeout | update interruption test | controller enters documented fallback |

## Required start procedure

The final procedure must state, in order:

1. how the LiPo is connected and switched;
2. expected initialization indication;
3. what happens when a required sensor or camera fails;
4. how long the robot must remain still for heading initialization;
5. the exact physical start-button action;
6. the condition that starts motor output;
7. the condition that ends the run.

These steps remain incomplete until the real Hardware V2 firmware and PCB exist.

## Post-run logging

Each structured test should record:

- date;
- commit;
- PCB revision;
- motor, driver and battery;
- Pixy settings;
- challenge layout;
- run result and time;
- contacts or moved pillars;
- fault or failure cause;
- change made before the next test.

Use [`hardware_v2_validation_template.md`](../testing/hardware_v2_validation_template.md).
