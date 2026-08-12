# Risks and failures

Some of the most useful changes came from things that did not work well on the first robot. The early steering geometry overloaded the servo, low-grip front wheels wasted steering motion, the metal differential bound in corners and a loose IMU mount made heading less repeatable. Those problems are why we now test mechanics and software together instead of trying to tune around a mechanical fault.

For V2 the main risks are different because the power system, camera, PCB and motor are changing.

| Risk | What could happen | What we will check |
|---|---|---|
| wrong LiPo voltage or weak regulator margin | damaged parts or resets | lock the exact pack before final PCB review and measure every rail |
| motor stall current higher than expected | H-bridge/connector overheating | measure current safely and leave design margin |
| MG90S current spike | ESP32 reset or sensor dropout | measure rail sag while steering under load |
| motor electrical noise | SPI/I2C errors | suppression/layout checks and communication test with motor running |
| PixyCam colour confusion | wrong obstacle decision | test signatures under several lighting conditions |
| ToF startup/address conflict | missing distance reading | controlled startup and repeated full power cycles |
| wrong PCB pin map | board and software do not match | cross-check schematic, connector labels and source before testing |
| higher vehicle speed | late turns or obstacle reaction | repeat reaction-distance and track tests after the motor change |
| heat in motor driver/regulators | unstable or damaged electronics | measure temperature after repeated runs |

When a real failure happens on V2 we will add the date, robot revision, what we saw, what we changed and the retest result to [`../testing/iteration_log.md`](../testing/iteration_log.md).
