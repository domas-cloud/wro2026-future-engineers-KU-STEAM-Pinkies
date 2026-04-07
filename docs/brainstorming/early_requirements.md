# Early Requirements

## Functional Requirements

- Follow the lane reliably.
- Detect obstacles and react without losing the path.
- Keep steering commands proportional and stable.
- Support a clear separation between camera capture on the Raspberry Pi Zero and calculations on the ESP32.

## Non-Functional Requirements

- Reproducible by another team from the repository.
- Mechanically rigid enough to survive repeated runs.
- Power distribution must be safe for the compute board, sensors, and motors.
- Software must be understandable through module names and architecture docs.

## Early Design Targets

- ESP32 handles real-time actuator control.
- Raspberry Pi Zero handles camera capture only.
- IMU and ToF sensors provide extra context beyond vision alone.
- The robot should be easy to inspect, tune, and maintain.

## Documentation Requirement

The documentation must explain why each subsystem exists and how it interacts with the others.
That is the main way we show engineering quality in the absence of raw performance metrics.
