# 2 užduotis

## Programos tikslas

Programa nuskaito mokinio duomenis, paskaičiuoja galutinį studento pažymį naudojant vidurkį ir medianą.
```shell
Pavardė     Vardas   Galutinis (Vid.)    Galutinis (Med.)
-----------------------------------------------------------
Arvydas     Sabonis         x.xx               x.xx
Rimas       Kurtinaitis     y.yy               y.yy
```
## Programos naudojimas

Programą galima naudoti įvedant rezultatus pačiam arba nuskaitant rezultatus iš susidaryto tekstinio failo.

Tekstinio failo pavyzdys:
```shell
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Pavardė1    8    9     10   6    10   9
Vardas2     Pavardė2    7    10    8    5    4    6
...
```
Taip pat yra galimybė atsitiktinai sugeneruoti 5 tekstinius šabloninius failus, apskaičiuoti kiekvieno mokinio galutinį balą pagal vidurkį ir rezultatus įrašyti į du tekstinius failus: kietiakai.txt ir silpnuoliai.txt:

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

## Versijų istorija

* v0.1.1 pirmi_du_punktai - Vidurkio ir medianos skaičiavimas

* v0.1.2 pirmi_du_punktai + generacija - Pridėta galimybė pasirinktinai generuoti egzamino rezultatus

* v0.1.3 c_masyvas - Užduotis įvykdyta pakeičiant statinį masyvą į dinaminį, tuomet, kai vartotojas pasirinktinai veda tiek, kiek nori elementų.

* v0.1 su_vektoriais - Užduotis atlikta su vektoriais. Nepapildyta jokiais saugikliais. Bus pridėta vėliau.

* v0.2 su_txt - Pridėta galimybė duomenis nuskaityti iš duomenų failo. Rezultatai išrikiuoti. Programa perskirtyta: iš ilgo main'o perdaryta į funkcijas - supaprastintas programos kodas.

* v0.3 isskaidyta_programa - Iš vieno .cpp failo padaryta main.cpp circle.h ir circle.cpp. Pridėtas minimalus išimčių valdymas skaitymo funkcijoje.

* v0.3.1 isskaidyta_programa+txt - Pridėtas tekstinis failas.

* v0.4.1 5_txt_generacija - Pridėta funkcija, kurioje galima generuoti 5 šabloninius .txt failus. Sugrįžta prie ištisos programos. Galutinėje versijoje programa taip pat bus išskaidyta.

* v0.4 tekstiniu_generacija_ir_laiko_skaiciavimas - Sugeneruoti penki šabloniniai sąrašai. Studentai padalinti į dvi kategorijas. Atlikta programos veikimo analizė.


