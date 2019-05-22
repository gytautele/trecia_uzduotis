#ifndef V1_1_MAIN_HEADER_H
#define V1_1_MAIN_HEADER_H

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
using std::string;

class duomenys
{
private:
    string vardas_;
    string pavarde_;
    double egz_{};
    double galut_{};
    vector <double> nd_;

public:
    duomenys(){}
    duomenys(const duomenys&);
    duomenys(duomenys&& s) :  //kodel 2 referencai???
            vardas_{s.vardas_},
            pavarde_{s.pavarde_},
            egz_{s.egz_},
            galut_{std::move(s.galut_)},
            nd_{std::move(s.nd_)}{}

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double galutinis() const { return galut_; }
    inline int vard_ilgis() const { return vardas_.length(); }
    inline int pavard_ilgis() const { return pavarde_.length(); }

    void galutinis(char &);
    void spausdinimas(std::ofstream& out, int &, int &);
    std::istringstream irasymas(std::istringstream&);
    duomenys& operator=(const duomenys&);

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
    bool operator==(const duomenys& d)
    {
        return galut_ == d.galut_;
    }
    
    bool operator!=(const duomenys& d)
    {
        if (galut_ != d.galut_)
            return true;
        return false;
    }
    ~duomenys() = default;
};

std::ostream& operator<<(std::ostream&, const duomenys&);

bool tikrinimas_gal(duomenys, duomenys);
bool tikrinimas_5(duomenys);
bool tikrinimas_vard(duomenys, duomenys);
bool tikrinimas_pavard(duomenys, duomenys);

void skaitymas(vector <duomenys>&, int, char&);
void ilgio_nustatymas(vector<duomenys>&, int&, int&);
void isvedimas(vector <duomenys>&, vector <duomenys>&, int&, int&);
void atrinkimas(vector <duomenys>&, vector<duomenys>&);
void generavimas(std::ofstream&, int);
void generavimas2();
int kazkas(const char string1[]);

#endif //V1_1_MAIN_HEADER_H
