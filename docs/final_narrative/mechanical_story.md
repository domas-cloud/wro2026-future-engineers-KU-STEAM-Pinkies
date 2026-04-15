# Our Mechanical Story

## Why We Changed Our Mechanical Concept

At the beginning of this season, we already had experience from our previous robot. That robot was larger, used a more powerful motor and gearbox, and had a more complicated steering solution.

However, in practice we saw that it was harder to turn, the engineering was more complicated, and the steering behaviour was less repeatable than we wanted.

Because of that, we decided to move toward a simpler and more compact mechanical concept.

## Why We Chose a Compact Chassis

Our final robot dimensions are approximately:

- **Length:** 21 cm  
- **Width:** 10 cm  
- **Height:** 8 cm

We chose this size because, in our opinion, it was close to ideal for our needs. It was:

- small enough to turn more easily,
- better suited for the parking task,
- and compact enough to stay mechanically controlled.

This was one of our first major trade-offs:  
**smaller size vs easier packaging**.

A compact robot is harder to arrange internally, but for us the turning and parking benefits were worth it.

## Our Frame and Custom Parts

We built the main frame from **wood**. We also used several custom parts, including:

- **3D-printed steering parts**,
- a **motor mount**,
- and a **camera mount**.

We chose this approach because it gave us enough freedom to place the mechanical and sensing parts exactly where we needed them.

## How We Selected the Drive Motor

We tested three **N20 motors**:

- **300 rpm**,
- **600 rpm**,
- **1000 rpm**.

The 300 rpm motor was too slow for the kind of performance we wanted.

The 1000 rpm motor had the opposite problem: it did not provide enough torque.

The **600 rpm motor** gave us the best balance between speed and torque, so we selected it as our final motor.

This was a good example of a classic engineering trade-off:

**too little speed vs too little torque**.

Instead of choosing an extreme option, we chose the one that gave the best practical balance.

## Why the Differential Was So Important for Us

From our earlier experience, we already knew that using a differential was a must.

Without a good differential solution, our robot became harder to turn and less controlled in corners. During development we also changed from a **metal differential** to a **LEGO differential**.

That change made the robot:

- more precise,
- less likely to jam,
- and less resistant in turning.

This showed us that the differential was not just a detail. It was one of the key parts that influenced real driving behaviour.

## How Our Steering Evolved

The steering system went through three main versions.

### Version 1
In Version 1, the wheel support was attached to the side of the gear, and from that support a screw extended outward to hold the wheel.

This created a **large lever arm**.

Because of that, the servo had to work much harder. The concept worked, but mechanically it was not efficient enough.

### Version 2
In Version 2, we removed the large lever arm and changed the construction so that the wheels rotated more directly in place.

This was the biggest mechanical improvement in our steering development.

The most obvious practical result was simple:  
**the servo could turn the wheels much more easily**.

### Version 3
In Version 3, we kept the better steering geometry from V2 and improved it with:

- **bearings mounted in the frame**,
- **custom silicone front wheels**.

This version gave us the best final combination of:

- lower friction,
- lower servo load,
- better grip,
- and better repeatability.

## Why We Limited the Steering Angle

The servo itself can rotate about **90 degrees**, but in the robot we limited the usable steering range to about **60 degrees**.

We did this because one of the most important trade-offs in our whole robot was:

**steering angle vs stability**.

A larger steering angle looked good in theory, but in practice it made the robot less stable. So we intentionally chose the more controlled option.

## Why We Used Silicone Front Wheels

Earlier front-wheel versions could slip. That meant the steering command was not always transferred effectively into real movement on the field.

After switching to **silicone front wheels**, the front wheels no longer slipped, and the robot could make stronger useful turns.

This was important because the front wheels are used for steering, so grip at the front mattered more than simply using the same wheels everywhere.

## Our Main Mechanical Problem: Straight Driving

One of the hardest practical issues for us was straight driving.

At different stages, the robot could drift slightly to either side. This showed us that the problem was not caused by only one part. It depended on several subsystems working together:

- steering geometry,
- wheel mounting,
- front-wheel grip,
- differential behaviour.

The two biggest practical improvements for straight driving were:

- **better wheel mounting**,
- **changing to the LEGO differential**.

After all the final changes, the robot still drifted only minimally, which was a much better result than in earlier versions.

## How We Compared Mechanical Versions

When we compared mechanical versions, we did not just look at them visually. We used practical driving criteria.

The most important ones were:

- how much space the robot needed to make a **90-degree turn**,
- and how much it drifted over a **3-meter straight drive**.

We did about **10 test runs** while comparing versions, and the clearest improvement was the change from **steering V1 to V2**.

## Our Main Mechanical Lesson

The most important lesson for us was that **repeatability mattered more than complexity**.

The final robot is not better because it is more complicated. It is better because it is:

- easier to turn,
- more precise,
- less resistant mechanically,
- and more stable in repeated runs.
