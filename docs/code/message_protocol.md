# Message Protocol

## Purpose

This document describes the message boundary between the `Raspberry Pi Zero` and `ESP32`.
The protocol should be simple enough to debug, but structured enough to prevent ambiguous commands.

## Suggested Message Content

- requested behavior state;
- steering target or steering correction;
- drive enable flag;
- drive intensity or speed request;
- confidence or safety flag;
- optional heartbeat or sequence counter.

## Responsibilities

- the Raspberry Pi Zero computes what the robot wants to do;
- the ESP32 executes the command and applies low-level safety checks;
- both sides should tolerate a short communication pause without creating unsafe motion.

## Reliability Notes

- a message should be clearly identifiable from the previous one;
- stale messages should not be treated as new commands;
- if the command stream pauses, the ESP32 should enter a safe hold or stop behavior according to the selected policy;
- the exact transport can be serial, but the content and purpose should remain stable.

## Documentation Use

When the team adds code, this file should match the actual command fields and the actual startup handshake.
