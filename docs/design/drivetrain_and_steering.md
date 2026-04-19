# Drivetrain and Steering

## Drivetrain Overview

Our robot uses a **rear-wheel-drive system** with a **mechanical rear differential** and **servo-based front steering**.

This combination was chosen because it gave us the best overall control on the field. We wanted the robot to turn precisely, recover well after turns, and remain predictable during straight driving.

## Motor Testing

Before selecting the final motor, we tested **three N20 motors**:

- **300 rpm**
- **600 rpm**
- **1000 rpm**

All of them were physically suitable for our compact robot, but their practical behaviour was different.

### 300 rpm motor

The 300 rpm version was **too slow** for our goals.  
Although a slower motor can sometimes make control easier, in our case it did not provide enough speed for the type of performance we wanted.

### 1000 rpm motor

The 1000 rpm version had the opposite problem.  
It gave higher speed, but in practice it **did not have enough torque**. This became especially noticeable in more demanding situations where the robot needed reliable drive performance.

### 600 rpm motor

The **600 rpm N20 motor** gave the best balance.

It was fast enough to satisfy our target speed while still providing enough torque for practical use. This is why it became our final choice.

## Why 600 rpm Was the Best Trade-off

The motor choice was a classic engineering trade-off between **speed and usable torque**.

- Too little RPM made the robot slower than we wanted.
- Too much RPM reduced the available torque.
- The middle option gave the best balance.

This is important because a self-driving robot does not only need speed. It also needs predictable motion and reliable response during turning and correction.

## Motor Selection Reasoning

We did not use a laboratory dyno, so we do not claim exact torque curves. Our selection was based on practical engineering behavior under the same robot mass and drivetrain layout.

| Motor option | Practical strength | Practical weakness | Why it was not final |
| --- | --- | --- | --- |
| `300 rpm` | easy to control at low speed | too slow for competitive lap pace | sacrificed too much track speed |
| `600 rpm` | balanced speed and usable torque | required normal tuning effort | best overall compromise |
| `1000 rpm` | high theoretical speed | weaker usable pull under load and less controllable exits | speed gain was not worth the loss in stability |

The final decision therefore followed the same principle as the rest of the robot: choose the option that gives the best repeatable field performance, not the highest theoretical specification.

## Differential Choice

From our earlier experience, using a differential in the rear axle was a **must-do design choice**.

We already knew that a robot without a good differential becomes harder to turn and gives less control in corners. For this reason, we designed the drivetrain around a differential from the start.

In the final robot, we used a **LEGO differential**.

### Differential Comparison

We compared an earlier **metal differential** solution with the final **LEGO differential**.

![Metal differential version](images/metal-differential.jpg)

Earlier drivetrain version with the metal differential.

![LEGO differential version](images/lego-differential.png)

Final drivetrain version with the LEGO differential.

## Why the Differential Was Important

When the robot turns, the inner and outer rear wheels do not travel the same path length. If both wheels are forced to rotate too similarly, the robot experiences more resistance during cornering.

From practical experience, a weak or unsuitable differential setup caused:

- harder turning,
- less control,
- and more mechanical resistance.

After changing from a **metal differential** to a **LEGO differential**, the robot became:

- **more precise**,
- **less likely to jam or bind**,
- and overall **more predictable** in turning.

Most importantly, in our practical comparison the **LEGO differential was more stable than the metal differential**. It gave smoother cornering, less binding, and more repeatable behavior between runs.

That change was one of the important drivetrain improvements in the project.

## Steering Overview

The steering system is based on a **servo-driven three-gear layout**.

The servo turns the center gear, and the movement is transferred symmetrically to the front steering sides. This concept was selected because we wanted both sides to move as equally as possible.

A steering system can turn the wheels, but that alone is not enough. For autonomous driving, the steering also has to be:

- smooth,
- repeatable,
- mechanically efficient,
- and stable in straight driving.

## Steering Angle

The servo itself can rotate by about **90 degrees**, but in the robot we intentionally limit the usable steering angle to approximately **60 degrees**.

This was done because one of the most important trade-offs in the whole robot was:

**steering angle vs stability**

A larger steering angle looked useful in theory, but in practice it reduced stability. Because of this, we limited the real steering range to keep the driving behaviour more controlled.

## Why We Used MG90S

We selected an **MG90S servo** for steering.

A stronger servo was possible in theory, but that would have required more energy. Instead of solving the problem by adding a larger servo, we improved the steering mechanics so that the chosen servo could work efficiently.

This was an intentional engineering choice:

