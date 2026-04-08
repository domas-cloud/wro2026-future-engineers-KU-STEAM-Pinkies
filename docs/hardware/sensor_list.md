# Jutiklių Sąrašas

## Naudojami Jutikliai

- `OV5647 5Mpx wide-angle` kamera (`Waveshare 14037`) juostos, kliūčių ir priekyje esančio atstumo įvertinimui.
- `BNO085 9-DOF IMU` orientacijai ir judėjimo stabilumui.
- 2 `VL53L5CX` matriciniai ToF moduliai artimo atstumo ir kliūčių patvirtinimui.

## Kiekvieno Jutiklio Vaidmuo

- Kamera suteikia bendrą trasos vaizdą ir padeda įvertinti priekyje esantį atstumą.
- IMU padeda stabilizuoti judėjimą ir nustatyti krypties pokyčius.
- 2 matriciniai ToF moduliai pateikia artimo atstumo informaciją ir patvirtina kliūtis, kai kamerinis įvertinimas nėra pakankamas.

## Surinkimo Pastabos

- `BNO085` turi būti sumontuotas standžiai, kad sujungimo rezultatai atspindėtų roboto judėjimą, o ne plokštės lankstumą;
- `VL53L5CX` padėtis turi atitikti kliūčių zonos geometriją ir neužstoti matymo linijų;
- kamera ir 2 matriciniai ToF moduliai turi būti aprašyti kartu, nes jie sprendžia skirtingas tos pačios navigacijos problemos dalis;
- naudojant tik 2 ToF modulius sumažinamos energijos sąnaudos ir supaprastinama elektronikos architektūra.

## Dokumentacijos Reikalavimai

- išvardyti tikslius naudojamus modulius;
- paaiškinti, kur sumontuotas kiekvienas jutiklis;
- paaiškinti, ką kiekvienas jutiklis prisideda prie roboto sprendimų ciklo;
- nurodyti bet kokius kalibravimo ar suderinimo reikalavimus.
