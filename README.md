# 2 užduotis

## Programos tikslas

### v0.1-v0.3

Programa nuskaito mokinio duomenis, paskaičiuoja galutinį studento pažymį naudojant vidurkį ir medianą.
```shell
Pavardė     Vardas   Galutinis (Vid.)    Galutinis (Med.)
-----------------------------------------------------------
Arvydas     Sabonis         x.xx               x.xx
Rimas       Kurtinaitis     y.yy               y.yy
```
### v0.4 ir toliau

Programos tikslas yra ir patikrinti kaip sparčiai programa gali atlikti užduotį ir kaip jos vykdymo greitis priklauso nuo pradinių duomenų failo dydžio ir kiekio.

## Programos naudojimas

Programą galima naudoti įvedant rezultatus pačiam arba nuskaitant rezultatus iš sudaryto/asmeniškai susidaryto tekstinio failo.

Tekstinio failo pavyzdys:
```shell
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Pavardė1    8    9     10   6    10   9
Vardas2     Pavardė2    7    10    8    5    4    6
...
```
Taip pat yra galimybė atsitiktinai sugeneruoti 5 tekstinius šabloninius failus, apskaičiuoti kiekvieno mokinio galutinį balą pagal vidurkį (arba medianą pasirinktinai) ir rezultatus įrašyti į du tekstinius failus: kietiakai.txt ir silpnuoliai.txt:

Šabloninio tekstinio failo pavyzdys:
```shell
Vardas0 Pavarde0 8 8 4 7 7 
Vardas1 Pavarde1 4 6 7 5 1 
Vardas2 Pavarde2 8 1 8 5 3
...
```
Kietiakai.txt failo pavyzdys:
```shell
Vardas0 Pavarde0 8.9
Vardas3 Pavarde3 7.2
Vardas4 Pavarde4 7.3
Vardas6 Pavarde6 8.3
...
```
## Programos paleidimas

Jei norite išbandyti programą tereikia pasileisti CMakeLists.txt.

## Versijų istorija

### v0.1:

* v0.1.1 pirmi_du_punktai - Vidurkio ir medianos skaičiavimas
* v0.1.2 pirmi_du_punktai + generacija - Pridėta galimybė pasirinktinai generuoti egzamino rezultatus
* v0.1.3 c_masyvas - Užduotis įvykdyta pakeičiant statinį masyvą į dinaminį, tuomet, kai vartotojas pasirinktinai veda tiek, kiek nori elementų.
* v0.1 su_vektoriais - Užduotis atlikta su vektoriais. Nepapildyta jokiais saugikliais. Bus pridėta vėliau.

### v0.2:

* v0.2 su_txt - Pridėta galimybė duomenis nuskaityti iš duomenų failo. Rezultatai išrikiuoti. Programa perskirtyta: iš ilgo main'o perdaryta į funkcijas - supaprastintas programos kodas.

### v0.3:

* v0.3 isskaidyta_programa - Iš vieno .cpp failo padaryta main.cpp circle.h ir circle.cpp. Pridėtas minimalus išimčių valdymas skaitymo funkcijoje.
* v0.3.1 isskaidyta_programa+txt - Pridėtas tekstinis failas.

### v0.4:

* v0.4.1 5_txt_generacija - Pridėta funkcija, kurioje galima generuoti 5 šabloninius .txt failus. Sugrįžta prie ištisos programos. Galutinėje versijoje programa taip pat bus išskaidyta.
* v0.4 tekstiniu_generacija_ir_laiko_skaiciavimas - Sugeneruoti penki šabloniniai sąrašai. Studentai padalinti į dvi kategorijas. Atlikta programos veikimo analizė.
* v0.4.3 v0.1_istaisymas - Ištaisyta pirma versija, kurioje buvo reikalauti padaryti 2 cpp failus: pirmame užduotį atlikti su masyvais, antrame - su vektoriais. Pridėta apsauga nuo tuščio vektoriaus tuo atveju, jei vartotojas neįveda jokių duomenų.
* v0.4.4 v0.2/v0.3_istaisymas - Pataisyta 3 versija, bet kartu ir 2 , kadangi jos glaudžiai susiję: sutaisyta try catch, kadangi laužė visą programą; įdėta apsauga medianos ir vidurkio skaičiavime; nuimtas medianos referencas, kad nebūtų išsaugomi sortinami rezultatai; vietoj sumos naudojama funkcija std::accumulate
* v0.4.5 pataisyta_v0.4_versija - Pridėta: tvarkingas stulpelių rikiavimas pagal ilgiausią vardą/pavardę; panaudota rikiavimo funkcija, kuri per nepastabumą buvo apibrėžta, bet nenaudojama; pridėtas tekstinių failų ištrynimas prieš pradedant programą; Yra bėdų su programos veikimo laiku.
* v0.4.6 spartesne_v0.4 - Sutrumpintas programos veikimo laikas. Pridėta išsamenė analizė:

#### Programos veikimo laikas:
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.013295 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0307256 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.150251 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 1.33017 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 12.1396 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 0.54403 sekundziu
Visos programos veikimas: 12.6853 sekundziu
```
