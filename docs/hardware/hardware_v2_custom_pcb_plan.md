# Custom PCB rebuild

The V1 robot used separate modules and perfboard. It worked, but the wiring became difficult to reproduce and the new motor/power/camera changes gave us a good reason to redesign the electronics as one custom board.

## What the new board needs to do

The board is built around an ESP32-WROOM-32. It must connect the BNO085, front VL53L1X, two VL53L4CD sensors, PixyCam over SPI, MG90S servo, start button and the final motor driver.

The power side will accept the final LiPo through a protected input and provide the rails needed by logic, sensors, camera and servo. Motor power and high-current return paths must be routed so they do not unnecessarily disturb I2C/SPI signals.

We also want the board to be easier to work on than the perfboard: labelled connectors, clear pin-1 orientation, programming/reset access and useful test points.

## Why several values are still open

The exact battery, motor and H-bridge are linked decisions. We do not want to finish the power tree or driver layout using guessed current and voltage values. First we choose/measure the motor and LiPo, then lock the driver and regulator margins, then finish the schematic and PCB.

The same applies to the ESP32 GPIO map. PixyCam SPI, ToF startup pins, servo, motor control and start button will be assigned once the board routing is reviewed, then the new source will use that map.

## First board test

The first power-up will be done with the motor and servo disconnected. We will check battery input, protection and every regulator rail before connecting the ESP32 and sensors. After I2C is stable we will test PixyCam SPI, then servo transients, and finally the motor driver under load.

We want at least ten full power cycles without sensor/address failures and a motor-on communication test before relying on the PCB for track runs.

## Files we still need for the final version

The final PCB package should contain the editable schematic and PCB source, schematic PDF, Gerbers, drill files, BOM/assembly information, connector and GPIO map, board dimensions/mounting holes and photos of the assembled top and bottom. Bench notes should include current, rail sag, temperatures and any board correction made after first power-up.

The earlier PCB/perfboard material in [`schemes/`](../../schemes/) is kept as V1 history until the new board files replace it.
