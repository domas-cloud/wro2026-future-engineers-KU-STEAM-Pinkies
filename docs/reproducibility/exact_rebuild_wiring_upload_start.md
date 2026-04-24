# Exact Rebuild, Wiring, Upload, And Start Procedure

This page is the shortest exact rebuild path for a functionally equivalent robot.

## 1. Rebuild The Hardware

Use these files in this order:

1. [Bill Of Materials](../hardware/parts_list.md)
2. [Drivetrain And Steering](../design/drivetrain_and_steering.md)
3. [Model Files](../../models/README.md)
4. [PCB And Wiring Diagrams](../hardware/pcb_wiring_diagrams.md)
5. [Custom Schematic PDF](../../schemes/Wro_customPCBs.pdf)

Build target used by this repository:

- compact rear-wheel-drive robot;
- front steering with `MG90S`;
- rear `N20 6 V 250 rpm` drive motor through `L298N`;
- `ESP32-WROOM-32` low-level controller;
- `Raspberry Pi Zero` plus camera for perception;
- `BNO085` and `front VL53L1X + 2x VL53L1CD`.

## 2. Wire It Exactly

### Main power path

```text
2x 18650 battery pack
  -> perfboard distribution
     -> motor branch -> L298N -> N20 motor
     -> regulated logic branch -> ESP32
     -> regulated logic branch -> Raspberry Pi Zero
     -> regulated sensor branch -> BNO085 + VL53L1CD sensors
     -> steering branch -> MG90S servo
```

### ESP32 pin map

| Function | ESP32 pin |
| --- | --- |
| start button | `GPIO13` |
| motor PWM enable | `GPIO32` |
| motor direction 1 | `GPIO26` |
| motor direction 2 | `GPIO25` |
| steering servo | `GPIO33` |
| front ToF XSHUT | `GPIO15` |
| left ToF XSHUT | `GPIO5` |
| right ToF XSHUT | `GPIO18` |
| Pi UART RX | `GPIO16` |
| Pi UART TX | `GPIO17` |

### Sensor addresses and roles

| Sensor | Address | Role |
| --- | --- | --- |
| `BNO085` | `0x4A` with `0x4B` fallback | yaw / heading |
| front `VL53L1X` | `0x30` | turn trigger |
| left `VL53L1CD` | `0x31` | left clearance |
| right `VL53L1CD` | `0x32` | right clearance |

## 3. Upload The ESP32 Firmware

1. Open [src](../../src/) as the PlatformIO project.
2. Confirm [platformio.ini](../../src/platformio.ini) uses environment `upesy_wroom`.
3. Connect the `ESP32` over USB.
4. Build the firmware.
5. Upload the firmware to the board.
6. Open serial monitor at `115200` baud if a startup check is needed.

The active runtime file is [src/src/main.cpp](../../src/src/main.cpp).

## 4. Start The Pi Zero Side

If obstacle / perception guidance is used:

1. connect the camera to the `Raspberry Pi Zero`;
2. connect Pi UART to `ESP32 GPIO16/GPIO17` with `3.3 V` TTL levels;
3. install the Pi dependencies from [requirements.txt](../../src/pi-zero/requirements.txt);
4. run the perception process described in [src/pi-zero/README.md](../../src/pi-zero/README.md);
5. verify that UART packets match [protocol.md](../../src/pi-zero/protocol.md).

Expected packet:

```text
VISION,<mode>,<lane_shift_mm>,<obstacle_side>,<confidence>,<age_ms>
```

## 5. Pre-Run Checks

Before each run:

1. robot is placed in the correct start position;
2. battery is charged and regulators are stable;
3. `BNO085` gives stable yaw while robot is still;
4. all three ToF sensors respond with valid readings;
5. steering returns near center;
6. motor direction is forward;
7. Pi packets are fresh if perception mode is enabled.

## 6. Exact Start Procedure

1. power the robot;
2. wait for sensor initialization to finish;
3. confirm the robot is stationary and aligned with the track;
4. press the physical start button once;
5. the controller stores the current yaw as `targetAngle`;
6. the motor starts and the autonomous loop begins.

Run stop behavior:

- after the required edge count, the controller stops the motor and centers steering;
- if the run is restarted, the start button toggles the next cycle.

## 7. One-Page Judge Note

If a judge wants the shortest reproducibility proof, these are the key checkpoints:

- parts are listed in [parts_list.md](../hardware/parts_list.md);
- wiring and addresses are listed in [pcb_wiring_diagrams.md](../hardware/pcb_wiring_diagrams.md);
- firmware is in [src/src/main.cpp](../../src/src/main.cpp);
- build target is in [platformio.ini](../../src/platformio.ini);
- obstacle interface is in [vision_interface.md](../code/vision_interface.md).
