#include "library.h"
#include "student.h"

Student::Student() {
    vardas = "";
    pavarde = "";
    nd.push_back(0);
    egz = 0;
    galutinis = 0;
}
Student::Student(string var, string pav, vector<int> sp, int e) {
        vardas = var;
        pavarde = pav;
        nd = sp;
        egz = e;
        galutinis = 0;
    }
Student::Student(const Student& Laik)
    {
        vardas = Laik.vardas;
        pavarde = Laik.pavarde;
        nd = Laik.nd;
        egz = Laik.egz;
        galutinis = Laik.galutinis;
    }
//Student& operator=(const Student& Laik) {}
double Student::calcVid()
    {
            galutinis = 0;
            for (int i = 0; i < nd.size(); i++)
            {
                galutinis += nd[i];
            }
            galutinis = (galutinis / nd.size()) * 0.4 + egz * 0.6;

            return galutinis;
    }

double Student::calcMed()
    {
        int ns = nd.size();
        sort(nd.begin(), nd.end());
        if (ns % 2 == 1) {
            ns = ns / 2;
            galutinis = (nd[ns] * 0.4) + (egz * 0.6);
        }
        else {
            ns = ns / 2;
            ns = (nd[ns - 1] + nd[ns]) / 2;
            galutinis = ns * 0.4 + egz * 0.6;
        }
    return galutinis;
    }

Student::~Student(){}


istream& operator>>(istream& input, Student& S) 
{
    cout << "\nĮveskite studento vardą: \n\n";
    input >> S.vardas;

    cout << "\nĮveskite studento pavardę: \n\n";
    input >> S.pavarde;

    cout << "\nĮveskite studento semestro pažymius (pažymius atskirkite tarpais, baige įvedinėti paspauskite ENTER.)\n(Norėdami generuoti atsitiktinius balus palikti langą tuščia ir paspauskite ENTER): \n\n";
    cin.ignore();
    string eil;
    int paz;
    getline(input, eil);
    if (eil != "") {
        istringstream iss(eil);
        while (iss >> paz)
        {
            S.nd.push_back(paz);
        }
        cout << "\nĮveskite studento egzamino pažymį: \n\n";
        input >> S.egz;
        return input;
    }
    else {
        cout << "\nKiek balų generuoti?\n\n";
        int bal;
        input >> bal;
        for (int i = 0; i < bal; i++) {
            S.nd.push_back((rand() % 10) + 1);
        }
        S.egz = (rand() % 10) + 1;
        return input;
    }
}

ostream& operator<<(ostream& output, const Student& S) 
{
    output << fixed << setw(12) << left << S.vardas << setw(13) << left << S.pavarde << setw(20) << setprecision(2) << S.galutinis << "\n";
    return output;
}