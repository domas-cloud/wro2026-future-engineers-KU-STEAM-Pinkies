# Software redesign notes

This folder is where we kept the software that no longer matches the active V2 hardware and where we can try ideas before they become part of the real robot program.

- `previous-source/` is the source tree we had before the 12 August reset.
- `previous-docs/` contains the corresponding software documentation.

The useful ideas from the old program are not being thrown away. We will probably keep some form of heading + side-distance control, explicit driving states and sensible behaviour when camera data is missing. What changes is that these ideas now have to be rebuilt around PixyCam SPI, the custom PCB, the new motor driver and the final GPIO map.

Experiments can live here while they are uncertain. Once something works on the physical robot, the tested implementation belongs in `src/` and its explanation belongs in `docs/code/`.
