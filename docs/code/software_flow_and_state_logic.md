# Software Flow and State Logic

## Why We Structured the Software This Way

When we developed our robot, we wanted the software to stay understandable both for us and for other people reading the repository.

For that reason, we do not describe the software as one large block of code. We describe it as a sequence of connected stages that work together during a run.

This makes the logic easier to explain and also fits the way we thought about the system during development.

## High-Level Flow

Our software can be understood through the following main flow:

1. **read visual information**,
2. **estimate the current path situation**,
3. **decide which target path to follow**,
4. **calculate steering correction using PD control**,
5. **send final movement commands**,
6. **repeat continuously during the run**.

This is the main control loop idea behind our robot.

## Perception Stage

In the first stage, we use the camera-side system to observe the track in front of the robot.

At this stage, we are interested in information such as:

- where the path is,
- how the robot is positioned relative to it,
- and whether there is a relevant obstacle with colour information.

We process this on the **Raspberry Pi Zero** side.

## Decision Stage

After perception, the robot must decide what the current target path should be.

### Normal situation
If there is no relevant obstacle, the target path is the normal driving line.

### Obstacle situation
If a red or green obstacle is detected, the target path changes according to the passing rule.

This is one of the most important ideas in our software:

- the controller does not change into a completely separate navigation system,
- only the **target path** changes.

## Control Stage

Once the target path is known, the robot calculates the steering correction.

At this stage, the **ESP32** uses PD control to transform the current path error into steering output.

This means the control stage answers the question:

**how much should we steer right now to move back toward the correct target path?**

## Actuation Stage

After the steering correction is calculated, the ESP32 sends the final output to:

- the steering servo,
- and the drive motor.

This produces the real movement of the robot.

## Continuous Loop Behaviour

The whole process repeats continuously during driving. That is important because the robot does not solve the track in one large decision. It keeps updating its understanding of the situation and correcting its movement step by step.

This is one of the reasons why the robot can adapt better than a system that relies only on fixed manoeuvres.

## Practical State Logic

Even though our robot keeps one main navigation principle, we can still describe its behaviour through several practical states.

### 1. Normal lane following
In this state, the robot follows the standard target line.

### 2. Obstacle-adjusted following
In this state, the robot still uses the same PD controller, but now it follows a shifted target path based on obstacle colour.

### 3. Correction / recovery behaviour
If the robot becomes less stable or less aligned, the controller behaviour focuses more on returning the robot to a safer state.

### 4. Parking behaviour
After the required laps are completed, the robot transitions into the final parking task.

## Why This Is Useful for Documentation

Describing the logic in these practical states helps in two ways:

- it makes the software easier to explain,
- and it makes the behaviour easier to connect to the actual robot performance.

Even if the code itself is organised differently, the state-based explanation is still useful because it reflects what the robot is doing from an engineering point of view.

## Suggested Simple Flowchart

The logic can be shown in a simple flowchart like this:

```text
Camera input -> path / obstacle analysis -> target path selection -> PD steering calculation -> servo + motor output -> repeat
```

A more state-oriented version could be shown like this:

```text
Start -> Normal follow -> Obstacle detected? -> shift target path -> continue PD control -> obstacle passed -> return to normal follow -> parking
```

## What Should Be Added from the Final Code

To make this document even stronger, the next step would be to insert the real file or function names from the final implementation, for example:

- the perception function name,
- the obstacle decision function name,
- the PD calculation function name,
- the parking logic function name.

That would make the explanation even more directly connected to the source code.

## Final Conclusion

We structured our software so that the robot behaviour could be understood as a flow of perception, decision, control, and actuation.

For us, that structure was important because it helped us:

- keep the logic clear,
- explain the code better,
- and improve the robot in a more systematic way.
