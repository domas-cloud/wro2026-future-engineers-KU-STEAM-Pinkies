# Ankstyvieji Reikalavimai

## Funkciniai Reikalavimai

- patikimai sekti juostą;
- aptikti kliūtis ir sureaguoti neišvažiuojant iš trajektorijos;
- išlaikyti proporcingas ir stabilias vairo komandas;
- aiškiai atskirti kameros vaizdo gavimą `Raspberry Pi Zero` ir visus skaičiavimus `ESP32`.

## Nefunkciniai Reikalavimai

- repozitoriumas turi būti pakankamai aiškus, kad kita komanda galėtų atkurti robotą;
- konstrukcija turi išlikti standi per pakartotinius važiavimus;
- maitinimo grandinė turi būti saugi valdikliams, jutikliams ir varikliams;
- programinė architektūra turi būti suprantama iš modulių ir dokumentacijos.

## Ankstyvieji Konstrukcijos Tikslai

- `ESP32` vykdo realaus laiko valdymą;
- `Raspberry Pi Zero` tiekia tik kameros vaizdą;
- `BNO085` ir 2 `VL53L5CX` moduliai papildo kameros įvestį;
- robotas turi būti lengvai patikrinamas, derinamas ir prižiūrimas.
