# What Worked

This section describes the solutions that proved effective in testing and were kept in later robot versions.

## Mechanics

- the three-gear steering layout allowed the servo motion to be transferred to both front wheels at the same time;
- rotating the side assemblies around their own axis reduced the large wheel lever-arm problem and the servo load;
- keeping the differential on the rear axle reduced turning resistance and improved track behavior.

## Sensors

- the `OV5647 5Mpx wide-angle` camera provided a wide enough track view for lane and obstacle evaluation;
- the `BNO085 9-DOF IMU` helped maintain more stable heading after several turns and reduced uncertainty that would otherwise depend only on the camera;
- the distance sensors worked well as a short-range confirmation layer near obstacles.

## System Architecture

- using the `ESP32` for control kept the robot decision cycle simpler and faster;
- limiting the number of ToF modules reduced power consumption and simplified the electronics architecture;
- rigid `BNO085` mounting and cleaner sensor placement reduced the effect of vibration on the readings.

## Overall Evaluation

The most effective decisions were those that reduced mechanical load and simplified the system structure.
That was especially visible in the steering geometry, the use of the differential, and the clearer separation of sensor roles.
