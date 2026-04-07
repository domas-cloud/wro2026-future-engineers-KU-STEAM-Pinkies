# Risk Assessment

## Main Risks

- Steering backlash or binding.
- Sensor misalignment or blind spots.
- Power instability under motor load.
- Software latency on the Raspberry Pi Zero.
- Mechanical loosening after repeated runs.

## Mitigation

- Test the steering geometry before finalizing the chassis.
- Place sensors according to field geometry and verify coverage.
- Separate motor power from sensitive electronics where possible.
- Keep software modular so one failure does not collapse the whole control loop.
- Record every failure mode and fix in the problem log.

## Documentation Rule

If a risk appears during development, it should be documented with the symptom, cause, fix, and follow-up test.
