#ifndef FUNCTION
#define FUNCTION
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<random>
#include<algorithm>
#include<vector>
#include<sstream>
#include<ctype.h>
#include<chrono>
#include<list>
#include<deque>
#include<iterator>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::list;
using std::deque;

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

std::ostream& operator<<(std::ostream&, const Studentas&);

bool tikrinimas_gal(Studentas, Studentas);
bool tikrinimas_5(Studentas);
bool tikrinimas_vard(Studentas, Studentas);
bool tikrinimas_pavard(Studentas, Studentas);

void skaitymas(vector <Studentas>&, int, char&);

void ilgio_nustatymas(vector<Studentas>&, int&, int&);

void isvedimas(vector <Studentas>&, vector <Studentas>&, int&, int&);

void atrinkimas(vector <Studentas>&, vector<Studentas>&);

void generavimas2();

#endif // FUNCTION