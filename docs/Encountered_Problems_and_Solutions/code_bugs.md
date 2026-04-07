# Code Bugs

## What To Log

- logic errors;
- wrong state transitions;
- communication problems between ESP32 and Pi Zero;
- unsafe fallback behavior;
- performance bottlenecks.

## Build-Specific Examples

- serial message parsing errors between `ESP32` and `Raspberry Pi Zero`;
- state machine not returning to lane follow after obstacle handling;
- stale sensor values being reused after a camera pause.

## Fix Log Format

Each bug should show the failing behavior, the root cause, the patch, and the verification step.
