# KU STEAM Pinkies - WRO 2026 Future Engineers

This repository contains the engineering documentation, design reasoning, and technical structure of our **WRO 2026 Future Engineers** robot.

Our goal was to build a compact autonomous self-driving robot that is mechanically stable, easy to control, and strong in straight driving and obstacle obedience. During the season, we improved the robot through several mechanical and software iterations. The final version reflects not only the final design, but also the engineering decisions that helped us solve practical problems.

---

## Team

We are **KU STEAM Pinkies**, a team participating in the **WRO 2026 Future Engineers** category.

### Team Members And Main Responsibilities

- **Marius** – software development and mechanical design  
- **Domas** – project coordination, testing, and documentation  
- **Jonas** – electronics and hardware design  

Although each member had a main responsibility area, all major design decisions were discussed together and tested as one system.

---

## Project Goal

Our goal is to design and build a reliable autonomous robot that can perceive its environment, make decisions in real time, and drive smoothly and safely while obeying the WRO Future Engineers challenge rules.

---

## Robot Overview

The robot dimensions are approximately:

- **Length:** 21 cm
- **Width:** 10 cm
- **Height:** 8 cm

The robot uses:

- **rear-wheel drive**
- **front-wheel steering**
- **mechanical rear differential**
- **servo-based steering**
- **Raspberry Pi Zero**
- **ESP32**
- **BNO085 9-DOF IMU**
- **2 VL53L5CX matrix ToF sensors**
- **camera-based vision processing**

The chassis base is made mainly from **plywood**.

We selected plywood because it is rigid, practical for custom mechanical construction, and suitable for a compact robot where alignment, stiffness, and repeatability matter.

---

## Mechanical Design

### Chassis Philosophy

Our chassis was designed to support stable steering and repeatable motion.  
A robot may have good software, but if the mechanical structure flexes, sticks, or behaves asymmetrically, the driving result becomes unstable.

For this reason, our chassis design focused on:

- stiffness in important structural areas;
- low-friction steering movement;
- compact packaging;
- even mass distribution;
- predictable wheel alignment.

The robot is intentionally small. A compact robot is easier to package inside the WRO size limits and can also reduce unnecessary rotational inertia.

### Base Material

The base structure uses **plywood** as the main chassis material.  
We selected it because it is easy to machine, strong enough for the required loads, and practical for making a custom geometry around the steering system, drivetrain, electronics, and sensors.

The purpose was not to make the robot visually complex, but to make it mechanically reliable.

---

## Drivetrain

### Drive Layout

The robot uses **rear-wheel drive**.  
The rear axle is the driven axle, while the front axle is used only for steering.

The drive motor is a:

- **N20 motor**
- **6 V**
- **600 rpm**

We selected this motor because it is **small and fast**, which matched our goal of building a compact robot with enough speed while keeping the drivetrain simple.

### Rear Differential

One of the most important drivetrain decisions was using a **mechanical rear differential**.

The rear axle uses an **original LEGO Technic differential**.  
The motor drives a gear, and that gear drives the rear differential.

We chose this solution because during cornering the inner and outer rear wheels do not travel the same distance. If the rear wheels are forced to rotate too similarly, the robot experiences more turning resistance.

In practical development, we observed that without an effective differential the robot:

- resisted turning more;
- cornered less smoothly;
- experienced more mechanical stress;
- produced less predictable motion.

By keeping a mechanical differential in the drivetrain, the robot cornered more smoothly and with lower resistance.

---

## Steering System

### Steering Architecture

The front steering system is based on a **three-gear layout**.

All three gears have **26 teeth**, so the transmission ratio is **1:1**.  
The servo drives the center gear, and the center gear transfers motion symmetrically to both side gears.

This was an important design decision because symmetric left-right steering behavior is critical for straight driving and repeatable turning.

We use an **MG90 servo** for steering.

This servo was chosen because it is a common, compact, and easy-to-integrate steering solution. It also made development and replacement easier.

### Steering Range

Although the servo itself can rotate through a large range, in the robot the usable steering range is **mechanically limited**.

