# Navigation Strategy

The robot navigates by combining sector-based heading control with local distance sensing.

## Core Navigation Idea

On straight sections, the robot tries to keep:

- the current heading target in `targetAngle`;
- an approximate wall offset through `TARGET_DISTANCE`.

At corners, the front distance sensor triggers a hard turn and the heading target is rotated by `90` degrees.

So the navigation is built from two clearly different behaviors:

- continuous correction on straights;
- forced corner turns at sector changes.

## Obstacle Rule

For obstacle driving, the high-level rule is direct:

- `red pillar -> pass right`
- `green pillar -> pass left`

The clean way to implement that rule is to shift the reference line inside the current sector. The low-level steering logic can then stay the same.

## Straight Sections

On a straight segment, the robot stabilizes around:

- `targetAngle`
- `TARGET_DISTANCE`

That makes it behave like a heading-guided wall follower.

If camera guidance is active, it can bias the reference line left or right without changing the basic control structure.

## Turn Trigger

The front sensor is the main trigger for leaving straight control:

```text
frontDistance.distance <= TURN_DISTANCE
```

When that happens, the robot enters the hard-turn routine.

## Turn Direction

The current code decides the turn direction from the left sensor:

```text
isClockwise = leftDistance.distance <= 800 && leftDistance.status == 0;
```

So a close valid left reading leads to a clockwise turn; otherwise the robot turns the other way.

## Corner Execution

Once the controller decides to turn, it:

- forces the servo to one steering extreme;
- waits until the front sensor sees open space again;
- updates `targetAngle` by `90` degrees;
- increments `edge`.

This keeps the corner logic separate from the straight-line regulation.

## Current Side-Correction Logic

The current controller uses:

- `leftDistance` when the robot is turning clockwise;
- `rightDistance` when the robot is turning counterclockwise.

That keeps the wall-correction term aligned with the outer side of the sector instead of hard-coding one sensor for both directions.

## Run Completion

The run ends when:

- `edge >= 12`
- and the steering error has settled near center again.

At that point the controller stops and restarts.
At that point the controller stops, centers the steering, and waits for the next start command.
