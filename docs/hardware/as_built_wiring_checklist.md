# Hardware V2 As-Built Wiring Checklist

## Status

Hardware V2 has not yet been assembled, so this is a completion checklist rather than a claim that the wiring already exists. The Hardware V1 checklist was archived at [`archivo/hardware-v1-esp32-250rpm/docs/hardware/as_built_wiring_checklist.md`](../../archivo/hardware-v1-esp32-250rpm/docs/hardware/as_built_wiring_checklist.md).

## Build identification

| Field | Value |
|---|---|
| PCB revision | `TBD` |
| schematic revision | `TBD` |
| firmware commit | `TBD` |
| LiPo specification | `TBD` |
| motor | `TBD` |
| motor driver | `TBD` |
| assembly date | `TBD` |

## Power path checks

- [ ] battery chemistry, cell count and maximum charged voltage match the schematic;
- [ ] connector polarity and pin-1 markings are documented;
- [ ] main switch and protection device are fitted;
- [ ] reverse-polarity protection is verified;
- [ ] every regulator output is measured before connecting loads;
- [ ] ESP32, PixyCam, sensors, servo and motor rails are labelled;
- [ ] motor and servo current do not return through sensitive sensor-ground paths;
- [ ] rail voltage is measured during motor launch and steering movement;
- [ ] no ESP32 reset or sensor dropout occurs during the worst observed transient.

## Controller and connector checks

- [ ] programming connector works;
- [ ] boot and reset access works;
- [ ] physical start button works on the documented GPIO;
- [ ] status outputs match the firmware;
- [ ] PixyCam connector orientation is keyed or clearly marked;
- [ ] front, left and right ToF connectors cannot be confused;
- [ ] motor and servo connectors have strain relief;
- [ ] complete pin map matches the schematic and source code.

## Sensor and camera checks

- [ ] `BNO085` starts repeatedly and reports stable yaw while stationary;
- [ ] front `VL53L1X` starts at the documented address;
- [ ] left `VL53L4CD` starts at the documented address;
- [ ] right `VL53L4CD` starts at the documented address;
- [ ] ten full power cycles complete without address conflict;
- [ ] PixyCam SPI initializes repeatedly;
- [ ] red and green signatures are documented;
- [ ] camera data remains stable with motor and servo active;
- [ ] stale or missing camera data produces the documented fallback.

## Motor and steering checks

- [ ] motor direction agrees with the firmware command;
- [ ] PWM sweep is tested without driver fault;
- [ ] launch and stall current are recorded safely;
- [ ] motor-driver temperature is recorded after repeated load;
- [ ] MG90S centres without heavy buzzing;
- [ ] servo rail remains within the required voltage range;
- [ ] steering limits do not force the mechanism against a hard stop.

## Evidence to attach

- PCB top and bottom photos;
- labelled connector photo;
- measured power table;
- thermal table;
- ten-start sensor table;
- PixyCam detection table;
- schematic and PCB revision links;
- firmware commit;
- signed review note stating that hardware, text and code match.

Until these items are completed with real measurements, this file remains a preparation checklist.
