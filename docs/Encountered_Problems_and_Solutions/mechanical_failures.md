# Mechaniniai Gedimai

Šiame skyriuje aprašomi svarbiausi mechaniniai trūkumai, pastebėti kuriant robotą, ir jų reikšmė tolimesnėms iteracijoms.

## 1. Per didelė vairo apkrova

Ankstyvuose bandymuose viena iš pagrindinių problemų buvo per didelė vairo mechanizmo apkrova.
Ji atsirasdavo dėl didelio rato peties, todėl servo turėdavo perduoti per daug jėgos.
Ši problema tiesiogiai paskatino vairo geometrijos perdirbimą.

## 2. Padidėjęs pasipriešinimas posūkiuose be diferencialo

Ankstesnė patirtis parodė, kad be diferencialo galinėje ašyje robotas posūkiuose susiduria su gerokai didesniu pasipriešinimu.
Dėl to blogėja trajektorijos tikslumas, didėja slydimo tikimybė ir apkrovos transmisijai.
Todėl diferencialas buvo laikomas ne papildomu, o būtinu mechaniniu sprendimu.

## 3. Pavarų ir tvirtinimų laisvumas

Mechanikoje ypač svarbu sumažinti nereikalingą laisvumą.
Jei dantračių ar tvirtinimų grandinėje atsiranda per daug laisvos eigos, vairavimo judesys tampa mažiau tikslus ir sunkiau pakartojamas.
Todėl konstrukcijoje buvo siekiama kompaktiško ir standaus jėgos perdavimo kelio.

## 4. Konstrukcijos standumo įtaka

Net jei atskiros dalys veikia teisingai, per silpnas bendras konstrukcijos standumas gali pabloginti rezultatą.
Tai ypač svarbu vairo sistemai ir jutiklių tvirtinimams, nes lankstumas gali iškraipyti tiek mechaniką, tiek matavimus.
Dėl to vėlesnėse iteracijose daugiau dėmesio skirta standumui ir tikslesniam tvirtinimui.
