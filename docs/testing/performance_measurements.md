# Našumo Matavimai

Šiame skyriuje fiksuojami rodikliai, pagal kuriuos galima palyginti skirtingas roboto versijas.
Kol kas didžioji dalis išvadų yra kokybinės, tačiau matavimo struktūra jau apibrėžta ir naudojama testuose.

## Svarbiausi Stebimi Rodikliai

- vairo centro pakartojamumas po kelių ciklų;
- kairės ir dešinės posūkio simetrija;
- roboto stabilumas važiuojant juosta;
- kliūčių įveikimo patikimumas;
- roboto elgesys po staigesnio posūkio arba korekcijos.

## Kokybinės Išvados Iš Dabartinių Testų

- Po vairo geometrijos pakeitimo servo dirbo lengviau ir centras išliko stabilesnis.
- Diferencialo naudojimas sumažino slydimą ir pasipriešinimą posūkiuose.
- 2 `VL53L5CX` moduliai buvo pakankami artimo atstumo patvirtinimui, kai vien kameros informacijos neužteko.
- Standžiau sumontuotas `BNO085` pagerino krypties stabilumo vertinimą.

## Ką Dar Reikia Kaupti

Kad dokumentacija būtų stipresnė, prie šio skyriaus verta pridėti vienodomis sąlygomis surinktus skaitinius duomenis:

- kiek kartų iš eilės vairas grįžta į tą pačią neutralią padėtį;
- kiek sėkmingų važiavimų iš eilės robotas atlieka toje pačioje trasoje;
- kiek kartų kliūties patvirtinimui prireikia ToF modulio įsikišimo;
- kiek kartų posūkiuose pasireiškia slydimas arba perteklinė korekcija.

## Matavimo Pastaba

Kol nėra pilnos kiekybinės lentelės, šiame skyriuje pateikiami tik tie stebėjimai, kurie buvo nuosekliai matomi per kelias iteracijas.
Tokiu būdu išlaikoma sąžininga dokumentacija ir neįrašomi neišmatuoti skaičiai.
