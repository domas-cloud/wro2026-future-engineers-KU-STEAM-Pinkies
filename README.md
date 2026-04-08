# KU STEAM Pinkies - WRO 2026 Future Engineers

Autonominio Future Engineers roboto dokumentacija.

## Santrauka

- Pavara: `MG90S` vairavimo servomechanizmas, `N20` variklis, `L298N H-bridge`.
- Skaičiavimai: `Raspberry Pi Zero` tik kameros duomenims, `ESP32` visiems skaičiavimams ir valdymui.
- Jutikliai: `BNO085 9-DOF IMU`, 2 `VL53L5CX` matriciniai ToF moduliai, kamera.
- Maitinimas: `2x 18650 Li-ion` akumuliatorių paketas su reguliuotomis loginėmis šakomis.

## Komanda

KU STEAM Pinkies.

## Robotas

Tai automobilio tipo robotas su servo vairavimu ir galiniu varikliu.
Dokumentacijoje daugiausia dėmesio skiriama mechanikai, maitinimo ir jutiklių architektūrai, programinės įrangos elgsenai, testavimui ir atkuriamumui.

## Licencija

Šiame repozitoriume naudojama [MIT licencija](LICENSE).

## Judėjimo Valdymas

- [Kėbulo konstrukcija](docs/design/chassis_design.md)
- [Vairo sistema](docs/design/steering_system.md)
- [Ratų tvirtinimas ir pakabos sprendimai](docs/design/wheel_mounting_suspension.md)
- [CAD modeliai](docs/design/cad_models.md)
- [Dalių sąrašas](docs/hardware/parts_list.md)

## Surinkimo Dokumentacija

- [Dokumentacijos indeksas](docs/README.md)
- [Idėjų generavimas](docs/brainstorming/problem_identification.md)
- [Techninė įranga](docs/hardware/electronics_overview.md)
- [Programinė įranga](docs/code/code_architecture.md)

## Versijos Pastabos

- [Pakeitimų žurnalas](CHANGELOG.md)

## Kaip Skaityti Repo

1. Pradėk nuo santraukos ir roboto skyriaus.
2. Perskaityk judėjimo ir surinkimo dokumentaciją, kad suprastum techninius pasirinkimus.
3. Perskaityk programinės įrangos skyrių, kad suprastum elgsenos logiką.
