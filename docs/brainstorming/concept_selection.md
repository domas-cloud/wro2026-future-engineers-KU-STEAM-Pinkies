# Steering System - Concept Selection

## Selected Concept

We selected a servo-steered front axle with a three-gear synchronizing mechanism.
The central gear receives steering input and transfers motion to the left and right gears so both sides move together.

## Why We Chose It

- The steering motion is symmetric, which helps keep the front axle aligned.
- Gear linkage gives us a compact way to convert servo motion into predictable wheel angle movement.
- The layout is easier to document and reproduce than a loose multi-link steering arrangement.
- The concept matches our goal of a car-like robot with controlled turns rather than skid steering.

## What The Mechanism Should Do

- Turn the front wheels with proportional response to the steering command.
- Keep left and right motion synchronized.
- Reduce visible backlash as much as possible.
- Support repeated testing and tuning without changing the whole chassis.

## Current Status

The concept is the basis for the mechanical and software documentation in this repository.
If later testing shows backlash, insufficient range, or poor return-to-center behavior, those issues should be recorded in the problems and testing sections instead of hidden.
