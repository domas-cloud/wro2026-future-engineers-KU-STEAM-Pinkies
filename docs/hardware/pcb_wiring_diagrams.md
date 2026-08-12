# PCB and wiring

The current wiring direction is shown below. Exact GPIO numbers and regulator/driver parts will be added after the schematic is locked.

```text
LiPo
  |
  +-- protection / power switch
  |
  +-- motor driver --> drive motor
  +-- servo rail ----> MG90S
  +-- logic rails ---> ESP32-WROOM-32
                       |-- I2C --> BNO085
                       |          VL53L1X front
                       |          VL53L4CD left/right
                       |-- SPI --> PixyCam
                       |-- input -> start button
```

The three ToF sensors need a documented startup/address scheme so identical devices do not collide on I2C. The PixyCam connector also needs clear pin-1 orientation and verified logic levels.

The final page will include the real connector names, GPIO map, rail voltages and schematic links. Until then, [`schemes/`](../../schemes/) contains the V1 drawings and the work-in-progress description for V2.
