# Kas Neveikė

Šiame skyriuje surašyti sprendimai ir situacijos, kurios nepasiteisino arba turėjo būti perdirbtos.

## Per didelis rato petys vairavimo mechanikoje

Vienas iš svarbiausių ankstyvų trūkumų buvo didelis rato petys.
Dėl jo servo turėdavo įveikti gerokai didesnę apkrovą, todėl sistema buvo mažiau efektyvi ir sunkiau pakartojama.
Šis sprendimas nebuvo paliktas, nes realiuose testuose jis blogino vairavimo patikimumą.

## Ankstesnio roboto sprendimas be diferencialo

Praeito roboto klaida buvo nenaudoti diferencialo.
Posūkiuose tai labai padidindavo pasipriešinimą sukimui, blogino trajektoriją ir didino slydimo tikimybę.
Dėl šios priežasties dabartiniame robote diferencialas buvo paliktas kaip būtina važiuoklės dalis.

## Per didelis pasikliovimas vienu jutiklių tipu

Bandymų metu paaiškėjo, kad vien tik vieno tipo jutiklių nepakanka stabiliai navigacijai visose situacijose.
Vien kamera arba vien artimo atstumo jutikliai negali patikimai išspręsti visų trasos scenarijų.
Todėl buvo pasirinktas mišrus sprendimas su kamera, `BNO085` ir 2 `VL53L5CX` moduliais.

## Nestandūs tvirtinimai

Jei `BNO085` arba kiti svarbūs komponentai montuojami nepakankamai standžiai, rodmenys tampa mažiau patikimi.
Tai ypač svarbu tada, kai konstrukcija vibruoja arba šiek tiek lankstosi važiuojant.
Dėl to buvo atsisakyta silpnesnių tvirtinimo sprendimų ir daugiau dėmesio skirta standumui.
