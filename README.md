# trecia_uzduotis

## Programos tikslas

Programa siekia:
* pereiti nuo stuktūrų prie klasių
* palyginti klasių ir struktūrų spartos skirtumus
* išbandyti kompiliavimo vėliavėles ir ištirti kaip nuo jų priklauso sparta
* realizuoti tinkamus operatorius klasei
* išbandyti Unit testingus/Doxygen

## Programos esmė

* Sugeneruojami tam tikro (šiuo atveju 10 000 ir 100 000) failai su šabloniniais studentų vardais ``Vardas0  Pavarde0  3 5 9 7 2 3 3 9 4 3 9``. Naudojant vektoriaus konteinerį pagal duotą formulę ``galutinis_pazymys = vidurkis * 0.4 + 0.6 * egzaminas;`` suskaičiuojamas kiekvieno studento galutinis balas. Naudojant bendrą studentų konteinerį ir "silpnų" konteinerį bei ``std::find_if, std::copy, std::back_inserter`` pagalbą, studentai atrenkami į "stiprius" ir "silpnus" (jei galutinis balas >5 - studentas stiprus, jei ne - silpnas).

## Programos veikimo analizė (benchmarking.txt)

Štai kaip atrodo programos spartos analizės tekstinis failas programą paleidus 4 kartus:

```
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.31231 s.
100000 Apdorojimo laikas = 3.17883 s.
------------------------------------------------------------------------------:
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.185727 s.
100000 Apdorojimo laikas = 1.70363 s.
------------------------------------------------------------------------------:
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.157607 s.
100000 Apdorojimo laikas = 1.64043 s.
------------------------------------------------------------------------------:
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.180459 s.
100000 Apdorojimo laikas = 1.56524 s.

```

## [v1.1](https://github.com/gytautele/trecia_uzduotis/releases/tag/v1.1) 

```
Su struct'ūromis:

Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.384756 s.
100000 Apdorojimo laikas = 3.41232 s.
------------------------------------------------------------------------------:
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.318632 s.
100000 Apdorojimo laikas = 3.313873 s.
------------------------------------------------------------------------------:
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.23744 s.
100000 Apdorojimo laikas = 3.142581 s.

```

```
Su class'ėmis:

Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.354424 s.
100000 Apdorojimo laikas = 3.37221 s.
------------------------------------------------------------------------------:
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.323365 s.
100000 Apdorojimo laikas = 3.23744 s.
------------------------------------------------------------------------------:
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.313873 s.
100000 Apdorojimo laikas = 3.41232 s.

```

### Skirtumai tarp optimizacijos lygių

Norint pasileisti programą komandinėje eilutėje su flag'ais (čia parinkta su -O3) tereikia įrašyti ``g++ -O3 -o programa main.cpp classes/generavimas.cpp classes/function.cpp classes/timer.cpp``

Be:
```
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.31231 s.
100000 Apdorojimo laikas = 3.17883 s.
```
O1:
```
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.185727 s.
100000 Apdorojimo laikas = 1.70363 s.
```
O2:
```
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.157607 s.
100000 Apdorojimo laikas = 1.64043 s.
```
O3:
```
Programos veikimo laikai: 
10000 Apdorojimo laikas = 0.180459 s.
100000 Apdorojimo laikas = 1.56524 s.
```

### Analizės komentaras

* Struktūrų ir klasių veikimo sparta iš esmės beveik nesiskiria
* Optimizacijos lygiai žymiai spartina programos veikimą (beveik 2 kartus greičiau veikia programa)
* Priklausomai nuo optimizacijos lygio, priklausomai didėja ir programos sparta

##  [v1.2](https://github.com/gytautele/trecia_uzduotis/releases/tag/v1.2)

Realizuoti reikiami operatoriai turimai Studentas klasei.

```
std::ostream& operator<<(std::ostream out, const duomenys& studentas)
{
    out << studentas.vardas() << studentas.pavarde() << studentas.galutinis() << endl;
    return out;
}
```

```
duomenys& duomenys::operator=(const duomenys& studentas)
{
    if (&studentas == this) return *this;

    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    egz_ = studentas.egz_;
    galut_ = studentas.galut_;
    nd_ = studentas.nd_;
    return *this;
}
```

```
friend std::istream& operator>>(std::istream& in, duomenys& studentas)
    {
        in >> studentas.vardas_ >> studentas.pavarde_;
        double temp;
        for (int i = 0; i < 10; i++)
        {
            in >> temp;
            studentas.nd_.push_back(temp);
        }
        in >> studentas.egz_;
        return in;
    }
```

```
 bool operator==(const duomenys& d)
    {
        return galut_ == d.galut_;
    }
```

```
bool operator!=(const duomenys& d)
    {
        if (galut_ != d.galut_)
            return true;
        return false;
    }
```

##  [v1.5](https://github.com/gytautele/trecia_uzduotis/releases/tag/v1.5)

Vietoje turimos vienos Studentas klasės sukurkitos dvi: bazinė klasė - "Žmogus", skirta bendrai aprašyti žmogų ir jos išvestinė (derived) klasė - "Studentas".

