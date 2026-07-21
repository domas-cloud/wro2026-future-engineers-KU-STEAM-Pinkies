# Risk And Failure Analysis

## Version status

The previous Hardware V1 analysis was archived at [`archivo/hardware-v1-esp32-250rpm/docs/design/risk_and_failures.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/design/risk_and_failures.md).

## Historical Hardware V1 risks and lessons

- large steering lever arm increased servo load;
- excessive useful steering angle reduced stability;
- front-wheel slip weakened turning;
- an unsuitable differential increased binding;
- motor extremes were less useful than the V1 middle option;
- loose IMU mounting reduced heading consistency;
- mechanics and software had to be improved together.

## Hardware V2 risk register

| Risk | Likely effect | Required mitigation/evidence |
|---|---|---|
| unknown LiPo maximum voltage | damaged electronics | select exact pack before schematic release |
| underestimated motor stall current | H-bridge or connector failure | safe current measurement and design margin |
| servo current spike | reset or sensor fault | separate/robust rail, capacitance and transient test |
| motor noise | SPI/I2C errors | suppression, layout separation and motor-on communication test |
| PixyCam false colour match | wrong passing side | trained signatures and varied-lighting test matrix |
| PixyCam stale/ambiguous block | unstable avoidance | explicit rejection and timeout handling |
| ToF address/startup conflict | missing local distance | XSHUT/startup sequence and ten-cycle validation |
| wrong PCB pin map | non-functional board | schematic-code cross-review |
| faster speed | late detection and overshoot | reaction-distance and repeated track testing |
| loose connectors | intermittent round failure | keyed connectors and strain relief |
| thermal overload | shutdown or damage | repeated-load temperature measurement |

## Failure-log format

| Date | Revision/commit | Failure | Root-cause hypothesis | Change | Retest | Evidence |
|---|---|---|---|---|---|---|
| `TBD` | `TBD` | observed behaviour | testable cause | controlled change | measured result | link |

Hardware V2 conclusions must be based on the final assembled system, not copied from Hardware V1.
