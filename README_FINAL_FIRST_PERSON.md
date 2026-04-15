# KU STEAM Pinkies - WRO 2026 Future Engineers

We are **KU STEAM Pinkies**, participating in **WRO 2026 Future Engineers**.

In this repository, we document not only our final robot, but also the engineering process that led us to it. Our goal this season was to build a compact autonomous self-driving robot that would be mechanically stable, easy to control, reliable in straight driving, and capable of obeying obstacle rules and parking requirements.

We tried to document our work in a way that shows:

- what we built,
- why we built it this way,
- what we tested,
- what failed,
- and why we selected the final version.

---

## Team

Our team members and main roles are:

- **Marius** – software development and mechanical design  
- **Domas** – project coordination, testing, and documentation  
- **Jonas** – electronics and hardware design  

Even though each of us had a main responsibility area, we discussed the most important design decisions together and tested the robot as one connected system.

---

## Project Goal

Our goal was to design and build a reliable autonomous robot that could:

- perceive its environment,
- make decisions in real time,
- drive smoothly and predictably,
- obey the obstacle rules,
- and perform the parking task.

We did not want to build a robot that only looked advanced. We wanted to build a robot that actually performed better in practice.

---

## Robot Overview

Our final robot is a compact vehicle with the following approximate dimensions:

- **Length:** 21 cm  
- **Width:** 10 cm  
- **Height:** 8 cm

We chose these dimensions because, in our opinion, they were very close to ideal for our needs. The robot is small enough to turn more easily and well suited for the parking task.

Our robot uses:

- **rear-wheel drive**,
- **front-wheel steering**,
- **mechanical rear differential**,
- **servo-based steering**,
- **Raspberry Pi Zero**,
- **ESP32**,
- **BNO085 9-DOF IMU**,
- **2 VL53L5CX matrix ToF sensors**,
- and **camera-based vision processing**.

The main frame is built from **wood**, and we also use several custom parts such as:

- **3D-printed steering parts**,
- a **motor mount**,
- and a **camera mount**.

---

## Why We Changed Our Mechanical Concept

Before building the final robot, we had experience from an older robot. That robot was larger, used a stronger motor and gearbox, and had a more complicated steering concept.

However, in practice we saw several disadvantages:

- it was harder to turn,
- the engineering was more complicated,
- and the steering behaviour was less repeatable.

Because of that, we deliberately moved toward a simpler and more compact concept. One of the most important lessons for us this season was that a more complicated robot is not automatically a better robot.

---

## Mechanical Design

### Chassis Philosophy

We designed our chassis to support:

- stable steering,
- repeatable straight driving,
- compact packaging,
- and good mounting precision.

For us, a good chassis was not only a structure that holds parts together. It also had to keep the steering geometry stable and reduce unnecessary mechanical problems during driving.

### Material Choice

We used **wood** for the main frame because it was practical for creating a custom layout and gave us enough freedom to place the drivetrain, steering, camera, and other systems where we needed them.

### Main Mechanical Trade-off

One of the biggest mechanical trade-offs in our robot was:

**steering angle vs stability**

Our servo can rotate about **90 degrees**, but in the robot we limited the usable steering range to about **60 degrees**. We did this because a larger steering angle looked good in theory, but in practice it made the robot less stable.

---

## Drivetrain

### Motor Testing

We tested three **N20 motors**:

- **300 rpm**,
- **600 rpm**,
- **1000 rpm**.

The 300 rpm motor was too slow for our goals.

The 1000 rpm motor did not provide enough torque.

The **600 rpm motor** gave us the best balance between speed and torque, so we selected it for the final robot.

This was one of the clearest examples of an engineering trade-off in our project. We did not choose the slowest option or the fastest option. We chose the option that gave the best overall result.

### Differential

From our earlier experience, we already knew that integrating a differential was a must.

Without a good differential solution, the robot became harder to turn and less controlled in corners. During development, we also changed from a **metal differential** to a **LEGO differential**.

That change made the robot:

- more precise,
- less likely to jam,
- and less resistant in turning.

---

## Steering System

Our steering system went through three main versions.

### Version 1

In the first version, the wheel support created a **large lever arm**. That meant the servo had to work much harder.

### Version 2

In the second version, we removed the large lever arm and changed the construction so that the wheels rotated more directly in place.

This was the biggest steering improvement in our project, because the servo could turn the wheels much more easily.

### Version 3

In the third version, we improved the V2 geometry further with:

- **bearings mounted in the frame**,
- **custom silicone front wheels**.

This final version gave us better grip, lower friction, lower servo load, and more repeatable steering behaviour.

### Servo Choice

We use an **MG90S servo**.

A stronger servo was possible in theory, but that would also have required more energy. Instead of solving the problem by choosing a stronger servo first, we improved the steering mechanics. After those improvements, the MG90S was sufficient for our final robot.

---

## Wheel Choice

We intentionally used different wheel strategies for the front and rear.

