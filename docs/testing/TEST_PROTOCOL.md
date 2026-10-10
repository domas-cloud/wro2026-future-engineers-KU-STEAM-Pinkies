# WRO 2026: repeatable test and evidence protocol

This document defines how to capture **new physical tests** for the KU STEAM Pinkies robot. It is a procedure, **not a record of tests already performed**. Do not backfill empty rows using predicted or estimated values.

## Traceability for every run

Before changing firmware or tuning, save the full Git commit SHA and select the correct PlatformIO environment:
- `platformio run -d src -e open_challenge`
- `platformio run -d src -e obstacle_challenge`

Use a copy of `docs/testing/raw/run-template.csv` for each physical test series. Record the date/time, firmware SHA, mode, direction and track layout, battery voltage/state if measured, parameter intentionally changed, outcome, elapsed time, observed errors and any reset or repair. Enter `not measured` when an instrument or reliable visual measurement is unavailable rather than inventing a precision value.

The test layout should record the corridor widths (for Open Challenge), start zone, direction and the positions and signatures of relevant coloured pillars (for Obstacle Challenge). A top-view photo or sketch labelled with the run ID is useful.

## Protocol A: steering and corner tuning

1. Record the deployed values of `Kp`, `Kg`, `Kd`, turn thresholds and 60°/120° steering limits.
2. Check the servo centre and both mechanical end positions with the drive motor disabled.
3. Drive a known straight segment. If measuring drift, identify the reference line, the distance travelled (2 m or 3 m), and the lateral offset at the endpoint in cm.
4. Test clockwise and counter-clockwise 90° corners with identical layout and start speed.
5. For each attempt, note whether the front ToF initiated a turn, whether it exited the turn condition, any wall contact, and any visibly excessive correction.
6. Change only one gain or threshold at a time, keeping a record of the old and new values and of the same test layout. Do not describe an improvement quantitatively unless matched measurements were retained.

## Protocol B: Pixy2 signatures and obstacle passing

The team uses signature **1 = green** and signature **2 = red**. WRO 2026 requires green to be passed on the left and red on the right.

1. In PixyMon verify each of the two trained colour signatures under the lighting used for the test.
2. Place the green and red pillar in turn at known track positions. Record each detected signature and whether the physical pass is on the required side.
3. Repeat from the two track directions where the layout permits.
4. Vary one parameter per series: target image offsets (`-105` for signature 1 and `55` for the other-signature fallback), block-height filter, steering gain (`0.32`) or recovery period (`450 ms`).
5. Note mistaken signatures, missed detections, contacts, side errors and recovery behaviour. A video link and timestamp should be attached for decisive cases.
6. When a detection is not signature 1 or 2, record the event; the current source code uses its fallback offset rather than rejecting it.

## Protocol C: three-lap run and final stopping

1. Record the firmware SHA, track layout and start configuration.
2. Attempt three full laps without touching or adjusting the vehicle after the authorised start.
3. Record laps and counted corners, final stopping behaviour, wall/pillar contacts and whether intervention was required.
4. **Current status:** autonomous parallel parking is **not implemented**. For an Obstacle Challenge driving run, score the three-lap/obstacle portion separately and record parking as `not implemented`, never `success`. If parking is added in a future firmware revision, separately record whether the parking-space boundaries remain untouched and whether the robot finishes inside and parallel. The present `FINISHED` state only implements a stop condition.
5. A success fraction is `successful independently documented runs / all independently documented attempts`. Keep failed attempts in the denominator; do not combine incompatible layouts as if they were identical.

## Informal current performance estimates

According to the team, the robot currently succeeds in approximately **8 out of 10 Open driving attempts** and **6 out of 10 Obstacle driving/avoidance attempts**. These are rough observed frequencies without retained independent per-run logs, not a completed 10-trial study. The Obstacle estimate excludes parking, which is currently not implemented. Future tests should state the precise success definition, layout and all unsuccessful attempts before calculating an actual rate.

## Metric definitions

| Metric | Definition | Source |
|---|---|---|
| Straight-line drift (cm) | Lateral endpoint offset after a stated 2 m or 3 m straight | Tape/ruler and reference line |
| Turn overshoot (cm) | Maximum lateral deviation from the stated intended path after a 90° corner | Marked track / measured video |
| Obstacle pass success | Correct pass side with no disqualifying contact | Video + run sheet |
| Three-lap completion | Three complete laps and separately recorded finish behaviour | Video + run sheet |
| Obstacle recovery (s) | Time from obstacle no longer being detected to normal steering control, using a defined source | Instrumented trace / frame-by-frame video |
| Reset/timeout count | Number of controller resets or uncompleted turn conditions per run | Serial/event notes |
| Supply voltage (V) | Measured 5 V line or battery voltage and specified load state | Multimeter / logger |

Report `n`, exact metric, units, setup and spread/range with any average. When a metric cannot be measured, log the observation qualitatively and leave the numeric field blank or mark it unavailable.

## Evidence hierarchy

1. Source-controlled firmware SHA, raw run record, corresponding video with time markers and a documented layout.
2. Dated test notes with measured values and enough setup information to repeat.
3. Historical team summary and observations, which can illustrate development but are not equivalent to a traceable run series.

Preserve the existing `validation-summary.csv` as a historical summary. Add new physical results with their own source evidence and do not overwrite older values to make the trend look smoother.
