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
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double galutinis() const { return galut_; }
    inline int vard_ilgis() const { return vardas_.length(); }
    inline int pavard_ilgis() const { return pavarde_.length(); }
    void galutinis(char &);
    void spausdinimas(std::ofstream& out, int &, int &);
    std::istringstream irasymas(std::istringstream&);
    ~duomenys() = default;
};

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

#endif //V1_1_MAIN_HEADER_H
