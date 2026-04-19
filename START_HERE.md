# Start Here

This file is the main entry point to our documentation.

We created several improved documentation files during the season, and this file shows which ones should be treated as the main reading order for judges and other teams.

## Our Team

We are **KU STEAM Pinkies**, participating in **WRO 2026 Future Engineers**.

### Main roles in our team

- **Marius** - software development and mechanical design
- **Domas** - project coordination, testing, and documentation
- **Jonas** - electronics and hardware design

Even though each of us had a main responsibility area, we discussed the most important design decisions together and tested the robot as one system.

## Recommended Reading Order

If you want to understand our robot quickly, we recommend reading the documentation in this order:

### 1. Main overview

- `README.md`
- `docs/design/system_overview.md`
- `docs/reproducibility/evidence_map.md`
- `docs/reproducibility/submission_checklist.md`

### 2. Mechanical design

- `docs/design/chassis_design_improved.md`
- `docs/design/drivetrain_and_steering.md`
- `docs/design/engineering_decisions.md`
- `docs/design/risk_and_failures.md`

### 3. Electronics

- `docs/hardware/electronics_overview.md`
- `docs/hardware/pcb_wiring_diagrams.md`
- `schemes/Wro_customPCBs.pdf`

### 4. Testing

- `docs/testing/mechanical_and_software_testing.md`
- `docs/testing/track_testing.md`

### 5. Software

- `docs/code/software_architecture_improved.md`
- `docs/code/navigation_strategy_improved.md`

## Fast Judge Path

If a judge has only a few minutes, these are the most useful files:

1. `README.md`
2. `docs/reproducibility/evidence_map.md`
3. `docs/design/drivetrain_and_steering.md`
4. `docs/hardware/electronics_overview.md`
5. `docs/design/engineering_decisions.md`
6. `docs/testing/mechanical_and_software_testing.md`

## Reproducibility Path

For another team, the shortest rebuild-oriented reading path is:

1. `README.md`
2. `docs/reproducibility/evidence_map.md`
3. `docs/reproducibility/submission_checklist.md`
4. `docs/hardware/parts_list.md`
5. `docs/hardware/pcb_wiring_diagrams.md`
6. `docs/design/drivetrain_and_steering.md`
7. `models/README.md`

## Note For Judges

The main files above are written as judge-facing explanations. More detailed implementation files still exist in the repository for completeness, but they are not required for understanding the main engineering decisions.

## Why We Added This File

Some older files in the repository reflect earlier documentation stages. We kept them because they are part of our work history, but the files listed above are the ones that best describe our final engineering reasoning more clearly.

## Our Documentation Style

In our final documentation, we try to explain:

- what we built,
- why we built it this way,
- what we tested,
- what failed,
- and why the final version was selected.

Our goal is not only to show the final robot, but to show our engineering process.
