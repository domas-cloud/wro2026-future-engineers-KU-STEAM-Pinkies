# Žinučių Protokolas

## Paskirtis

Šis dokumentas aprašo žinučių ribą tarp `Raspberry Pi Zero` ir `ESP32`.

## Siūlomas Žinutės Turinys

- prašoma elgsenos būsena;
- vairo tikslas arba vairo korekcija;
- važiavimo įjungimo žyma;
- važiavimo stiprumas arba greičio prašymas;
- pasitikėjimo arba saugos žyma;
- sekos skaitiklis arba „heartbeat“, jei įgyvendinimas jį naudoja.

## Atsakomybės

- `Raspberry Pi Zero` apskaičiuoja, ko robotas nori imtis;
- `ESP32` įvykdo komandą ir taiko žemo lygio saugos patikras;
- fizinis ryšys aprašytas laidų apžvalgoje.

## Patikimumo Pastabos

- seni pranešimai neturi būti laikomi naujomis komandomis;
- jei komandų srautas sustoja, `ESP32` pagal pasirinktą politiką turi pereiti į saugų laikymo arba stabdymo režimą;
- kiekviena žinutė turi būti aiškiai atskiriama nuo ankstesnės.

## Naudojimas Dokumentacijoje

Kai komanda pridės kodą, šis failas turi sutapti su tikrais komandų laukais ir paleidimo „handshake“.
