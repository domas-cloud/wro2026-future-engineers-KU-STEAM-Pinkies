# Vision Interface

This document defines the perception-to-controller interface used between the `Raspberry Pi Zero` and the `ESP32`.

## Physical Link

| Item | Value |
| --- | --- |
| transport | UART |
| logic level | `3.3 V` TTL |
| baud rate | `115200` |
| Pi TX -> ESP32 RX | `GPIO14` -> `GPIO16` |
| Pi RX <- ESP32 TX | `GPIO15` <- `GPIO17` |
| update rate target | `10 Hz` |

## Packet Format

Each packet is one ASCII line:

```text
VISION,<mode>,<lane_shift_mm>,<obstacle_side>,<confidence>,<age_ms>
```

Example:

```text
VISION,TRACK,-35,RIGHT,0.82,45
```

## Field Meaning

| Field | Meaning |
| --- | --- |
| `mode` | `TRACK`, `OBSTACLE`, or `NEUTRAL` |
| `lane_shift_mm` | desired lateral reference shift relative to center |
| `obstacle_side` | `LEFT`, `RIGHT`, or `NONE` |
| `confidence` | `0.00` to `1.00` confidence estimate |
| `age_ms` | age of the perception result when sent |

## Timeout Behavior

- if no fresh packet arrives within `250 ms`, the controller falls back to neutral guidance;
- if confidence drops below `0.40`, the packet should be treated as advisory only;
- stale camera data must never override the local IMU and distance-sensor safeguards.

## Why The Interface Is Small

The `ESP32` does not need image data. It only needs a compact, time-bounded driving reference. That keeps the low-level controller deterministic while still allowing higher-level perception decisions.
