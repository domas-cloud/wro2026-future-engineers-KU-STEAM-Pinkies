# Message Protocol

## Purpose

This document describes the message boundary between the `Raspberry Pi Zero` and `ESP32`.

## Suggested Message Content

- requested behavior state;
- steering target or steering correction;
- drive enable flag;
- drive intensity or speed request;
- confidence or safety flag;
- sequence counter or heartbeat if the implementation uses one.

## Responsibilities

- the Raspberry Pi Zero computes what the robot wants to do;
- the ESP32 executes the command and applies low-level safety checks;
- the physical link is documented in the wiring overview.

## Reliability Notes

- stale messages should not be treated as new commands;
- if the command stream pauses, the ESP32 should enter a safe hold or stop behavior according to the selected policy;
- each message should be distinguishable from the previous one.

## Documentation Use

When the team adds code, this file should match the actual command fields and the startup handshake.
