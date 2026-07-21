# Final Submission Checklist

## Version rule

The previous checklist was archived at [`archivo/hardware-v1-esp32-250rpm/docs/reproducibility/submission_checklist.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/reproducibility/submission_checklist.md).

Run this checklist against **Hardware V2**, not against mixed Hardware V1 and V2 files.

## Entry and navigation

- [ ] README is at least 5000 characters and states the exact robot version;
- [ ] START_HERE gives a one-minute reading path;
- [ ] evidence map separates verified evidence from missing evidence;
- [ ] no active page calls Hardware V1 electronics the final Hardware V2 design;
- [ ] all important links work.

## Mechanical evidence

- [ ] final dimensions and mass;
- [ ] wheelbase, track widths, wheel diameter and clearance;
- [ ] exact motor and drivetrain data;
- [ ] motor speed/torque/current reasoning;
- [ ] steering geometry and limits;
- [ ] final CAD/STL/source files;
- [ ] iteration and failure evidence;
- [ ] final mechanical photos.

## Electronics and PCB evidence

- [ ] exact LiPo and safety information;
- [ ] complete power/current budget;
- [ ] schematic and editable source;
- [ ] PCB source, Gerbers and drills;
- [ ] BOM;
- [ ] connector and pin map;
- [ ] assembled PCB photos;
- [ ] measured voltage/current/temperature;
- [ ] ten-start sensor and communication test;
- [ ] as-built wiring checklist completed.

## Software evidence

- [ ] final Hardware V2 source code;
- [ ] PixyCam SPI implementation;
- [ ] exact board/build environment;
- [ ] code comments explain important logic;
- [ ] state diagram matches source;
- [ ] red/green decisions documented;
- [ ] stale/ambiguous/camera-fault handling documented;
- [ ] upload and calibration procedure tested.

## Testing evidence

- [ ] final motor comparison;
- [ ] power and thermal results;
- [ ] PixyCam detection matrix;
- [ ] Open Challenge repeated runs;
- [ ] Obstacle Challenge repeated runs;
- [ ] failures linked to corrections and retests;
- [ ] final results tied to a commit and physical revision.

## Media

- [ ] team photo;
- [ ] final Hardware V2 front/back/left/right/top/bottom photos;
- [ ] final Open Challenge video;
- [ ] final Obstacle Challenge video;
- [ ] links are public or accessible by link;
- [ ] video runtime and autonomous segment satisfy the rules.

## Honesty check

- [ ] every number is measured or clearly labelled as calculated;
- [ ] no `TBD` is hidden by an estimate;
- [ ] Hardware V1 evidence is labelled historical;
- [ ] diagrams, code, BOM, photos and text describe the same final robot;
- [ ] another person can rebuild without undocumented team knowledge.
