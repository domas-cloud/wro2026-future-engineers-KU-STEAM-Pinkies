# Navigation Strategy

## Core Navigation Idea

The core navigation principle of our robot is **PD-based line following**.

This is one of the most important software decisions in the whole project. Instead of building one controller for normal driving and a completely different controller for obstacle behaviour, we kept one main control method and changed the **target path** when needed.

In other words:

- the robot always keeps the same basic driving logic,
- but obstacle information changes which line or lane target the controller follows.

This made the robot simpler, smoother, and easier to tune.

## Why We Chose PD Control

We chose PD line following because it gave us a practical balance between:

- control simplicity,
- smooth response,
- and easier tuning.

A more fragmented control structure with many separate hard-coded manoeuvres would have made the behaviour more difficult to manage and less adaptable to random track situations.

The PD controller allowed the robot to continuously correct its steering instead of relying on fixed-angle turns.

## Obstacle Handling Concept

Obstacle handling is integrated into the same navigation system.

When the robot detects an obstacle, it does not abandon the main controller. Instead, it changes the path target depending on the obstacle colour.

This was a very important engineering decision because the robot must not only avoid an object physically, but must also obey the WRO rule about which side to pass.

## Colour-Based Target Selection

The obstacle colour tells the robot how to bias its path.

- A **red obstacle** changes the target so the robot passes on the required side.
- A **green obstacle** changes the target in the opposite way.

The important point is that obstacle handling is not treated as a separate disconnected system. It is treated as a **modified form of the same lane-following logic**.

This gave several advantages:

- smoother transitions,
- fewer unstable mode changes,
- easier tuning,
- and easier documentation.

## Practical Navigation Sequence

The practical logic can be described in a simplified sequence:

1. read the camera-based navigation result,
2. estimate the current path error,
3. apply PD correction,
4. check obstacle meaning,
5. if needed, change the target path,
6. continue PD control with the updated target,
7. return to the normal target after the obstacle is passed.

This structure is simple, but it is also powerful because it keeps one stable control idea through multiple situations.

## Why We Did Not Use Fixed Manoeuvres

A fixed obstacle manoeuvre can look easier at first, but it becomes weaker when:

- the robot approaches with a different angle,
- the robot is slightly shifted inside the corridor,
- or the track situation changes.

For our project, a target-shift method was better because the robot could still adapt to its current position instead of forcing the same turn shape every time.

## Relation to Straight Driving

The navigation strategy also supports straight driving.

Because the robot keeps a continuous correction method instead of sharp mode switching, the behaviour stays more predictable over longer movement. This is important because our testing showed that consistency matters more than aggressive steering.

## Main Navigation Trade-off

The most important software trade-off was:

**simplicity and repeatability vs more aggressive behaviour**

A very aggressive robot can look faster in one attempt, but it is often less stable across repeated runs. We learned that a slightly calmer but more repeatable control strategy gave better overall results.

## Why This Strategy Improved the Robot

This navigation method improved the robot in three major ways:

### 1. Stability

The robot stayed closer to one main control principle instead of jumping between many disconnected behaviours.

### 2. Obstacle obedience

Obstacle colour directly changed the path target, so the robot could obey the challenge rule while still using the same main controller.

### 3. Easier tuning

Because the same control logic stayed active most of the time, tuning became easier and more consistent.

## Final Conclusion

Our final navigation strategy is built around one key idea:

**PD line following remains the base behaviour at all times.**

Obstacle logic does not replace that behaviour. It changes the target that the same controller follows.

This made the robot easier to understand, easier to tune, and more stable in practical driving.
