# Valdymo Algoritmai

## Architektūra

Valdymo logika turi atskirti suvokimą nuo vykdymo:

- `Raspberry Pi Zero` fiksuoja ir perduoda kamerų duomenis;
- `ESP32` interpretuoja kameros ir jutiklių informaciją bei valdo techninę įrangą;
- `ESP32` gauna valdymo komandas ir vykdo techninę įrangą.

## Pagrindinės Valdymo Atsakomybės

- iš kamerų įvesties išskirti juostos padėtį arba juostos paklaidą;
- kamerų įvestį sujungti su `BNO085` ir `VL53L5CX` pagalbiniais signalais;
- esamą paklaidą paversti vairo komanda;
- riboti vairo pokyčius, kad robotas nesiūbuotų;
- mažinti važiavimo išėjimą, kai pasitikėjimas mažas arba robotas yra atsigavimo būsenoje.

## Algoritmų Tipai

- važiavimo juosta valdymas;
- vairo korekcija;
- reakcija į kliūtis;
- saugos perrašymai, kai jutiklio įvestis atrodo neteisinga.

## Pageidaujamas Elgsenos Rinkinys

- pirmiausia kamerų įvestis, kad būtų matoma juostos geometrija;
- inercinė pagalba krypties stabilumui;
- vietinis atstumo matavimas kliūties patvirtinimui;
- būsenų mašinos logika sprendimui, ar sekti juostą, apvažiuoti, sulėtinti ar sustoti.

## Dokumentacijos Pastabos

Jei komanda vėliau pasirinks kitą valdymo metodą, dokumente reikia paaiškinti, kodėl tas pasirinkimas buvo geresnis už ankstesnį ir kokie įrodymai lėmė pokytį.

## Dokumentacijos Reikalavimas

Paaiškink algoritmo pasirinkimą, kodėl jis tinka robotui, ir kokius gedimo atvejus jis turi valdyti.
