# Seno Algoritmo Pritaikymas Naujame Robote

## Kas Išlieka Tas Pats

Senojo roboto idėja iš esmės išlieka ta pati:

- jutiklių nuskaitymas;
- paklaidos apskaičiavimas;
- PD arba panašus korekcinis valdymas;
- vairo ir važiavimo komandų formavimas;
- kliūčių logika ir saugus sustojimas.

Tai reiškia, kad keičiasi ne algoritmo esmė, o jo pritaikymas prie naujo roboto aparatūros.

## Kas Keičiasi

| Seno repo komponentas | Naujo repo komponentas | Pastaba |
| --- | --- | --- |
| `Arduino Mega 2560` | `ESP32` | Valdymas pereina į `ESP32`, nes jis vykdo visus skaičiavimus ir komandas. |
| `Raspberry Pi Zero 2` | `Raspberry Pi Zero` | Naujoje versijoje Pi naudoja tik kamerai. |
| `Adafruit Motor Shield V2` | `L298N H-bridge` | Variklio valdymas keičiasi, bet drive logika lieka panaši. |
| `VL53L1X` | `VL53L5CX` | Išlieka ToF pagrindu veikiantis kliūčių matavimas, tik keičiasi modulis. |
| `TCS34725` | nenaudojamas | Jei ši funkcija naujame robote nereikalinga, jos logikos neperkeliame. |
| `SG90` | `MG90S` | Vairo servo principas išlieka toks pats, tik keičiasi konkretus servomechanizmas. |
| DC variklis + perdavimas | `N20` + `L298N` | Važiavimo logika išlieka, tik hardware sprendimas kitoks. |

## Kokia Logika Perkeliama

Seno repo README matosi tokia seka:

1. jutiklių nuskaitymas;
2. paklaidos įvertinimas;
3. PD valdymas;
4. servo vairavimas;
5. variklio greičio korekcija;
6. kliūties logika.

Šią pačią struktūrą galima perkelti į naują robotą, tik pritaikant ją prie `ESP32` skaičiavimų ir kameros duomenų iš `Raspberry Pi Zero`.

## Kaip Tai Atrodo Naujame Robote

- `Raspberry Pi Zero` tik fiksuoja kamerą ir perduoda kameros duomenis.
- `ESP32` sujungia kameros informaciją su `BNO085` ir `VL53L5CX`.
- `ESP32` apskaičiuoja paklaidą ir elgsenos būseną.
- `ESP32` siunčia servo ir variklio komandas.
- Saugos logika nutraukia važiavimą, jei įvestys tampa nepatikimos.

## Naudojimo Paskirtis

Šis dokumentas padeda perkelti seną algoritminę idėją į naują konstrukciją nekeičiant pagrindinės valdymo filosofijos.
Jei vėliau algoritmas bus keičiamas, šį failą reikia atnaujinti kartu su `docs/code/control_algorithms.md`.
