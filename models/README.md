# CAD Models

This folder stores exported models for the steering mechanism and related parts.

## What Is Stored Here

This folder contains the exported STL files and related fabrication assets used to document the custom parts of the robot.

The exact file set may evolve during development, but the purpose stays the same:

- steering-related geometry;
- supporting structural parts;
- fabrication evidence for reproducibility.

## Purpose

These files support the steering-system documentation and the reproducibility checklist.
If the geometry changes, update the related design documents as well so the text and models stay aligned.

## Model Index

| File | Description |
| --- | --- |
| `steering-column-housing-short.stl` | Steering column housing. |
| `steering-gear-cover-disc.stl` | Cover disc for the steering gear. |
| `steering-gear-hub.stl` | Main steering gear hub. |
| `steering-gear-plate.stl` | Thin steering gear plate. |
| `steering-linkage-bracket.stl` | Steering linkage bracket. |
| `motor-mount-block.stl` | Motor mount block. |
| `steering-pin-adapter.stl` | Small steering pin adapter. |
| `motor-shaft-spacer.stl` | Motor shaft spacer. |

## Rebuild Notes

For another team, these files are not standalone instructions. They should be used together with:

- [docs/design/drivetrain_and_steering.md](../docs/design/drivetrain_and_steering.md)
- [docs/design/chassis_design_improved.md](../docs/design/chassis_design_improved.md)
- [docs/reproducibility/evidence_map.md](../docs/reproducibility/evidence_map.md)

The STL files are evidence of the steering-part geometry, while the design documents explain why those parts exist and how they fit the final steering concept.
