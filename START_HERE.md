# Start here

This branch follows the Hardware V2 rebuild of our WRO 2026 Future Engineers car.

If you only want the current robot story, read [`README.md`](README.md) first. For technical detail use [`docs/README.md`](docs/README.md).

## Current robot direction

We are keeping the mechanical ideas that worked on the first robot, but changing most of the electronics:

- ESP32-WROOM-32 as the main controller;
- first-generation PixyCam connected by SPI;
- BNO085 IMU;
- one front VL53L1X and two side VL53L4CD sensors;
- MG90S steering servo;
- LiPo power;
- a faster drive motor;
- a custom PCB instead of the development-board/perfboard wiring.

The exact LiPo, motor, H-bridge, regulators and final PCB pin map are not locked yet. We leave those details open instead of guessing them.

## Old robot and software

The previous working robot is kept in [`archivo/hardware-v1-esp32-250rpm/`](archivo/hardware-v1-esp32-250rpm/). Its measurements, photos and code are useful because they show what led to V2.

The old software and the first V2 software ideas are in [`brainstorm/software-redesign/`](brainstorm/software-redesign/). `src/` is reserved for the new program after it matches the rebuilt hardware.

## Useful links

- [`docs/design/engineering_decisions.md`](docs/design/engineering_decisions.md) — why we changed parts
- [`docs/hardware/electronics_overview.md`](docs/hardware/electronics_overview.md) — current electronics
- [`docs/hardware/parts_list.md`](docs/hardware/parts_list.md) — parts we know and parts still being selected
- [`docs/testing/performance_measurements.md`](docs/testing/performance_measurements.md) — measurements from the working V1 robot
- [`docs/testing/hardware_v2_validation_template.md`](docs/testing/hardware_v2_validation_template.md) — tests we will run on V2
- [`models/`](models/) — mechanical files
- [`schemes/`](schemes/) — wiring and PCB material
- [`engineering-journal/`](engineering-journal/) — dated development notes

The short work list for the next build session is in [`NEXT_REVIEW.md`](NEXT_REVIEW.md).
