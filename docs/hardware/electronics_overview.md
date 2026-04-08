# Elektronikos Apžvalga

## Sistemos Padalijimas

Robotas naudoja du pagrindinius skaičiavimo sluoksnius:

- `Raspberry Pi Zero` tik kameros duomenims;
- `ESP32` visiems skaičiavimams, valdymui ir laikui jautrioms užduotims.

## Funkcinės Ribos

- `Raspberry Pi Zero` atlieka tik kameros gavimą ir perduoda vaizdo įvestį;
- `ESP32` atlieka skaičiavimus, vairo išėjimą, variklio valdymą ir greitą saugos reakciją;
- kameros srautas yra Pi Zero įvestis, o `BNO085` ir 2 `VL53L5CX` moduliai skaito `ESP32`;
- baterija ir reguliatoriai tiekia švarią energiją, o ne elgseną.

## Pagrindiniai Elektriniai Blokai

- `L298N H-bridge` skirtas `N20` varikliui;
- `MG90S` vairo servomechanizmas;
- `OV5647 5Mpx wide-angle` kamera (`Waveshare 14037`) `Raspberry Pi Zero`;
- `BNO085 9-DOF IMU`;
- 2 `VL53L5CX` matriciniai ToF moduliai;
- elektronikos mazgas ant perfboard tipo plokštės;
- maitinimo reguliavimas ir paskirstymas.

## Projektavimo Tikslas

Elektronikos architektūra turi išlaikyti valdymo grandinę lengvai suprantamą:

- Pi Zero pateikia kameros įvestį;
- `ESP32` naudoja kameros įvestį situacijai priekyje įvertinti, todėl nereikia daug atskirų ToF jutiklių;
- `ESP32` priima važiavimo sprendimus ir vykdo vykdiklių komandas;
- jutikliai tiesiogiai teikia navigacijos kontekstą ir saugos duomenis `ESP32`;
- pagrindiniai elektronikos sujungimai surinkti ant perfboard, kad mechaninis tvirtinimas ir laidų maršrutai būtų paprastesni;
- akumuliatorių paketas tiekia variklio galią, o loginės šakos yra reguliuojamos atskirai.
