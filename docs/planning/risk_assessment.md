# Risk Assessment

## Main Risks

- steering play or jamming;
- sensor misalignment or blind spots;
- power instability while the motor is active;
- software delay related to the `Raspberry Pi Zero`;
- mechanical loosening after repeated runs.

## Mitigation Measures

- verify steering geometry before finalizing the chassis;
- place sensors according to track geometry and verify their coverage;
- separate motor power from sensitive electronics as much as possible;
- keep the software modular so one failure does not break the whole control loop;
- record each failure type and fix in the problem log.

## Documentation Rule

If a risk appears during development, it should be documented together with the symptom, cause, fix, and follow-up test.
