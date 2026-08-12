# Engineering decisions

This page keeps the important choices in one place. We use the old robot as evidence, but we do not assume every V1 result still applies after the electronics and motor change.

## Decisions that came from V1 testing

| What we changed | What we chose | Why we kept it |
|---|---|---|
| large/complex chassis ideas | compact chassis | easier packaging trade-off, better manoeuvrability and simpler tuning |
| first steering linkage | corrected, shorter-lever geometry | lower servo load and better centre repeatability |
| earlier front wheels | silicone tyres | noticeably better steering grip |
| metal differential | LEGO differential | less binding in turns |
| 50 / 250 / 1000 rpm N20 motors | 250 rpm for V1 | best balance on the first robot |
| loose heading-only ideas | BNO085 + local ToF sensing | more useful combination on the track |

## Decisions already made for V2

We are keeping the ESP32, BNO085, MG90S and three ToF sensors. The Raspberry Pi Zero is removed. A first-generation PixyCam will do colour detection and communicate with the ESP32 over SPI. Power moves to LiPo and the electronics move onto a custom PCB. We are also reopening the motor choice to get more speed.

## Decisions still open

The exact LiPo, faster motor, H-bridge, regulators, PCB GPIO/connector map and final PixyCam settings are still being worked out. We will add the final choices after they exist on the physical robot and have been tested.

For a major choice we try to keep four things together: what problem we had, what alternatives we actually considered, what we measured, and why we kept or rejected the result. More PCB-specific notes are in [`../hardware/hardware_v2_decision_register.md`](../hardware/hardware_v2_decision_register.md).
