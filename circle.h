#ifndef PENKTA_SU_HEADERIAIS_CIRCLE_H
#define PENKTA_SU_HEADERIAIS_CIRCLE_H

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
#include <random>
#include <deque>
#include <list>
#include <iterator>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::setw;
using std::vector;
using std::deque;
using std::list;

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
void ivedimas (deque<mok> &duomenys, int i);
int pasirinkimas2();
void generacija(deque<mok> &duomenys, int i);
void ivedimas_rezultatu(deque<mok> &duomenys, int i);
double mediana(deque<mok> duomenys, int i, double &med);
void vidurkis(deque<mok> &duomenys, int i);
void spausdinimas(deque<mok> &duomenys, int i, int did_vard, int did_pav);
void skaitymas (deque<mok> &duomenys, int &nr);
void remelis (deque<mok> &duomenys, int i, int &did_vard, int &did_pav);
void rikiavimas (deque<mok> &duomenys, int &nr);
void generuoti_txt(int i, int &nr);
void skaitymas_gen (list<mok>& duomenyss, int i);
void rezultatu_skaidymas(list<mok> &duomenyss, list<mok> &silpnii, list<mok> &kietii);
void spausdinu (list<mok> silpnii, list<mok> kietii);

#endif //PENKTA_SU_VEKTORIAIS_CIRCLE_H
