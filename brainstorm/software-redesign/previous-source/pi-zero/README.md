# Raspberry Pi Zero Perception Runtime

This folder contains the published perception-side process for the `Raspberry Pi Zero`.

## Files

- [main.py](main.py): detects red/green traffic pillars and sends compact controller packets
- [requirements.txt](requirements.txt): Python dependencies
- [protocol.md](protocol.md): packet format and timeout behavior
- [scripts/camera.py](scripts/camera.py): Pi camera / USB camera wrapper
- [scripts/pillar.py](scripts/pillar.py): detected-pillar data model

## Runtime Role

The Pi-side process does not drive motors or servos directly. Its job is to:

- detect red and green traffic pillars with HSV thresholding;
- choose the obstacle-pass side (`GREEN -> LEFT`, `RED -> RIGHT`);
- estimate the pillar offset from the camera center;
- send a compact packet to the `ESP32`;
- fall back to a neutral command if no fresh perception result is available.

## Install

```bash
python3 -m venv .venv
. .venv/bin/activate
pip install -r requirements.txt
```

On Raspberry Pi OS, `picamera2` is normally installed through the system package manager:

```bash
sudo apt install -y python3-picamera2
```

## Run On Robot

```bash
python3 main.py --serial-port /dev/ttyS0 --baud 9600
```

## Interface Test Without Camera

```bash
python3 main.py --mock --serial-port /dev/ttyS0 --baud 9600
```

Mock mode sends deterministic `TRACK`, `LEFT`, and `RIGHT` packets so the UART link and ESP32 parser can be tested before the camera is mounted.
