# Hardware V2 Motor And Servo Selection

## Status

The previous generic page was archived at [`archivo/hardware-v1-esp32-250rpm/docs/hardware/motor_servo_selection.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/hardware/motor_servo_selection.md).

## Steering servo

`MG90S` is confirmed for Hardware V2 because it matches the existing steering baseline. Final validation still requires:

- supply voltage;
- normal and near-stall current;
- centre repeatability;
- full left/right load;
- rail voltage during movement;
- performance at the selected faster driving speed.

## Drive motor

The exact Hardware V2 motor is `TBD`. It must be faster than the V1 250 rpm baseline while remaining controllable and electrically compatible.

For every candidate record:

- exact model and supplier/datasheet;
- rated voltage;
- no-load rpm;
- gearbox ratio;
- stall torque/current;
- loaded wheel speed;
- launch current;
- 3 m time;
- corner/overshoot behaviour;
- motor and driver temperature;
- repeated three-lap result.

## Selection rule

Do not choose only by rpm. Choose the candidate that improves useful track time without causing repeated steering, perception, current, thermal or reliability failures.

See [`../design/hardware_v2_motor_upgrade_plan.md`](../design/hardware_v2_motor_upgrade_plan.md).
