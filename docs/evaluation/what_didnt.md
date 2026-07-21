# What Did Not Work — Historical And Current Risks

## Status

The previous page was archived at [`archivo/hardware-v1-esp32-250rpm/docs/evaluation/what_didnt.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/evaluation/what_didnt.md).

## Hardware V1 rejected or weak approaches

- large steering lever arm increased MG90S load;
- earlier low-grip front wheels reduced steering effectiveness;
- metal/less suitable differential behaviour increased binding;
- one sensor type alone was insufficient for all navigation needs;
- insufficiently rigid IMU/sensor mounting reduced consistency;
- extreme motor choices were less useful than the V1 250 rpm compromise.

## Architecture retired for Hardware V2

- Raspberry Pi Zero perception stack;
- Pi camera and UART message layer;
- 2x18650 supply;
- perfboard/module integration;
- L298N as the assumed final driver;
- 250 rpm motor as the assumed final motor.

These items are not erased; they remain Hardware V1 evidence.

## Hardware V2 failure evidence still required

The final report should document at least one real failure and correction for:

- PCB bring-up;
- PixyCam signature/lighting setup;
- SPI or I2C stability under motor load;
- faster-motor control;
- LiPo/regulator transient behaviour;
- repeated obstacle runs.
