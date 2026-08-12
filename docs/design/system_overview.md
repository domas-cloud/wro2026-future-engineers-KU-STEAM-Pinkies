# System overview

We treat the car as one system because almost every useful change affects more than one subsystem. A faster motor changes the current demand, reaction distance and steering tuning. Servo current can disturb the logic supply. Camera height changes when an obstacle becomes visible. Wheel grip changes how much a software steering command actually turns the car.

The Hardware V2 data path is intended to be:

```text
PixyCam ───────┐
BNO085 ────────┤
front/side ToF ├──> ESP32-WROOM-32 ──> steering + motor driver
start button ──┘
```

The PixyCam handles colour-signature processing. The ESP32 combines that with heading and distance measurements and controls the MG90S and motor driver.

The first robot showed us that correcting steering geometry, adding front-wheel grip, using the LEGO differential and rigidly mounting the IMU made the car easier to control. We are carrying those lessons into V2, but the new motor, power system, PCB and camera still need their own measurements.

At the moment the exact LiPo, motor, H-bridge, regulators and final pin map are still open. The V2 system becomes a final build only when the hardware, source, wiring, photos and repeated test results all refer to the same physical revision.
