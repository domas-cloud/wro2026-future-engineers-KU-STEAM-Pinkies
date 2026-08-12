# Faster motor for Hardware V2

The V1 car used an N20 6 V 250 rpm motor. We chose it after trying 50, 250 and 1000 rpm versions because it was the easiest useful compromise on that robot.

For V2 we want more speed, so we are reopening the motor choice. The custom PCB and new power system also mean we can choose a driver that better matches the motor instead of designing around the old L298N module.

We do not want to choose from rpm alone. For every serious candidate we will record the exact model, rated voltage, gearbox/rpm, current data, shaft/mount dimensions and the wheel size used. On the car we will measure loaded speed or a fixed-distance time, launch behaviour, current, temperature, straight drift and corner behaviour.

A simple speed estimate is still useful:

`vehicle speed = motor output rpm × wheel circumference / 60`

but it is only an estimate. Battery sag, gearbox losses, tyre slip and the real mass of the car matter more once it is on the floor.

The motor we keep should make the car faster without causing brownouts, excessive wheelspin, uncontrollable corner exits or a large drop in repeated-run reliability. We also need enough current/thermal margin in the H-bridge and connectors.

After the motor changes we will retune turn timing, steering response and obstacle reaction distance because the old thresholds were developed at the V1 speed. We will also check the LEGO differential, shaft coupling and motor mount for the higher load.

The final comparison will sit here once we have real candidate measurements rather than guessed values.
