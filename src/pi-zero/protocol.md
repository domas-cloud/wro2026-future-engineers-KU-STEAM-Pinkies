# Pi Zero To ESP32 Protocol

The perception side publishes one ASCII line per update:

```text
VISION,<mode>,<lane_shift_mm>,<obstacle_side>,<confidence>,<age_ms>
```

Example:

```text
VISION,OBSTACLE,20,LEFT,0.91,38
```

The packet is deliberately small so the `ESP32` can validate it quickly and ignore stale or low-confidence guidance.
