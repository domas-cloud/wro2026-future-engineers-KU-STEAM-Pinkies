# Maitinimo Paskirstymas

## Maitinimo Kelias

Robotas turi kontroliuotai paskirstyti baterijos energiją varikliui, vairo servomechanizmui, `ESP32`, `Raspberry Pi Zero` ir jutikliams.

## Projektavimo Tikslai

- neleisti triukšmingoms variklio apkrovoms trikdyti skaičiavimo plokščių;
- naudoti reguliuotas šakas ten, kur to reikia;
- kad maitinimo kelias būtų lengvai sekamas laidų schemoje;
- aiškiai dokumentuoti, kuris komponentas priklauso nuo kurios įtampos.

## Kodėl Tai Svarbu

Maitinimo problemos dažnai atrodo kaip programinės įrangos klaidos.
Ši dalis turi aiškiai parodyti, kaip robotas vengia tokio painiojimo.

## Šio Roboto Maitinimo Architektūra

Robotui naudojamas bendras baterijos šaltinis, bet apkrova išskirstoma pagal funkciją:

- variklio maitinimas eina per `L298N` pavaros grandinę;
- `ESP32` vykdo valdymą reguliuotoje loginėje šakoje;
- `Raspberry Pi Zero` gauna atskirą stabilų maitinimą kameros darbui;
- `MG90S` servomechanizmas maitinamas iš šakos, galinčios atlaikyti vairo apkrovos šuolius;
- `BNO085` ir `VL53L5CX` maitinami iš jutiklių loginės šakos pagal jų breakout reikalavimus.

## Projektavimo Logika

Tokia schema sumažina tikimybę, kad variklio srovės kritimai iš naujo paleis skaičiavimo plokštes arba sugadins jutiklių rodmenis.
Taip pat ji palengvina gedimų paiešką, nes kiekvieną maitinimo problemą galima susieti su konkrečia šaka, o ne su visu robotu.

## Paleidimo Eiga

1. baterija prijungiama prie maitinimo paskirstymo grandinės;
2. pirmiausia stabilizuojasi loginės šakos;
3. `ESP32` paleidžia skaičiavimus ir valdymą, o `Raspberry Pi Zero` paleidžia kameros gavimą;
4. jutikliai inicializuojami ir pateikia teisingą būseną;
5. `MG90S` nustato vairą į centrą;
6. `N20` variklio išėjimas įjungiamas tik tada, kai sistema jau pasiruošusi.

## Gedimų Valdymas

- jei loginė įtampa krenta, robotas neturi tęsti važiavimo;
- jei variklio šaka sukelia perkrovimus, pavaros kelią reikia izoliuoti arba stipriau filtruoti;
- jei servomechanizmo srovė trikdo loginę šaką, servo maitinimui reikia atskiro buferio arba reguliatoriaus kelio;
- jei važiavimo metu jutiklių rodmenys tampa nestabilūs, pirmiausia tikrink įžeminimą ir kabelių maršrutą.
