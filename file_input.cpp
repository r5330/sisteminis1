#include "library.h"


void file_input() 
{
	ifstream open_f("kursiokai.txt");

    string eil;
    vector<string> eilute;
    getline(open_f, eil);
    stringstream iss(eil);

    Student S;
    vector<Student> sarasas;

    string var;
    string pav;
    vector<int> pazymiai;
    int p;
    int egz;
    
    while (iss >> eil)
    {
        eilute.push_back(eil);
    }
     //cout << "\n" << eilute.size()<<"\n"; //kiek elementu eiluteje, test.

    for (string eil; getline(open_f, eil);) {
        stringstream iss(eil);
        iss >> var >> pav;
        for (int i = 0; i < eilute.size()-3; i++) {
            iss >> p;
            pazymiai.push_back(p);
        }
        iss >> egz;

        Student Laik(var, pav, pazymiai, egz);
        sarasas.push_back(Laik);
    }
    open_f.close();

    int option;
    do
    {
        cout << "\nKaip skaičiuoti galutini pažymį?\n1. skaičiuoti vidurkį\n2. skaičiuoti medianą\n3. atšaukti\n";
        cin >> option;
        switch (option)
        {
        case 1:
            for (int i = 0; i < sarasas.size(); i++) {
                if (i == 0)
                    cout << setw(12) << left << "Pavardė" << setw(20) << left << "Vardas" << setw(13) << left << "Galutinis (Vid.)\n--------------------------------------------------\n";
                sarasas.at(i).calcVid();
                cout << sarasas.at(i);
            }
            break;
        case 2:
            for (int i = 0; i < sarasas.size(); i++) {
                if (i == 0)
                    cout << setw(12) << left << "Pavardė" << setw(20) << left << "Vardas" << setw(13) << left << "Galutinis (Med.)\n--------------------------------------------------\n";
                sarasas.at(i).calcMed();
                cout << sarasas.at(i);
            }
            break;
        case 3:
            break;
        }
    } while (option != 1 && option != 2 && option != 3);

    
    
    
}