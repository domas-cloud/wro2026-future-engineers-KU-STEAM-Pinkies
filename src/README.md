# Source code

The active Hardware V2 source has not been written yet.

The previous source tree is preserved in [`../brainstorm/software-redesign/previous-source/`](../brainstorm/software-redesign/previous-source/). It is useful development history, but it belongs to the older hardware/software assumptions and should not be treated as the program for the custom-PCB robot.

Before adding the new program here we need the final PCB GPIO map, tested PixyCam SPI connection, final motor-driver control and a repeatable startup sequence for the BNO085 and ToF sensors.

The new source will start with hardware bring-up, then normal driving/cornering, then obstacle handling and tuning from track runs. Build and upload instructions will be added here together with the code.
