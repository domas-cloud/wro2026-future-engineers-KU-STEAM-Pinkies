# V2 wiring check

We will use this page when the custom PCB is assembled. It is deliberately empty of final part numbers until the board exists.

## Build details

| Item | Value |
|---|---|
| PCB revision | not recorded yet |
| schematic revision | not recorded yet |
| source commit | not recorded yet |
| LiPo | not selected yet |
| motor | not selected yet |
| motor driver | not selected yet |
| assembly date | not recorded yet |

## Before connecting the motor

- [ ] battery polarity and maximum voltage match the schematic
- [ ] protection and main power switch are fitted
- [ ] every regulator rail is measured first
- [ ] ESP32, camera and sensors start correctly
- [ ] programming/reset access works
- [ ] connector labels match the real cable positions

## Sensors and camera

- [ ] BNO085 starts repeatedly and yaw is stable while the car is still
- [ ] front VL53L1X starts at the documented address
- [ ] both VL53L4CD sensors start at their documented addresses
- [ ] ten full power cycles complete without an I2C address problem
- [ ] PixyCam SPI starts repeatedly
- [ ] red/green signatures and camera settings are saved

## Servo and motor

- [ ] MG90S centres without forcing the linkage against a hard stop
- [ ] logic rails do not dip enough to reset the ESP32 while steering
- [ ] motor direction agrees with the command
- [ ] PWM range is tested
- [ ] launch and stall current are recorded safely
- [ ] driver/regulator temperature is checked after repeated load
- [ ] sensor and camera communication still works with the motor running

When this checklist is complete we will add PCB photos, measured power/temperature tables and the source commit used for the test.