We did this intentionally.  
Allowing the wheels to turn too far made the robot unstable and reduced control quality. In practice, a controlled steering range produced better driving than maximum theoretical steering angle.

This is a good example of an engineering trade-off: more steering angle is not always better if it reduces stability.

### Steering Iterations

The steering system went through three main versions.

#### Version 1

The first version used the same three-gear concept, but the side attachments created a **large turning lever arm**.  
That meant the servo had to overcome too much mechanical load.

This version proved the idea worked, but it was not efficient enough.

#### Version 2

The second version kept the same three-gear idea, but changed the support structure so the effective turning lever arm became almost zero.

This reduced the required steering force and improved the behavior.

#### Version 3

The third version kept the same basic steering concept, but improved it with:

- **bearings**
- **custom silicone front wheels**

This version was created because the earlier version still did not have enough precision and could sometimes stick. The robot could also pull slightly to one side, which made straight driving harder.

The final version improved:

- grip;
- steering precision;
- friction;
- servo load;
- repeatability.

In practice, the final steering system gave **lower mechanical load** and a **more precise result**.

---

## Wheel Design

The front and rear wheels were designed for different purposes.

### Front Wheels

The front wheels are used only for steering.  
For this reason, we selected **custom silicone wheels** on the front axle.

The main reason was **better grip**.

Better front grip improved:

- steering accuracy;
- turning consistency;
- control quality;
- reduction of wasted motion caused by slipping.

This was important because the steering system is only useful if the front wheels can actually follow the commanded direction on the field surface.

### Rear Wheels

The rear axle uses **LEGO wheels** connected to the differential.

This kept the drivetrain reliable and mechanically simple.

### Suspension Philosophy

We did not prioritize a complex suspension system.  
Instead, we prioritized a **rigid and predictable wheel geometry**.

For this challenge, that was the better engineering choice because extra suspension movement would introduce more play and reduce steering consistency.

---

## Main Mechanical Challenge

One of the biggest mechanical challenges during development was creating the conditions for **stable straight driving**.

At different stages, the robot could drift because of combined effects such as:

- steering friction;
- uneven steering behavior;
- sticking in the steering mechanism;
- too much servo load;
- insufficient grip.

This means the problem was not solved by one single fix.

We improved straight driving by:

- reducing the steering lever-arm load;
- using a more efficient steering geometry;
- adding bearings;
- using custom silicone front wheels;
- reducing friction;
- improving steering precision;
- keeping left and right steering movement more equal.

This is one of the clearest examples of systems thinking in our robot: straight driving quality depended on several subsystems working correctly together.

---

## Weight Distribution

We intentionally placed:

- the **electronics at the rear**
- the **batteries at the front**

The reason was to create a more even weight distribution across the robot.

Balanced weight distribution helps the robot behave more predictably and reduces unwanted imbalance between front and rear.

---

## Electronics Architecture

The robot uses a split architecture with two main computing boards:

- **Raspberry Pi Zero**
- **ESP32**

We separated these roles intentionally.

The **Raspberry Pi Zero** handles the **camera and the camera algorithm**.  
The **ESP32** handles the **main control tasks**, including steering and motor-related behavior.

This architecture was chosen because the ESP32 is better suited for fast control tasks and easier actuator handling, while the Raspberry Pi Zero is more suitable for camera-side processing.

The robot also uses:

- **BNO085 IMU**
- **2 VL53L5CX matrix ToF sensors**
- front-mounted camera

The detailed power architecture and sensor placement are documented further in the hardware section and will be expanded as the documentation is refined.

---

## Software Architecture

### Main Control Principle

The main navigation logic is based on **PD line following**.

This is a very important design choice in our project.  
Instead of building one controller for normal driving and a completely separate controller for obstacle driving, we kept one main control framework and changed the path target when needed.

This made the control logic simpler and more stable.

### Obstacle Strategy

When the robot sees an obstacle, it changes the **PD lane target** depending on the **obstacle color**.

The obstacle color tells the robot whether it should drive:

- **closer to the wall**
- or **further away from the wall**

So the robot does not abandon line following.  
Instead, it keeps the same PD-based control idea and only changes the line reference.

