#ifndef MAIN_SU_TXT_CIRCLE_H
#define MAIN_SU_TXT_CIRCLE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::setw;
using std::vector;

struct mok
{
    string vardas;
    string pavarde;
    vector <int> nd;
    double galutinis1=0; //rezultatas su vidurkiu
    double galutinis2=0; //rezultatas su mediana
    int egz=0;
    int sum=0;
    double med=0;
    double vid=0;
    int paz_sk=0;
};


int pasirinkimas ();
int mok_sk (int &m);
void ivedimas (vector<mok> &duomenys, int i);
int pasirinkimas2();
void generacija(vector<mok> &duomenys, int i);
void ivedimas_rezultatu(vector<mok> &duomenys, int i);
double mediana(vector<mok> &duomenys, int i);
void vidurkis(vector<mok> &duomenys, int i);
void spausdinimas(vector<mok> &duomenys, int i);
void skaitymas (vector<mok> &duomenys, int &nr);
void remelis ();
void rikiavimas (vector<mok> &duomenys, int &nr);

#endif //MAIN_SU_TXT_CIRCLE_H

