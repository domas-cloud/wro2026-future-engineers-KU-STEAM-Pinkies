# Raspberry Pi Zero Perception Runtime

This folder contains the published perception-side process for the `Raspberry Pi Zero`.

## Files

- [main.py](main.py): reads perception input and transmits compact controller packets
- [requirements.txt](requirements.txt): Python dependencies
- [protocol.md](protocol.md): packet format and timeout behavior

## Runtime Role

The Pi-side process does not drive motors or servos directly. Its job is to:

- estimate the preferred lane offset;
- choose the obstacle-pass side at a higher level;
- send a compact packet to the `ESP32`;
- fall back to a neutral command if no fresh perception result is available.

## Run

1. install dependencies from `requirements.txt`
2. connect the Pi UART to the `ESP32`
3. run `python main.py --port /dev/serial0`

For development without a camera, `main.py` can also run in mock mode and emit deterministic packets for interface testing.
