# Jutiklių Sąrašas

## Naudojami Jutikliai

- Kamera juostos ir kliūčių matymui.
- `BNO085 9-DOF IMU` orientacijai ir judėjimo stabilumui.
- `VL53L5CX` matricos ToF lidarui atstumui ir kliūčių suvokimui.

## Kiekvieno Jutiklio Vaidmuo

- Kamera suteikia bendrą trasos vaizdą.
- IMU padeda stabilizuoti judėjimą ir nustatyti krypties pokyčius.
- ToF jutiklis pateikia artimo atstumo informaciją, kuri papildo vaizdą.

## Surinkimo Pastabos

- `BNO085` turi būti sumontuotas standžiai, kad sujungimo rezultatai atspindėtų roboto judėjimą, o ne plokštės lankstumą;
- `VL53L5CX` padėtis turi atitikti kliūčių zonos geometriją ir neužstoti matymo linijų;
- kameros kadras ir ToF aprėptis turi būti aprašyti kartu, nes jie sprendžia skirtingas tos pačios navigacijos problemos dalis.

## Dokumentacijos Reikalavimai

- išvardyti tikslius naudojamus modulius;
- paaiškinti, kur sumontuotas kiekvienas jutiklis;
- paaiškinti, ką kiekvienas jutiklis prisideda prie roboto sprendimų ciklo;
- nurodyti bet kokius kalibravimo ar suderinimo reikalavimus.
