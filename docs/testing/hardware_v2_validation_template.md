# Hardware V2 Validation Template

Use this page during the Hardware V2 build. Replace `TBD` only with real measurements or observed results.

## Build identification

| Field | Value |
|---|---|
| date | `TBD` |
| Git commit | `TBD` |
| PCB revision | `TBD` |
| ESP32 implementation | `TBD` |
| PixyCam revision / photo reference | `TBD` |
| motor model | `TBD` |
| motor driver | `TBD` |
| LiPo specification | `TBD` |
| robot mass | `TBD` |
| robot dimensions | `TBD` |

## Power validation

| Condition | Battery voltage | 5 V / servo rail | 3.3 V / logic rail | Total current | Notes |
|---|---:|---:|---:|---:|---|
| power on, idle | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| sensors active | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| PixyCam detecting | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| steering sweep | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| motor launch | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| motor + steering transient | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| repeated full run | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |

## Thermal validation

Record ambient temperature and the measurement method.

| Component | Start temperature | After test | Test duration / load | Pass condition | Result |
|---|---:|---:|---|---|---|
| motor driver | `TBD` | `TBD` | `TBD` | no thermal shutdown or unsafe heating | `TBD` |
| motor | `TBD` | `TBD` | `TBD` | stable operation and no mechanical damage | `TBD` |
| main regulator | `TBD` | `TBD` | `TBD` | voltage remains inside required range | `TBD` |
| servo regulator / rail | `TBD` | `TBD` | `TBD` | no reset or excessive heating | `TBD` |

## Sensor startup reliability

Repeat at least ten cold or full power-cycle starts.

| Start number | VL53L1X | Left VL53L4CD | Right VL53L4CD | BNO085 | PixyCam SPI | Notes |
|---:|---|---|---|---|---|---|
| 1 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 2 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 3 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 4 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 5 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 6 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 7 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 8 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 9 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 10 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |

## PixyCam detection validation

| Scenario | Distance / position | Lighting | Expected signature | Detected result | Stable decision distance | Notes |
|---|---|---|---|---|---:|---|
| red pillar, centre | `TBD` | `TBD` | red | `TBD` | `TBD` | `TBD` |
| red pillar, left | `TBD` | `TBD` | red | `TBD` | `TBD` | `TBD` |
| red pillar, right | `TBD` | `TBD` | red | `TBD` | `TBD` | `TBD` |
| green pillar, centre | `TBD` | `TBD` | green | `TBD` | `TBD` | `TBD` |
| green pillar, left | `TBD` | `TBD` | green | `TBD` | `TBD` | `TBD` |
| green pillar, right | `TBD` | `TBD` | green | `TBD` | `TBD` | `TBD` |
| both colours visible | `TBD` | `TBD` | strategy-dependent | `TBD` | `TBD` | `TBD` |
| no pillar | `TBD` | `TBD` | no valid block | `TBD` | `TBD` | `TBD` |
| motor at high PWM | `TBD` | `TBD` | unchanged detection | `TBD` | `TBD` | `TBD` |

## Motor candidate comparison

| Candidate | Voltage | Rated / no-load rpm | Wheel diameter | Loaded 3 m time | Launch peak current | Stall current | Driver temperature | 3-lap completion rate | Decision |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| Hardware V1 250 rpm baseline | `6 V` | `250 rpm` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | baseline |
| candidate A | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| candidate B | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| candidate C | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |

## Open Challenge final runs

| Run | Date | Commit | Battery state | Time | Wall contacts | Completed 3 laps | Parking result | Notes |
|---:|---|---|---|---:|---:|---|---|---|
| 1 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 2 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 3 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 4 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 5 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 6 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 7 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 8 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 9 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 10 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |

## Obstacle Challenge final runs

| Run | Date | Commit | Layout | Red decisions | Green decisions | Pillars moved | Completed 3 laps | Parking result | Notes |
|---:|---|---|---|---:|---:|---:|---|---|---|
| 1 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 2 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 3 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 4 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 5 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 6 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 7 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 8 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 9 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |
| 10 | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |

## Failure and iteration log

| Date | Version / commit | Failure observed | Root-cause hypothesis | Change made | Retest result | Evidence link |
|---|---|---|---|---|---|---|
| `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` | `TBD` |

## Honesty rule

Do not replace `TBD` with estimates presented as measurements. Calculated values must be labelled as calculations, and measured values must state the method and conditions.
