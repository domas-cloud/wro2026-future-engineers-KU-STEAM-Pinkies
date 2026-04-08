# Testai Trasos Sąlygomis

## Paskirtis

Trasos testai patikrina visą robotą sąlygomis, artimesnėmis varžyboms.

## Ką Stebėti

- važiavimo juosta pastovumą;
- elgesį įveikiant kliūtis;
- vairo stabilumą posūkiuose;
- pakartojamumą per kelis važiavimus.

## Specifiniai Surinkimo Stebėjimai

- ar `MG90S` nuosekliai grįžta į centrą;
- ar `N20` variklis ir `L298N` išlaiko pakartojamą įsibėgėjimą;
- ar 2 `VL53L5CX` matricinių ToF modulių rodmenys išlieka naudingi šalia kliūčių ir atspindinčių paviršių;
- ar `BNO085` padeda stabilizuoti kryptį po kelių posūkių.

## Trasos Testų Scenarijai

- tiesus važiavimas juosta aiškioje atkarpoje;
- kairių ir dešinių posūkių kartojimas su pakartotine vairo korekcija;
- kliūties atsiradimas ir atsigavimas trumpame ruože;
- visas ratas, kuriame robotas turi kelis kartus pakartoti tą patį elgesį.

## Ką Išsaugoti

- trasos išdėstymą arba trumpą jos aprašą;
- ratų skaičių arba pakartojimų skaičių;
- kas nepavyko arba kas pagerėjo;
- nuotraukas arba video laiką, jei tokie yra.

## Dokumentacijos Taisyklė

Užrašyk testų paruošimą, sąlygas ir stebėtą elgesį net tada, kai robotas dar nėra tobulas.
