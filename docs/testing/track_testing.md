# Track Testing

## Version status

The previous Hardware V1 track-testing narrative was archived at [`archivo/hardware-v1-esp32-250rpm/docs/testing/track_testing.md`](../../../archivo/hardware-v1-esp32-250rpm/docs/testing/track_testing.md).

Current measured results in `performance_measurements.md` describe Hardware V1. Hardware V2 has not yet completed final track validation.

## Hardware V1 purposes

Track tests were used to compare:

- straight drift and heading stability;
- corner entry and exit;
- steering centring and mechanical binding;
- obstacle-section recovery;
- repeated route completion;
- effect of sensor mounting and tuning.

## Hardware V2 controlled-test requirements

For each comparison record:

- date and commit;
- PCB and mechanical revision;
- exact motor, driver and LiPo;
- PixyCam settings;
- field layout and direction;
- surface and lighting notes;
- unchanged tuning across the comparison block;
- run count, pass count and failure reason.

## Open Challenge metrics

- three-lap completion;
- time;
- wall contacts;
- straight drift;
- turn-space/overshoot;
- parking result;
- repeatability across at least five, preferably ten, final runs.

## Obstacle Challenge metrics

- correct red decisions;
- correct green decisions;
- pillars moved;
- late detections;
- alignment after obstacle;
- three-lap completion;
- parking result;
- repeated-run success rate.

## Acceptance rule

A Hardware V2 version becomes stable only when it improves the target problem without introducing a repeated failure elsewhere. One best run is not sufficient.
