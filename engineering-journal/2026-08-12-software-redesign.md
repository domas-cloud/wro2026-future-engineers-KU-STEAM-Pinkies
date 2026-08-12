# 12 August 2026 — starting the software again

By August the robot hardware had changed enough that our old program no longer matched it.

The first robot used a Raspberry Pi Zero for camera processing and sent results to the ESP32 over UART. For the new version we removed the Pi, chose a first-generation PixyCam connected directly to the ESP32 over SPI, started moving the electronics onto a custom PCB, changed the battery direction to LiPo and reopened the drive-motor choice.

We initially tried to keep adapting the old software notes, but that created a confusing situation: some pages described the old Pi program, some described planned PixyCam code, and none of it was yet the tested program for the real V2 car.

So we decided to clear the active software area and keep the old work in `brainstorm/software-redesign/`. Nothing useful was deleted. The previous source and documents are still there if we need ideas or want to show how the project changed.

The next software version will start smaller. First we want to prove the PCB pin map, BNO085, three ToF sensors, PixyCam SPI, steering servo and motor driver. After that we can build the normal driving/corner logic and then obstacle handling. Tuning comes last, from real runs with the faster car.

The important lesson from the old software is still valid: it is much easier to tune a controller after the mechanics and sensor mounting are repeatable. We also want clear behaviour when a sensor/camera value is missing instead of allowing an old value to steer the car indefinitely.

We will move the new source into `src/` only when it actually runs on the V2 hardware. Until then, unfinished experiments stay in `brainstorm/`.
