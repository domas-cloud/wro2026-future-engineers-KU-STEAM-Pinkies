# Problem Identification

## What We Needed To Solve

The robot had to move reliably on a structured track, follow the lane, recognize obstacles, and remain controllable across repeated runs.
That means the main problem was not just building a moving car, but balancing steering accuracy, driving stability, sensor coverage, and compute latency in one system.

## Main Constraints

- Limited on-robot compute and power.
- Need for precise steering without excessive mechanical backlash.
- Need to detect obstacles and track features without overcomplicating the build.
- Need for documentation that another team can actually reproduce.

## Why This Matters

In Future Engineers, small errors in steering, sensor placement, or control timing can cascade into missed turns or obstacle collisions.
The documentation therefore focuses on design decisions, not only the final shape of the robot.

## Success Criteria

- Robot can follow the lane and handle obstacles in a repeatable way.
- Steering is mechanically stable and electronically controllable.
- Power and sensor layout support the full system without interference.
- The repository shows how the robot evolved, not only the final version.
