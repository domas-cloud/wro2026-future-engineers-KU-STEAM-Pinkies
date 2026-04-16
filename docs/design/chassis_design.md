# Chassis Design

## Dimensions

The robot has approximate outer dimensions of:

- **Length:** 21 cm
- **Width:** 10 cm
- **Height:** 8 cm

These compact dimensions were chosen to keep the robot small, agile, and easier to control on the WRO field.

## Why We Changed the Mechanical Concept

Our previous robot was larger and used a more complex steering system. Although that design was more advanced mechanically, in practice it created more friction, more resistance, and less repeatable steering behaviour.

For the new robot, we intentionally moved to a simpler and more compact mechanical concept. The goal was not to make the system more complicated, but to make it work better on the field. The final design gave lower friction, better repeatability, and easier control.

This was one of the main engineering trade-offs in our project: we moved away from a larger and more complex system and selected a simpler mechanical solution that performed better in practice.

## Chassis Philosophy

The chassis was designed to support stable steering and repeatable motion.

A robot may have good software, but if the mechanical structure flexes, sticks, or behaves asymmetrically, the driving result becomes unstable. For this reason, our chassis design focused on:

- structural stiffness in important load-bearing areas,
- compact packaging,
- predictable wheel alignment,
- stable component mounting,
- and reduced unnecessary friction in the steering-related parts.

The robot is intentionally small. A compact platform is easier to package inside the WRO size limits and can also reduce unnecessary rotational inertia. At the same time, compact packaging is more difficult, so we had to carefully arrange the drivetrain, batteries, electronics, and steering system.

## Base Material

The main chassis structure is made from **plywood**.

We selected plywood because it is rigid, practical to machine, and suitable for a custom geometry. It allowed us to build a compact structure around the steering system, drivetrain, electronics, and sensors while maintaining enough stiffness for reliable operation.

The purpose was not to make the robot visually complex, but to make it mechanically reliable.

## Drive Layout

The robot uses a **rear-wheel-drive layout** with **front-wheel steering**.

The rear axle is the driven axle, while the front axle is used only for steering.

The rear wheel diameter is **4.5 cm**, while the front wheel diameter is **2.5 cm**.

The motor drives a gear, and that gear drives the **rear mechanical differential**.

## Motor Selection

The drive motor is a **6 V N20 motor rated at 600 rpm**.

We tested **three different motors** before selecting the final one.

After comparing them in practice, we chose the **N20 motor** because it matched our robot best in terms of size and performance. Other options were less suitable for our platform:

- some motors had RPM that was too low,
- faster options did not provide enough torque,
- and some alternatives were physically less suitable for our compact robot.

The N20 gave the best balance between compact size, usable speed, and sufficient torque, so it was the most suitable solution for our final drivetrain.

## Speed and Torque Considerations

During motor selection, we considered the trade-off between speed and controllability.

A motor with higher RPM could in theory make the robot faster, but if torque is too low, the robot becomes less reliable during turning and correction. On the other hand, a motor with too little RPM reduces performance and makes the robot unnecessarily slow.

Our final choice was therefore based on balance, not on maximum speed. We selected the motor that gave enough speed for competitive driving while still maintaining enough torque for stable and predictable behaviour.

## Why We Used a Differential

The differential in the rear axle is a **LEGO mechanical differential**.

We kept a mechanical differential because it improves cornering behaviour. When the robot turns, the inner and outer rear wheels do not travel the same distance. Without a differential, both wheels are forced to rotate too similarly, which increases turning resistance.

In earlier practical testing, we observed that without an effective differential the robot had worse turning behaviour. The robot experienced more resistance in corners, which increased mechanical stress and made driving less smooth and less predictable.

Using the differential reduced those problems and supported smoother cornering.

## Steering and Chassis Interaction

The chassis and steering system were designed together, not as separate parts.

The steering needed low friction and stable geometry, while the chassis needed to hold that geometry consistently. A flexible or imprecise front assembly would directly reduce straight-driving accuracy.

That is why the later steering version used bearings and a more precise support structure. The front of the chassis had to support repeatable steering motion, not only hold the wheels in place.

## Weight Distribution

We intentionally distributed mass across the robot:

- the **electronics are placed at the rear**,
- the **batteries are placed at the front**.

This was done to keep the weight distribution more even across the chassis. Balanced weight distribution helps the robot remain more stable during forward motion and reduces unwanted imbalance between the front and rear of the vehicle.

## Wheel Choice

The front and rear wheels were designed for different purposes.

### Front Wheels

The front wheels are used only for steering. For this reason, we selected **custom silicone wheels** on the front axle.

The main reason was **better grip**.

Better front grip improved:

- steering accuracy,
- turning consistency,
- control quality,
- and reduction of wasted motion caused by slipping.

This was important because the steering system is only useful if the front wheels can actually follow the commanded direction on the field surface.

### Rear Wheels

The rear axle uses **LEGO wheels** connected to the differential.

This kept the drivetrain reliable and mechanically simple.

## Main Mechanical Development Goal

The main mechanical goal throughout development was to create the conditions for **stable straight driving**.

To achieve this, we improved several areas over time:

- reduced steering lever-arm load,
- reduced friction in the steering mechanism,
- improved grip with custom wheels,
- improved precision by using bearings,
- kept left and right steering motion as equal as possible.

These changes made the final version more competition-ready than the earlier prototypes.

## Mechanical Iteration Summary

| Version | Main characteristic | Problem | Result |
|--------|----------------------|---------|--------|
| Previous robot | Larger chassis, more complex steering | More friction, more resistance, less repeatable steering | Worked, but was mechanically less efficient |
| Early new robot | Simpler compact concept | Needed refinement of component choices and geometry | Better foundation for stable driving |
| Final robot | Compact chassis, simpler low-friction steering, balanced motor choice, improved front grip | Balanced size, torque, speed, and steering reliability | Selected as final design |

## Final Mechanical Conclusion

The most important lesson from our mechanical development was that a simpler system can outperform a more complex one if it has lower friction and better repeatability.

Our final robot was chosen not because it was the most complicated design, but because it delivered the most reliable real-world performance.

The final combination of:

- a more compact chassis,
- a simpler and lower-friction steering system,
- a well-matched N20 motor,
- a rear mechanical differential,
- and improved front-wheel grip

gave us the best overall mechanical result.
