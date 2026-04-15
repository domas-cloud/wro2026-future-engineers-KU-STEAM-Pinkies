# Our Software Story

## Our Main Software Idea

From the beginning, we wanted our software to stay as clear and stable as possible.

Instead of building many disconnected behaviours, we decided to keep one main driving principle and adapt it when needed. Our main navigation method is **PD-based line following**.

The key idea is simple:

- under normal conditions, we follow the normal target line,
- when we detect an obstacle, we change the target line,
- but we still keep the same main controller.

This made our robot easier to tune and more stable in practice.

## Why We Split the Software Across Two Boards

We use a split architecture:

- **Raspberry Pi Zero** for camera-based perception,
- **ESP32** for control, steering, and motor output.

We chose this because perception and actuation have different requirements.

The Raspberry Pi Zero is better suited for camera-side work, while the ESP32 is better suited for fast control tasks. We did not want one board to do everything, because that would make the system harder to tune and less predictable.

This split also matched our team roles well:

- Marius focused strongly on software logic and how the robot should behave,
- Domas focused on testing and how those ideas worked in real runs,
- and we used those test results together to improve the final system.

## What the Pi Zero Does

On the Pi Zero side, we handle:

- reading the camera,
- extracting the useful visual information,
- identifying obstacle colour,
- and sending simplified navigation information forward.

An important design decision was that we do **not** send raw image data to the ESP32. Instead, we send only the result that the control system needs.

That keeps the control side cleaner and more efficient.

## What the ESP32 Does

On the ESP32 side, we handle:

- receiving the processed navigation result,
- calculating steering correction,
- controlling the motor,
- and executing the final movement commands.

This separation helped us reduce the chance that image-processing delay would directly disturb steering behaviour.

## Why We Chose PD Line Following

We chose PD line following because it gave us the right balance between:

- simplicity,
- smooth correction,
- and practical tunability.

We did not want a robot that only used fixed manoeuvres, because random WRO situations require the robot to adapt to different positions and approach angles.

A PD-based approach allowed us to keep the steering continuously corrected instead of relying on the same hard-coded turn every time.

## How We Handle Obstacles

Obstacle handling is one of the most important parts of our software.

When the robot detects an obstacle, it changes the target line depending on the **obstacle colour**.

That means obstacle logic is not a completely separate system. It is an extension of the same navigation method.

This gave us several practical benefits:

- smoother transitions,
- easier tuning,
- fewer unstable mode changes,
- and clearer documentation.

## Why We Did Not Use Fixed Obstacle Manoeuvres

A fixed manoeuvre can look easier at first, but we knew that in practice the robot will not always approach an obstacle in exactly the same way.

If the robot is slightly shifted or slightly rotated, a fixed turn can become less reliable.

That is why we preferred a target-shift approach:

- the robot keeps the same main controller,
- but changes its target path depending on the obstacle meaning.

This made the behaviour more adaptive.

## Our Main Software Trade-off

The most important software trade-off for us was:

**simplicity and repeatability vs aggressive behaviour**.

A very aggressive controller can look fast in one attempt, but it is often harder to keep stable over repeated runs. We learned that a slightly calmer but more repeatable controller gave better overall results.

## How We Improved the Software Over Time

Our software was not final from the start.

### Early stage
At first, the robot could already drive, but the behaviour was less refined and turning was more reactive.

### Middle stage
We improved obstacle handling by integrating it into the same line-following logic instead of treating it as a disconnected behaviour.

### Later stage
We made the software structure clearer and more modular, and the split between perception and control became more useful in practice.

## What We Learned

The main thing we learned in software was that **clean structure helps real performance**.

A controller that is easier to understand is also usually easier to tune and improve.

For us, the final software was better not because it was more complicated, but because:

- it kept one strong main idea,
- it matched the physical robot better,
- and it supported more stable repeated runs.
