# What Worked — Hardware V1 Evidence

## Status

The previous page was archived at [`archivo/hardware-v1-esp32-250rpm/docs/evaluation/what_worked.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/evaluation/what_worked.md).

## Supported Hardware V1 lessons

### Mechanics

- corrected steering geometry reduced the large lever-arm problem;
- MG90S became sufficient after mechanical resistance was reduced;
- silicone front wheels improved useful steering grip;
- LEGO differential reduced turning resistance and binding;
- compact packaging improved manoeuvrability.

### Sensors and control

- BNO085 provided heading feedback;
- front/side ToF sensing supported local distance control;
- rigid mounting improved consistency;
- ESP32 handled the real-time controller.

### Process

- comparing repeated runs was more useful than judging one best run;
- mechanical improvements made software tuning easier;
- preserving rejected versions made the engineering decisions explainable.

## Hardware V2 caution

The Raspberry Pi camera, 18650 power system, L298N and 250 rpm motor are not active V2 choices. PixyCam, LiPo, custom PCB and the faster motor require new validation before being added to this list.
