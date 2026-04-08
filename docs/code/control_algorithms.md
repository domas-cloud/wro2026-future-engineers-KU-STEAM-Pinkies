# Valdymo Algoritmai

## Architektūra

Valdymo logika turi atskirti suvokimą nuo vykdymo:

- `Raspberry Pi Zero` fiksuoja ir perduoda `OV5647` kameros duomenis;
- `ESP32` interpretuoja kameros ir jutiklių informaciją bei valdo techninę įrangą;
- `ESP32` gauna valdymo komandas ir vykdo techninę įrangą.

## Ryšys Su Senu Roboto Modeliu

Pagrindinė algoritmo idėja perimta iš ankstesnio KU STEAM Pinkies roboto: paklaidos skaičiavimas, korekcinis valdymas, vairo ir variklio išėjimas bei kliūčių logika.
Skirtumas tas, kad naujame robote visa skaičiavimo dalis perkelta į `ESP32`, o `Raspberry Pi Zero` paliktas tik kameros vaizdo gavimui.

## Pagrindinės Valdymo Atsakomybės

- iš kamerų įvesties išskirti juostos padėtį arba juostos paklaidą;
- kamerų įvestį sujungti su `BNO085` ir 2 `VL53L5CX` matricinių ToF modulių pagalbiniais signalais;
- pagal kameros vaizdą ir artimo atstumo įvestis įvertinti situaciją priekyje;
- esamą paklaidą paversti vairo komanda;
- riboti vairo pokyčius, kad robotas nesiūbuotų;
- mažinti važiavimo išėjimą, kai pasitikėjimas mažas arba robotas yra atsigavimo būsenoje.

## Algoritmų Tipai

- važiavimo juosta valdymas;
- vairo korekcija;
- reakcija į kliūtis;
- saugos perrašymai, kai jutiklio įvestis atrodo neteisinga.

## Pageidaujamas Elgsenos Rinkinys

- pirmiausia kameros įvestis, kad būtų matoma juostos geometrija ir galima įvertinti situaciją priekyje;
- inercinė pagalba krypties stabilumui;
- 2 matriciniai ToF moduliai artimo atstumo kliūties patvirtinimui;
- būsenų mašinos logika sprendimui, ar sekti juostą, apvažiuoti, sulėtinti ar sustoti.

## Dokumentacijos Akcentas

Šiame projekte svarbiausia aiškiai parodyti, kad kamera yra pagrindinė įvestis, o `BNO085` ir 2 `VL53L5CX` moduliai veikia kaip papildomas stabilumo ir artimo atstumo patvirtinimas.
