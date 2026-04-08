# Unit Testing

## Purpose

Unit tests are used to verify small parts of the logic before track testing.

## Suitable Candidates

- steering conversion logic;
- filtering of sensor values;
- state-transition rules;
- command formatting between software layers.

## Specific Goals For This System

- translation of steering error into `MG90S` servo position;
- interpretation of `BNO085` calibration status;
- reading distance frames from the 2 `VL53L5CX` matrix ToF modules;
- choosing a safe state before sending drive commands.

## What Should Be Stored

- test name;
- expected result;
- actual result;
- whether the test passed;
- any note about why the case matters.

## Documentation Goal

The repository should make it clear what was tested and why those parts matter for robot reliability.
