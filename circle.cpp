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
void ivedimas (deque<mok> &duomenys, int i) {

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
void ivedimas_rezultatu(deque<mok> &duomenys, int i) {
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
double mediana(deque<mok> duomenys, int i, double &med) {

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
void vidurkis(deque<mok> &duomenys, int i) {

    while (duomenys[i].nd.empty())
    {
        throw std::domain_error ("negalima skaiciuoti vidurkio tusciam vektoriui");
    }

    duomenys[i].vid=(double)duomenys[i].sum/(double)duomenys[i].paz_sk;

}
//--------------------------------------
void generacija(deque<mok> &duomenys, int i) {

    int kiek;
    int laik;
    cout << "Kiek norite generuoti skaiciu?" << endl;
    cin >> kiek;

    srand (time(NULL));
    duomenys[i].paz_sk=kiek;
    std::mt19937 mt(1729);
    std::uniform_int_distribution <int> dist (1,10);

    for (int j = 0; j <kiek; j++) {

        laik = dist(mt);
        duomenys[i].nd.push_back(laik);
        duomenys[i].sum += laik;
    }

    laik = dist(mt);
    duomenys[i].egz = laik;

}
//----------------------------
void remelis (deque<mok> &duomenys, int i, int &did_vard, int &did_pav)
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
void spausdinimas(deque<mok> &duomenys, int i, int did_vard, int did_pav) {

    duomenys[i].galutinis1 = 0.4 * duomenys[i].vid + 0.6 *(double) duomenys[i].egz;
    duomenys[i].galutinis2 = 0.4 * duomenys[i].med + 0.6 * (double) duomenys[i].egz;

    cout<<std::left<<std::setw(did_pav+15)<<duomenys[i].pavarde;
    cout<<std::left<<std::setw(did_vard+15)<<duomenys[i].vardas;
    cout<<std::left<<std::setw(did_vard+15)<<std::fixed <<std::setprecision(2)<< duomenys[i].galutinis1;
    cout<<std::left<<std::setw(did_vard+15)<<std::fixed << std::setprecision(2) << duomenys[i].galutinis2;
    cout << endl;

    for (int g=0; g<did_vard+did_pav+70; g++)
        cout<<std::left<< "-";
    cout<<endl;
}
//-------------------------
void skaitymas (deque<mok> &duomenys, int &nr) {

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
void rikiavimas (deque<mok> &duomenys, int &nr)
{
    string p;
    for (int i=0; i<nr-1; i++)
        for (int j=i+1; j<nr; j++)
            if (duomenys[i].pavarde>duomenys[j].pavarde) {
               p=duomenys[i].pavarde;
               duomenys[i].pavarde=duomenys[j].pavarde;
               duomenys[j].pavarde=p;

            }
}
//-----------------------------------------
void generuoti_txt(int i, int &nr)
{
    string file_name[5]={"test.txt", "test1.txt", "test2.txt", "test3.txt", "test4.txt"};

    int laik;

    std::ofstream outfile (file_name[i]);
    std::mt19937 mt(1729);
    std::uniform_int_distribution <int> dist (1,10);

    //std::vector<int>::iterator IT;

    //std::randome_device rd;
    //std::mt19937 mt(rd());
    //std::uniform_int_distribution <int> range (0,99);
    //cout << range(mt) << " ";

    for (int g=0; g<nr; g++)
    {
        outfile << "Vardas" << g << " " << "Pavarde" << g << " ";

        for (int j = 0; j <5; j++) {

            laik = dist(mt);
            outfile << laik << " ";
        }

        outfile << std::endl;
    }

    outfile.close();
}
//--------------------------------------------------
void skaitymas_gen (list<mok>& duomenyss, int i) {

    string temp;
    string eil;
    string file_name[5] = {"test.txt", "test1.txt", "test2.txt", "test3.txt", "test4.txt"};
    std::ifstream in_file(file_name[i]);

    if (in_file.fail()) {
        std::cout << "Rasymo i faila klaida";
        in_file.clear();
    }

    while (std::getline(in_file, eil)) {
        mok duomuo;
        std::istringstream in_line(eil);
        in_line >> duomuo.vardas >> duomuo.pavarde;
        while (in_line >> temp) {
            int ivedu = std::stoi(temp); //pavercia string i integer
            if (ivedu >= 0 && ivedu <= 10) {
                duomuo.nd.push_back(ivedu);
                duomuo.sum += ivedu;
                duomuo.paz_sk++;
            }

        }
        in_line.end;
        duomuo.egz = duomuo.nd[duomuo.paz_sk-1];
        duomuo.nd.clear();
        duomuo.sum -= duomuo.egz;
        duomuo.paz_sk--; //sumazinamas pazymiu skaicius, nes skaiciuoja ir egzamina
        duomuo.vid=(double)duomuo.sum/(double)duomuo.paz_sk;
        duomuo.galutinis1= 0.4 * duomuo.vid + 0.6 * (double) duomuo.egz;
        duomenyss.push_back(duomuo);

    }

    in_file.close();
}
//-------------------------
void rezultatu_skaidymas(list<mok> &duomenyss, list<mok> &silpnii, list<mok> &kietii) {

    std::list<mok>::iterator itr = duomenyss.begin();
    mok laik;

    for (itr; itr != duomenyss.end(); itr++){

        //cout << itr -> galutinis1 << endl;

        if (itr -> galutinis1 > 5.0){
            laik.vardas = itr -> vardas;
            laik.pavarde = itr -> pavarde;
            laik.galutinis1 = itr -> galutinis1;
            kietii.push_back(laik);
        }
        else {
            laik.vardas = itr -> vardas;
            laik.pavarde = itr -> pavarde;
            laik.galutinis1 = itr -> galutinis1;
            silpnii.push_back(laik);
        }
    }
    duomenyss.clear();

}
//------------------------
void spausdinu (list<mok> silpnii, list<mok> kietii)
{
    string file_name[2] = {"kietiakai.txt", "silpnuoliai.txt"};

    std::ofstream outfile(file_name[0], std::ios::app);
    std::ofstream outfil(file_name[1], std::ios::app);

    std::list<mok>::iterator i;
    for(i=kietii.begin(); i!=kietii.end(); i++)
    {
        outfile << i->vardas << " " << i->pavarde << " " << i->galutinis1<< std::endl;
    }

    std::list<mok>::iterator is;
    for(is=silpnii.begin(); is!=silpnii.end(); is++)
    {
        outfil << is->vardas << " " << is->pavarde << " " << is->galutinis1<< std::endl;
    }

    silpnii.clear();
    kietii.clear();
    outfile.close();
    outfil.close();

}
