#ifndef PENKTA_SU_HEADERIAIS_CIRCLE_H
#define PENKTA_SU_HEADERIAIS_CIRCLE_H

#endif //PENKTA_SU_HEADERIAIS_CIRCLE_H

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
#include <chrono>
#include <numeric> //std::accumulate

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
    vector <int> nd_gen; //saugomi sugeneruoti skaiciai , kai dirbama su tekstiniais failais
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
double mediana(vector<mok> duomenys, int i, double &med);
void vidurkis(vector<mok> &duomenys, int i);
void spausdinimas(vector<mok> &duomenys, int i, int did_vard, int did_pav);
void skaitymas (vector<mok> &duomenys, int &nr);
void remelis (vector<mok> &duomenys, int i, int &did_vard, int &did_pav);
void rikiavimas (vector<mok> &duomenys, int &nr);
void generuoti_txt(int i, int &nr);
void skaitymas_gen (vector<mok> &duomenys, int &i);
void rezultatu_skaidymas(vector<mok> &duomenys, int &i);

