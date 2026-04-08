# Valdymo Programinė Įranga

Šiame aplanke saugomas roboto valdymo kodas ir viskas, ko reikia jam paleisti.

## Numatyta Struktūra

- `perception/` kameros ir jutiklių duomenų gavimui `Raspberry Pi Zero`;
- `control/` vairavimui, važiavimui ir būsenų logikai;
- `communication/` žinutėms tarp Pi Zero ir `ESP32`;
- `tests/` programinės įrangos validacijai, jei to reikia.

## Atsakomybės

- kameros interpretavimas ir kliūčių atpažinimas `Raspberry Pi Zero` pusėje;
- `BNO085` ir 2 `VL53L5CX` matricinių ToF modulių paruošimas tolimesniam naudojimui;
- komandų siuntimas į `ESP32` serijiniu ryšiu;
- `MG90S` vairavimo valdymas ir `N20` variklio išėjimas `ESP32` pusėje.

## Ko Tikimasi Dokumentacijoje

- aiškiai išvardyti modulius;
- paaiškinti, kurios dalys veikia Pi Zero, o kurios `ESP32`;
- komandų pavadinimus suderinti su `docs/code/message_protocol.md`;
- aprašyti paleidimo seką;
- nurodyti bet kokias prielaidas apie valdymo ciklo ar jutiklių atnaujinimo dažnį.
