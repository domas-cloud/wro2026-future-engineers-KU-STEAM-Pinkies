# Mechanical And Software Testing

## Version status

The previous text was archived at [`archivo/hardware-v1-esp32-250rpm/docs/testing/mechanical_and_software_testing.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/testing/mechanical_and_software_testing.md).

This page separates strict Hardware V1 evidence from Hardware V2 tests that are still pending.

## Hardware V1 comparisons

The documented V1 motor options were:

- `50 rpm` N20;
- `250 rpm` N20;
- `1000 rpm` N20.

The `250 rpm` motor was retained for Hardware V1. Earlier text that referred to a `300 rpm` alternative was inconsistent and is preserved only in the archived snapshot.

Other V1 comparisons included:

- steering versions V1, V2 and V3;
- earlier front wheels versus silicone front wheels;
- metal versus LEGO differential;
- sensor mounting and controller tuning.

## Strict Hardware V1 quantitative source

Use [`performance_measurements.md`](performance_measurements.md) as the source of numeric V1 evidence.

| Metric | Earlier version | Hardware V1 result |
|---|---:|---:|
| average drift over `3 m` | `10.6 cm` | `4.0 cm` |
| approximate `90°` turn space | `46 cm` | `39 cm` |
| open straight clean passes | not kept as a matched earlier set | `5/5` |
| obstacle slalom clean passes | not kept as a matched earlier set | `4/5` |
| full practice route completions | not kept as a matched earlier set | `4/5` |

Older text claimed separate `2 m` drift, overshoot, recovery-time and `6/10 → 9/10` datasets. Those figures are not used here because the stricter measurement document says they were not logged as one consistent matched dataset.

## Hardware V1 qualitative conclusions

- corrected steering geometry reduced mechanical load;
- silicone wheels improved useful front grip;
- LEGO differential reduced binding;
- rigid sensor mounting improved consistency;
- software tuning worked better after the mechanics became more repeatable.

## Hardware V2 testing required

Hardware V2 changes camera, communication, battery, motor, motor driver and PCB integration. V1 results cannot be copied as V2 results.

Required V2 tests include:

1. motor free-run, loaded, launch and stall current;
2. 3 m speed and drift comparison;
3. turn-space and overshoot at the selected speed;
4. MG90S current and steering stability;
5. LiPo and regulator voltage under transient load;
6. motor-driver temperature;
7. ten full sensor/camera startup cycles;
8. Pixy red/green detection under several positions and lighting conditions;
9. SPI stability with motor and servo active;
10. repeated Open and Obstacle Challenge runs.

Use [`hardware_v2_validation_template.md`](hardware_v2_validation_template.md) and tie each test to a commit and physical revision.
