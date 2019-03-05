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
double mediana(vector<mok> duomenys, int i, double &med) {

    typedef vector<double>::size_type dydis;
    dydis size=duomenys[i].nd.size();
    if (size==0)
    {
        throw std::domain_error ("negalima skaiciuoti medianos tusciam vektoriui");
    }

    std:: sort(duomenys[i].nd.begin(), duomenys[i].nd.end(), std::greater<int>());

    if (duomenys[i].paz_sk% 2 != 0)
    {
        med=(double)duomenys[i].nd[duomenys[i].paz_sk/2];
        return med;
    }
    else
    {
        med=(double)(duomenys[i].nd[(duomenys[i].paz_sk-1)/2] + duomenys[i].nd[duomenys[i].paz_sk/2])/2.0;
        return med;
    }

}
//------------------------------------
void vidurkis(vector<mok> &duomenys, int i) {

    if (duomenys[i].nd.size()==0)
    {
        throw std::domain_error ("negalima skaiciuoti vidurkio tusciam vektoriui");
    }

    duomenys[i].vid=std::accumulate(duomenys[i].nd.begin(), duomenys[i].nd.begin(), 0.0)/duomenys[i].nd.size();

}
//--------------------------------------
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
void remelis (vector<mok> &duomenys, int i, int &did_vard, int &did_pav)
{
    if(duomenys[i].vardas.size()>did_vard)
        did_vard=duomenys[i].vardas.size();

    if(duomenys[i].pavarde.size()>did_pav)
        did_pav=duomenys[i].pavarde.size();

    cout<<std::left<<std::setw(did_vard+15)<<"Vardas ";
    cout<<std::left<<std::setw(did_vard+15)<<"Pavarde ";
    cout<<std::left<<std::setw(did_vard+15)<<"Galutinis (Vid.)";
    cout<<std::left<<std::setw(did_vard+15)<<("Galutinis (Med.)");
    cout<<endl;

    for (int g=0; g<did_vard+did_pav+70; g++)
    cout<<std::left<< "-";

    cout<<endl;

}
//----------------------------
void spausdinimas(vector<mok> &duomenys, int i, int did_vard, int did_pav) {

    duomenys[i].galutinis1 = 0.4 * duomenys[i].vid + 0.6 *(double) duomenys[i].egz;
    duomenys[i].galutinis2 = 0.4 * duomenys[i].med + 0.6 * (double) duomenys[i].egz;

    cout<<std::left<<std::setw(did_pav+15)<<duomenys[i].pavarde;
    cout<<std::left<<std::setw(did_vard+15)<<duomenys[i].vardas;
    cout<<std::left<<std::setw(did_vard+15)<< duomenys[i].galutinis1;
    cout<<std::left<<std::setw(did_vard+15)<< duomenys[i].galutinis2;
    cout << endl;

    for (int g=0; g<did_vard+did_pav+70; g++)
        cout<<std::left<< "-";
    cout<<endl;
}
//-------------------------
void skaitymas (vector<mok> &duomenys, int &nr) {

    string temp;
    string eil, vard, pav;
    std::ifstream in_file("kursiokai.txt");

    int sk = 0;
    int h = 0;

    try {
        if (!in_file.good()) {
            throw "Failas neegzistuoja";
        }
    } catch (const char *msg) {
        cout << msg << endl;
    }

    while (std::getline(in_file, eil)) {

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
                duomenys[sk].sum += ivedu;
                duomenys[sk].paz_sk++;
            }

        }
        sk++;

        in_line.end;

        int egz = 0;

        egz = duomenys[h].nd[duomenys[h].paz_sk - 1];
        duomenys[h].egz = egz;


        h++;
        duomenys[sk - 1].nd[duomenys[sk - 1].paz_sk - 1] = 0;
        duomenys[sk - 1].sum = duomenys[sk - 1].sum - duomenys[h - 1].egz;
        duomenys[sk - 1].paz_sk--; //sumazinamas pazymiu skaicius, nes skaiciuoja ir egzaminas

    }

    in_file.close();

}
//-------------------------
void rikiavimas (vector<mok> &duomenys, int &nr)
{
    for (int i=0; i<nr-1; i++)
        for (int j=i+1; j<nr; j++)
            if (duomenys[i].pavarde<duomenys[j].pavarde) {

                std::swap (duomenys[i], duomenys[j]);

            }
}
//-----------------------
void generuoti_txt(int i, int &nr)
{
    string file_name[5]={"test.txt", "test1.txt", "test2.txt", "test3.txt", "test4.txt"};

    srand (time(NULL));
    int laik;

    std::ofstream outfile (file_name[i]);

    for (int g=0; g<nr; g++)
    {
        outfile << "Vardas" << g << " " << "Pavarde" << g << " ";

        for (int j = 0; j <5; j++) {

            laik = rand() % 10 + 1;
            outfile << laik << " ";
        }

        outfile << std::endl;
    }

    outfile.close();
}
//--------------------------------------------------
void skaitymas_gen (vector<mok> &duomenys, int &i) {

    string temp;
    string eil, vard, pav;
    string file_name[5]={"test.txt", "test1.txt", "test2.txt", "test3.txt", "test4.txt"};
    std::ifstream in_file(file_name[i]);

    if (in_file.fail())
    {
        std::cout << "Rasymo i faila klaida";
        in_file.clear();
    }

    int sk = 0;
    int h=0;
    int j=0; //vardu skaicius

    while (std::getline(in_file, eil)) {
        duomenys.push_back(mok());
        std::istringstream in_line(eil);
        in_line >> vard >> pav;
        duomenys[j].vardas.reserve(1000);
        duomenys[j].pavarde.reserve(1000);
        duomenys[j].vardas = vard;
        duomenys[j].pavarde = pav;
        j++;

        while (in_line >> temp) {
            int ivedu = std::stoi(temp); //pavercia string i integer
            if (ivedu >= 0 && ivedu <= 10) {
                duomenys[sk].nd.push_back(ivedu);
                duomenys[sk].paz_sk++;
            }
        }

        sk++;


        in_line.end;

        int egz = 0;

        egz = duomenys[h].nd[duomenys[h].paz_sk-1];
        duomenys[h].egz=egz;

        h++;
        duomenys[sk-1].nd[duomenys[sk-1].paz_sk-1]=0;
        duomenys[sk-1].sum=duomenys[sk-1].sum-duomenys[h-1].egz;
        duomenys[sk-1].paz_sk--; //sumazinamas pazymiu skaicius, nes skaiciuoja ir egzaminas
    }
}
//-------------------------
void rezultatu_skaidymas(vector<mok> &duomenys, int &i) {

    string file_name[2] = {"kietiakai.txt", "silpnuoliai.txt"};

    std::ofstream outfile(file_name[0], std::ios::app);
    std::ofstream outfil(file_name[1], std::ios::app);

    duomenys[i].galutinis1 = 0.4 * duomenys[i].vid + 0.6 * (double) duomenys[i].egz;

    if (duomenys[i].galutinis1 >= 5) {
        outfile << duomenys[i].vardas << " " << duomenys[i].pavarde << " " << duomenys[i].galutinis1 << endl;
    }
    if (duomenys[i].galutinis1 < 5) {
        outfil << duomenys[i].vardas << " " << duomenys[i].pavarde << " " << duomenys[i].galutinis1 << endl;
    }

    outfile.close();
    outfil.close();

}
