# PCB ir Laidų Schemos

## Kodėl Tai Svarbu

Laidų schema reikalinga ne tik surinkimui, bet ir tam, kad būtų galima įvertinti, ar sistemą iš tiesų galima atkurti.
Tai taip pat lengviausias būdas parodyti, kad komanda apgalvojo srovės srautą ir signalo vientisumą.

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