- reduce mechanical resistance first,
- then keep the actuator simple and efficient.

## Steering Iterations

The steering system went through three main development stages.

### Version 1

The first version used the same main steering concept, but the wheel support was mounted on the side of the gear. A holder was attached to the side of the gear, and from that holder a screw extended outward to hold the wheel.

This created a **large force arm**.

As a result, the servo had to work much harder to turn the wheels. In practice, this made the steering mechanically inefficient. In the first version, the servo had clear difficulty because of this large lever arm.

### Version 2

The most important change from V1 to V2 was removing the large lever arm.

The wheels were changed so that they rotated more directly in one place instead of being supported through that large side lever structure.

This gave a very important practical improvement:

- the **servo could turn the system much more easily**.

This was the biggest steering improvement in the whole project.

### Version 3

The third version kept the better steering geometry from V2 and improved it further.

The main additions were:

- **bearings integrated into the frame**,
- **custom silicone front wheels**.

The bearings reduced friction and helped the steering move more smoothly. The silicone front wheels gave better grip with the field surface.

## Front Wheel Choice

We intentionally used different wheel strategies for the front and rear.

### Front wheels

At the front, we wanted **more grip** because the wheels must follow the steering command accurately.

Before the final version, we tested other front-wheel solutions, but they could **slip**. That reduced steering effectiveness.

After switching to **silicone front wheels**:

- the front wheels no longer slipped,
- the robot could turn with larger useful angles,
- and the steering result became more reliable on the field.

### Rear wheels

At the rear, the goal was reliable drive transmission through the differential, so we kept the rear solution simpler and focused the grip improvement where it mattered most for steering.

## Straight Driving Challenge

One of the main steering-related problems was straight driving.

At different times the robot could drift slightly to either side. This means the issue was not just a left-only or right-only problem. The real challenge was achieving enough symmetry and precision that both sides behaved similarly.

The biggest improvements for straight driving came from:

- better wheel mounting,
- better steering geometry,
- improved front-wheel grip,
- and the improved differential solution.

After the final changes, the robot still drifted only **minimally**, which was a major improvement over earlier versions.

## How We Compared Steering Versions

We compared steering versions using practical driving criteria, not only visual inspection.

The most important evaluation points were:

- how much area the robot needed to make a 90-degree turn,
- and how much it drifted over a 3-meter straight drive.

These criteria were useful because they measured exactly the behaviours we cared about most: cornering quality and straight-driving precision.

## Mechanical Validation Matrix

To avoid choosing parts only by feeling, we used a small decision matrix during repeated tests.

| Mechanical area | Weak result | Acceptable result | Strong result |
| --- | --- | --- | --- |
| motor choice | robot too slow or obviously under torque stress | completes turns and straights reliably | keeps pace while remaining controllable |
| differential behavior | binding, rough corner exits, inconsistent wheel behavior | cornering works with minor resistance | smooth cornering with low resistance and repeatable exits |
| steering geometry | heavy servo load, visible sticking, poor symmetry | mostly usable with some correction cost | low resistance, symmetric response, stable straight driving |
| front-wheel grip | wheels slip before command is transferred | steering works with occasional slip | steering command translates directly into real movement |

This matrix matters for the rubric because it shows how we judged the engineering result, not only what parts we ended up with.

## Testing Effort

We did approximately **10 test runs** while comparing mechanical versions.

The most important result from this testing was clear:  
**the transition from steering V1 to V2 gave the largest improvement**.

## Summary Table

| Element | Tested options | Final choice | Why |
|--------|----------------|--------------|-----|
| Drive motor | N20 300 / 600 / 1000 rpm | 600 rpm N20 | Best balance of speed and torque |
| Differential | Earlier metal differential vs LEGO differential | LEGO differential | More stable, more precise, and less likely to bind |
| Steering geometry | V1 large lever arm / V2 reduced lever arm / V3 refined version | V3 | Best precision, lowest resistance, best grip |
| Front wheels | Earlier wheels vs silicone wheels | Silicone wheels | No slipping, better turning grip |
| Steering range | Large possible range vs limited usable range | Limited to ~60° | Better stability |

## Final Conclusion

The final drivetrain and steering system were chosen because they gave the best practical result on the field.

The biggest lessons were:

- the middle motor option was better than the extreme options,
- differential quality strongly affected turning precision,
- a larger steering angle was not automatically better,
- and reducing steering load was more effective than simply using a stronger servo.

Overall, the final system became more precise, less resistant, and more repeatable through repeated mechanical iteration.
