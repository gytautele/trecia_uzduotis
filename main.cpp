#include "circle.h"

int main () {

    deque<mok> duomenys;
    deque<mok> silpni;

    double med=0;

    int jj;
    cout << "Jei norite generuoti 5 tekstinius failus, spauskite 5. Jei ne- bet koki kita skaiciu:" << endl;
    cin >> jj;

    std::remove("silpnuoliai.md");
    std::remove("kietiakai.md");

    int nr=1;
    int sk = 0;
    int h=0;
    int j=0;

    if (jj==5) {

        for (int i=0; i<1; i++)
        {
            nr=10000;
            generuoti_txt(i, nr);
            skaitymas_gen (duomenys, i, sk, h, j);
        }

        auto startas = std::chrono::system_clock::now();
        //silpni=rasksilpnus(duomenys);
        //silpni=raskminkstus(duomenys);
        silpni=iterpkkietus(duomenys, nr);
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast< std::chrono::duration<double> > (pabaiga - startas).count();
        cout << "Rezultatu skaidymas uztruko: " << uztruko << " sekundziu" << endl;

        spausdinu(silpni, duomenys);
    }

    if (jj==5) return 0;

    int did_vard=0;
    int did_pav=0;

    if (jj!=5)
    {
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
                    mediana(duomenys, i, med);
                    duomenys[i].med=med;
                    vidurkis(duomenys, i);
                    if (i==0) remelis(duomenys, i, did_vard, did_pav);
                    spausdinimas(duomenys, i, did_vard, did_pav);
                } else {
                    ivedimas_rezultatu(duomenys, i);
                    mediana(duomenys, i, med);
                    duomenys[i].med=med;
                    vidurkis(duomenys, i);
                    if (i==0) remelis(duomenys, i, did_vard, did_pav);
                    spausdinimas(duomenys, i, did_vard, did_pav);

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
                if (i==0) remelis(duomenys, i, did_vard, did_pav);
                spausdinimas(duomenys, i, did_vard, did_pav);
                rikiavimas (duomenys, nr);
            }

        }

        return 0;
    }
}