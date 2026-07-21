# Software Architecture

The software is easiest to understand as two layers:

- a perception layer on the `Raspberry Pi Zero`;
- a low-level control layer on the `ESP32`.

The repository now documents both the `ESP32` runtime and the Pi-side perception interface, with the `ESP32` remaining the clearest view of the real-time controller.

## What The `ESP32` Controller Does

The code in `src/src/main.cpp` is responsible for:

- startup and sensor initialization;
- reading yaw and distance sensors;
- waiting for the start button;
- holding heading and wall offset on straight sections;
- making hard turns at corners;
- stopping after the required edge count.

## Main Software Pieces

The low-level controller is built from a few simple pieces.

### Initialization

`setup()` starts serial, I2C, sensors, PWM, servo, lights, and motor control. If a critical sensor fails to initialize, the robot stays halted.

### Sensing

The active runtime inputs are:

- `frontSensor`
- `leftSensor`
- `rightSensor`
- `robotCompass`
- the start button

### State Logic

In normal use, the controller moves between a few simple states:

- idle before the run starts;
- straight control while following the current sector;
- hard turn when the front sensor reaches the turn threshold;
- finish when the run is complete.

### Control

The steering output combines:

- heading error;
- side-distance error;
- a damping term.

### Actuation

- `engine.drive(255)` drives the motor;
- `myservo.write(...)` sets the steering angle;
- LEDs show simple status information.

## How The Camera Layer Fits

The camera layer should sit above the low-level controller, not replace it.

Its job is to decide the preferred driving line:

- which side should be used around an obstacle;
- whether the reference line should shift left or right;
- what the controller should aim for in the current sector.

The `ESP32` still does the real-time part:

- sensor polling;
- steering calculation;
- hard-turn execution;
- final actuation.

The Pi-side interface is documented in:

- `src/pi-zero/protocol.md`
- `docs/code/vision_interface.md`

## Data Flow

The low-level loop is straightforward:

1. read button and yaw;
2. if not started, keep the motor stopped;
3. read front, left, and right distances;
4. if the front sensor says a corner is near, run the turn routine;
5. otherwise calculate steering from heading and side distance;
6. constrain the servo angle and write it.

If camera guidance is active, it modifies the reference line before step 5. The steering law itself does not need to be replaced.

## Why The Architecture Stayed Simple

We kept the controller simple on purpose:

- one clear low-level loop;
- direct sensor-to-actuator path;
- separate perception and control roles;
- no unnecessary control layers inside the `ESP32`.

That made the robot easier to tune and easier to explain.
