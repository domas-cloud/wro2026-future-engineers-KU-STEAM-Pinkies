# Next build notes

This is our working list for the Hardware V2 rebuild. It is not a description of finished work; once something is tested, the result should be written in the proper hardware, software or testing page.

## Parts we still need to lock

### Battery and power

We have decided to use a LiPo, but still need the exact cell count, voltage, capacity, C-rating, connector, dimensions and mass. After that we can finish the regulator and protection choices and measure idle, driving and peak current.

### Drive motor

We want more speed than the V1 250 rpm motor. Before choosing the final motor we need its rated voltage, gearbox/rpm, current, shaft dimensions and loaded performance on the car. The important comparison is not unloaded rpm — it is track speed, control, temperature and run reliability.

### Motor driver

The H-bridge on the custom PCB has to be chosen after we know the real motor current. We need enough peak-current margin, 3.3 V logic compatibility, sensible losses and acceptable temperature during repeated runs.

### PCB

Still to finish/record: ESP32 implementation, complete GPIO map, programming/boot circuit, power rails, connectors, I2C startup lines, PixyCam SPI pins, board dimensions and mounting holes. Final submission also needs the editable schematic/PCB files, Gerbers, drill files, BOM and assembly photos.

## Sensors and camera

Record the final position and height of the front VL53L1X, both VL53L4CD side sensors, BNO085 and PixyCam. We also need the final I2C addresses/startup pins and IMU orientation.

For PixyCam, save the red/green signature settings, SPI wiring and clock, and test useful detection distance in different lighting. Recheck communication with the motor and servo running.

## Software

The old program was moved to `brainstorm/software-redesign/` on 12 August. The new V2 program should start with a small hardware test for ESP32, ToF, BNO085, PixyCam, servo and motor driver. Only after those interfaces are stable should we add driving states, obstacle logic and tuning.

Before calling the software final, check that the start button, stop/finish behaviour, fault handling, GPIO map and build instructions all match the physical PCB.

## Bench tests

When the board is assembled:

- power it first without motor/servo and check every rail;
- run at least ten full power cycles and make sure the I2C/SPI devices start every time;
- measure current at idle, normal driving and the worst observed transient;
- measure 3.3 V/5 V rail sag while the servo moves and motor launches;
- record motor, driver and regulator temperature after repeated load;
- check that PixyCam and ToF readings remain stable with the drive system active.

## Track tests

After hardware bring-up, repeat the same basic measurements we used on V1 so the comparison is meaningful: straight drift, 90° turn space, repeated Open runs and repeated Obstacle runs. Add failures to the iteration log instead of only recording the successful attempt.

## Media and final rebuild notes

Before submission we still need six new V2 vehicle views, PCB top/bottom photos, sensor/connector photos, PixyCam settings screenshots and final Open + Obstacle videos.

The final rebuild guide must use the exact V2 BOM, PCB files, pin map, software and calibration/start procedure. Do not copy V1 values into it unless they are still physically true on V2.
