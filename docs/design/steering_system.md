# Vairo Sistema

## Mechanizmas

Robotas naudoja servo pagrindu veikiantį vairavimą su pavaromis susietą priekinę ašį.
Tikslas yra paversti servo judėjimą į simetrišką ratų judėjimą su prognozuojamais kampų pokyčiais.
Vairo mechanizmą sudaro trys dantračiai. Servo suka vidurinį dantratį, o šis vienu metu perduoda judesį į abu šoninius dantračius.
Ant abiejų šoninių dantračių pritvirtintos vairo kojelės, prie kurių tvirtinami ratai, todėl abu priekiniai ratai pasisuka kartu.

## Inžinerinės Pastabos

- išlaikyti vairavimo kelią kuo kompaktiškesnį;
- kiek įmanoma sumažinti laisvumą;
- išvengti pavarų sistemos ir kėbulo susikirtimo;
- užtikrinti, kad servo nuosekliai grįžtų į centrą.
- išlaikyti vienodą abiejų šoninių dantračių darbą, kad ratų kampai nesiskirtų.

## Integracijos Pastabos

Vairo sistema turi būti dokumentuojama kartu su kėbulu, nes tvirtinimo aukštis, traukės ilgis ir pavarų suderinimas veikia tikrąjį vairo kampą.
Jei pasikeičia servo išėjimas arba traukės geometrija, programinės įrangos vairo ribas reikia patikrinti iš naujo.

## Ką Dokumentuoti

- vairo geometriją;
- judėjimo diapazoną;
- kas buvo testuota prototipavimo metu;
- bet kokias problemas, tokias kaip strigimas, laisvumas ar poslinkis.
