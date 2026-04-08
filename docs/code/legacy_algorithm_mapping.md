# Seno Algoritmo Pritaikymas Naujame Robote

## Kas Išlieka Tas Pats

Iš senojo roboto perimama ne ta pati jutiklių realizacija, o ta pati valdymo logikos struktūra:

- paklaidos apskaičiavimas;
- PD arba panašus korekcinis valdymas;
- vairo ir važiavimo komandų formavimas;
- kliūčių logika ir saugus sustojimas.

Keičiasi įėjimų tipai ir aparatūra, bet ne pagrindinė valdymo idėja.

## Kas Keičiasi

| Seno repo komponentas | Naujo repo komponentas | Pastaba |
| --- | --- | --- |
| `Arduino Mega 2560` | `ESP32` | Valdymas pereina į `ESP32`, nes jis vykdo visus skaičiavimus ir komandas. |
| `Raspberry Pi Zero 2` | `Raspberry Pi Zero` | Naujoje versijoje Pi pateikia `OV5647` kameros vaizdą, o priekinio atstumo įvertinimas remiasi tuo vaizdu jau bendroje valdymo logikoje. |
| `Adafruit Motor Shield V2` | `L298N H-bridge` | Variklio valdymas keičiasi, bet drive logika lieka panaši. |
| `VL53L1X` | 2 × `VL53L5CX` | Išlieka ToF pagrindu veikiantis kliūčių patvirtinimas, bet moduliai sumažinti iki 2, kad taupytume energiją. |
| `TCS34725` | nenaudojamas | Jei ši funkcija naujame robote nereikalinga, jos logikos neperkeliame. |
| `SG90` | `MG90S` | Vairo servo principas išlieka toks pats, tik keičiasi konkretus servomechanizmas. |
| DC variklis + perdavimas | `N20` + `L298N` | Važiavimo logika išlieka, tik hardware sprendimas kitoks. |

## Kokia Logika Perkeliama

Seno repo README matosi tokia logikos seka:

1. įėjimų gavimas;
2. paklaidos įvertinimas;
3. PD valdymas;
4. servo vairavimas;
5. variklio greičio korekcija;
6. kliūties logika.

Šią pačią struktūrą galima perkelti į naują robotą, tik pritaikant ją prie `ESP32` skaičiavimų, `Raspberry Pi Zero` tiekiamo kameros vaizdo ir mažesnio ToF kiekio.

## Kaip Tai Atrodo Naujame Robote

- `Raspberry Pi Zero` fiksuoja `OV5647` kamerą ir perduoda vaizdo duomenis.
- `ESP32` sujungia kameros informaciją su `BNO085` ir 2 `VL53L5CX` moduliais.
- `ESP32` apskaičiuoja paklaidą, įvertina priekinį atstumą ir parenka elgsenos būseną.
- `ESP32` siunčia servo ir variklio komandas.
- Saugos logika nutraukia važiavimą, jei įvestys tampa nepatikimos.

## Naudojimo Paskirtis

Šis dokumentas parodo, kaip sena valdymo schema perkelta į naują roboto architektūrą, nekeičiant pagrindinės valdymo filosofijos.
