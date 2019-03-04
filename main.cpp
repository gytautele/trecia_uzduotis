#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <ctype.h>
#include <algorithm>

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
    double galutinis1=0; //galutinis rezultatas
    double galutinis2=0; //galutinis rezultatas
    double med=0; //mediana
};

int main ()
{
    vector<mok> duomenys;
    vector<int> nd;
    int m=0;

    while(true) {
        cout << "Iveskite savo varda ir pavarde" << endl;
        duomenys.push_back(mok());
        cin >> duomenys[m].vardas;
        cin >> duomenys[m].pavarde;

        int a; //skaicius skirtas pasirinkti

        cout << "Jei norite generuoti rezultatus automatiskai spauskite 0. Jei norite ivesti patys spauskite 1:" << endl;
        cin >> a;

        double sum = 0; //suma;
        int kiek=0;
        int b=0;

        if (a==1)
        {
            cout << "Iveskite namu darbu rezultatus. Kai baigsite, spauskite 0:" << endl;
            cin >> b;
            do
            {
                nd.push_back(b);
                kiek++;

            } while (b==0);

            typedef vector <double>::size_type dydis;
            dydis size = duomenys[i].nd.size();
            if (size==0)
            {
                cout << "Privalote ivesti namu darbu rezultatus. Bandykite is naujo." << endl;
                return 1;
            }

            std::sort(nd.begin(), nd.end());

            if (kiek% 2 != 0) duomenys[m].med=(double)nd[kiek/2];

            else duomenys[m].med=(double)(nd[(kiek-1)/2] + nd[kiek/2])/2.0;
        }

        else
        {
            cout << "Kiek norite generuoti skaiciu?" << endl;
            cin >> kiek;
            int *ndd=new int[kiek]; //namu darbu rezultatai
            for (int j = 0; j < kiek; j++) {
                ndd[j]=rand()%10;
                cout << ndd[j] << endl;
                sum+=ndd[j];
                cout << sum << endl;
                cout << "-----------------" << endl;
            }

            int laik; //laikinas kintamasis rikiavimui
            for (int k=0; k<kiek-1; k++)
                for (int l=k+1; l<kiek; l++)
                    if (ndd[k]>ndd[l])
                    {
                        laik=ndd[k];
                        ndd[k]=ndd[l];
                        ndd[l]=laik;
                    }

            if (kiek% 2 != 0) duomenys[m].med=(double)ndd[kiek/2];

            else duomenys[m].med=(double)(ndd[(kiek-1)/2] + ndd[kiek/2])/2.0;

            delete []ndd;

        }

        int egz; //egzamino rezultatas
        cout << "Iveskite egzamino pazymi" << endl;
        cin >> egz;

        int o;
        cout << "Jei norite baigti - spauskite 0, jei norite testi - veskite rezultatus toliau";
        cin >> o;

        if (o==0) break;


        double vid=0; //vidurkis
        vid=sum/(double)kiek;
        duomenys[m].galutinis1 = 0.4 * vid + 0.6 * (double)egz;
        duomenys[m].galutinis2 = 0.4 * duomenys[m].med + 0.6 * (double)egz;

        cout << "Pavarde" <<std::right << setw(20) << "Vardas" << std::right <<setw(20) << "VidGalutinis" << std::right << setw(20) << "MedGalutinis" << endl;
        cout << "------------------------------------------------------------------------" << endl;

        for (int i=0; i<m; i++)
        {
            cout << duomenys[m].pavarde << std::right << setw(20) << duomenys[m].vardas << std::right << setw(20) << std::fixed << std::setprecision(2) << std::right << duomenys[m].galutinis1 << setw(20) << std::right << duomenys[m].galutinis2 << endl;
        }
            m++;



    }

}