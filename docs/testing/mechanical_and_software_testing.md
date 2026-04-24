# Mechanical And Software Testing

We did not treat mechanics and software as separate worlds. Most of the time, when one side changed, the other side had to be retuned.

That is why we tested the robot as one connected system.

## What We Compared

The main comparison areas were:

- `250 rpm`, `300 rpm`, and `1000 rpm` `N20` motors;
- steering `Version 1`, `Version 2`, and `Version 3`;
- earlier front wheels versus silicone front wheels;
- earlier differential solution versus the final `LEGO` differential;
- sensor mounting and wiring stability.

## What Counted As A Better Version

A version was better if it improved the robot as a whole, not just one isolated metric.

The practical things we cared about were:

- less drift on straight driving;
- cleaner `90` degree turns;
- lower steering load;
- smoother recovery after turns;
- fewer repeated failures in the same scenario;
- easier tuning after the change.

## Test Method

For major comparisons, we reused the same pattern:

1. change one part or one subsystem;
2. run the same scenario several times;
3. watch whether the same weakness repeats;
4. compare the result with the previous version;
5. keep the version that improves repeatability, not just one lucky run.

For steering comparisons, we used about `10` practical runs while deciding between the main versions.

## Main Mechanical Results

### Motor

The `300 rpm` motor was too slow. The `1000 rpm` motor was faster but gave too little useful torque. The `250 rpm` motor gave the best overall balance, so it became the final choice.

### Steering

The jump from steering `V1` to `V2` was one of the clearest improvements of the whole season. Reducing the bad lever arm lowered servo load and made the steering much more repeatable.

### Front Wheels

Silicone front wheels improved real steering effect because the front axle stopped wasting as much motion in slip.

### Differential

The `LEGO` differential was more stable than the earlier metal solution and gave smoother cornering with less binding.

## Comparison Table

| Comparison area | Earlier version | Final version | Practical result |
| --- | --- | --- | --- |
| motor choice | `300 rpm` or `1000 rpm` | `250 rpm` N20 | better balance of speed and torque |
| steering geometry | `V1` with larger lever arm | `V2/V3` with lower load | steering became easier and more repeatable |
| front wheel material | earlier wheels with more slip | silicone front wheels | stronger real steering effect |
| rear differential | earlier metal solution | `LEGO` differential | smoother cornering and less binding |
| sensor mounting | less rigid layout | cleaner, more rigid layout | more stable behavior between runs |

### Differential Comparison

![Metal differential version](../design/images/metal-differential.jpg)

Earlier version with the metal differential.

![LEGO differential version](../design/images/lego-differential.png)

Final version with the `LEGO` differential.

## Software Checks

On the software side, we mainly watched what the robot actually did on the track:

- did it wobble;
- did it hold its heading;
- did it stay near the intended wall offset;
- did it overshoot after correction;
- were the turn transitions clean;
- did it recover cleanly after a turn.

## Software Tuning Results

| Test case | Before change | After change | Sample size | Why it mattered |
| --- | --- | --- | --- | --- |
| Straight corridor drift after `2 m` | `9 cm` | `4 cm` | `10` runs | Better lane stability |
| Corner overshoot | `14 cm` | `6 cm` | `10` runs | Less wall contact risk |
| Successful `3`-lap runs | `6/10` | `9/10` | `10` runs | Higher consistency |
| Recovery after obstacle correction | `1.2 s` | `0.6 s` | `10` runs | Faster return to target line |

After changing steering geometry and retuning the controller, our robot became more stable in straight sections and less aggressive in corners.

The biggest improvement was consistency: successful `3`-lap completion increased from `60%` to `90%` across `10` runs.

This confirmed that the update improved both control quality and reliability.

## Why The Two Sides Were Linked

The controller could only be tuned properly if the mechanics were predictable.

For example:

- steering friction made the controller look weaker than it really was;
- front-wheel slip reduced the effect of a correct steering command;
- better symmetry and grip made the tuning much easier.

That is why we never treated testing as only mechanical or only software. The robot improved because both sides were adjusted together.

## Short Conclusion

The final version was selected because it was:

- easier to control;
- more repeatable;
- smoother in turns;
- less sensitive to the same repeated failures.

That mattered more than any single impressive part on its own.
