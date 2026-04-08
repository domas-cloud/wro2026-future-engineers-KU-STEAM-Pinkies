# Kėbulo Konstrukcija

## Kėbulo Tikslas

Kėbulas turi išlaikyti robotą pakankamai standų, kad vairavimas būtų tikslus, ir kartu palikti vietos elektronikai, jutikliams bei laidams.

## Konstrukcijos Medžiaga

Rėmas pagamintas iš lazeriu pjautos faneros.
Ties vairo mazgu naudojami du faneros sluoksniai, kad būtų galima tiksliai įstatyti guolius.
Į tuos guolius remiasi varžtai, kurie sudaro vairo mechanizmo ašis ir palaiko steering mazgą.

## Konstrukciniai Svarstymai

- kuo mažesnis lankstumas aplink vairo tvirtinimą;
- didesnis standumas ties vairo mazgu dėl dvigubo faneros sluoksnio;
- pakankamas tarpas ratų judėjimui;
- saugus akumuliatoriaus ir skaičiavimo plokščių tvirtinimas;
- lengva prieiga priežiūrai ir patikrai.

## Komponentų Išdėstymo Logika

- `MG90S` turi būti ten, kur vairo traukė išlieka trumpa ir tiesi;
- vairo mazgas turi remtis į guolius, kad varžtai ir steering ašys judėtų tiksliai ir su mažesniu laisvumu;
- `N20` ir `L298N` turi būti sumontuoti taip, kad pavaros kelias išliktų mechaniškai tvarkingas;
- `ESP32` ir `Raspberry Pi Zero` pageidautina išdėstyti kuo toliau nuo triukšmingiausios maitinimo šakos;
- `BNO085` turi būti tvirtai pritvirtintas ir, kiek įmanoma, toliau nuo vibracijos šaltinių;
- 2 `VL53L5CX` matriciniai ToF moduliai turi turėti aiškų matymo lauką į sritis, kurias turi stebėti.

## Kodėl Tai Svarbu

Jei kėbulas per daug lankstosi, vairavimo geometrija ir jutiklių suderinimas judant pradeda kisti.
Todėl dokumentacijoje reikia aiškinti ne tik išvaizdą, bet ir konstrukcijos standumą.
Dvigubas faneros sluoksnis ties vairo mazgu ir guolių panaudojimas padeda išlaikyti tikslesnę steering geometriją.
