# Hardware V2 Source Status

`[HW2-TBD]` The active Hardware V2 source tree is intentionally empty while the software is redesigned around the final Hardware V2 electronics.

The exact pre-reset source tree is preserved at:

- [`../brainstorm/software-redesign/previous-source/`](../brainstorm/software-redesign/previous-source/)

That source is engineering history. It must not be described as the final Hardware V2 runtime.

## Before new source is added here

The team should first lock or verify:

- final custom-PCB GPIO map;
- PixyCam SPI electrical connection and tested communication;
- final motor driver and control mode;
- LiPo and regulator architecture relevant to software fault handling;
- BNO085 and ToF startup sequence;
- start / stop behaviour required by the final robot.

The new active source should then be built incrementally: hardware bring-up first, navigation and obstacle logic second, and tuning only after the hardware interfaces are verified.

See [`../docs/code/README.md`](../docs/code/README.md) for the active software documentation status and [`../engineering-journal/2026-08-12-software-redesign.md`](../engineering-journal/2026-08-12-software-redesign.md) for the engineering decision behind the reset.
