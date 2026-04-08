# Code Bugs

## What To Record

- logic errors;
- incorrect state transitions;
- communication problems between the `ESP32` and Pi Zero;
- unsafe fallback behavior;
- performance bottlenecks.

## Specific Examples

- serial-message parsing errors between the `ESP32` and `Raspberry Pi Zero`;
- the state machine fails to return to lane following after obstacle handling;
- stale sensor data is reused after a camera pause.

## Fix Log Format

Each bug entry should show the failing behavior, the cause, the fix, and the verification step.
