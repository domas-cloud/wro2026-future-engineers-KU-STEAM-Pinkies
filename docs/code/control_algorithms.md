# Valdymo Algoritmai

## Architektūra

Valdymo logika turi atskirti suvokimą nuo vykdymo:

- `Raspberry Pi Zero` fiksuoja ir perduoda `OV5647` kameros duomenis;
- `ESP32` interpretuoja kameros ir jutiklių informaciją bei valdo techninę įrangą;
- `ESP32` vykdo paklaidos skaičiavimą, būsenų logiką, saugos patikras ir techninės įrangos valdymą.

## Ryšys Su Senu Roboto Modeliu

Pagrindinė algoritmo idėja perimta iš ankstesnio KU STEAM Pinkies roboto: paklaidos skaičiavimas, korekcinis valdymas, vairo ir variklio išėjimas bei kliūčių logika.
Skirtumas tas, kad naujame robote visa skaičiavimo dalis perkelta į `ESP32`, o `Raspberry Pi Zero` paliktas tik kameros vaizdo gavimui.
Perkeliama tik algoritmo filosofija, o ne tas pats sensor reading sluoksnis ar tie patys aparatūriniai moduliai.

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

## Aktyvus Valdymo Modelis

- kamera yra pagrindinė įvestis juostos geometrijai ir situacijai priekyje vertinti;
- `BNO085` padeda krypties stabilumui;
- 2 matriciniai `VL53L5CX` moduliai naudojami artimo atstumo kliūties patvirtinimui;
- būsenų logika sprendžia, ar sekti juostą, apvažiuoti, sulėtinti ar sustoti.
