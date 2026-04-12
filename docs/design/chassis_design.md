# Chassis Design

## Dimensions

The robot has approximate outer dimensions of:

- **Length:** 21 cm
- **Width:** 10 cm
- **Height:** 8 cm

These compact dimensions were chosen to keep the robot small, agile, and easier to control on the WRO field.

## Drive Layout

The robot uses a **rear-wheel-drive layout** with a **mechanical differential on the rear axle**.  
The rear wheel diameter is **4.5 cm**, while the front wheel diameter is **2.5 cm**.

The drive motor is a **6 V N20 motor rated at 300 rpm**.  
We selected this motor because it is **small and fast**, which matched our design goal of building a compact robot with enough speed while keeping the drivetrain simple.

The motor drives a gear, and that gear drives the **rear mechanical differential**.

## Why We Used a Differential

The differential in the rear axle is a **LEGO mechanical differential**.

We kept a mechanical differential because it improves cornering behavior.  
When the robot turns, the inner and outer rear wheels do not travel the same distance.  
Without a differential, both wheels are forced to rotate too similarly, which increases turning resistance.

In earlier practical testing, we observed that without an effective differential the robot had worse turning behavior.  
The robot experienced more resistance in corners, which increased mechanical stress and made driving less smooth and less predictable.

Using the differential reduced those problems and supported smoother cornering.

## Steering And Chassis Interaction

The chassis and steering system were designed together, not as separate parts.  
The steering needed low friction and stable geometry, while the chassis needed to hold that geometry consistently.

That is why the later steering version used bearings and a more precise support structure.  
A flexible or imprecise front assembly would directly reduce straight-driving accuracy.

## Weight Distribution

We intentionally distributed mass across the robot:

- the **electronics are placed at the rear**;
- the **batteries are placed at the front**.

This was done to keep the weight distribution more even across the chassis.  
Balanced weight distribution helps the robot remain more stable during forward motion and reduces unwanted imbalance between the front and rear of the vehicle.

## Wheel Choice

The final robot uses **custom silicone wheels**.  
These were chosen mainly because they provided better **grip**.

In practice, the custom wheels improved:

- traction;
- steering precision;
- consistency of movement;
- reduction of unnecessary mechanical load.

This was especially important because better grip also supported more accurate steering and reduced wasted motion caused by slipping.

## Main Mechanical Development Goal

The main mechanical goal throughout development was to create the conditions for **stable straight driving**.

To achieve this, we improved several areas over time:

- reduced steering lever-arm load;
- reduced friction in the steering mechanism;
- improved grip with custom wheels;
- improved precision by using bearings;
- kept left and right steering motion as equal as possible.

These changes made the final version more competition-ready than the earlier prototypes.
