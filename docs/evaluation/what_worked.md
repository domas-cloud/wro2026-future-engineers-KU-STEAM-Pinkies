# Kas Veikė

Šiame skyriuje aprašomi sprendimai, kurie testuose pasiteisino ir buvo palikti vėlesnėse roboto versijose.

## Mechanika

- Trijų dantračių vairo schema leido servo judesį perduoti abiem priekiniams ratams vienu metu.
- Šoninių mazgų sukimas apie savo ašį vietoje sumažino didelio rato peties problemą ir servo apkrovą.
- Diferencialo palikimas galinėje ašyje sumažino pasipriešinimą posūkiuose ir pagerino roboto elgesį trasoje.

## Jutikliai

- `OV5647 5Mpx wide-angle` kamera suteikė pakankamai platų trasos vaizdą juostos ir kliūčių vertinimui.
- `BNO085 9-DOF IMU` padėjo išlaikyti stabilesnę kryptį po kelių posūkių ir sumažino vien kameros neapibrėžtumą.
- 2 `VL53L5CX` matriciniai ToF moduliai pasiteisino kaip artimo atstumo patvirtinimo sluoksnis šalia kliūčių.

## Sistemos Architektūra

- `ESP32` naudojimas valdymui leido išlaikyti paprastesnį ir greitesnį roboto sprendimų ciklą.
- Ribotas ToF modulių skaičius sumažino energijos sąnaudas ir supaprastino elektronikos architektūrą.
- Standus `BNO085` montavimas ir tvarkingesnis jutiklių išdėstymas sumažino vibracijos įtaką rodmenims.

## Bendras Vertinimas

Labiausiai pasiteisino tie sprendimai, kurie mažino mechaninę apkrovą ir paprastino sistemos struktūrą.
Tai ypač matėsi vairo geometrijoje, diferencialo naudojime ir jutiklių tarpusavio vaidmenų atskyrime.
