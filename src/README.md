# Valdymo Programinė Įranga

Šiame aplanke saugomas roboto valdymo kodas.
Aktyvus projekto kodas turi būti laikomas šiame repozitoriume, ne išoriniame `src` submodule.

## Kodo Struktūra

- `perception/` kameros ir jutiklių duomenų gavimui `Raspberry Pi Zero`;
- `control/` vairavimui, važiavimui ir būsenų logikai;
- `communication/` žinutėms tarp Pi Zero ir `ESP32`;
- `safety/` saugaus stabdymo ir klaidų valdymo logikai;
- `tests/` programinės įrangos validacijai.

## Atsakomybės

- kameros vaizdo gavimas `Raspberry Pi Zero` pusėje;
- `BNO085` ir 2 `VL53L5CX` matricinių ToF modulių duomenų naudojimas `ESP32` pusėje;
- komandų ir kameros būsenos perdavimas į `ESP32`;
- `MG90S` vairavimo valdymas ir `N20` variklio išėjimas `ESP32` pusėje.
