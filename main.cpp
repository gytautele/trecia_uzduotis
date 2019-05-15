#include "headers/main_header.h"
#include "headers/time.h"

int main() {

    char pasirinkimas;
    generavimas2();

    std::ofstream out;
    out.open("benchmarking.txt", std::fstream::app);
    out << "------------------------------------------------------------------------------:" << endl;
    out << "Programos veikimo laikai: " << endl;
    int skaicius = 10000;
    for (int i = 0; i < 2; i++) {
        vector<duomenys> studentai, silpni;
        Time laikas;
        laikas.Start_clock();
        studentai.reserve(skaicius);
        skaitymas(studentai, i, pasirinkimas);
        int ilgiausias_vardas = 6, ilgiausia_pavarde = 7;
        ilgio_nustatymas(studentai, ilgiausias_vardas, ilgiausia_pavarde);
        atrinkimas(studentai, silpni);
        isvedimas(studentai, silpni, ilgiausias_vardas, ilgiausia_pavarde);
        silpni.clear();
        laikas.Stop_clock();
        laikas.Get_time(out, skaicius);
    }
    out.close();
    return 0;

}
