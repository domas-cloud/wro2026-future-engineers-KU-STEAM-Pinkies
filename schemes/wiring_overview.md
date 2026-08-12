# Wiring overview

```text
LiPo -> protection/switch
   |-> motor driver -> motor
   |-> servo supply -> MG90S
   |-> regulated logic -> ESP32-WROOM-32
                          |-> I2C: BNO085 + 3 ToF sensors
                          |-> SPI: PixyCam
                          |-> start button
```

Exact voltages, regulator/driver parts and GPIO numbers will be added after the battery, motor and PCB routing are final. The old V1 wiring remains available in this folder for comparison.
