# Software Flow And State Logic

## Version status

The previous Hardware V1 flow description was archived at [`archivo/hardware-v1-esp32-250rpm/docs/code/software_flow_and_state_logic.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/code/software_flow_and_state_logic.md).

Use [`software_state_machine_and_obstacle_flow.md`](software_state_machine_and_obstacle_flow.md) as the active Hardware V2 state reference.

## Hardware V2 flow summary

```text
power on
  -> initialize ESP32, sensors, PixyCam and outputs
  -> initialization valid?
       no -> safe fault state
       yes -> wait for physical start
  -> read yaw, ToF and Pixy blocks
  -> trusted red/green block?
       yes -> select legal avoidance reference
       no  -> neutral local control
  -> corner condition?
       yes -> execute corner and update heading reference
       no  -> continue straight/avoidance control
  -> run complete?
       yes -> stop using documented final state
       no  -> repeat
```

## Exact implementation still required

- final pin map;
- Pixy SPI module;
- accepted block rules;
- stale and ambiguous handling;
- corner trigger;
- lap/finish logic;
- parking logic;
- fault transitions;
- final stop/restart behaviour.

The final diagram must be regenerated from the actual tested source, not from an earlier Pi/UART concept.
