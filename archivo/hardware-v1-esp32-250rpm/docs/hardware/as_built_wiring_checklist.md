# As-Built Wiring Checklist

This checklist turns the current wiring documentation into a single judge-friendly verification page.

## Power Path

| From | To | Purpose | Check |
| --- | --- | --- | --- |
| `2x 18650` battery pack | perfboard main input | main energy source | confirm polarity before powering |
| perfboard distribution | `L298N` motor branch | drive motor power | motor branch isolated from logic wiring as much as possible |
| perfboard distribution | logic regulator | stable logic voltage | regulator output checked before connecting boards |
| logic regulator | `ESP32` | low-level controller power | common ground with all modules |
| logic regulator | `Raspberry Pi Zero` | perception computer power | stable under camera load |
| sensor branch | `BNO085` and ToF sensors | sensing power | common I2C ground |
| steering branch | `MG90S` servo | steering actuation | servo power path checked under movement |

## ESP32 Pin Checklist

| Function | ESP32 pin / address | Verification |
| --- | --- | --- |
| start button input | `GPIO13` | button toggles run state |
| motor PWM / enable | `GPIO32` | motor speed output changes |
| motor direction 1 | `GPIO26` | forward direction correct |
| motor direction 2 | `GPIO25` | reverse/brake logic not swapped |
| steering servo PWM | `GPIO33` | servo centers and turns both directions |
| front ToF XSHUT | `GPIO15` | front sensor initializes |
| left ToF XSHUT | `GPIO5` | left sensor initializes |
| right ToF XSHUT | `GPIO18` | right sensor initializes |
| Pi UART RX | `GPIO16` | ESP32 receives Pi packets |
| Pi UART TX | `GPIO17` | optional controller transmit line |
| I2C bus | `400 kHz` | IMU and ToF sensors respond |

## Sensor Address Checklist

| Module | Address | Role | Verification |
| --- | --- | --- | --- |
| `BNO085` | `0x4A`, fallback `0x4B` | yaw / heading | stable heading while robot is still |
| front ToF | `0x30` | front distance / turn trigger | distance changes when object moves in front |
| left ToF | `0x31` | left clearance | distance changes on left side |
| right ToF | `0x32` | right clearance | distance changes on right side |

## Pi Link Checklist

| Item | Expected value |
| --- | --- |
| voltage level | `3.3 V` TTL UART |
| baud rate | `115200` |
| packet format | `VISION,<mode>,<lane_shift_mm>,<obstacle_side>,<confidence>,<age_ms>` |
| behavior on stale data | ESP32 should not depend on old perception packets |

## Final Cross-Check

Before submission, compare this page against:

- [pcb_wiring_diagrams.md](pcb_wiring_diagrams.md);
- [schemes/wiring_overview.md](../../schemes/wiring_overview.md);
- [schemes/Wro_customPCBs.pdf](../../schemes/Wro_customPCBs.pdf);
- final robot photos in [v-photos/](../../v-photos/).

If the physical robot differs from this checklist, update the documentation instead of leaving a mismatch.

