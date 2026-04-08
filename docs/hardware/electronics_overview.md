# Elektronikos Apžvalga

## Sistemos Padalijimas

Robotas naudoja du pagrindinius skaičiavimo sluoksnius:

- `Raspberry Pi Zero` tik kameros duomenims;
- `ESP32` visiems skaičiavimams, valdymui ir laikui jautrioms užduotims.

## Funkcinės Ribos

- `Raspberry Pi Zero` atlieka kameros gavimą ir pateikia kamerinę įvestį atstumo įvertinimui priekyje;
- `ESP32` atlieka skaičiavimus, vairo išėjimą, variklio valdymą ir greitą saugos reakciją;
- kameros srautas yra Pi Zero įvestis, o `BNO085` ir 2 `VL53L5CX` moduliai skaito `ESP32`;
- baterija ir reguliatoriai tiekia švarią energiją, o ne elgseną.

## Pagrindiniai Elektriniai Blokai

- `L298N H-bridge` skirtas `N20` varikliui;
- `MG90S` vairo servomechanizmas;
- `OV5647 5Mpx wide-angle` kamera (`Waveshare 14037`) `Raspberry Pi Zero`;
- `BNO085 9-DOF IMU`;
- 2 `VL53L5CX` matriciniai ToF moduliai;
- maitinimo reguliavimas ir paskirstymas.

## Projektavimo Tikslas

Elektronikos architektūra turi išlaikyti valdymo grandinę lengvai suprantamą:

- Pi Zero pateikia kameros įvestį;
- kamera naudojama ir priekyje esančio atstumo įvertinimui, todėl nereikia daug atskirų ToF jutiklių;
- `ESP32` priima važiavimo sprendimus ir vykdo vykdiklių komandas;
- jutikliai tiesiogiai teikia navigacijos kontekstą ir saugos duomenis `ESP32`;
- akumuliatorių paketas tiekia variklio galią, o loginės šakos yra reguliuojamos atskirai.

## Dokumentacijos Rezultatas

Ši dalis turi būti pagrįsta laidų schemomis ir aiškiu ryšių sąrašu aplanke `schemes/`.
