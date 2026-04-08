# Iteracijos ir Koregavimai

Ši dalis aprašo, kaip robotas keitėsi per kelias pagrindines mechanikos ir jutiklių iteracijas.

## 1 Iteracija: Ankstyvas vairo prototipas

Pirmoje versijoje buvo bandomas ankstyvas vairo sprendimas su centriniu dantračiu ir šoniniais mazgais.
Dar prieš dabartinę geometriją buvo pasireiškusi didelio rato peties problema, todėl servo apkrova buvo per didelė.
Šis etapas parodė, kad vien tik veikiančios mechanikos nepakanka, jei ji apkrauna servo ir blogina pakartojamumą.

## 2 Iteracija: Vairo geometrijos pataisa

Vėliau šoniniai mazgai buvo perdirbti taip, kad suktųsi apie savo ašį vietoje.
Taip buvo pašalintas didelis petys, sumažinta apkrova servo mechanizmui ir pagerintas jėgos perdavimas į ratus.
Po šio pakeitimo vairavimo sistema tapo stabilesnė ir tinkamesnė tolimesniems testams.

## 3 Iteracija: Diferencialo išlaikymas

Vienas svarbiausių sprendimų buvo neatsisakyti diferencialo galinėje ašyje.
Ankstesnė patirtis su robotu be diferencialo parodė, kad posūkiuose labai padidėja pasipriešinimas sukimui.
Paliktas diferencialas sumažino slydimą, apkrovas transmisijoje ir pagerino roboto elgesį trasoje.

## 4 Iteracija: Jutiklių vaidmenų aiškus paskirstymas

Jutiklių sistema buvo paprastinama ir aiškiau suskirstyta pagal funkciją.
Kamera liko bendram trasos vaizdui, 2 `VL53L5CX` moduliai artimo atstumo patvirtinimui, o `BNO085` krypties stabilumui.
Toks atskyrimas sumažino painiavą sistemoje ir leido lengviau suprasti, kuris jutiklis už ką atsakingas.

## 5 Iteracija: Tvirtinimo ir stabilumo gerinimas

Papildomas dėmesys buvo skirtas standesniam `BNO085` montavimui ir tvarkingesniam jutiklių išdėstymui.
Tai sumažino vibracijos ir konstrukcijos lankstumo įtaką rodmenims.
Po šių pakeitimų roboto judėjimo vertinimas tapo nuoseklesnis per kelis bandymus iš eilės.
