# Vairo Sistemos - Koncepcijos Pasirinkimas

## Pasirinkta Koncepcija

Pasirinkome servo valdomą priekinę ašį su trijų pavarų sinchronizavimo mechanizmu.
Centrinė pavara priima vairo įvestį ir perduoda judesį į kairę ir dešinę puses, kad abi pusės judėtų kartu.

## Kodėl Ją Pasirinkome

- Vairo judėjimas yra simetriškas, todėl lengviau išlaikyti priekinę ašį lygią.
- Pavarų trauka leidžia kompaktiškai paversti servo judesį į prognozuojamą ratų kampą.
- Tokį sprendimą lengviau dokumentuoti ir atkurti nei laisvą kelių trauklių konstrukciją.
- Ši koncepcija atitinka mūsų tikslą sukurti automobilio tipo robotą su valdomais posūkiais, o ne skersiniu slydimu važiuojantį robotą.

## Ką Turi Daryti Mechanizmas

- Sukti priekinius ratus proporcingai vairo komandai.
- Išlaikyti kairės ir dešinės pusių judėjimo sinchronizaciją.
- Kiek įmanoma sumažinti matomą laisvumą.
- Leisti kartoti testavimą ir derinimą nekeičiant viso kėbulo.

## Dabartinė Būsena

Ši koncepcija yra šios repozitoriumo mechaninės ir programinės dokumentacijos pagrindas.
Jei vėlesni testai parodys laisvumą, per mažą diapazoną arba blogą grįžimą į centrą, tuos dalykus reikia įrašyti į problemų ir testavimo skyrius, o ne paslėpti.
