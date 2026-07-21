# Schemes And PCB Evidence

## Version status

This folder currently contains **Hardware V1 schematic and perfboard evidence**. The previous folder description was archived at [`archivo/hardware-v1-esp32-250rpm/schemes/README.md`](../archivo/hardware-v1-esp32-250rpm/schemes/README.md).

The active Hardware V2 custom PCB has not yet produced a final schematic, PCB layout or manufacturing package.

## Existing Hardware V1 evidence

- [`Wro_customPCBs.pdf`](Wro_customPCBs.pdf) — previous electrical drawing;
- [`images/schematic-overview.png`](images/schematic-overview.png) — preview of the previous system;
- [`images/sensor-bus-detail.png`](images/sensor-bus-detail.png) — previous sensor-bus view;
- [`images/power-regulator-reference.jpg`](images/power-regulator-reference.jpg) — previous regulator reference;
- [`images/perfboard-wiring.jpg`](images/perfboard-wiring.jpg) — real Hardware V1 perfboard assembly;
- [`wiring_overview.md`](wiring_overview.md) — active Hardware V2 block-level requirements;
- [`custom_pcb_description.md`](custom_pcb_description.md) — active Hardware V2 schematic/PCB requirements.

The Hardware V1 images may show Raspberry Pi Zero, `L298N`, `2x 18650` and the older integration. Those parts are not the active Hardware V2 target.

## Hardware V2 files still required

When the custom PCB is designed and built, this folder should contain:

1. editable schematic source;
2. exported schematic PDF;
3. editable PCB source;
4. board layout screenshots;
5. Gerber and drill files;
6. assembly drawing;
7. BOM with exact part numbers;
8. complete connector and GPIO map;
9. PCB top and bottom photographs;
10. revision and bring-up notes.

Do not add empty placeholder design files. Add each item only when the real artifact exists.

## Current active references

- [`Hardware V2 custom PCB plan`](../docs/hardware/hardware_v2_custom_pcb_plan.md)
- [`Hardware V2 decision register`](../docs/hardware/hardware_v2_decision_register.md)
- [`Electronics overview`](../docs/hardware/electronics_overview.md)
- [`Hardware V2 BOM`](../docs/hardware/parts_list.md)
- [`PCB and wiring status`](../docs/hardware/pcb_wiring_diagrams.md)
