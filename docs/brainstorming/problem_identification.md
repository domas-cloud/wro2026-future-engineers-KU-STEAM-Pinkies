# Problem Identification

## What Needed To Be Solved

The robot had to move reliably on a structured track, follow the lane, identify obstacles, and remain controllable over repeated runs.
The main challenge was therefore not only to build a moving car, but to balance steering precision, driving stability, sensor coverage, and computation delay in one system.
Another clear lesson came from the previous robot: a larger and more complex build makes tuning harder, increases the risk of mechanical play, and reduces repeatability.
Because of that, this project aimed from the start for a smaller and simpler robot with fewer unnecessary subsystems, shorter mechanical paths, and easier-to-manage architecture.

## How This Robot Differs From The Previous One

- smaller overall chassis and more compact subsystem layout;
- simpler electronics architecture, with the `ESP32` handling all control;
- the `Raspberry Pi Zero` kept only for camera input;
- fewer extra sensors and lower power consumption;
- stronger focus on structural rigidity and reduced mechanical play.

## Main Constraints

- limited onboard computing power and energy;
- a need for accurate steering without excessive mechanical play;
- a need to detect obstacles and track features without overcomplicating the robot;
- a need to keep the robot small and simple enough to tune and rebuild easily;
- a need for documentation that another team could realistically follow.

## Why This Matters

In Future Engineers competition runs, even small errors in steering, sensor placement, or control timing can lead to missed turns or collisions.
Because of that, the documentation focuses on the decisions behind the robot, not only on its final shape.
The experience from the previous robot showed that simplicity is not a compromise here, but a direct requirement for a more stable and repeatable result.

## Success Criteria

- the robot can repeatedly follow the lane and handle obstacles;
- the steering is mechanically stable and electronically controlled;
- the power and sensor layout supports the full system without interference;
- the repository shows how the robot developed, not only the final version.
