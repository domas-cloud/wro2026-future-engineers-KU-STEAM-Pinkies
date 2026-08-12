# V2 custom PCB

The new board replaces the V1 development-board/perfboard wiring. It is built around an ESP32-WROOM-32 and will connect the PixyCam over SPI, BNO085 and three ToF sensors, MG90S servo, start button and the final H-bridge/motor.

We have not published final production files yet because the exact LiPo, motor, H-bridge, regulators and GPIO map are still being locked. Those values affect the power tree, copper/current margin and connector layout.

The finished package will include schematic/PCB source, PDF schematic, Gerbers/drill files, BOM/assembly notes, board dimensions/mounting holes, connector pinout and photos of the assembled board. First-power-up notes will record any mistake or revision rather than hiding it.

The current `Wro_customPCBs.pdf` should be read as older V1 evidence, not as the final V2 board.
