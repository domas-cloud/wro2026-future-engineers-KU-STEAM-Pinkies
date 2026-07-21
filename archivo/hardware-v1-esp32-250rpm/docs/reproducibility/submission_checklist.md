# Final Submission Checklist

Use this checklist before the final WRO submission.

## Entry Path

Make sure these files are present and easy to read:

- `README.md`
- `START_HERE.md`
- `docs/README.md`
- `docs/reproducibility/evidence_map.md`
- `docs/reproducibility/full_rebuild_guide.md`
- `docs/reproducibility/mechanical_rebuild.md`
- `docs/testing/tests.md`
- `docs/testing/final_validation_results.md`

## Hardware And Rebuild Evidence

Confirm that the repository includes:

- electronics overview and wiring explanation
- at least one schematic file
- parts list
- CAD or STL files for custom parts
- mechanical rebuild notes
- as-built wiring checklist
- embedded controller README

Main files:

- `docs/hardware/electronics_overview.md`
- `docs/hardware/pcb_wiring_diagrams.md`
- `docs/hardware/as_built_wiring_checklist.md`
- `docs/hardware/parts_list.md`
- `docs/reproducibility/mechanical_rebuild.md`
- `schemes/Wro_customPCBs.pdf`
- `models/README.md`
- `src/README.md`

## Visual Submission Evidence

Confirm that these are final:

- team photo folder
- robot photo folder
- video link file

Main files:

- `t-photos/README.md`
- `v-photos/README.md`
- `video/video.md`

Checks:

1. `t-photos/` contains the single final team photo `team.jpg`
2. `v-photos/` contains front, rear, left, right, top, and bottom views
3. `video/video.md` contains the final public or accessible-by-link YouTube URL
4. the autonomous driving segment is at least 30 seconds long
5. counted final run results are filled in `docs/testing/final_validation_results.md`, or missing values are clearly left as `TBD`

## Repository Quality

Before submission, verify:

1. the repository is public
2. the README matches the final robot state
3. hardware names are consistent across the main documents
4. major links still work
5. a judge can understand where to start in less than one minute
6. the testing workflow explains how versions are validated and marked stable
7. runtime setup and calibration are documented in `docs/code/runtime_setup_and_calibration.md`

## Honest Scope Check

Before submission, verify that:

1. the repository does not claim evidence that is missing
2. measurements are only stated where they were really observed
3. diagrams, CAD, photos, and text describe the same final robot version
4. all `TBD` values in final validation tables are either replaced by real run data or left visible as missing evidence
