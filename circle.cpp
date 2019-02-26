#include "circle.h"

//-----------------------------------------
int pasirinkimas ()
{
    int f; //pasirinkimui
    cout << "Jei norite ivesti duomenis ranka, spauskite 0, jei norite is tekstinio failo spauskite 1:" << endl;
    cin >> f;
    return f;
}
//------------------------------------------
int mok_sk (int &m)
{
    cout << "Iveskite mokiniu skaiciu:" << endl;
    cin >> m;
    return m;
}
//----------------------------------------
void ivedimas (vector<mok> &duomenys, int i) {
    cout << "Iveskite studento varda ir pavarde" << endl;

    cout << i << endl;

    cin >> duomenys[i].vardas;
    cin >> duomenys[i].pavarde;
}
//----------------------------------------
int pasirinkimas2() {
    int a; //skaicius skirtas pasirinkti
    cout << "Jei norite generuoti rezultatus automatiskai spauskite 2. Jei norite ivesti patys spauskite 3:"
         << endl;
    cin >> a;

    return a;
}
//-----------------------------------------
void ivedimas_rezultatu(vector<mok> &duomenys, int i) {
    int b; //laikinas kintamasis pazymiui irasyti i vektoriu

    cout << "Iveskite namu darbu rezultatus. Kai noresite baigti - spauskite 0:" << endl;

    do {
        cin >> b;
        if (b > 0 && b < 11) {
            duomenys[i].nd.push_back(b);
            duomenys[i].paz_sk++;
            duomenys[i].sum += b;
        }

    } while (b != 0);

    cout << "Iveskite egzamino pazymi:" << endl;
    cin >> duomenys[i].egz;

}
//--------------------------------
double mediana(vector<mok> &duomenys, int i) {

    std:: sort(duomenys[i].nd.begin(), duomenys[i].nd.end(), std::greater<int>());

    if (duomenys[i].paz_sk% 2 != 0)
    {
        duomenys[i].med=(double)duomenys[i].nd[duomenys[i].paz_sk/2];
        return duomenys[i].med;
    }
    else
    {
        duomenys[i].med=(double)(duomenys[i].nd[(duomenys[i].paz_sk-1)/2] + duomenys[i].nd[duomenys[i].paz_sk/2])/2.0;
        return duomenys[i].med;
    }

}
//------------------------------------
void vidurkis(vector<mok> &duomenys, int i) {

    duomenys[i].vid=(double)duomenys[i].sum/(double)duomenys[i].paz_sk;

}
//-----------------------------------
bool skaicius(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
//---------------------------------------
void generacija(vector<mok> &duomenys, int i) {
    int kiek;
    int laik;
    cout << "Kiek norite generuoti skaiciu?" << endl;
    cin >> kiek;

    srand (time(NULL));
    duomenys[i].paz_sk=kiek;

    for (int j = 0; j <kiek; j++) {

        laik = rand() % 10 + 1;
        duomenys[i].nd.push_back(laik);
        duomenys[i].sum += laik;
    }

    laik = rand() % 10 + 1;
    duomenys[i].egz = laik;

}
//----------------------------
void remelis ()
{
    cout << "Pavarde" << std::right << setw(20) << "Vardas" << std::right << setw(20) << "VidGalutinis"
         << std::right << setw(20) << "MedGalutinis" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}
//----------------------------
void spausdinimas(vector<mok> &duomenys, int i) {

    duomenys[i].galutinis1 = 0.4 * duomenys[i].vid + 0.6 *(double) duomenys[i].egz;
    duomenys[i].galutinis2 = 0.4 * duomenys[i].med + 0.6 * (double) duomenys[i].egz;
    cout << duomenys[i].pavarde << std::right << setw(20) << duomenys[i].vardas << std::right << setw(20)
         << std::fixed << std::setprecision(2) << std::right << duomenys[i].galutinis1 << setw(20) << std::right
         << duomenys[i].galutinis2 << endl;

}
//-------------------------
void skaitymas (vector<mok> &duomenys, int &nr) {
    int y = 0;
    string temp;
    string eil, vard, pav;
    std::ifstream in_file("kursiokai.txt");

    /*if (in_file.fail())
        std::cout << "write failed" << std::endl;*/

    int sk = 0;
    int h=0;

    while (std::getline(in_file, eil)) {
        while (!in_file.eof()){
            try {
                if (!in_file.good()){
                    throw "Failas neegzistuoja";
                }
            } catch (const char* msg){
                cout << msg << endl;
                break;
            }

        duomenys.push_back(mok());
        std::istringstream in_line(eil);
        in_line >> vard >> pav;
        duomenys[nr].vardas = vard;
        duomenys[nr].pavarde = pav;
        nr++;

        while (in_line >> temp) {
            int ivedu = std::stoi(temp); //pavercia string i integer
            if (ivedu >= 0 && ivedu <= 10) {
                duomenys[sk].nd.push_back(ivedu);
                duomenys[sk].sum+=ivedu;
                duomenys[sk].paz_sk++;
            }

        }
        sk++;

        in_line.end;

        int egz = 0;
        int y=0;

        egz = duomenys[h].nd[duomenys[h].paz_sk-1];
        duomenys[h].egz=egz;



        h++;
        duomenys[sk-1].nd[duomenys[sk-1].paz_sk-1]=0;
        duomenys[sk-1].sum=duomenys[sk-1].sum-duomenys[h-1].egz;
        duomenys[sk-1].paz_sk--; //sumazinamas pazymiu skaicius, nes skaiciuoja ir egzaminas
    }


}
//-------------------------
void rikiavimas (vector<mok> &duomenys, int &nr)
{
    for (int i=0; i<nr-1; i++)
        for (int j=i+1; j<nr; j++)
            if (duomenys[i].vardas<duomenys[j].vardas) {

                std::swap (duomenys[i], duomenys[j]);

            }
}
//----------------------------