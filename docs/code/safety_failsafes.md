# Saugos ir Apsaugos Mechanizmai

## Paskirtis

Robotui reikia saugaus atsarginio elgesio tada, kai sugenda jutiklis, valdymo ciklas tampa nestabilus arba robotas praranda aplinkos suvokimą.

## Pavyzdžiai

- mažinti greitį, kai kameros pasitikėjimas mažas;
- sustabdyti arba laikyti būseną, kai jutiklių duomenys neteisingi;
- grąžinti vairą į centrą, jei komandų srautas sugenda;
- neleisti nesaugaus variklio išėjimo paleidimo metu.

## Prioritetų Tvarka

1. apsaugoti techninę įrangą;
2. neleisti robotui judėti nesaugiai;
3. išsaugoti pakankamai būsenos, kad būtų galima gražiai atsigauti;
4. grįžti prie normalaus važiavimo tik tada, kai jutikliai ir ryšys yra sveiki.

## Specifiniai Apsaugos Mechanizmai

- jei `Raspberry Pi Zero` kameros gavimas sustoja, robotas neturi toliau taikyti senų vairo komandų;
- jei `BNO085` duomenys tampa neteisingi, krypties korekcijas reikia sumažinti arba išjungti;
- jei `VL53L5CX` rodmenys netikėtai šokinėja, robotas turi grįžti į atsargesnį judėjimą arba sustojimo būseną;
- jei kamerinių duomenų ryšys tarp `Raspberry Pi Zero` ir `ESP32` nutrūksta, `ESP32` turi pereiti į saugų tuščios būsenos režimą.

## Dokumentacijos Taisyklė

Kiekvienas saugos veiksmas turi būti susietas su tuo gedimo tipu, nuo kurio jis saugo.

## Testavimo Lūkestis

Kiekvieną apsaugos mechanizmą reikia bent kartą išbandyti kontroliuojamame teste, kad komanda galėtų aprašyti, kas įvyko, ir patvirtinti, jog atsarginis elgesys veikia.
