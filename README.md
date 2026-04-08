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

## Vaidavimo Vaizdo Įrašas

- [Varžybinio video pastabos](video/video.md)

## Judėjimo Valdymas

- [Kėbulo konstrukcija](docs/design/chassis_design.md)
- [Vairo sistema](docs/design/steering_system.md)
- [Pavarų santykiai ir mechanika](docs/design/gear_ratios_mechanics.md)
- [Ratų tvirtinimas ir pakabos sprendimai](docs/design/wheel_mounting_suspension.md)
- [CAD modeliai](docs/design/cad_models.md)
- [Dalių sąrašas](docs/hardware/parts_list.md)

## Surinkimo Dokumentacija

- [Dokumentacijos indeksas](docs/README.md)
- [Idėjų generavimas](docs/brainstorming/problem_identification.md)
- [Planavimas](docs/planning/timeline_deadlines.md)
- [Techninė įranga](docs/hardware/electronics_overview.md)
- [Maitinimas ir laidai](docs/power_management/power_distribution.md)
- [Programinė įranga](docs/code/code_architecture.md)
- [Testavimas](docs/testing/test_log_template.md)
- [Vertinimas](docs/evaluation/reproducibility_checklist.md)
- [Problemos ir sprendimai](docs/Encountered_Problems_and_Solutions/solutions_fix_log.md)

## Versijos Pastabos

- [Pakeitimų žurnalas](CHANGELOG.md)

## Artefaktų Aplankai

- `models/` - CAD eksportai ir STL failai.
- `schemes/` - laidų ir elektromechaninės schemos.
- `src/` - valdymo programinė įranga.
- `t-photos/` - komandos nuotraukos.
- `v-photos/` - roboto nuotraukos.
- `video/` - vaizdo įrašų nuorodos ir pastabos.
- `other/` - papildomi failai, kurie netinka kitur.

## Kaip Skaityti Repo

1. Pradėk nuo santraukos ir roboto skyriaus.
2. Perskaityk judėjimo ir surinkimo dokumentaciją, kad suprastum techninius pasirinkimus.
3. Perskaityk programinės įrangos ir testavimo skyrius, kad suprastum elgseną ir validaciją.
4. Naudok artefaktų aplankus, kad tekstą sulygintum su tikrais failais.
