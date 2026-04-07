# Elektronikos Apžvalga

## Sistemos Padalijimas

Robotas naudoja du pagrindinius skaičiavimo sluoksnius:

- `Raspberry Pi Zero` tik kameros duomenims;
- `ESP32` visiems skaičiavimams, valdymui ir laikui jautrioms užduotims.

## Funkcinės Ribos

- `Raspberry Pi Zero` atlieka tik kameros gavimą;
- `ESP32` atlieka skaičiavimus, vairo išėjimą, variklio valdymą ir greitą saugos reakciją;
- kameros srautas yra Pi Zero įvestis, o `BNO085` ir `VL53L5CX` skaito `ESP32`;
- baterija ir reguliatoriai tiekia švarią energiją, o ne elgseną.

## Pagrindiniai Elektriniai Blokai

- `L298N H-bridge` skirtas `N20` varikliui;
- `MG90S` vairo servomechanizmas;
- kamera `Raspberry Pi Zero`;
- `BNO085 9-DOF IMU`;
- `VL53L5CX` matricos ToF lidar;
- maitinimo reguliavimas ir paskirstymas.

## Projektavimo Tikslas

Elektronikos architektūra turi išlaikyti valdymo grandinę lengvai suprantamą:

- Pi Zero pateikia kameros įvestį;
- `ESP32` priima važiavimo sprendimus ir vykdo vykdiklių komandas;
- jutikliai tiesiogiai teikia navigacijos kontekstą ir saugos duomenis `ESP32`;
- akumuliatorių paketas tiekia variklio galią, o loginės šakos yra reguliuojamos atskirai.

## Dokumentacijos Rezultatas

Ši dalis turi būti pagrįsta laidų schemomis ir aiškiu ryšių sąrašu aplanke `schemes/`.
