# WRO 2026 Future Engineers dokumentacijos įvertinimas

Vertinta pagal pateiktą **Future Engineers 2026 – Documentation Rubric** (1–2 psl.) ir šiame kataloge esančius failus. Balų skalė: 6 / 4 / 2 / 0. Tai preliminarus vietinės kopijos vertinimas; GitHub istorija iš šios kopijos nepasiekiama. Atlikta dokumentacijos ir kodo peržiūra, robotas ir firmware nebuvo vykdomi.

## Rezultatas

**26/30 (87%) — stipri ir kitai komandai atkartojama dokumentacija; likusios spragos daugiausia susijusios su matavimų atsekamumu ir GitHub istorija.**

Rubrika balus skiria penkioms pagrindinėms sritims; žemiau esantys punktai paaiškina kiekvienos srities balą, bet atskirai nesumuojami.

### 1. Mobilumas ir mechaninis projektavimas — 6/6

- **Rubrika vertina:** važiuoklės projektą, pavaros ir vairavimo pasirinkimus, sukimo momento / greičio pagrindimą ir mechaninį stabilumą.
- **Repo įrodymai:** [`README.md`](README.md) pateikia greičio ir sukimo momento įverčius, pavaros bei vairavimo pasirinkimų priežastis, iteracijų palyginimus, CAD/STL, bazės vektorių, nuotraukas ir surinkimo žingsnius.
- **Balą riboja:** nėra važiuoklės bazės ir vėžės matmenų, apkrauto greičio ar mechaninio stabilumo matavimų. Vis dėlto dokumentuoti skaičiavimai, kompromisai ir iteracijos atitinka aukščiausią rubrikos lygį.

### 2. Maitinimas ir jutiklių architektūra — 6/6

- **Rubrika vertina:** maitinimo schemą, srovės pagrindimą, jutiklių pasirinkimą ir vietą, kalibravimą bei laidų schemas.
- **Repo įrodymai:** PCB brėžinyje nurodyta 90 × 100 mm plokštė; surinkimo nuotraukose matyti kairysis ir dešinysis šoniniai jutikliai bei priekyje, prie kameros, esantis jutiklis. README aprašo jų paskirtį, pasirinkimo istoriją, kalibravimo veiksmus, maitinimo eigą ir projektinį srovės biudžetą.
- **Balas:** jutiklių vietą galima susieti su trasos geometrija pagal PCB brėžinį, surinkimo nuotraukas ir toliau pateiktą lauko projekciją; README taip pat pateikia jutiklių pasirinkimo, kalibravimo, maitinimo biudžeto, gedimų ir iteracijų informaciją.
- **Tikslumo riba:** projekcija remiasi prielaida, kad 90 mm PCB kraštas eina skersai roboto. Srovės ir įtampos kritimo reikšmės yra projektinės, ne išmatuotos; reikia patvirtinti jutiklių kampus ir atlikti lauko kalibravimą.

#### Jutiklių projekcija į WRO trasą

