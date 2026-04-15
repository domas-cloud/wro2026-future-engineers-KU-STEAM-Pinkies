# Engineering Decisions

## Purpose of This Section

This section explains not only what we built, but **why we built it this way**.

During the season, many of our most important improvements came from choosing between competing priorities. In other words, our robot was shaped by engineering trade-offs, not by random part selection.

## Main Mechanical Trade-off

The biggest mechanical trade-off in our robot was:

**steering angle vs stability**

At first, a larger steering angle seemed attractive because it suggested sharper turning. However, in practice we found that increasing the steering range too much made the robot less stable.

For this reason, although the servo itself could rotate about **90 degrees**, we limited the robot to about **60 degrees** of usable steering angle.

This was an important decision because it shows a key engineering principle:  
**maximum movement is not always the best movement**.

## Decision 1: Smaller Robot Instead of Larger Robot

Our previous robot was larger and used a more complicated engineering solution, including a stronger motor and gearbox.

At first glance, that older robot looked powerful and advanced. However, in practice it had important disadvantages:

- it was harder to turn,
- the engineering solution was more complicated,
- and it was less practical for the final driving behaviour we wanted.

We therefore chose a smaller final robot with dimensions of approximately:

- **21 cm length**
- **10 cm width**
- **8 cm height**

### Why this was the better choice

The smaller robot gave us several practical benefits:

- it could turn more easily,
- it better matched our parking goals,
- and it allowed a simpler and more controllable mechanical design.

### Engineering conclusion

We chose the smaller robot because it gave a better balance of turning ability, controllability, and suitability for the challenge.

## Decision 2: Middle Motor Option Instead of Extreme Motor Options

We tested three N20 motors:

- **300 rpm**
- **600 rpm**
- **1000 rpm**

### Why 300 rpm was rejected

The 300 rpm motor was too slow and did not satisfy our speed expectations.

### Why 1000 rpm was rejected

The 1000 rpm motor did not provide enough torque.

### Why 600 rpm was selected

The 600 rpm motor provided the best balance between:

- usable speed,
- and enough torque.

### Engineering conclusion

We did not choose the fastest motor or the slowest motor. We chose the one that gave the best total result.

## Decision 3: Differential as a Must-Have Element

From earlier experience, we already knew that integrating a differential was essential.

Without a good differential solution, the robot became:

- harder to turn,
- less controlled,
- and less smooth in corners.

In the final robot, after changing from a metal differential to a **LEGO differential**, the drivetrain became:

- more precise,
- less likely to jam,
- and more repeatable.

### Engineering conclusion

The differential was not just an extra part. It was a required element for predictable turning behaviour.

## Decision 4: Improving the Steering Mechanics Instead of Using a Stronger Servo

We used an **MG90S servo**.

A stronger servo would have been possible, but it would also have required more energy. Instead of solving the problem by increasing actuator size, we reduced the mechanical resistance of the steering system.

This was especially important after we saw the weakness of steering **Version 1**.

### Why V1 steering was rejected

In Version 1, a holder was attached to the side of the gear, and a screw extended from that holder to support the wheel. This created a **large force arm**.

As a result:

- the servo had to work much harder,
- steering was less efficient,
- and the system was mechanically worse than it looked in theory.

### Why V2 steering was better

In Version 2, we removed that large force arm. The wheels rotated more directly in place.

This gave a major practical benefit:

- the servo could turn the wheels much more easily.

### Engineering conclusion

The correct decision was not “buy a stronger servo”. The correct decision was **fix the mechanical geometry first**.

## Decision 5: Front Grip Was More Important Than Using the Same Wheels Everywhere

We intentionally chose different wheel strategies for different axles.

### Front axle goal

At the front, the priority was steering grip.

Earlier front wheels could slip, which reduced the real effect of the steering command.

### Final choice

We switched to **silicone front wheels**.

After this change:

- the front wheels stopped slipping,
- the robot could use larger useful steering angles,
- and turning became more effective.

### Engineering conclusion

Wheel choice should match the function of the axle. The steering axle needed grip more than the drive axle needed matching wheel type.

## Decision 6: Better Precision Over More Complexity

One of our repeated lessons during development was that **precision and repeatability mattered more than complexity**.

This was visible in several decisions:

- moving from the larger complicated robot to the smaller one,
- rejecting steering V1,
- limiting steering angle,
- choosing the 600 rpm motor instead of the extreme options,
- and replacing the differential with a LEGO differential.

All of these decisions followed the same engineering idea:

> choose the solution that performs better in real runs, not the one that only looks better on paper.

## Testing-Based Decision Making

We compared mechanical versions through practical testing.

The most important criteria were:

- how much area the robot needed to complete a 90-degree turn,
- and how much it drifted over a 3-meter straight drive.

We performed approximately **10 test runs** when comparing versions.

The most important result from these tests was that the change from **steering V1 to V2** gave the biggest improvement.

## Risk and Failure Thinking

Several of our decisions were made because we identified practical risks in the earlier versions.

| Risk / weakness | Effect on robot | Mitigation |
|-----------------|----------------|------------|
| Large steering lever arm | Servo overload, inefficient steering | Redesigned steering geometry in V2 |
| Too much steering angle | Less stable behaviour | Limited steering range to ~60° |
| Front wheel slipping | Weak real steering effect | Switched to silicone front wheels |
| Unsuitable differential behaviour | Less precise turning, more binding | Switched to LEGO differential |
| Extreme motor selection | Too slow or not enough torque | Selected 600 rpm N20 |

## Final Engineering Summary

The final robot is the result of repeated trade-off decisions.

The most important ones were:

- **smaller chassis instead of larger complex chassis**,
- **balanced motor instead of extreme motor**,
- **usable steering range instead of maximum steering range**,
- **better steering geometry instead of stronger servo**,
- **high front-wheel grip instead of slipping wheels**,
- **LEGO differential instead of a less suitable differential solution**.

## Final Conclusion

Our engineering process showed that the best robot was not the one with the most aggressive specifications. It was the one with the best practical balance.

The final design was selected because it was:

- easier to control,
- more precise in turning,
- more stable in straight driving,
- less mechanically resistant,
- and more suitable for real competition performance.
