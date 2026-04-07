# Test Log Template

## Purpose

Use this file as the standard format for recording tests in the repository.
It helps keep unit tests, track tests, and iteration notes consistent.

## Entry Format

- test id or name;
- date;
- build version;
- subsystem;
- setup;
- expected result;
- actual result;
- pass or fail;
- evidence link or photo/video reference;
- follow-up action.

## Example Entries

### Steering Center Check

- subsystem: steering;
- setup: robot on a flat surface with power on;
- expected result: `MG90S` returns to the same center point;
- actual result: fill in after the test;
- follow-up action: adjust steering trim or linkage if needed.

### Obstacle Response Check

- subsystem: perception and navigation;
- setup: lane segment with one obstacle;
- expected result: robot switches from lane follow to obstacle handling and back again safely;
- actual result: fill in after the test;
- follow-up action: tune state transitions or sensor thresholds if needed.

### Power Stability Check

- subsystem: power;
- setup: repeated starts and stops with the full robot powered;
- expected result: no brownout or reset during normal motion;
- actual result: fill in after the test;
- follow-up action: improve grounding or regulation if needed.

## How To Use

Copy this structure into the actual test notes and keep the entries short, factual, and tied to a specific robot version.
