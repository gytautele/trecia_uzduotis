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

Jei norite išbandyti programą tereikia pasileisti CMakeLists.txt. Arba Makefile:

```shell
Run:
	g++ -o test main.cpp circle.cpp
	./test
  
Clear:
	rm *.md test
```

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

### v0.5:

#### Programos veikimo laikas:

* kai užduotis atlikta su vektoriais (kai dirbama su txt failais iškart):
```shell
1-ojo failo skaitymas uztruko: 0.0092488 sekundziu
2-ojo failo skaitymas uztruko: 0.0222416 sekundziu
3-ojo failo skaitymas uztruko: 0.0885235 sekundziu
4-ojo failo skaitymas uztruko: 0.594704 sekundziu
5-ojo failo skaitymas uztruko: 5.72 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 4.88297 sekundziu
Visos programos veikimas: 10.6052 sekundziu
```
* kai užduotis atlikta su vektoriais (kai dirbama su vektoriais, vėliau juos išvedant į txt failus):
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.0081432 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0226051 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.135645 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 1.3408 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 11.9233 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 32.6658 sekundziu
Visos programos veikimas: 44.5918 sekundziu
```
* kai užduotis atlikta su deque:
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.0079596 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0238214 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.147717 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 1.43002 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 13.1182 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 32.3071 sekundziu
Visos programos veikimas: 45.4265 sekundziu
```
* kai užduotis atlikta su list'ais:
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.0089147 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0374781 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.17075 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 1.30393 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 10.1137 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 5.48772 sekundziu
Visos programos veikimas: 15.6039 sekundziu
```
### Spartos analizės komentaras

Lyginant programos darbą, kai dirbama su vektoriais, ji sparčiau veikia, kai iškart dirbama su txt failais, o ne saugant duomenis į vektorius ir tada juos išvedinėjant į txt failus. Naudojant vektorius ir deque programos sparta beveik nesiskiria. Lyginant std::<vector> ir std::<deque> konteinerius su list'ais skirtumas yra labai žymus - programa veikia pastebimai efektyviau.
  
 ### v1.0:
  
1 strategija:
* Užduoties spartos analizė,ž pateikta ankstesnėje versijoje (kadangi ji sutampa su mano atlikta).
* Normalu, kad sunaudojama daugiau atminties, kadangi tas pats studentas yra abejuose konteineriuose.

2 strategija:
* Atminties požiuriu ši strategija daug efektyvesnė.
* Laiko atžvilgiu užtrunka daug ilgiau:

su std::vector:
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.0051894 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0206429 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.141827 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 1.33938 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 12.8433 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 452.1433 sekundziu
```
su std::deque:
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.0078154 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0106421 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.182842 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 2.31939 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 11.8038 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 489.1253 sekundziu
```
su std::list:
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.0042882 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0192858 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.0538119 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 0.324236 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 2.27059 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 1.74474 sekundziu
Visos programos veikimas: 4.01631 sekundziu
```
 ### v1.0 (panaudojant algoritmus, spartinančius programą):
 
 su std::vector:
```shell
1-ojo failo generavimas ir skaitymas uztruko: 0.0049746 sekundziu
2-ojo failo generavimas ir skaitymas uztruko: 0.0099501 sekundziu
3-ojo failo generavimas ir skaitymas uztruko: 0.0419666 sekundziu
4-ojo failo generavimas ir skaitymas uztruko: 0.310295 sekundziu
5-ojo failo generavimas ir skaitymas uztruko: 3.95761 sekundziu
Rezultatu skaidymas i du tekstinius failus uztruko: 2.86979 sekundziu
Visos programos veikimas: 6.82846 sekundziu
```
### Spartos analizės komentaras

Atliekant programą pagal 2 strategiją su vektoriais, programos darbas tikrai ilgas. Modifikavus tą pačią programą, panaudojus algoritmą stable_partition programos sparta žymiai didesnė. Išvada: algoritmai gali žymiai paspartinti programos veikimą.
 
## Papildoma užduotis

#### Užduotis buvo atlikta 3-mis būdais:

1) rasksilpnus(duomenys):
* pushback'inama į silpnus, tada panaudojamas rikiavimas pagal galutinį pažymį ir naudojama resize();

``` shell
Su 10 000:
Rezultatu skaidymas uztruko: 0.220801 sekundziu
Su 100 000:
Rezultatu skaidymas uztruko: 2.89496 sekundziu
```

2) raskminkstus(duomenys):
* pushback'inama į silpnus ir ištrinama iš bendro sąrašo;

``` shell
Su 10 000:
Rezultatu skaidymas uztruko: 0.0241977 sekundziu
Su 100 000:
Rezultatu skaidymas uztruko: 0.441977 sekundziu
```

3) iterpkkietus(duomenys):
* pushback'inama į silpnus, insert'inama į priekį ir resiz'inama pagal suskaičiuotą kietų kiekį;

``` shell
Su 10 000:
Rezultatu skaidymas uztruko: 35.0112 sekundziu
Su 100 000:
Rezultatu skaidymas uztruko: 487.7854 sekundziu
```

4) Kai naudojama deque (testuojama 3 funkcija su insert()):

``` shell
Su 10 000:
Rezultatu skaidymas uztruko: 0.0512288 sekundziu
Su 100 000:
Rezultatu skaidymas uztruko: 0.429334 sekundziu
```

5) Kai naudojama deque (testuojama 3 funkcija su push_front()):

``` shell
Su 10 000:
Rezultatu skaidymas uztruko: 0.0481059 sekundziu
Su 100 000:
Rezultatu skaidymas uztruko: 0.411112 sekundziu
```

### Analizės komentaras

Lyginant funkcijų pranašumą tarpusavyje, kai dribama tik su vektoriais, greičiausiai veikia 2 funkcija. Antroje vietoje pagal spartą yra 1 funkcija, o 3-čia žymiai nusileidžia spartos atžvilgiu likusioms dviems. Lyginant vektorius su deque, bet kuriuo atveju, deque lenkia vektorių pagal spartą. Išvada: kai yra dirbama su deque ir naudojama push_front funkcija programa veikia greičiausiai.
