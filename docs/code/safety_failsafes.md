# Safety And Failsafes

## Purpose

The purpose of our safety system is to prevent the robot from continuing unsafe or unreliable motion when sensor input, communication, or control quality becomes invalid.

In a competition robot, the goal is not only to drive fast.  
The robot must also react safely when something goes wrong.

For this reason, our software includes failsafe logic that can:
- reduce speed;
- suppress invalid control output;
- stop the robot;
- return steering toward a safe position;
- enter a recovery state.

---

## Safety Philosophy

Our safety logic follows four priorities:

1. protect the hardware;
2. prevent uncontrolled robot movement;
3. avoid using invalid or stale sensor information;
4. return to normal driving only when the system becomes reliable again.

This means safety logic has higher priority than ideal navigation.

---

## Failure Types We Considered

We considered several important failure modes during development.

### 1. Camera or vision interruption
If the Raspberry Pi Zero stops delivering fresh vision results, the ESP32 must not continue using old commands as if they were still valid.

### 2. Sensor invalidity
If the IMU or ToF readings become unstable, inconsistent, or clearly unrealistic, they should not be trusted normally.

### 3. Communication loss
If the processed camera result is not received correctly, the robot must not continue driving with missing control input.

### 4. Robot alignment failure
If the robot gets too close to a wall or enters a position where normal lane following is no longer reliable, the robot should switch to a safer mode.

### 5. Startup or initialisation risk
The robot must not apply unsafe motor output before the control system is ready.

---

## Main Failsafe Actions

Depending on the failure type, the robot can apply one or more of the following actions:

- reduce motor speed;
- hold or stop forward motion;
- return steering toward centre;
- ignore invalid sensor input;
- switch from normal driving to a cautious state;
- enter a short recovery action;
- wait until valid data is available again.

These actions are chosen to make the robot predictable rather than aggressive in uncertain situations.

---

## Specific Failsafe Cases

## Camera Data Timeout
If the ESP32 does not receive fresh camera-based navigation data within the allowed time window, it must assume that the previous command is no longer safe.

In that case the robot should:
- stop using the old vision command;
- reduce or stop drive output;
- move steering toward a neutral position;
- wait for valid input or enter a recovery-safe state.

This prevents the robot from continuing with stale visual information.

## IMU Invalidity
If the `BNO085` produces invalid data, heading-based support must be reduced or disabled.

In that case the robot should:
- ignore the invalid heading correction;
- continue only with the remaining reliable inputs if possible;
- avoid strong corrections based on bad heading information.

This prevents the robot from applying false stabilisation commands.

## ToF Instability
If the 2 `VL53L5CX` matrix ToF sensors begin to produce unstable or obviously inconsistent short-range data, the robot should switch to more cautious behaviour.

In that case the robot should:
- reduce speed;
- avoid trusting aggressive close-range correction;
- prefer safer motion or a stopped state until readings stabilise.

This is important because false short-range readings can create unnecessary steering or collision risk.

## Communication Loss Between Pi And ESP32
If the camera result link between the Raspberry Pi Zero and ESP32 fails, the ESP32 must not keep driving as if navigation were still valid.

The robot should:
- enter no-command mode;
- suppress forward drive;
- keep steering in a safe direction;
- wait for valid messages again.

## Startup Safety
During startup, the robot must not produce unexpected motion before all required parts of the control loop are ready.

The startup safety rule is:
- no uncontrolled motor output before the system is ready;
- no unsafe steering movement before control initialisation is complete.

---

## Recovery State

Not every problem should end immediately in a hard stop.  
Some situations can be corrected safely.

For this reason, our software includes a recovery concept.

Recovery may include:
- stopping briefly;
- reversing slightly;
- reducing speed;
- re-centering steering;
- re-entering lane following only after the robot is in a better position.

We included this because track testing showed that some unstable situations can be corrected safely instead of immediately ending useful movement.

---

## Safety Triggers And Responses

The logic can be summarised like this:

- **fresh input available + robot stable** → normal driving;
- **input uncertain** → slower or limited driving;
- **input invalid or missing** → safe stop / no-command mode;
- **robot trapped or badly aligned** → recovery behaviour;
- **system not ready** → no drive output.

This structure helps keep the robot behaviour understandable and reproducible.

---

## Testing Expectation

Each failsafe should be tested at least once in a controlled condition.

Examples of useful tests:
- disconnect or pause the camera-data stream;
- simulate invalid sensor values;
- place the robot close to a wall and check whether safer behaviour activates;
- verify that the robot does not move dangerously during startup.

The purpose of these tests is not only software validation, but also documentation quality.  
A tested failsafe is much stronger evidence than a theoretical failsafe.

---

## Engineering Benefit

Failsafes improved our robot in several ways:

- better protection from bad sensor states;
- fewer dangerous or meaningless control actions;
- more predictable behaviour;
- easier debugging during development;
- more confidence during repeated runs.

In practice, a robot with clear fallback behaviour is more reliable than a robot that only works when every input is perfect.

---

## Summary

Our safety logic is designed to answer one question:

**What should the robot do when the normal control assumptions are no longer true?**

Our answer is:
- trust only fresh and valid data;
- reduce aggression when uncertainty increases;
- stop or recover when control becomes unreliable;
- return to normal driving only when the system is healthy again.

This makes the robot safer, more stable, and more robust for competition use.
