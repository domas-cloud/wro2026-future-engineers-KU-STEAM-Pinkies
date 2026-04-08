# Vairo Sistema

## Mechanizmas

Robotas naudoja servo pagrindu veikiantį vairavimą su pavaromis susietą priekinę ašį.
Tikslas yra paversti servo judėjimą į simetrišką ratų judėjimą su prognozuojamais kampų pokyčiais.
Vairo mechanizmą sudaro trys dantračiai. Servo suka vidurinį dantratį, o šis vienu metu perduoda judesį į abu šoninius dantračius.
Ant abiejų šoninių dantračių pritvirtintos vairo kojelės, prie kurių tvirtinami ratai, todėl abu priekiniai ratai pasisuka kartu.

## Pirmoji Iteracija

Pirmoji šio roboto vairo sistemos versija buvo ankstyvas prototipas, kuriame centrinis dantratis perduodavo judesį į du šoninius mazgus.
Šie šoniniai mazgai sukosi apie savo ašį vietoje, todėl sukimo momentui nereikėjo didelio peties kaip ankstesniuose bandymuose.
Toks išdėstymas sumažino apkrovą servo mechanizmui ir leido efektyviau perduoti judesį į ratus.
Vėlesnėse iteracijose ši idėja buvo toliau tikslinama, kad vairavimo sistema būtų standesnė ir patikimesnė.

## Diferencialas

Diferencialas buvo naudojamas prototipe ir buvo paliktas vėlesnėje roboto versijoje, nes pasitvirtino kaip svarbi važiuoklės dalis.
Jo paskirtis yra leisti kairiajam ir dešiniajam ratui posūkio metu suktis skirtingu greičiu, nes vidinis ir išorinis ratas nuvažiuoja nevienodą kelią.
Praeito roboto viena iš klaidų buvo diferencialo nenaudojimas, todėl posūkiuose pasipriešinimas sukimui labai padidėdavo, praktiškai net iki trigubo lygio.
Dėl šios priežasties didėjo apkrova mechanikai, blogėjo posūkio tikslumas ir ratai buvo labiau linkę slysti.
Paliktas diferencialas sumažino šias apkrovas, pagerino roboto elgesį posūkiuose ir leido važiuoti sklandžiau.

## Inžinerinės Pastabos

- išlaikyti vairavimo kelią kuo kompaktiškesnį;
- kiek įmanoma sumažinti laisvumą;
- išvengti pavarų sistemos ir kėbulo susikirtimo;
- užtikrinti, kad servo nuosekliai grįžtų į centrą.
- išlaikyti vienodą abiejų šoninių dantračių darbą, kad ratų kampai nesiskirtų.

## Integracijos Pastabos

Vairo kampui tiesiogiai įtaką daro tvirtinimo aukštis, traukės ilgis ir trijų dantračių suderinimas.
Todėl vairo mazgo geometrija turi sutapti su realiu kėbulo ir ratų išdėstymu.
