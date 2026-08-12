# Hardware V2 test sheet

We will fill this page with the real rebuilt car. Empty fields mean the test has not been done yet.

## Build used for the test

- PCB revision:
- source commit:
- LiPo:
- motor:
- motor driver:
- robot mass:
- date:

## Power and startup

Record idle current, normal driving current and the highest observed transient. Measure logic rails while the motor starts and servo moves. Also record motor-driver and regulator temperature after repeated runs.

Run at least ten full power cycles and note whether the ESP32, BNO085, all three ToF sensors and PixyCam start correctly each time.

## PixyCam

Test red and green pillars at useful approach distances. Include bright, dark and side-lit conditions. Note false detections, missed detections and whether SPI stays stable while motor/servo are active.

## Motor comparison

For each serious motor candidate record loaded speed (or 3 m time), launch/current behaviour, temperature, straight drift, corner behaviour and repeated-run success. The final choice should be the fastest one we can still control reliably, not simply the highest rpm.

## Track runs

### Open Challenge

| Run | Complete? | Time | Notes |
|---:|---|---|---|
| 1 |  |  |  |
| 2 |  |  |  |
| 3 |  |  |  |
| 4 |  |  |  |
| 5 |  |  |  |
| 6 |  |  |  |
| 7 |  |  |  |
| 8 |  |  |  |
| 9 |  |  |  |
| 10 |  |  |  |

### Obstacle Challenge

| Run | Complete? | Time | Notes |
|---:|---|---|---|
| 1 |  |  |  |
| 2 |  |  |  |
| 3 |  |  |  |
| 4 |  |  |  |
| 5 |  |  |  |
| 6 |  |  |  |
| 7 |  |  |  |
| 8 |  |  |  |
| 9 |  |  |  |
| 10 |  |  |  |

Any failure that changes the design or tuning should also be added to [`iteration_log.md`](iteration_log.md).
