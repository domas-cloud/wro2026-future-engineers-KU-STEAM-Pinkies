# Valdymo Algoritmai

## Architektūra

Valdymo logika turi atskirti suvokimą nuo vykdymo:

- `Raspberry Pi Zero` fiksuoja ir perduoda `OV5647` kamerų duomenis;
- `ESP32` interpretuoja kameros ir jutiklių informaciją bei valdo techninę įrangą;
- `ESP32` gauna valdymo komandas ir vykdo techninę įrangą.

## Ryšys Su Senu Roboto Modeliu

Pagrindinė algoritmo idėja perimta iš ankstesnio KU STEAM Pinkies roboto: jutiklių nuskaitymas, paklaidos skaičiavimas, korekcinis valdymas, vairo/variklio išėjimas ir kliūčių logika.
Skirtumas tas, kad ankstesnėje versijoje daugiau sprendimų buvo siejama su `Arduino Mega` ir `Raspberry Pi Zero 2`, o naujame robote visa skaičiavimo dalis perkelta į `ESP32`, o `Raspberry Pi Zero` paliktas kamerai ir kameriniam priekinio atstumo įvertinimui.

## Pagrindinės Valdymo Atsakomybės

- iš kamerų įvesties išskirti juostos padėtį arba juostos paklaidą;
- kamerų įvestį sujungti su `BNO085` ir 2 `VL53L5CX` pagalbiniais signalais;
- esamą paklaidą paversti vairo komanda;
- riboti vairo pokyčius, kad robotas nesiūbuotų;
- mažinti važiavimo išėjimą, kai pasitikėjimas mažas arba robotas yra atsigavimo būsenoje.

## Algoritmų Tipai

- važiavimo juosta valdymas;
- vairo korekcija;
- reakcija į kliūtis;
- saugos perrašymai, kai jutiklio įvestis atrodo neteisinga.

## Pageidaujamas Elgsenos Rinkinys

- pirmiausia kamerų įvestis, kad būtų matoma juostos geometrija ir priekyje esantis atstumas;
- inercinė pagalba krypties stabilumui;
- 2 matriciniai ToF moduliai kliūties patvirtinimui ir energijos taupymui;
- būsenų mašinos logika sprendimui, ar sekti juostą, apvažiuoti, sulėtinti ar sustoti.

## Dokumentacijos Pastabos

Jei komanda vėliau pasirinks kitą valdymo metodą, dokumente reikia paaiškinti, kodėl tas pasirinkimas buvo geresnis už ankstesnį ir kokie įrodymai lėmė pokytį.

## Dokumentacijos Reikalavimas

Paaiškink algoritmo pasirinkimą, kodėl jis tinka robotui, ir kokius gedimo atvejus jis turi valdyti.
