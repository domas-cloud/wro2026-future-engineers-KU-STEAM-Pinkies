# Control Algorithms

## Version status

The previous Hardware V1 description was archived at [`archivo/hardware-v1-esp32-250rpm/docs/code/control_algorithms.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/code/control_algorithms.md).

The current published controller uses heading and side-distance correction, but Hardware V2 values and camera integration are not final.

## Hardware V1 low-level concept

The steering command combines:

```text
heading correction
+ side-distance correction
+ damping / derivative term
```

The controller also uses front distance and sector information to enter a hard-turn routine.

## Hardware V2 retained concept

PixyCam should choose or bias the required obstacle path, while the ESP32 retains real-time heading, local-distance and actuator control. The camera should not directly command the servo.

## Code/documentation items to resolve

- verify derivative/error-history calculation;
- publish the real dynamic corner-trigger expression or replace it with a tested alternative;
- define the final finish and steering-centre behaviour;
- define sensor-invalid and camera-fault handling;
- make sensor type explicit rather than dependent on a GPIO number;
- retune gains for the final motor, mass, battery and steering response;
- publish units and limits for every control parameter.

## Required final algorithm evidence

- equations or pseudocode matching source code;
- parameter table with units;
- tuning method;
- before/after or candidate comparison;
- overshoot/drift/turn-space measurements;
- camera-decision timing at final speed;
- failure and fallback tests.
