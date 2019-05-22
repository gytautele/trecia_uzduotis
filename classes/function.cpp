#include "../headers/main_header.h"

std::ostream& operator<<(std::ostream out, const duomenys& studentas)
{
    out << studentas.vardas() << studentas.pavarde() << studentas.galutinis() << endl;
    return out;
}

duomenys& duomenys::operator=(const duomenys& studentas)
{
    if (&studentas == this) return *this;

    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    egz_ = studentas.egz_;
    galut_ = studentas.galut_;
    nd_ = studentas.nd_;
    return *this;
}

duomenys::duomenys(const duomenys& studentas)
{
    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    egz_ = studentas.egz_;
    galut_ = studentas.galut_;
    nd_ = studentas.nd_;
}

void duomenys::galutinis(char &pasirinkimas)
{
    if (nd_.size() == 0)
    {
        exit(0);
    }
    else
    {
        double vidurkis = 0;
        for (int w = 0; w < nd_.size(); w++)
        {
            vidurkis += nd_[w];
        }
        vidurkis /= double(nd_.size());
        galut_ = vidurkis * 0.4 + 0.6 * egz_;
    }
    nd_.clear();
}

void duomenys::spausdinimas(std::ofstream& out, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    out << std::setw(ilgiausias_vardas + 2) << std::left << vardas_ << std::setw(ilgiausia_pavarde + 2) << std::left << pavarde_ << std::fixed << std::setprecision(2) << std::setw(4) << std::left << galut_ << endl;
}

std::istringstream duomenys::irasymas(std::istringstream& skaitymas)
{
    skaitymas>>vardas_;
    skaitymas>>pavarde_;
    int temp_nd;
    for(int i=0;i<10;i++)
    {
        skaitymas>>temp_nd;
        nd_.push_back(temp_nd);
    }
    skaitymas>>egz_;
    try {
        if(nd_.size() == 0) throw std::runtime_error("Namu darbu skaicius lygus nuliui, todel jo galutinis pazymys bus 0\n");
    }
    catch (const std::runtime_error& e)
    {
        cout<<e.what();
        galut_ = 0;
    }
    std::istringstream end;
    return end;
}

void skaitymas(vector <duomenys> &studentai, int i, char &pasirinkimas)
{
    std::ifstream in;
    in.open("test" + std::to_string(i+1) + ".txt");
    try {
        if (!in) throw std::runtime_error("Failo atidarymo klaida\n");
    }
    catch(const std::runtime_error& e)
    {
        cout<<e.what();
        exit(0);
    }
    int temp=0;
    string eilute;
    while(getline(in,eilute))
    {
        std::istringstream skaityti(eilute);
        studentai.push_back(duomenys());
        studentai[temp].irasymas(skaityti);
        studentai[temp].galutinis(pasirinkimas);
        temp++;
    }
    in.close();
}

void isvedimas(vector <duomenys> &silpni, vector <duomenys> &geri, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    std::ofstream out1("geri.txt");
    std::ofstream out2("silpni.txt");
    out1 << std::setw(ilgiausias_vardas + 2) << std::left << "Vardas" << std::setw(ilgiausia_pavarde + 2) << std::left << "Pavarde  " << std::left << "Galutinis" << endl;
    out2 << std::setw(ilgiausias_vardas + 2) << std::left << "Vardas" << std::setw(ilgiausia_pavarde + 2) << std::left << "Pavarde  " << std::left << "Galutinis" << endl;

    for (int i = 0; i < ilgiausias_vardas + ilgiausia_pavarde + 13; i++)
    {
        out1 << "-";
        out2 << "-";
    }
    out1 << endl;
    out2 << endl;
    for (auto i : silpni)
        i.spausdinimas(out2, ilgiausias_vardas, ilgiausia_pavarde);
    for (auto i : geri)
        i.spausdinimas(out1, ilgiausias_vardas, ilgiausia_pavarde);
    out1.close();
    out2.close();
}

void ilgio_nustatymas(vector<duomenys>& studentai, int &ilgiausias_vardas, int& ilgiausia_pavarde)
{
    std::vector<duomenys>::iterator it = std::max_element(studentai.begin(), studentai.end(), tikrinimas_vard);
    ilgiausias_vardas = it->vard_ilgis();
    it = std::max_element(studentai.begin(), studentai.end(), tikrinimas_pavard);
    ilgiausia_pavarde = it->pavard_ilgis();
}

void atrinkimas(vector <duomenys>& studentai, vector<duomenys> &silpni)
{
    sort(studentai.begin(), studentai.end(), tikrinimas_gal);
    std::vector<duomenys>::iterator it = std::find_if(studentai.begin(), studentai.end(), tikrinimas_5);
    std::copy(it, studentai.end(), std::back_inserter(silpni));
    studentai.resize(studentai.size() - silpni.size());
}

bool tikrinimas_gal(duomenys stud1, duomenys stud2)
{
    return stud1.galutinis() < stud2.galutinis();
}

bool tikrinimas_5(duomenys stud1)
{
    return stud1.galutinis() == 5;
}

bool tikrinimas_vard(duomenys stud1, duomenys stud2)
{
    return stud1.vard_ilgis() < stud2.vard_ilgis();
}

bool tikrinimas_pavard(duomenys stud1, duomenys stud2)
{
    return stud1.pavard_ilgis() < stud2.pavard_ilgis();
}

int kazkas(const char string1[2])
{
    return 0;
}