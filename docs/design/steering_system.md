# Steering System

## Mechanism

The robot uses servo-based steering with a gear-linked front axle.
The goal is to convert servo motion into symmetric wheel movement with predictable angle changes.

## Engineering Notes

- keep the steering path compact;
- minimize backlash where possible;
- avoid interference between the gear train and the chassis;
- ensure the servo can return to center consistently.

## Integration Notes

The steering system should be documented together with the chassis because mounting height, linkage length, and gear alignment all influence the actual steering angle.
If the servo output or linkage geometry changes, the software steering limits should be rechecked.

## What To Document

- the steering geometry;
- the range of motion;
- what was tested during prototyping;
- any issues such as binding, slack, or offset.
