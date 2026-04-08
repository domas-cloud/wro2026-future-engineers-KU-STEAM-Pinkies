# Navigacijos Logika

## Laukiamas Elgesys

Robotas turi sekti juostą, atpažinti svarbias kliūtis ir keisti elgseną, kai pasikeičia situacija trasoje.

Navigacijos sluoksnis turi derinti kameros duomenis su `BNO085` ir 2 `VL53L5CX` matricinių ToF modulių įvestimis, o ne pasikliauti tik vienu jutikliu.

## Aukšto Lygio Eiga

- įvertinti esamą sceną `ESP32`;
- nuspręsti, ar svarbiau važiavimas juosta, ar kliūties apdorojimas;
- siųsti vairo ir važiavimo komandas;
- stebėti klaidų būsenas.

## Siūlomas Būsenų Modelis

- `INIT` aparatūros ir jutiklių paleidimui;
- `LANE_FOLLOW` normaliam važiavimui;
- `OBSTACLE_CHECK` vietiniam atstumo patvirtinimui;
- `AVOID_OR_STOP`, kai kelias užblokuotas arba neaiškus;
- `RECOVER`, kai juosta vėl tampa matoma.

## Perėjimo Taisyklės

- `INIT -> LANE_FOLLOW`, kai jutikliai ir skaičiavimo plokštės praneša, kad yra pasiruošusios;
- `LANE_FOLLOW -> OBSTACLE_CHECK`, kai aptinkama artima kliūtis arba riba;
- `OBSTACLE_CHECK -> AVOID_OR_STOP`, kai kliūtis patvirtinama;
- `AVOID_OR_STOP -> RECOVER`, kai kelias vėl tampa saugus;
- `RECOVER -> LANE_FOLLOW`, kai juostos matomumas ir jutiklių patikimumas grįžta į normą.

## Elgsenos Pastabos

- važiavimas juosta turi būti numatytoji būsena;
- kliūčių apdorojimas turi laikinai perimti prioritetą iš važiavimo juosta;
- robotas turi grįžti į važiavimą juosta tik tada, kai kelias laisvas ir jutiklių įvestis stabili;
- kai robotas yra atsigavimo arba neapibrėžtumo būsenoje, vairo komandos turi būti ribojamos.

## Sprendimų Įvestys

- kameros duomenys iš `Raspberry Pi Zero`;
- `BNO085` krypties stabilumui ir judėjimo suvokimui;
- 2 `VL53L5CX` matriciniai ToF moduliai artimų kliūčių patvirtinimui;
- ryšio būklė tarp `Raspberry Pi Zero` ir `ESP32`;
- maitinimo arba paleidimo būsena, jei ją programinė įranga mato.

## Ką Turi Parodyti Dokumentacija

- sprendimų seką;
- būsenų pokyčius;
- kaip kliūčių apdorojimas sąveikauja su važiavimu juosta;
- kaip sistema atsistato po nutrūkimo.
