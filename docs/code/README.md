# Software

The Hardware V2 program is being rewritten.

On 12 August we moved the previous source and software notes out of the active folders because they still assumed the Raspberry Pi/UART setup from the first robot. The old material is in [`../../brainstorm/software-redesign/`](../../brainstorm/software-redesign/) and the reason for the reset is recorded in [`../../engineering-journal/2026-08-12-software-redesign.md`](../../engineering-journal/2026-08-12-software-redesign.md).

The new program will be written against the final V2 hardware: ESP32-WROOM-32, PixyCam over SPI, BNO085, front VL53L1X, two VL53L4CD sensors, MG90S and the custom-PCB motor driver.

We will first make a small bring-up program that proves every sensor/actuator and the PCB pin map. Driving states, obstacle logic and tuning come after that. `src/` will contain the active code once it reaches that point.

Until then, this folder intentionally does not describe a final state machine, gains, obstacle thresholds or parking logic.