```
class zmogus
{
protected:
    string vardas_;
    string pavarde_;
public:
    virtual void fun() = 0;
    zmogus(const string& a = " ", const string& b = " ") : vardas_{a}, pavarde_{b} {}
    zmogus(string&& a, string&& b) : vardas_{a}, pavarde_{b} {}
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline int vard_ilgis() const { return vardas_.length(); }
    inline int pavard_ilgis() const { return pavarde_.length(); }
    ~zmogus() {}
};
```

```
class Studentas : public zmogus
{
private:
    double egz_;
    double galut_;
    vector <double> nd_;
public:
    void fun() {};
    Studentas(const string& a = " ", const string& b = " ", const double& egz = 10) : zmogus(a, b), egz_{egz} {}
    Studentas(const Studentas& a) : zmogus(a.vardas_, a.pavarde_), egz_{a.egz_}, galut_{a.galut_}, nd_{a.nd_} {}
    Studentas(Studentas&& a) : zmogus(std::move(a.vardas_), std::move(a.pavarde_)), egz_{std::move(a.egz_)}, galut_{std::move(a.galut_)}, nd_{std::move(a.nd_)} {}
    inline double galutinis() const { return galut_; }
    void galutinis(char &);
    void spausdinimas(std::ofstream& out, int &, int &);
    std::istringstream irasymas(std::istringstream&);
    Studentas& operator=(const Studentas&);
    friend std::istream& operator>>(std::istream& in, Studentas& studentas)
    {
        in >> studentas.vardas_ >> studentas.pavarde_;
        double temp;
        for (int i = 0; i < 10; i++)
        {
            in >> temp;
            studentas.nd_.push_back(temp);
        }
        in >> studentas.egz_ >> studentas.galut_;
        return in;
    }
    bool operator==(const Studentas& d)
    {
        return galut_ == d.galut_;
    }
    bool operator!=(const Studentas& d)
    {
        return galut_ != d.galut_;
    }
    ~Studentas() {}
};
```
##  [v2.0](https://github.com/gytautele/trecia_uzduotis/releases/tag/v2.0)

### Doxygen

* Programinės įrangos informacinių dokumentų rašymo įrankis
* Visi Doxygen sugeneruoti failai saugomi Doxygen aplanke.
* Vienas iš sugeneruotų pavyzdžių (paveldėjimo grafas):

```   
digraph "Graphical Class Hierarchy"
{
  edge [fontname="Helvetica",fontsize="10",labelfontname="Helvetica",labelfontsize="10"];
  node [fontname="Helvetica",fontsize="10",shape=record];
  rankdir="LR";
  Node1 [label="Time",height=0.2,width=0.4,color="black", fillcolor="white", style="filled",URL="$classTime.html"];
}
```

### Unit test'ai

Norint pratestuoti programą reikia:
* atsisiųsti catch.h failą (iš oficialios CLion svetainės, kadangi ten nuolat atnaujinama)
* jį iclud'inti ``#include "headers/catch.h"`` į test.cpp failą
* pasirašyti kelis testus funkcijoms, kurias norima testuoti
* komandinėjė eilutėje parašyti komandą ``g++ test.cpp classes/function.cpp -o <programos pavadinimas>``
* pasileisti testo rezultatus naudojant ``./<programos pavadinimas>``

Štai kaip atrodo mano test.cpp:

```
#define CATCH_CONFIG_MAIN
#include "headers/catch.h"
#include "headers/main_header.h"
#include "headers/time.h"

TEST_CASE("Testas1")
{
    CHECK(kazkas("0") == 0); //gerai
    CHECK(kazkas("ABC") == 0); //blogai
    CHECK(kazkas("Test1234") == 0); //blogai
}

duomenys stud1;
duomenys stud2;

TEST_CASE("Testas2")
{
    stud1.galutinis() == 5;
    CHECK(tikrinimas_5(stud1) == true); //gerai
    stud2.galutinis() == 17;
    CHECK(tikrinimas_5(stud2) == false); //blogai
    stud2.galutinis() == 5;
    CHECK(tikrinimas_5(stud2) == false); //gerai
}
```
Testų rezultatai:

```
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
test is a Catch v2.7.2 host application.
Run with -? for options

-------------------------------------------------------------------------------
Testas2
-------------------------------------------------------------------------------
test.cpp:17
...............................................................................

test.cpp:20: FAILED:
  CHECK( tikrinimas_5(stud1) == true )
with expansion:
  false == true

===============================================================================
test cases: 2 | 1 passed | 1 failed //iš dviejų vienas praėjo
assertions: 5 | 4 passed | 1 failed //iš 5 praėjo 4, vienas sufeilino
```

## Programos paleidimas

Nusikloninti repozitoriją `` git clone https://github.com/gytautele/trecia_uzduotis.git ``. Norint pasileisti programą tereikia turėti CMakeLists.txt. Visi sugeneruoti failai, rezultatų failai ir programos analizės failas "benchmarking.txt" (kuriame rašomi programos veikimo laikai) bus įrašytas į folderį "build".
