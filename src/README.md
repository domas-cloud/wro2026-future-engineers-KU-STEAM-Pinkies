# Valdymo Programinė Įranga

Šiame aplanke saugomas roboto valdymo kodas.

## Numatyta Struktūra

- `perception/` kameros ir jutiklių duomenų gavimui `Raspberry Pi Zero`;
- `control/` vairavimui, važiavimui ir būsenų logikai;
- `communication/` žinutėms tarp Pi Zero ir `ESP32`;
- `tests/` programinės įrangos validacijai, jei to reikia.

## Planuojamos Atsakomybės

- kameros vaizdo gavimas `Raspberry Pi Zero` pusėje;
- `BNO085` ir 2 `VL53L5CX` matricinių ToF modulių duomenų naudojimas `ESP32` pusėje;
- komandų siuntimas į `ESP32`, jei naudojamas atskiras ryšio sluoksnis;
- `MG90S` vairavimo valdymas ir `N20` variklio išėjimas `ESP32` pusėje.
