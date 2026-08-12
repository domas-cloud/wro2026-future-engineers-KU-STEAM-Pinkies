# Full Rebuild Guide

This is the single rebuild path from an empty table to a functionally equivalent robot.

## 1. Collect Parts

Start with:

- [parts_list.md](../hardware/parts_list.md);
- `ESP32-WROOM-32`;
- `Raspberry Pi Zero` with camera;
- `BNO085`;
- front, left, and right ToF sensors;
- `MG90S` steering servo;
- `N20 6 V 250 rpm` drive motor;
- `L298N` motor driver;
- `2x 18650` battery pack and regulators;
- printed parts from [models/](../../models/).

## 2. Print And Fit Mechanical Parts

1. Print the steering and motor support STL files listed in [models/README.md](../../models/README.md).
2. Build the compact chassis layout described in [mechanical_rebuild.md](mechanical_rebuild.md).
3. Install the drive motor and rear differential.
4. Install the front steering column, servo, and linkage.
5. Confirm that the steering returns to center and does not bind.

## 3. Wire The Robot

1. Follow [as_built_wiring_checklist.md](../hardware/as_built_wiring_checklist.md).
2. Compare against [pcb_wiring_diagrams.md](../hardware/pcb_wiring_diagrams.md).
3. Compare against [schemes/wiring_overview.md](../../schemes/wiring_overview.md).
4. Check the schematic PDF in [schemes/Wro_customPCBs.pdf](../../schemes/Wro_customPCBs.pdf).

## 4. Upload Controller Firmware

1. Open [src/](../../src/) as a PlatformIO project.
2. Build using [src/platformio.ini](../../src/platformio.ini).
3. Upload to the `ESP32`.
4. Confirm serial output at `115200` baud if needed.

## 5. Start Pi Perception Layer

1. Read [src/pi-zero/README.md](../../src/pi-zero/README.md).
2. Confirm packet format in [src/pi-zero/protocol.md](../../src/pi-zero/protocol.md).
3. Connect UART at `3.3 V` TTL to `ESP32 GPIO16/GPIO17`.
4. Run the Pi process only after confirming the ESP32 can run safely on its own.

## 6. Calibrate

Use [runtime_setup_and_calibration.md](../code/runtime_setup_and_calibration.md).

Minimum checks:

- steering center;
- motor direction;
- stable IMU heading;
- valid front/left/right ToF readings;
- fresh Pi packets if perception mode is enabled;
- battery/regulator stability under servo and motor load.

## 7. Validate

Use:

- [tests.md](../testing/tests.md);
- [performance_measurements.md](../testing/performance_measurements.md);
- [final_validation_results.md](../testing/final_validation_results.md).

The final submission should include real counted runs for open and obstacle layouts.

## 8. Judge Review Path

For fastest review:

1. [README.md](../../README.md)
2. [START_HERE.md](../../START_HERE.md)
3. [evidence_map.md](evidence_map.md)
4. [full_rebuild_guide.md](full_rebuild_guide.md)
5. [final_validation_results.md](../testing/final_validation_results.md)

