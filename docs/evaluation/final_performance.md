# Galutinis Našumas

Galutinė roboto versija buvo orientuota ne į maksimalų greitį, o į stabilesnį ir pakartojamą važiavimą trasoje.
Pagrindiniai pagerėjimai buvo pasiekti sumažinus mechaninę vairo apkrovą, palikus diferencialą ir aiškiau atskyrus jutiklių vaidmenis.

## Vairavimo Elgsena

Vairo sistema po geometrijos korekcijų veikė nuosekliau nei ankstesniuose bandymuose.
Servo apkrova sumažėjo, nes buvo pašalinta didelio rato peties problema, o priekinių ratų judesys išliko simetriškesnis.

## Posūkiai ir Trauka

Galinės ašies diferencialas pagerino roboto elgesį posūkiuose.
Palyginti su ankstesniu robotu be diferencialo, sumažėjo pasipriešinimas sukimui, todėl robotas posūkiuose judėjo sklandžiau ir mažiau slydo.

## Jutiklių Darbas

Kamera liko pagrindinis bendro trasos vaizdo šaltinis, o 2 `VL53L5CX` moduliai buvo naudojami artimo atstumo patvirtinimui.
`BNO085` papildė sistemą krypties ir judėjimo stabilumo informacija, ypač po kelių iš eilės posūkių.
Toks jutiklių vaidmenų paskirstymas padėjo sumažinti vieno jutiklio klaidos įtaką visam sprendimų ciklui.

## Likę Apribojimai

Tikslių skaitinių našumo rodiklių dar nėra surinkta tiek, kad būtų galima pateikti pilną kiekybinę lentelę.
Todėl šiame etape galutinis našumas apibendrinamas pagal realius testus ir stebėtą roboto elgesį trasoje.

## Tolimesni Patobulinimai

Toliau verta rinkti vienodos metodikos testų rezultatus: vairo centro paklaidą, pakartojamumą per kelis važiavimus ir kliūčių įveikimo sėkmės procentą.
Tai leistų šalia kokybinio vertinimo pateikti ir aiškią skaitinę pažangą tarp versijų.
