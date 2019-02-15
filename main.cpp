#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::cin;

struct mok
{
    string vardas;
    string pavarde;
    double galutinis=0; //galutinis rezultatas
    double med=0; //mediana
    int nd[50]; //namu darbu rezultatai
};

int main ()
{
    int m=0; //studentu skaicius
    cout << "Iveskite kiek bus studentu?" << endl;
    cin >> m;
    mok A[50];

    for (int i=0; i<m; i++) {
        cout << "Iveskite savo varda ir pavarde" << endl;
        cin >> A[i].vardas >> A[i].pavarde;

        int n; //namu darbu rezultatu skaicius
        cout << "Iveskite namu darbu rezultatu kieki" << endl;
        cin >> n;

        if (n>= 50) {
            cout << "Ivestas per didelis rezultatu kiekis. Iveskite dar karta: " << endl;
            cin >> n;
        }

        double sum = 0; //suma
        cout << "Iveskite namu darbu rezultatus" << endl;


        for (int j = 0; j < n; j++) {
            cin >> A[i].nd[j];
            sum+=A[i].nd[j];
        }

        int egz; //egzamino rezultatas
        cout << "Iveskite egzamino pazymi" << endl;
        cin >> egz;

        /*if (egz<1 && egz>10) {
            cout << "Negalimas pazymys. Iveskite dar karta: " << endl;
            cin >> egz;
        }*/

        double vid=0; //vidurkis
        vid=sum/(double)n;
        A[i].galutinis = 0.4 * vid + 0.6 * (double)egz;

        int laik; //laikinas kintamasis rikiavimui
        for (int k=0; k<n-1; k++)
            for (int l=i+1; l<n; l++)
                if (A[i].nd[k]>A[i].nd[l])
                {
                    laik=A[i].nd[k];
                    A[i].nd[k]=A[i].nd[l];
                    A[i].nd[l]=laik;
                }

        double kk=0; //laikinas

        if (n % 2 != 0) kk=(double)A[i].nd[n/2];

        else kk=(double)(A[i].nd[(n-1)/2] + A[i].nd[n/2])/2.0;

        A[i].med=0.4 * kk + 0.6 * (double)egz;

    }

    for (int i=0; i<m; i++)
    {
        cout << "Pavarde" << "  " << "Vardas" << "  " << "VidGalutinis" << "MedGalutinis" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << A[i].pavarde << "      " << A[i].vardas << "      " << std::fixed << std::setprecision(2) << A[i].galutinis << "     " << A[i].med << endl;
    }

}