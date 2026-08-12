# Drivetrain and steering

The drivetrain uses rear-wheel drive with a LEGO differential. Steering is at the front with an MG90S servo and custom linkage.

## What we kept from the first robot

The first steering arrangement put too much load on the servo. The problem was mainly geometry, not lack of servo torque, so we shortened the lever arm and corrected the linkage. That made the steering easier to centre and more repeatable. Silicone front tyres also helped because the wheels stopped sliding as much when the servo turned them.

We tried a metal differential before the LEGO one. The metal unit bound more in corners; the LEGO differential turned more smoothly, so it became our working baseline.

For Hardware V1 we also compared 50, 250 and 1000 rpm N20 motors. The 250 rpm motor gave the best balance on that version of the car. The old detailed notes are kept in [`archivo/`](../../../archivo/hardware-v1-esp32-250rpm/docs/design/drivetrain_and_steering.md).

## What changes for V2

We want a faster motor, but we have not locked the exact part yet. We will compare candidates using loaded speed/current, temperature, straight-line control, corner behaviour and repeated Open/Obstacle runs. The selected H-bridge has to match the measured motor current.

The steering and differential also need to be checked again at the new speed. Before the mechanical side is final we still need the final motor/mount, mass, wheelbase, track widths, wheel diameter, clearance, steering limits and measured turning space.

Motor test notes: [`hardware_v2_motor_upgrade_plan.md`](hardware_v2_motor_upgrade_plan.md).