Pagal [WRO 2026 taisykles](https://wro.hr/wp-content/uploads/2026/01/WRO-2026-Future-Engineers-Self-Driving-Cars-General-Rules.pdf) tarpas tarp trasos ribų „Open Challenge“ gali būti 600 arba 1000 mm (tarptautiniame finale ±100 mm), o „Obstacle Challenge“ — 1000 mm (±10 mm). PCB vaizde plokštė yra 90 × 100 mm; darant prielaidą, kad 90 mm kraštas eina skersai roboto ir abu šoniniai jutikliai yra ties plokštės kraštais, jų bazė yra apie 90 mm. Automobilis rodomas maždaug 165 × 145 mm.

Jei robotas važiuoja juostos viduriu, apytikslis kiekvieno šoninio jutiklio atstumas iki atitinkamos ribos yra `(trasos plotis − 90 mm) / 2`. Roboto korpuso šoninė prošvaisa skaičiuojama atskirai pagal 145 mm plotį: `(trasos plotis − 145 mm) / 2`.

| Trasos atkarpa | Tarpas tarp ribų | Šoninis jutiklis → artimiausia riba | Roboto korpusas → riba |
|---|---:|---:|---:|
| Open Challenge, siaura | 600 mm | ~255 mm | ~227,5 mm |
| Open Challenge, plati | 1000 mm | ~455 mm | ~427,5 mm |
| Obstacle Challenge | 1000 mm | ~455 mm | ~427,5 mm |

```text
Vaizdas iš viršaus — skersai koridoriaus (schema, ne pagal mastelį)

600 mm koridorius:
RIBA │← ~227,5 mm →│← 27,5 mm → ● kairysis ── 90 mm ── dešinysis ● ← 27,5 mm →│← ~227,5 mm →│ RIBA
                       ┌──────── automobilio korpusas ~145 mm ────────┐
                       │ PCB ~90 × 100 mm; jutikliai PCB kraštuose    │
                       │ priekyje: atstumo jutiklis greta Pixy2 kameros│
                       └──────────────────── PRIEKIS ↑ ────────────────┘

1000 mm koridorius:
RIBA │← ~427,5 mm →│← 27,5 mm → ● kairysis ── 90 mm ── dešinysis ● ← 27,5 mm →│← ~427,5 mm →│ RIBA

Taigi jutiklio centras iki ribos yra ~255 mm (600 mm koridoriuje) arba ~455 mm (1000 mm koridoriuje). Jutiklių bazė: ~90 mm. Roboto korpuso prošvaisa nuo abiejų ribų: ~227,5 mm arba ~427,5 mm.
```

Ši projekcija su lauko lentele, schema, prielaidomis ir `TARGET_DISTANCE` paaiškinimu įtraukta į komandos README 2.4 skiltį. Skaičiai lieka nominalūs: surinktame robote dar reikia patvirtinti jutiklių centrus bei kampus ir pridėti tikrus kalibravimo rezultatus.

### 3. Programinė architektūra ir kliūčių strategija — 4/6

- **Rubrika vertina:** kodo moduliškumą, būsenų / valdymo logiką, važiavimo ir kliūčių strategijas, algoritmų paaiškinimą ir kodo dokumentavimą.
- **Repo įrodymai:** yra būsenų diagrama, modulių aprašai, sienos sekimo / posūkio / kliūčių logika, du PlatformIO režimai, derinimo seka ir veikimo metrikos.
- **Balą riboja:** [`main.cpp`](src/src/main.cpp) posūkio ciklas neturi laiko limito, `pixy.init()` rezultatas netikrinamas, o `Kd` remiasi neatnaujinama ankstesne paklaida. README šias spragas atskleidžia, bet jos nepašalintos; bandymų santraukoje trūksta žalių žurnalų ir firmware versijos daliai rezultatų.

### 4. Sisteminis mąstymas ir inžineriniai sprendimai — 6/6

- **Rubrika vertina:** posistemių sąveiką, apribojimus ir kompromisus, sprendimų motyvus, iteracijas, bandymus bei rizikų mažinimą.
- **Repo įrodymai:** sprendimų lentelė ir roboto raidos aprašymas parodo pasirinkimus „kodėl“, o rizikų lentelė sieja gedimus su poveikiu ir mažinimo veiksmais. Yra kiekybiniai bandymų palyginimai.
- **Balą riboja:** dalies stebėjimų pirminiai duomenys neišsaugoti, todėl ne visus sprendimus galima nepriklausomai atsekti iki bandymo.

### 5. Atkartojamumas ir GitHub kokybė — 4/6 (laikinas)

- **Rubrika vertina:** GitHub struktūrą ir commitus (bent 3), README (bent 5000 simbolių), failų tvarką, CAD / laidų schemas / kodą ir galimybę robotą atkurti.
- **Repo įrodymai:** README yra **30 442 simbolių**. Yra firmware, CAD, PCB PDF/Gerber/gręžimo failai, BOM, nuotraukos, vaizdo įrašai, bandymų CSV, surinkimo žingsniai ir abiejų režimų GitHub Actions workflow.
- **Balą riboja:** vietinėje kopijoje nėra `.git`, o README nenurodo GitHub repo nuorodos, todėl commit istorijos patikrinti negalima. README taip pat nurodo, kad publikuoto release nėra.

Jei vertintojas pareikalaus commit istorijos įrodymo ir jo nepateiksite, 5 kriterijaus balas bei bendra suma mažėtų.

## Pirmiausia užpildyti spragas

1. Pridėti važiuoklės matmenų ir jutiklių padėties brėžinį su atstumais, kampais ir matymo laukais, susietą su trasos koridoriumi; pridėti realius kalibravimo rezultatus.
2. Išmatuoti srovės pikus ir maitinimo bėgių įtampos kritimą. [`validation-summary.csv`](docs/testing/validation-summary.csv) susieti su data, firmware SHA, baterijos būsena ir žalių bandymų žurnalais; dabartinis [`run-template.csv`](docs/testing/raw/run-template.csv) tuščias.
3. Uždėti laiko limitą `TURNING` būsenai, patikrinti Pixy2 paleidimo rezultatą ir pataisyti arba pašalinti nepatvirtintą `Kd` narį; pridėti regresijos bandymų įrodymus.
4. Pateikti GitHub istoriją su bent 3 prasmingais commitais ir išleisti pažymėtą firmware / dokumentacijos versiją, susietą su CSV rezultatais.

## Peržiūrėti failai

- `README.md`
- `src/src/main.cpp`, `src/platformio.ini`, `src/include/CompetitionMode.h`
- `.github/workflows/firmware.yml`, `scripts/check_final_architecture.py`
- `docs/testing/validation-summary.csv`, `docs/testing/raw/run-template.csv`
- `models/`, `schemes/` (įskaitant PCB PDF, Gerber ir gręžimo failus)
