# Kėbulo Konstrukcija

## Kėbulo Tikslas

Kėbulas turi išlaikyti robotą pakankamai standų, kad vairavimas būtų tikslus, ir kartu palikti vietos elektronikai, jutikliams bei laidams.

## Konstrukciniai Svarstymai

- kuo mažesnis lankstumas aplink vairo tvirtinimą;
- pakankamas tarpas ratų judėjimui;
- saugus akumuliatoriaus ir skaičiavimo plokščių tvirtinimas;
- lengva prieiga priežiūrai ir patikrai.

## Komponentų Išdėstymo Logika

- `MG90S` turi būti ten, kur vairo traukė išlieka trumpa ir tiesi;
- `N20` ir `L298N` turi būti sumontuoti taip, kad pavaros kelias išliktų mechaniškai tvarkingas;
- `ESP32` ir `Raspberry Pi Zero` pageidautina išdėstyti kuo toliau nuo triukšmingiausios maitinimo šakos;
- `BNO085` turi būti tvirtai pritvirtintas ir, kiek įmanoma, toliau nuo vibracijos šaltinių;
- `VL53L5CX` turi turėti aiškų matymo lauką į sritį, kurią turi stebėti.

## Kodėl Tai Svarbu

Jei kėbulas per daug lankstosi, vairavimo geometrija ir jutiklių suderinimas judant pradeda kisti.
Todėl dokumentacijoje reikia aiškinti ne tik išvaizdą, bet ir konstrukcijos standumą.
