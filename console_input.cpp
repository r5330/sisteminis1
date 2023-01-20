#include "library.h"


void console_input() 
{
    vector<Student> sarasas;
    Student S;

    cout << "\nĮveskite studentų skaičių: \n\n";
    int n;
    cin >> n;
    if (n == 1)
        cout << "\nPridėti " << n << " studentą...\n";
    else
        cout << "\nPridėti " << n << " studentus...\n";
    for (int i = 0; i < n; i++) {
        cin >> S;
        sarasas.push_back(S);
    }
    
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