### Front wheels

At the front, grip was very important because the wheels must follow the steering command accurately.

Earlier front-wheel versions could slip. After switching to **silicone front wheels**, the wheels no longer slipped and the robot could make stronger useful turns.

### Rear wheels

At the rear, we focused on reliable drivetrain behaviour together with the differential.

---

## Main Mechanical Challenge

One of our biggest practical mechanical challenges was **straight driving**.

At different stages, the robot could drift slightly to either side. This showed us that the problem was not caused by only one part. Straight driving depended on several things working together:

- steering geometry,
- wheel mounting,
- front-wheel grip,
- and differential behaviour.

The biggest improvements for straight driving came from:

- **better wheel mounting**,
- and **changing to the LEGO differential**.

After the final changes, the robot still drifted only minimally.

---

## Electronics Architecture

Our robot uses a split electronics architecture with two main boards:

- **Raspberry Pi Zero** for perception,
- **ESP32** for control and actuation.

We chose this because perception and control have different requirements. Camera processing is more computational, while steering and motor output require fast and predictable execution.

We also use:

- **BNO085 IMU**,
- **2 VL53L5CX matrix ToF sensors**,
- and a **front-mounted camera**.

More detailed hardware information is documented in the hardware section of the repository.

---

## Software Architecture

### Main Software Idea

Our main navigation method is **PD-based line following**.

Instead of building one controller for normal driving and a completely separate one for obstacle situations, we kept one main control principle and changed the target path when needed.

### Obstacle Strategy

When we detect an obstacle, we do not abandon the main controller. Instead, we change the target line depending on the obstacle colour.

This gave us:

- smoother transitions,
- easier tuning,
- fewer unstable mode changes,
- and clearer logic.

### Split Architecture

On the **Pi Zero** side, we handle camera-based perception.

On the **ESP32** side, we handle steering, motor output, and the final control behaviour.

We chose this split because it helped us keep the robot more stable and made the software easier to understand and tune.

---

## Systems Thinking and Engineering Decisions

One of the strongest lessons from our season was that the robot had to be improved as a **complete system**, not as isolated parts.

For example:

- a stronger servo would not solve poor steering geometry,
- good software could not fully compensate for slipping front wheels,
- and a good motor alone would not guarantee precise turning if the differential behaviour was weak.

That is why many of our important decisions were made based on system behaviour, not only on individual component specifications.

Some of our most important engineering decisions were:

- choosing a **smaller chassis** instead of a larger more complicated one,
- choosing the **600 rpm motor** instead of the extreme options,
- limiting steering angle for better stability,
- improving steering geometry instead of immediately choosing a stronger servo,
- switching to **silicone front wheels**,
- and changing to a **LEGO differential**.

---

## Testing and Iteration

Testing was one of the most important parts of our project.

We compared mechanical versions using practical criteria such as:

- how much space the robot needed to complete a **90-degree turn**,
- and how much it drifted over a **3-meter straight drive**.

We performed about **10 test runs** while comparing the main mechanical versions.

The clearest mechanical improvement was the transition from **steering V1 to V2**.

Software also improved through repeated testing. Our software became better when we kept one clear main control idea and integrated obstacle handling into the same navigation principle instead of building many disconnected behaviours.

---

## Risk and Failure Analysis

During development, we identified several important risks:

- unstable steering behaviour,
- front-wheel slipping,
- excessive steering load on the servo,
- poor differential behaviour,
- wrong motor balance between speed and torque,
- and reduced straight-driving repeatability.

We tried to solve these problems by improving the root cause, not only by adding stronger parts.

For example:

- we reduced steering resistance instead of immediately choosing a stronger servo,
- we switched to silicone front wheels when slipping reduced real steering effectiveness,
- and we changed the differential when we needed better precision and less binding.

---

## Repository Structure

For the clearest reading path, we recommend starting with:

- `START_HERE.md`
- `docs/final_narrative/team_overview.md`
- `docs/final_narrative/mechanical_story.md`
- `docs/final_narrative/software_story.md`
- `docs/final_narrative/engineering_story.md`
- `docs/final_narrative/testing_story.md`

We also created more detailed supporting files for design, testing, risk analysis, and hardware documentation.

---

## Reproducibility

We want this repository to show not only the final robot, but also the process behind it.

Our goal is that another team should be able to understand:

- how our robot is built,
- why we chose this design,
- how our software logic works,
- what changed during development,
- and why the final version was selected.

Our documentation is therefore not only a description of the final robot. It is a record of our engineering process.

---

## Final Conclusion

Our final robot is the result of repeated iteration, testing, and engineering trade-offs.

The most important lesson for us was that **repeatability mattered more than complexity**.

We selected our final design because it gave us the best practical balance between:

- turning ability,
- straight-driving stability,
- obstacle obedience,
- parking suitability,
- and overall controllability.

In the end, our robot became better not because it was the most complicated version, but because it became the most balanced and repeatable one.
