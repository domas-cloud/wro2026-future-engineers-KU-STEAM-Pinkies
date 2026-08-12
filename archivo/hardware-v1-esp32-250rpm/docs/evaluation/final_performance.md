# Final Performance

The final robot version was optimized not for maximum speed, but for more stable and repeatable track driving.
The main improvements came from reducing mechanical steering load, keeping the differential, and separating sensor roles more clearly.

## Steering Behavior

After the geometry corrections, the steering system behaved more consistently than in earlier tests.
Servo load decreased because the large wheel lever-arm problem was removed, and front-wheel motion remained more symmetric.

## Turning And Traction

The rear-axle differential improved the robot's behavior in turns.
Compared with the earlier robot without a differential, turning resistance was reduced, so the robot cornered more smoothly and slipped less.

## Sensor Performance

The camera remained the main source of overall track information, while the distance sensors were used for short-range confirmation.
The `BNO085` added heading and motion-stability information, especially after several consecutive turns.
This distribution of sensor roles reduced the impact of any single-sensor error on the full decision cycle.

## Quantitative Summary

| Test layout | Runs | Successful runs | Robot version | Notes |
| --- | --- | --- | --- | --- |
| 3 m straight stability check | `5` | `5` | final steering geometry + `250 rpm` motor | drift stayed within `3-5 cm` |
| obstacle practice route | `5` | `4` | final geometry + 3 ToF sensors + IMU | one late correction on a pillar approach |
| full practice loop | `5` | `4` | final repository-state robot | one run ended with corner-exit misalignment |

## Remaining Limitations

The robot is repeatable enough to summarize with counted runs, but it is still not a laboratory dataset.
The tables above are the compact measurements we kept because they influenced design decisions directly.

## Further Improvements

It would be useful to continue collecting results with one consistent method: steering-center deviation, repeatability across multiple runs, and obstacle-handling success rate.
That would make it possible to present clear numerical progress alongside the qualitative evaluation.
