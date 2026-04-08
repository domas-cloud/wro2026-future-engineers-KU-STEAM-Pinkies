# Message Protocol

## Purpose

This document describes the message boundary between the `Raspberry Pi Zero` and the `ESP32`.

## Proposed Message Content

- requested behavior state;
- steering target or steering correction;
- drive-enable flag;
- drive strength or speed request;
- confidence or safety flag;
- sequence counter or heartbeat if the implementation uses one.

## Responsibilities

- the `Raspberry Pi Zero` calculates what the robot should attempt to do;
- the `ESP32` executes the command and applies low-level safety checks;
- the physical connection is described in the wiring overview.

## Reliability Notes

- old messages must not be treated as new commands;
- if the command stream stops, the `ESP32` must switch to a safe hold or braking mode according to the selected policy;
- each message must be clearly distinguishable from the previous one.

## Use In Documentation

When the team adds code, this file should match the real command fields and the startup handshake.
