# Drivetrain And Steering

## Version status

The previous detailed document was archived at [`archivo/hardware-v1-esp32-250rpm/docs/design/drivetrain_and_steering.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/design/drivetrain_and_steering.md).

This page records verified Hardware V1 mechanical evidence and the information still required for Hardware V2.

## Hardware V1 verified baseline

- rear-wheel drive;
- front steering with MG90S;
- LEGO rear differential;
- custom silicone front wheels;
- three main steering iterations;
- tested `50`, `250` and `1000 rpm` N20 options;
- `250 rpm` retained for Hardware V1.

The 250 rpm choice is historical and is not the final Hardware V2 motor decision.

## Steering lessons retained for Hardware V2

- reduce mechanical resistance before selecting a stronger servo;
- avoid a large wheel lever arm;
- keep left/right geometry symmetric;
- use enough front grip to translate servo motion into real turning;
- limit steering travel to the useful mechanical range;
- validate centre repeatability after repeated left/right cycles.

## Differential

The LEGO differential remains the current baseline because Hardware V1 testing indicated smoother turning and less binding than the earlier metal solution. It must be retested with the selected faster motor.

## Hardware V2 motor selection required

The final motor document must include:

- exact model and rated voltage;
- no-load and loaded rpm;
- gearbox ratio;
- wheel diameter and calculated speed;
- free-run, launch and stall current;
- available torque or measured acceleration;
- compatibility with the differential and mount;
- H-bridge temperature;
- repeated Open and Obstacle results;
- reason for choosing it over at least one realistic alternative.

Use [`hardware_v2_motor_upgrade_plan.md`](hardware_v2_motor_upgrade_plan.md).

## Final mechanical data still required

- final mass;
- wheelbase and track widths;
- wheel diameters;
- ground clearance;
- measured steering limits;
- turning space at final speed;
- final motor mount and CAD;
- photos of the final drivetrain and steering.
