# Sensors

Hardware V2 uses the following sensing setup:

| Sensor | Position / job |
|---|---|
| VL53L1X | front distance and turn timing |
| VL53L4CD | left-side distance |
| VL53L4CD | right-side distance |
| BNO085 | heading/yaw |
| first-generation PixyCam | red/green traffic pillars |

The old `VL53L1CD` side-sensor name found in some archived V1 text was incorrect. The current side sensors are `VL53L4CD`.

We still need to record final mounting heights/angles, I2C addresses and startup pins after the custom PCB is assembled. The BNO085 will be mounted rigidly and its orientation/calibration will be written down with the final setup.

PixyCam settings are not final yet. We will save the actual red/green signatures, camera angle, useful detection distance and lighting tests after the camera is mounted on the V2 car.