This gave several advantages:

- smoother behavior;
- simpler tuning;
- less switching complexity;
- easier explanation in documentation;
- better reproducibility.

### Raspberry Pi And ESP32 Cooperation

The Raspberry Pi Zero does not only capture the camera image.  
It also runs the camera-side algorithm and sends the **algorithm result** to the ESP32.

The ESP32 then combines that information with the rest of the control logic and sends output to the steering and drive system.

This means the architecture is better described as:

- **Pi Zero = vision / perception**
- **ESP32 = control / actuation**

rather than saying Pi is only a camera bridge.

---

## Sensor Strategy

The robot uses multiple sensing sources instead of relying on only one type of input.

Main sensing elements:

- camera;
- IMU;
- 2 matrix ToF sensors.

The camera is placed at the **front of the robot** to achieve the best possible visibility of the track.

The general idea behind sensor placement was to maximize useful field visibility and choose the most effective matrix point or matrix region for the algorithm.

The final sensor and calibration section will be expanded further in the documentation files.

---

## Engineering Decisions And Trade-Offs

During development, we repeatedly had to choose between competing priorities.

### Steering Range vs Stability

A large steering range may look better in theory, but in practice it reduced stability.  
So we limited the usable steering range.

### High Grip vs Low Friction

We wanted low friction inside the steering system, but high grip at the wheel-floor contact.  
This is why we used:

- **bearings** to reduce mechanical friction;
- **silicone front wheels** to increase grip.

### Simple Drivetrain vs Better Cornering

A simpler rear axle without a differential would have been easier mechanically, but worse during turns.  
We chose the differential because it improved cornering behavior.

### Compact Size vs Packaging Difficulty

A compact robot is good for agility, but harder to package.  
We solved this by carefully arranging batteries, electronics, drivetrain, and steering layout.

---

## Testing And Iteration

The robot was improved through repeated practical testing rather than only theoretical design.

The most important improvements came from observing real behavior and then changing the mechanism accordingly.  
For example:

- steering versions were compared based on load and precision;
- the differential decision was validated through smoother turning behavior;
- custom silicone front wheels were kept because they improved grip;
- bearings were added because earlier steering versions could sometimes stick and lacked enough precision.

This iterative process was important because many of the final improvements came from practical testing rather than from the first design idea.

---

## Reproducibility

This repository is intended not only to show the final robot, but to make the engineering process understandable and reproducible.

The repository includes or is being expanded to include:

- mechanical design documentation;
- steering documentation;
- wheel and mounting choices;
- electronics overview;
- wiring and power notes;
- software architecture;
- navigation logic;
- testing observations;
- evaluation and iteration history.

Our goal is that another team should be able to understand:

- how the robot is built;
- why the robot is built this way;
- how the main software logic works;
- what changed from one version to another;
- how the final design was reached.

---

## Repository Structure

Important documentation sections in this repository include:

- `docs/design/chassis_design.md`
- `docs/design/steering_system.md`
- `docs/design/wheel_mounting_suspension.md`
- `docs/hardware/electronics_overview.md`
- `docs/hardware/pcb_wiring_diagrams.md`
- `docs/code/code_architecture.md`
- `docs/code/navigation_logic.md`

Additional sections continue to document the engineering process, testing results, software decisions, and final performance.

---

## Development Summary

The final robot is the result of repeated engineering improvement rather than a single finished design.

Some of the most important lessons from our development were:

- straight driving depends strongly on mechanical precision;
- steering symmetry matters;
- grip and friction must be optimized separately;
- a differential improves cornering smoothness;
- the simplest control architecture is often the most stable one;
- obstacle handling can be integrated into line following instead of replacing it.

Our robot improved most when we stopped thinking about parts separately and started treating the robot as one connected system.

---

## Final Note

This repository documents not only what our robot looks like, but how it was engineered.

That includes:

- mechanical design choices;
- drivetrain and steering trade-offs;
- wheel and grip decisions;
- system architecture;
- control strategy;
- iteration-based improvement.

Our aim in this project was to build a robot that is not only functional, but explainable, justifiable, and reproducible.
