# Programos Architektūra

## Numatyta Atskirtis

- kameros gavimo sluoksnis veikia `Raspberry Pi Zero`;
- valdymo ir vykdiklių sluoksnis veikia `ESP32`;
- bendras sąsajos sluoksnis komandų, jutiklių rodmenų ir saugos būsenų perdavimui.

## Modulių Žemėlapis

- `camera`:
  - kameros gavimas `Raspberry Pi Zero`;
  - kadrų perdavimas į `ESP32`;
  - kameros ryšio būklės stebėjimas.
- `sensing`:
  - `BNO085` orientacijos ir judėjimo duomenys `ESP32` pusėje;
  - `VL53L5CX` atstumo kadrai `ESP32` pusėje;
  - jutiklių būklės tikrinimas ir paprastas filtravimas.
- `control`:
  - vairo korekcija;
  - važiavimo išėjimo formavimas;
  - būsenų mašinos pagrindu veikiantis elgsenos pasirinkimas;
  - visi skaičiavimai `ESP32` pusėje.
- `communication`:
  - kamerinių duomenų žinutės iš Pi Zero į `ESP32`;
  - patvirtinimo arba „heartbeat“ žinutės, jei jos naudojamos;
  - saugus atsarginis elgesys nutrūkus ryšiui.

## Sąsajos Sutartis

Tarp plokščių siunčiama žinutė turi nešti tik tiek informacijos, kiek reikia patikimam kamerinių duomenų perdavimui:

- kameros kadro arba stebėjimo duomenys;
- kadro laiko žyma arba sekos numeris;
- užfiksavimo būsena;
- trumpas būklės indikatorius, jei ryšys tai palaiko.

Tikslus transportas gali skirtis, bet paskirtis turi likti ta pati: `Raspberry Pi Zero` tiekia kameros duomenis, o `ESP32` atlieka visus skaičiavimus.

## Duomenų Srautas

1. Kameros duomenys užfiksuojami `Raspberry Pi Zero`.
2. Pi Zero perduoda kameros duomenis į `ESP32`.
3. `ESP32` apdoroja kameros, IMU ir atstumo jutiklių informaciją.
4. `ESP32` pasirenka elgsenos būseną, pavyzdžiui, važiavimą juosta arba kliūties apvažiavimą.
5. `ESP32` paverčia šiuos sprendimus į `MG90S` vairo išėjimą ir `L298N` variklio valdymą.
6. `ESP32` toliau tikrina jutiklių patikimumą ir, jei įvestys nepatikimos, gali pereiti į saugią būseną.

## Kodėl Tokia Struktūra

Toks padalijimas padeda sistemą išlaikyti suprantamą ir sumažina riziką, kad viena funkcija bus atsakinga už viską.
Be to, taip repozitoriumą lengviau atkurti, nes kiekvienas sluoksnis turi aiškią atsakomybę.

## Ką Reikia Įtraukti

- modulių sąrašą;
- duomenų srauto diagramą;
- paleidimo seką;
- klaidų valdymą ir atsigavimo elgseną.

## Paleidimo Seką

- inicializuoti skaičiavimo plokštes;
- aktyvuoti kameros gavimo kelią ir jutiklių magistrales;
- `ESP32` pusėje patikrinti `BNO085` ir `VL53L5CX` pasirengimą;
- patvirtinti kameros duomenų srautą tarp `Raspberry Pi Zero` ir `ESP32`;
- nustatyti `MG90S` į centrinę padėtį;
- `N20` išėjimą laikyti išjungtą, kol sistema bus pasiruošusi.

## Klaidos Valdymas

- jei kameros duomenų nėra, robotas turi likti saugioje budėjimo arba laikymo būsenoje;
- jei trūksta jutiklių įvesties, reikia rinktis saugiausią galimą elgseną, o ne spėlioti;
- jei kameros ryšys nutrūksta, `ESP32` turėtų sustoti arba laikyti paskutinę saugią būseną pagal pasirinktą saugos politiką;
- jei paleidimo seka nebaigiama, variklio įjungti negalima.
