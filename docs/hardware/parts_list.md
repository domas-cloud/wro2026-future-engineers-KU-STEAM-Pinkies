# Parts List

This table lists the final robot package used for the current repository state.

| Qty | Part | Exact model / material | Voltage / RPM / interface | Function | Replacement / fallback | Source / note |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | main controller | `ESP32-WROOM-32` dev board | `3.3 V` logic, `Wi-Fi/BLE`, I2C, UART | low-level control loop, sensor polling, steering and motor output | any stable `ESP32` dev board with the same pin map | active firmware under `src/` |
| 1 | perception controller | `Raspberry Pi Zero` | `5 V` logic computer | camera-side perception and reference output | `Raspberry Pi Zero 2 W` if power budget allows | interface documented in `src/pi-zero/protocol.md` |
| 1 | camera | `OV5647 5 MP` wide-angle module | CSI camera interface | lane and obstacle interpretation | any Pi-compatible wide-angle camera with retuned parameters | used by the Pi-side process |
| 1 | IMU | `BNO085 9-DOF` | I2C, `0x4A` / `0x4B` | yaw reference and heading stabilization | `BNO086` with matching driver support | rigid mounting matters more than raw spec sheet |
| 3 | distance sensors | `VL53L4CD` | I2C, `0x30`, `0x31`, `0x32` | front turn trigger and side-distance correction | equivalent short-range ToF only with retuned thresholds | startup sequencing uses separate shutdown pins |
| 1 | steering servo | `MG90S` metal gear servo | `5 V` PWM servo | front-wheel steering actuation | higher-torque micro servo if geometry changes | final steering geometry kept servo load acceptable |
| 1 | drive motor | `N20 6 V 600 rpm` geared motor | `6 V`, `600 rpm` | rear-wheel propulsion | slower `300 rpm` and faster `1000 rpm` were tested and rejected | `600 rpm` gave the best speed/torque balance |
| 1 | motor driver | `L298N` module | motor rail + PWM/direction inputs | drive motor switching | smaller H-bridge if current and cooling remain sufficient | simple and robust during testing |
| 1 | battery pack | `2x 18650 Li-ion` holder | about `7.4 V` nominal | main robot energy source | equivalent protected 2-cell pack | powers all branches through regulated splits |
| 2 | regulators | buck regulators for logic and sensors | `5 V` regulated outputs | stable logic and sensor rails | equivalent step-down modules with enough current margin | separate branches reduce motor/servo noise coupling |
| 1 | drivetrain differential | `LEGO` differential | mechanical | reduces rear-axle resistance in turns | fixed axle only with major handling tradeoffs | kept after testing because it improved turning |
| 1 | steering gear set | printed gears from `models/` | mechanical | transfers servo motion to both front wheels | regenerated STL if geometry changes | final set corresponds to current CAD folder |
| 2 | rear wheels | `LEGO` wheels | mechanical | driven rear axle contact | equivalent diameter wheels with retuned controller gains | chosen for robustness and repeatability |
| 2 | front wheels | custom silicone wheels | mechanical | steering response and front grip | re-cast wheels from the same mould set | gave better steering authority than earlier options |
| 1 | chassis set | printed body and brackets from `models/` | mechanical | holds drivetrain, boards, sensors, and servo | revised prints if packaging changes | see `models/README.md` for the exported parts |
| assorted | wiring and connectors | jumper wires, headers, fasteners | signal and power interconnects | joins modules into the final robot | same-gauge wiring with clear labeling | exact lengths are adjusted during assembly |
