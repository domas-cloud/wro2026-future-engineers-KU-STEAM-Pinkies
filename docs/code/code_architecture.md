# Code Architecture

## Separation Of Subsystems

The robot uses a split software architecture with two main computing layers:

- the **Raspberry Pi Zero** handles the **camera input and the vision algorithm**;
- the **ESP32** handles **control, actuator output, and fast robot behavior**.

This division was chosen because the Raspberry Pi Zero is better suited for camera-related processing, while the ESP32 is more suitable for fast control tasks and easier actuator handling.

## Functional Split

The Raspberry Pi Zero does not only capture frames.  
It also processes the camera information using the vision algorithm and sends the **algorithm result** to the ESP32.

The ESP32 then uses that result together with the other onboard sensor information to control the robot.

In practice:

- the **Pi Zero** is responsible for camera-based observation and algorithm output;
- the **ESP32** is responsible for steering, motor commands, state handling, and fast reaction logic.

## Module Map

### Raspberry Pi Zero side

- `camera`  
  captures the image from the front camera;

- `vision_algorithm`  
  processes the camera image and extracts the useful result needed for navigation;

- `communication_tx`  
  sends the camera-algorithm result to the ESP32.

### ESP32 side

- `sensing`  
  reads the `BNO085` and the 2 `VL53L5CX` sensors;

- `control`  
  calculates steering and drive output based on the Raspberry result and local sensor data;

- `state_logic`  
  selects the current robot behavior;

- `safety`  
  handles uncertainty, invalid input, and safe reaction behavior;

- `actuation`  
  drives the `MG90` servo and the `N20` motor through the control chain.

## Interface Contract

The communication between the Raspberry Pi Zero and ESP32 is designed to transfer the **result of the camera algorithm**, not the entire raw camera stream.

The transferred message can include:

- processed camera result;
- navigation-related output from the vision algorithm;
- frame status or validity status;
- timing or sequence information if needed.

This makes the interface lighter and more useful for control than sending full image data.

## Data Flow

1. The front camera captures the scene.
2. The Raspberry Pi Zero runs the vision algorithm on the camera image.
3. The Raspberry Pi Zero sends the processed result to the ESP32.
4. The ESP32 combines that result with IMU and ToF information.
5. The ESP32 selects the robot behavior state.
6. The ESP32 generates steering and drive commands.
7. The ESP32 sends output to the `MG90` steering servo and the motor control path.

## Why This Structure

We chose this structure because it separates perception from control.

The Raspberry Pi Zero handles the camera-side work, while the ESP32 focuses on fast control and physical robot behavior.  
This reduces the need for the ESP32 to process full camera data directly and keeps the control side simpler.

It also improves clarity in the documentation because each board has a clear engineering role.

## Startup Logic

The robot startup sequence should ensure that both compute layers are ready before motion is enabled.

A typical startup flow is:

- initialize Raspberry Pi Zero;
- initialize ESP32;
- confirm camera readiness;
- confirm algorithm output from Raspberry;
- confirm IMU and ToF readiness on ESP32;
- center the servo;
- enable motor output only after the full control chain is ready.

## Fault Handling

The system must be able to react safely if any important data source becomes invalid.

Examples:

- if the Raspberry Pi Zero does not provide a valid algorithm result, the ESP32 should not continue normal driving blindly;
- if IMU or ToF data becomes unreliable, the ESP32 should choose a safer behavior;
- if startup is incomplete, the robot should not enable drive output.

This supports safer and more predictable autonomous behavior.
