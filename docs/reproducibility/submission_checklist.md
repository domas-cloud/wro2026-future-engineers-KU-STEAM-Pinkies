# Final Submission Checklist

This page is a final repository-quality checklist for WRO submission.

Its purpose is to reduce ambiguity and help us confirm that the repository is not only complete, but also easy for judges to evaluate.

## Repository Entry Path

Confirm that these files are present and readable:

- `README.md`
- `START_HERE.md`
- `docs/README.md`
- `docs/reproducibility/evidence_map.md`

## Hardware And Rebuild Evidence

Confirm that the repository includes:

- electronics overview and wiring explanation
- at least one schematic file
- parts list
- CAD or STL evidence for custom parts
- embedded controller project README

Main files:

- `docs/hardware/electronics_overview.md`
- `docs/hardware/pcb_wiring_diagrams.md`
- `docs/hardware/parts_list.md`
- `schemes/Wro_customPCBs.pdf`
- `models/README.md`
- `src/README.md`

## Visual Submission Evidence

Confirm that these are present and final:

- team photo folder
- robot photo folder
- final video link file

Main files:

- `t-photos/README.md`
- `v-photos/README.md`
- `video/video.md`

Rules-based final evidence check:

1. `t-photos/` contains at least one clear final team photo
2. `v-photos/` contains robot photos from front, rear, left, right, top, and bottom
3. `video/video.md` contains the final public or accessible-by-link YouTube URL
4. the autonomous driving part shown in video is at least 30 seconds long
5. if separate challenge videos are required by the event, both links are clearly provided

## GitHub Timing And History Check

Before final submission, verify:

1. the repository is public
2. the repository will remain public for at least 12 months after the event
3. the commit history includes the required milestone commits before the competition
4. the important commits have meaningful messages, not only generic placeholders
5. the README reflects the actual final robot state at the evaluation deadline

## Judge-Facing Quality Check

Before final submission, verify:

1. a judge can understand where to start in less than one minute
2. a judge can find files for each rubric criterion without searching blindly
3. final hardware names are consistent across the main documentation
4. older files do not look like the primary submission path
5. links between major files still work

## Honest Scope Check

Before final submission, verify that:

1. the repository does not claim evidence that is missing
2. measured values are only stated where we really observed them
3. diagrams, CAD, and text describe the same final robot version

## Final Goal

If this checklist can be answered with yes, the repository is much closer to a strong `Criterion 5` score because it becomes easier to navigate, easier to trust, and easier to reproduce.
