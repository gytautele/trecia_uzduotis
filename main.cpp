#include "circle.h"

int main () {

    vector<mok> duomenys;
    double med=0;

    int jj;
    cout << "Jei norite generuoti 5 tekstinius failus, spauskite 5. Jei ne- bet koki kita skaiciu:" << endl;
    cin >> jj;

    auto startas = std::chrono::system_clock::now();

    std::remove("silpnuoliai.txt");
    std::remove("kietiakai.txt");

    int nr=1;

    if (jj==5) {

        for (int i=0; i<5; i++)
        {
            nr=nr*10;
            generuoti_txt(i, nr);
            skaitymas_gen (duomenys, i);
            auto pabaiga = std::chrono::system_clock::now();
            auto uztruko = std::chrono::duration_cast< std::chrono::duration<double> > (pabaiga - startas).count();
            cout << i+1 << "-ojo failo generavimas ir skaitymas uztruko: " << uztruko << " sekundziu" << endl;

        }
        auto startas1 = std::chrono::system_clock::now();

        rezultatu_skaidymas (duomenys);

        auto pabaiga2 = std::chrono::system_clock::now();
        auto uztruko1 = std::chrono::duration_cast< std::chrono::duration<double> >(pabaiga2 - startas1).count();
        cout << "Rezultatu skaidymas i du tekstinius failus uztruko: " << uztruko1 << " sekundziu" << endl;
        auto pabaiga3 = std::chrono::system_clock::now();
        auto uztruko3 = std::chrono::duration_cast< std::chrono::duration<double> >(pabaiga3 - startas).count();
        cout << "Visos programos veikimas: " << uztruko3 << " sekundziu" << endl;
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