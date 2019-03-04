#include "circle.h"

int main () {
    vector<mok> duomenys;

    auto startas = std::chrono::system_clock::now();

    int jj;
    cout << "Jei norite generuoti 5 tekstinius failus, spauskite 5" << endl;
    cin >>jj;

    int nr=1;

    if (jj==5) {

        for (int i=0; i<5; i++)
        {
            nr=nr*10;
            generuoti_txt(i, nr);
            skaitymas_gen (duomenys, i);

            for (int j=0; j<nr; j++)
            {
                mediana(duomenys, j);
                vidurkis(duomenys, j);
                rezultatu_skaidymas (duomenys, j);

            }

            //if (nr==100) break;

        }

    }

    auto pabaiga = std::chrono::system_clock::now();
    auto uztruko = std::chrono::duration_cast< std::chrono::duration<double> >(pabaiga - startas).count();
    cout << "Failo generavimas ir skaitymas uztruko: " << uztruko << " sekundziu" << endl;

    if (jj==5) return 0;

    int m = 0;

    const int a = pasirinkimas();

    if (a == 0) {
        int n = mok_sk(m);
        for (int i = 0; i < n; i++) {
            duomenys.push_back(mok()); //pastumia elementus
            ivedimas(duomenys, i);
            int b = pasirinkimas2();

            if (b == 2) {
                generacija(duomenys, i);
                mediana(duomenys, i);
                vidurkis(duomenys, i);
                if (i==0) remelis();
                spausdinimas(duomenys, i);
            } else {
                ivedimas_rezultatu(duomenys, i);
                mediana(duomenys, i);
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
            mediana(duomenys, i);
            vidurkis(duomenys, i);
            if (i==0) remelis();
            rikiavimas(duomenys, nr);
            spausdinimas (duomenys, i);
        }

    }

    return 0;
}