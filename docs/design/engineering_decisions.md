# Engineering Decisions

## Version status

The previous Hardware V1 decision narrative was archived at [`archivo/hardware-v1-esp32-250rpm/docs/design/engineering_decisions.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/design/engineering_decisions.md).

## Verified Hardware V1 decisions

| Decision | Alternatives | Hardware V1 choice | Evidence level |
|---|---|---|---|
| chassis direction | larger complex robot vs compact simpler robot | compact robot | design history and photos |
| steering geometry | large lever arm vs corrected geometry | corrected geometry | practical comparison |
| front wheels | lower-grip earlier wheels vs silicone | silicone | practical observation |
| differential | metal vs LEGO | LEGO | practical comparison |
| V1 motor | 50 / 250 / 1000 rpm N20 | 250 rpm | Hardware V1 testing |
| heading/local sensing | single source vs mixed sensing | BNO085 + ToF + camera layer | working V1 architecture |

These choices remain historical evidence. Only the retained mechanical lessons can be carried into V2 without new validation.

## Confirmed Hardware V2 decisions

- retain ESP32-WROOM-32;
- remove Raspberry Pi Zero;
- use first-generation PixyCam over SPI;
- use front VL53L1X and two side VL53L4CD sensors;
- retain BNO085 and MG90S;
- move to LiPo;
- build a custom PCB;
- select a faster motor.

## Open decisions

- exact LiPo;
- exact motor;
- exact H-bridge;
- regulator topology;
- ESP32 module/carrier implementation;
- complete pin map;
- PCB size and mounting;
- PixyCam settings and thresholds.

## Decision evidence format

Every final choice should record:

1. problem;
2. alternatives;
3. selection criteria;
4. calculations;
5. test method;
6. measured result;
7. risk/regression;
8. final keep/reject decision;
9. evidence link and commit.

See [`hardware_v2_decision_register.md`](../hardware/hardware_v2_decision_register.md).
