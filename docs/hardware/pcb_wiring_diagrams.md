# PCB ir Laidų Schemos

## Ką Turi Rodyti Ši Dalis

- kaip paskirstomas baterijos maitinimas;
- kurios dalys maitinamos tiesiogiai, o kurios eina per reguliatorius;
- kaip sujungti `ESP32`, Pi Zero, jutikliai, servomechanizmas ir variklis;
- kur susijungia signalų ir maitinimo žemės.

## Kodėl Tai Svarbu

Laidų schema reikalinga ne tik surinkimui, bet ir tam, kad būtų galima įvertinti, ar sistemą iš tiesų galima atkurti.
Tai taip pat lengviausias būdas parodyti, kad komanda apgalvojo srovės srautą ir signalo vientisumą.

## Vietos Repozitoriume

Visos schemos turi būti aplanke `schemes/` ir susietos su šiuo dokumentu.
Taip pat žr.: [Laidų apžvalgą](../../schemes/wiring_overview.md)

## Praktinė Laidų Struktūra

Laidų struktūra yra tokia:

- `2x 18650 Li-ion` akumuliatorių paketas maitina pagrindinę įvestį;
- pavaros šaka eina per `L298N H-bridge` į `N20` variklį;
- loginė šaka per reguliuotas grandines maitina `ESP32` ir `Raspberry Pi Zero`;
- pagrindiniai loginiai sujungimai surinkti ant perfboard tipo plokštės;
- `MG90S` servomechanizmas gauna stabilią šaką, tinkamą vairo apkrovai;
- `BNO085` ir 2 `VL53L5CX` matriciniai ToF moduliai prie `ESP32` jungiami per jų jutiklių magistralę;
- `Raspberry Pi Zero` tiekia kameros duomenis į `ESP32`;
- visos žemės sujungiamos viename kontroliuojamame bendrame taške.

## Ko Tikimasi Dokumentacijoje

Galutinėje schemoje turi būti pažymėta:

- jungčių pavadinimai;
- šakų įtampos;
- signalų kryptys;
- kuri plokštė generuoja valdymo signalą;
- kuri plokštė tą signalą priima;
- kur vyksta maitinimo atskyrimas tarp variklio ir loginės dalies.

## Schemos Kontrolinis Sąrašas

- parodytas baterijos įėjimo taškas;
- parodyti reguliatorių išėjimai;
- `L298N` variklio kelias atskirtas nuo loginės laidų dalies;
- `ESP32` ir `Raspberry Pi Zero` parodyti kaip atskiri skaičiavimo mazgai;
- `Raspberry Pi Zero` parodyta tik kaip kameros įvestis;
- `BNO085` ir 2 `VL53L5CX` matriciniai ToF moduliai parodyti kaip jutiklių įvestys į `ESP32`, o ne kaip maitinimo blokai;
- `MG90S` parodytas kaip vairo vykdiklis.
