# Sprendimų ir Pataisymų Žurnalas

Šiame žurnale trumpai surašyti svarbiausi realūs pakeitimai, kurie buvo atlikti vystant robotą.

## 1. Vairo geometrijos pataisa

- Problema: ankstesniuose bandymuose buvo susidaręs didelis rato petys, todėl servo turėdavo įveikti per didelę apkrovą.
- Pataisymas: šoniniai vairo mazgai buvo perdirbti taip, kad suktųsi apie savo ašį vietoje.
- Patikrinimas: po pakeitimo vairavimas tapo lengvesnis, stabilesnis ir tinkamesnis tolimesnėms iteracijoms.

## 2. Diferencialo grąžinimas ir palikimas

- Problema: ankstesniame robote diferencialo nenaudojimas labai padidindavo pasipriešinimą sukimui posūkiuose.
- Pataisymas: galinėje ašyje buvo paliktas diferencialas.
- Patikrinimas: posūkiuose sumažėjo mechaninė apkrova, ratai mažiau slydo, o važiavimas tapo sklandesnis.

## 3. Jutiklių vaidmenų atskyrimas

- Problema: vien tik vieno tipo jutiklių nepakako visoms navigacijos situacijoms.
- Pataisymas: kamera palikta bendram trasos vaizdui, o 2 `VL53L5CX` moduliai naudojami artimo atstumo ir kliūčių patvirtinimui.
- Patikrinimas: jutiklių sistema tapo aiškesnė, o kliūčių aptikimas patikimesnis sudėtingesnėse situacijose.

## 4. `BNO085` montavimo standinimas

- Problema: jei IMU tvirtinimas nėra pakankamai standus, dalis judesio rodmenų gali atspindėti ne roboto, o plokštės lankstumą.
- Pataisymas: `BNO085` buvo montuojamas standžiai ir kuo arčiau stabilios roboto konstrukcijos dalies.
- Patikrinimas: krypties ir judėjimo vertinimas tapo nuoseklesnis per kelis posūkius.

## 5. Elektronikos supaprastinimas

- Problema: didesnis jutiklių ir šakų skaičius komplikuoja elektroniką ir didina energijos sąnaudas.
- Pataisymas: pasirinkta architektūra su 2 `VL53L5CX` moduliais vietoje perteklinio artimo atstumo jutiklių skaičiaus.
- Patikrinimas: sistema liko paprastesnė, lengviau pakartojama ir patogesnė testuoti.
