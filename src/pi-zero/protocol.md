# Pi Zero To ESP32 Protocol

The perception side publishes one ASCII line per update:

```text
VISION,<mode>,<lane_shift_mm>,<obstacle_side>,<confidence>,<age_ms>
```

Example:

```text
VISION,TRACK,0,NONE,0.95,0
VISION,OBSTACLE,20,LEFT,0.91,38
```

Allowed values:

- `mode`: `TRACK` or `OBSTACLE`
- `lane_shift_mm`: signed lateral offset from the camera center, clipped to `-250..250`
- `obstacle_side`: `LEFT`, `RIGHT`, or `NONE`
- `confidence`: `0.00` to `1.00`
- `age_ms`: packet age when transmitted

The packet is deliberately small so the `ESP32` can validate it quickly and ignore stale or low-confidence guidance.
