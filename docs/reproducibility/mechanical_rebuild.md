# Mechanical Rebuild Notes

This page collects the mechanical details that can be rebuilt from the current repository without needing extra team notes.

## Rebuild Goal

Build a compact rear-wheel-drive WRO Future Engineers car with:

- front steering driven by an `MG90S` servo;
- rear drive from an `N20 6 V 250 rpm` motor;
- rear differential to reduce cornering resistance;
- low, compact chassis layout;
- printed steering and motor support parts from the `models/` folder.

## Core Mechanical References

| Need | File |
| --- | --- |
| chassis reasoning | [docs/design/chassis_design_improved.md](../design/chassis_design_improved.md) |
| drivetrain and steering reasoning | [docs/design/drivetrain_and_steering.md](../design/drivetrain_and_steering.md) |
| trade-offs and rejected options | [docs/design/engineering_decisions.md](../design/engineering_decisions.md) |
| known risks and fixes | [docs/design/risk_and_failures.md](../design/risk_and_failures.md) |
| printable mechanical parts | [models/README.md](../../models/README.md) |
| final robot views | [v-photos/README.md](../../v-photos/README.md) |

## Printable Parts

| File | Rebuild role |
| --- | --- |
| `motor-mount-block.stl` | holds the drive motor in the chassis |
| `motor-shaft-spacer.stl` | supports motor-to-drivetrain spacing |
| `steering-column-housing-short.stl` | supports the compact steering column |
| `steering-gear-cover-disc.stl` | keeps the steering gear area constrained |
| `steering-gear-hub.stl` | steering gear hub interface |
| `steering-gear-plate.stl` | steering gear mounting plate |
| `steering-linkage-bracket.stl` | linkage support for the steering mechanism |
| `steering-pin-adapter.stl` | adapter for steering pin geometry |

## Assembly Order

1. Build the chassis base and leave enough clearance for the rear differential and motor.
2. Mount the `N20 6 V 250 rpm` motor using the printed motor support pieces.
3. Install the rear differential and check that both rear wheels rotate freely.
4. Mount the front steering column and linkage using the printed steering pieces.
5. Install the `MG90S` servo and center it before attaching the steering linkage.
6. Fit the front wheels and check left/right steering symmetry.
7. Mount electronics only after the drivetrain and steering move without binding.
8. Place the `BNO085` rigidly so yaw readings do not change because of board vibration.
9. Place the front, left, and right ToF sensors so they can see the wall/obstacle direction without chassis blockage.

## Mechanical Acceptance Checks

| Check | Pass condition |
| --- | --- |
| rear drivetrain | wheels rotate without strong resistance |
| differential | inside/outside rear wheels can rotate at different speeds in a turn |
| steering center | servo returns close to the same center after left/right movement |
| steering load | servo does not buzz heavily when holding center |
| front wheel clearance | wheels do not rub chassis at maximum steering angle |
| sensor line of sight | ToF sensors are not blocked by wires or chassis parts |
| IMU mounting | board is rigid and does not move when the robot accelerates |

## Missing Data Not Invented Here

This page does not invent exact measurements that were not present in the repository. For a perfect rebuild record, add measured values for:

- wheelbase;
- front and rear track width;
- ground clearance;
- steering linkage length;
- servo horn angle at center;
- motor mount screw spacing;
- exact sensor height from the floor.

