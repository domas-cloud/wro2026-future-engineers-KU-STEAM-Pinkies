# Motor and steering servo

## Steering servo

We use an `MG90S`. The first robot showed that the steering problem was mostly linkage geometry rather than lack of servo power. After shortening the lever arm and improving the front-wheel grip, the MG90S worked much more consistently, so we are keeping it for V2.

We still need to recheck centre repeatability and current draw with the faster V2 drivetrain.

## Drive motor

Hardware V1 compared 50, 250 and 1000 rpm N20 motors and used the 250 rpm version. Hardware V2 is intentionally reopening that choice because we want more speed and the power/driver electronics are changing.

The final V2 motor has not been selected yet. We will compare realistic candidates using loaded speed, current, temperature, straight drift, corner behaviour and repeated challenge runs. See [`../design/hardware_v2_motor_upgrade_plan.md`](../design/hardware_v2_motor_upgrade_plan.md).
