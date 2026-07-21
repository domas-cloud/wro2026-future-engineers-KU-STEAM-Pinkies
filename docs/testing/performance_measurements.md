# Hardware V1 Performance Measurements

## Version status

The previous file was archived at [`archivo/hardware-v1-esp32-250rpm/docs/testing/performance_measurements.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/testing/performance_measurements.md).

All numbers on this page describe Hardware V1 or comparisons leading to Hardware V1. They are not Hardware V2 results.

## Measurement scope

The strict numeric evidence retained in the repository covers:

- drift over 3 m;
- approximate space required for a 90° turn;
- count-based clean passes on three practice layouts.

Overshoot and post-obstacle recovery were observed but were not kept as a consistent matched numeric dataset, so exact unsupported figures are not used.

## 3 m straight-drive drift

| Run | Hardware V1 final drift | Earlier robot drift |
|---:|---:|---:|
| 1 | 4 cm | 11 cm |
| 2 | 5 cm | 10 cm |
| 3 | 3 cm | 12 cm |
| 4 | 4 cm | 9 cm |
| 5 | 4 cm | 11 cm |

- Hardware V1 average: 4.0 cm;
- earlier average: 10.6 cm;
- difference: 6.6 cm, approximately 62% lower drift in this recorded set.

## Practice-layout pass counts

| Layout | Runs | Clean passes | Result |
|---|---:|---:|---:|
| open straight test | 5 | 5 | 100% |
| obstacle slalom test | 5 | 4 | 80% |
| full practice route | 5 | 4 | 80% |

## 90° turn space

| Version | Approximate measured space |
|---|---:|
| early steering layout | 46 cm |
| Hardware V1 final steering layout | 39 cm |

Approximate reduction: 7 cm, around 15%.

## Hardware V1 conclusions

- corrected steering geometry reduced load and improved repeatability;
- silicone front wheels improved grip;
- LEGO differential reduced binding;
- rigid BNO085 mounting improved heading behaviour;
- Hardware V1 used one front VL53L1X and two side VL53L4CD sensors;
- 250 rpm was retained from the tested 50/250/1000 rpm N20 options for Hardware V1.

## Hardware V2 rule

Do not reuse these values as V2 results. Hardware V2 must repeat the relevant measurements with its final LiPo, motor, driver, PCB, PixyCam and firmware. Use [`hardware_v2_validation_template.md`](hardware_v2_validation_template.md).
