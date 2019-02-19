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

int main () {
    int f; //pasirinkimui
    cout << "Jei norite ivesti duomenis ranka, spauskite 0, jei norite is tekstinio failo spauskite :1" << endl;
    cin >> f;

    if (f == 0) {
        vector<mok> duomenys;
        int m = 0;

        cout << "Iveskite mokiniu skaiciu:" << endl;
        cin >> m;

        for (int i = 0; i < m; i++) {

            duomenys.push_back(mok());

            cout << "Iveskite studento varda ir pavarde" << endl;
            duomenys.push_back(mok());
            cin >> duomenys[i].vardas;
            cin >> duomenys[i].pavarde;

            int a; //skaicius skirtas pasirinkti
            int b; //laikinas kintamasis pazymiui irasyti i vektoriu

            cout << "Jei norite generuoti rezultatus automatiskai spauskite 0. Jei norite ivesti patys spauskite 1:"
                 << endl;
            cin >> a;

            if (a == 1) {

                cout << "Iveskite namu darbu rezultatus. Kai noresite baigti - spauskite 0:" << endl;

                do {
                    cin >> b;
                    if (b > 0 && b < 11) {
                        duomenys[i].nd.push_back(b);
                        duomenys[i].paz_sk++;
                        duomenys[i].sum += b;
                    }

                } while (b != 0);

                duomenys[i].vid = (double) duomenys[i].sum / (double) duomenys[i].paz_sk;
                std::sort(duomenys[i].nd.begin(), duomenys[i].nd.end());

                if (duomenys[i].paz_sk % 2 != 0) duomenys[i].med = (double) duomenys[i].nd[duomenys[i].paz_sk / 2];
                else
                    duomenys[i].med = (double) (duomenys[i].nd[(duomenys[i].paz_sk - 1) / 2] +
                                                duomenys[i].nd[duomenys[i].paz_sk / 2]) / 2.0;

                cout << "Iveskite egzamino pazymi:" << endl;
                cin >> duomenys[i].egz;
            } else

                {
                int kiek;
                int laik;
                cout << "Kiek norite generuoti skaiciu?" << endl;
                cin >> kiek;

                for (int j = 0; j < kiek; j++) {
                    laik = rand() % 10 + 1;
                    duomenys[i].nd.push_back(laik);
                    duomenys[i].sum += laik;
                }

                laik = rand() % 10 + 1;
                duomenys[i].egz = laik;

                duomenys[i].vid = (double) duomenys[i].sum / (double) kiek * 1.0;

                std::sort(duomenys[i].nd.begin(), duomenys[i].nd.end());

                if (duomenys[i].paz_sk % 2 != 0) duomenys[i].med = (double) duomenys[i].nd[kiek / 2];

                else
                    duomenys[i].med = (double) (duomenys[i].nd[(duomenys[i].paz_sk - 1) / 2] +
                                                duomenys[i].nd[duomenys[i].paz_sk / 2]) / 2.0;
            }

        }

        cout << "Pavarde" << std::right << setw(20) << "Vardas" << std::right << setw(20) << "VidGalutinis"
             << std::right << setw(20) << "MedGalutinis" << endl;
        cout << "------------------------------------------------------------------------" << endl;

        for (int i = 0; i < m; i++) {
            duomenys[i].galutinis1 = 0.4 * duomenys[i].vid + 0.6 * (double) duomenys[i].egz;
            duomenys[i].galutinis2 = 0.4 * duomenys[i].med + 0.6 * (double) duomenys[i].egz;
            cout << duomenys[i].pavarde << std::right << setw(20) << duomenys[i].vardas << std::right << setw(20)
                 << std::fixed << std::setprecision(2) << std::right << duomenys[i].galutinis1 << setw(20) << std::right
                 << duomenys[i].galutinis2 << endl;
        }

    }
    if (f==1)
        {

        std::ifstream in("kursiokai.txt");
        std::vector<mok> duomenys;
        int temp = 0, temp_nd;
        string eilute;
        getline(in, eilute);
        while (getline(in, eilute)) {
            std::istringstream skaitymas(eilute);
            duomenys.push_back(mok());
            skaitymas >> duomenys[temp].vardas;
            skaitymas >> duomenys[temp].pavarde;
            while (skaitymas) {
                skaitymas >> temp_nd;
                duomenys[temp].nd.push_back(temp_nd);
            }
            duomenys[temp].egz = duomenys[temp].nd.back();
            duomenys[temp].nd.erase(duomenys[temp].nd.end() - 1);
            duomenys[temp].nd.erase(duomenys[temp].nd.end() - 1);
            temp++;
        }
        in.close();

        for (int i = 0; i<duomenys.size(); i++) {
            duomenys[i].vid = 0;
            for (int w = 0; w < duomenys[i].nd.size(); w++) {
                duomenys[i].vid += duomenys[i].nd[w];
            }
            duomenys[i].vid /= duomenys[i].nd.size() * 1.0;
            std::sort(duomenys[i].nd.begin(), duomenys[i].nd.end());
            if (duomenys[i].nd.size() % 2 == 0) {
                duomenys[i].med =
                        (duomenys[i].nd[duomenys[i].nd.size() / 2 - 1] + duomenys[i].nd[duomenys[i].nd.size() / 2]) /
                        2.0;
            } else {
                duomenys[i].med = duomenys[i].nd[duomenys[i].nd.size() / 2] * 1.0;
            }
        }

        cout << "Pavarde" << std::right << setw(20) << "Vardas" << std::right << setw(20) << "VidGalutinis"
             << std::right << setw(20) << "MedGalutinis" << endl;
        cout << "------------------------------------------------------------------------" << endl;

        for (int i = 0; i < duomenys.size(); i++) {
            duomenys[i].galutinis1 = 0.4 * duomenys[i].vid + 0.6 * (double) duomenys[i].egz;
            duomenys[i].galutinis2 = 0.4 * duomenys[i].med + 0.6 * (double) duomenys[i].egz;
            cout << duomenys[i].pavarde << std::right << setw(20) << duomenys[i].vardas << std::right << setw(20)
                 << std::fixed << std::setprecision(2) << std::right << duomenys[i].galutinis1 << setw(20) << std::right
                 << duomenys[i].galutinis2 << endl;
        }

    }
}