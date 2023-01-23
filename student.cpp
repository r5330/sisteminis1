#include "library.h"

Student::Student() {
    vardas = "";
    pavarde = "";
    nd.push_back(0);
    egz = 0;
    galutinis = 0;
}
//Student& operator=(const Student& Laik); neveikia, pilnai aprasytas header faile
Student::Student(string var, string pav, vector<int> sp, int e) {
    vardas = var;
    pavarde = pav;
    nd = sp;
    egz = e;
    galutinis = 0;
}
Student::Student(string var, string pav, list<int> sp, int e) {
    vardas = var;
    pavarde = pav;
    nd_l = sp;
    egz = e;
    galutinis = 0;
}
Student::Student(string var, string pav, deque<int> sp, int e) {
    vardas = var;
    pavarde = pav;
    nd_d = sp;
    egz = e;
    galutinis = 0;
}

Student::Student(const Student& C) {
    vardas = C.vardas;
    pavarde = C.pavarde;
    nd = C.nd;
    egz = C.egz;
    galutinis = C.galutinis;
}

istream& operator>>(istream &input, Student &S) {
    input >> S.vardas;
    input >> S.pavarde;
    input.ignore();
    string eil;
    int paz;
    getline(input, eil);
    if (eil != "") {
        istringstream iss(eil);
        while (iss >> paz)
        {
            S.nd.push_back(paz);
        }
        S.egz = S.nd.back();
        S.nd.pop_back();
        return input;
    }
}
ostream& operator<<(ostream &output,const Student &S) {
        output << S.vardas << "\t" << S.pavarde << "\t";
        for (auto& i : S.nd) output << i << "\t";
        output << S.egz;
        return output;
}
void Student::calcGalutinis(int option) { //skaiciuoti vidurki
    if (option == 1) {
        for (int i = 0; i < nd.size(); i++) {
            galutinis += (nd[i] * 1.0);
        }
        galutinis = (galutinis / nd.size()) * 0.4 + egz * 0.6;
        cout << fixed << setw(12) << left << vardas << setw(13) << left << pavarde << setw(20) << setprecision(2) << galutinis << "\n";
    }
    else if (option == 2) { //skaiciuoti mediana
        int ns = nd.size();
        sort(nd.begin(), nd.end());
        if (ns % 2 == 1) {
            ns = ns / 2;
            galutinis = (nd[ns] * 0.4) + (egz * 0.6);
        }
        else {
            ns = ns / 2;
            ns = (nd[ns - 1] + nd[ns]) / 2;
            galutinis = (ns * 0.4) + (egz * 0.6);
        }
        cout << fixed << setw(12) << left << vardas << setw(13) << left << pavarde << setw(20) << setprecision(2) << galutinis << "\n";
    }
}
string Student::getVardas() {
    return vardas;
}
string Student::getPavarde() {
    return pavarde;
}
//Student::~Student(){}
