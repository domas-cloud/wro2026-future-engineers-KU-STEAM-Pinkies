# Reproducibility Checklist

## Purpose

Use this checklist to verify that another team could rebuild the robot from the repository.

## Checklist

- the main robot concept is explained in the brainstorming docs;
- the hardware stack is named with real component models;
- the wiring and power path are described in text and diagrams;
- the software architecture explains what runs on the `ESP32` and what runs on the `Raspberry Pi Zero`;
- the sensor placement is explained in relation to the chassis and the field;
- the CAD files are linked and match the written description;
- the repository contains team photos, vehicle photos, and a video reference;
- the test logs show how the robot was checked and adjusted over time;
- the problems log explains what failed and how it was fixed.

## Evidence To Check

- `README.md`;
- `docs/`;
- `schemes/`;
- `models/`;
- `t-photos/`;
- `v-photos/`;
- `video/`;
- `src/`.

## Acceptance Rule

If any major subsystem cannot be identified from the repository, the reproducibility score drops because the build is no longer easy to reconstruct.
