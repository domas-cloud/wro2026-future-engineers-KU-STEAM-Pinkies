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

## Remaining Limitations

Precise numerical performance data has not yet been collected in a complete enough form to present a full quantitative table.
Because of that, final performance at this stage is summarized from real tests and observed robot behavior on the track.

## Further Improvements

It would be useful to continue collecting results with one consistent method: steering-center deviation, repeatability across multiple runs, and obstacle-handling success rate.
That would make it possible to present clear numerical progress alongside the qualitative evaluation.
