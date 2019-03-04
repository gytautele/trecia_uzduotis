#include "circle.h"

int main () {

    vector<mok> duomenys;

    int m = 0;
    double med=0;

    const int a = pasirinkimas();

    if (a == 0) {
        int n = mok_sk(m);
        for (int i = 0; i < n; i++) {
            duomenys.push_back(mok()); //pastumia elementus
            ivedimas(duomenys, i);
            int b = pasirinkimas2();

            if (b == 2) {
                generacija(duomenys, i);
                mediana(duomenys, i, med);
                duomenys[i].med=med;
                vidurkis(duomenys, i);
                if (i==0) remelis();
                spausdinimas(duomenys, i);
            } else {
                ivedimas_rezultatu(duomenys, i);
                mediana(duomenys, i, med);
                duomenys[i].med=med;
                vidurkis(duomenys, i);
                if (i==0) remelis();
                spausdinimas(duomenys, i);

            }
        }
    }
    else
    {
        int nr=0;
        skaitymas(duomenys, nr);

        for (int i=0; i<nr; i++)
        {
            mediana(duomenys, i, med);
            duomenys[i].med=med;
            vidurkis(duomenys, i);
            if (i==0) remelis();
            rikiavimas(duomenys, nr);
            spausdinimas (duomenys, i);
        }

    }

    return 0;
}