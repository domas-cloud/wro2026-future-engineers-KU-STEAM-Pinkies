# Parts

This is the parts list for the Hardware V2 direction. Items marked **open** are still being selected and should not be used as final BOM values.

| Part | Qty | Current state | Notes |
|---|---:|---|---|
| ESP32-WROOM-32 | 1 | chosen | main controller in the custom-PCB design |
| first-generation PixyCam / CMUcam5 | 1 | chosen | colour detection, wired SPI to ESP32 |
| BNO085 | 1 | chosen | heading/yaw |
| VL53L1X | 1 | chosen | front distance |
| VL53L4CD | 2 | chosen | left/right distance |
| MG90S | 1 | chosen | steering |
| LEGO differential | 1 | kept from V1 | rear axle differential |
| custom silicone front wheels | 2 | kept from V1 | front grip |
| LiPo battery | 1 | open | exact cell count/capacity/C-rating/connector not locked |
| geared DC drive motor | 1 | open | faster than the V1 250 rpm baseline |
| H-bridge / motor driver | 1 | open | chosen after motor current is known |
| logic/power regulators | as needed | open | final values depend on LiPo and loads |
| custom PCB | 1 | in design | ESP32, power, connectors and motor-driver integration |

The old V1 BOM (Pi Zero, L298N, 2x18650 and N20 250 rpm) is kept in the archive and is not the current build list.

The final BOM will add manufacturer/part numbers, ratings, connector types and quantities after the components are physically locked.
