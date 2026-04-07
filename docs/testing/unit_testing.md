# Unit Testing

## Purpose

Unit tests are used to check small logic pieces before field testing.

## Good Candidates

- steering conversion logic;
- sensor value filtering;
- state transition rules;
- command formatting between software layers.

## Build-Specific Unit Targets

- conversion from steering error to `MG90S` servo position;
- interpretation of `BNO085` calibration status;
- parsing of `VL53L5CX` distance frames;
- safety-state selection before drive commands are emitted.

## Evidence To Keep

- test name;
- expected outcome;
- actual outcome;
- whether the test passed;
- any note about why the case matters.

## Documentation Goal

The repo should say what was tested and why those parts matter to the robot's reliability.
