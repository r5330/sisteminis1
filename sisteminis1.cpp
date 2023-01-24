#include "library.h"

int main()
{
    vector<Student> sarasas;
    Student S;

    //Student B = S; // suveike priskyrimo-kopijavimo operatorius (copy-assignment)
    //Student C(S); //kopijavimo konstruktorius
    //sarasas.push_back(Student("Vardas", "Pavarde", {1, 2, 4, 10}, 7));
    //sarasas.push_back(Student());

    int input_option; // kokiu budu ivesti duomenis 1 is konsoles, 2 is failo
    int calc_option; // kokiu budu skaiciuoti galutini 1 vidurkis, 2 mediana
    cout << "Kaip įvesti duomenis?\n 1 - Pridėti studentus konsoleje.\n 2 - Skaityti iš failo kursiokai.txt.\n 3 - Generuoti studentų failus ir atlikti rušiavimą\n";
    cin >> input_option;
    if (input_option == 1) { //meniu pasirinkimas 1 duomenu ivedimas is konsoles
        cout << "\nĮveskite studentų skaičių: \n\n";
        int n;
        cin >> n;
        if (n == 1)
            cout << "\nPridėti " << n << " studentą...\n\n";
        else
            cout << "\nPridėti " << n << " studentus...\n\n";
        for (int i = 0; i < n; i++) {
            cout << "Vienoje eilutėje įveskite studento vardą, pavardę, semestro pažymius ir egzamino rezultatą.\n(paskutinis skaičius yra egzamino rezultatas):\n\n";
            cout << "pvz: Vardenis Pavardenis nd1 nd2 nd3 nd4 nd5 egz (semestro darbų skaičius yra neribotas)\n\n";
            cin >> S;
            sarasas.push_back(S);
            cout << "\n+++Studentas išsaugotas+++\n\n";
        }
        cout << "Kaip skaičiuoti galutini pažymį?\n\t1. Skaičiuoti vidurkį\n\t2. Skaičiuoti medianą\n";
        cin >> calc_option;
        for (int i = 0; i < sarasas.size(); i++) {
            if (i == 0 && calc_option == 1) {
                cout << setw(13) << left << "Pavardė" << setw(13) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)\n--------------------------------------------------\n";
            }

            else if (i == 0 && calc_option == 2) {
                cout << setw(13) << left << "Pavardė" << setw(13) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)\n--------------------------------------------------\n";

            }
            sarasas.at(i).calcGalutinis(calc_option);
            cout << fixed << setw(12) << left << sarasas.at(i).getVardas() << setw(13) << left << sarasas.at(i).getPavarde() << setw(20) << setprecision(2) << sarasas.at(i).getGalutinis() << "\n";
        }

    }
    else if (input_option == 2) { // meniu pasirinkimas 2 duomenu ivedimas is failo
        ifstream open_f("kursiokai.txt");
        string eil;
        getline(open_f, eil);
        while (open_f) {

            if (!open_f.eof()) {
                open_f >> S;
                sarasas.push_back(S);

            }
            else break;

        }
        open_f.close();



        cout << "Kaip skaičiuoti galutini pažymi?\n\t1. Skaičiuoti vidurkį\n\t2. Skaičiuoti medianą\n";
        cin >> calc_option;
        sort(sarasas.begin(), sarasas.end());
        for (int i = 0; i < sarasas.size(); i++) {
            if (i == 0 && calc_option == 1)
                cout << setw(13) << left << "Pavardė" << setw(13) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)\n--------------------------------------------------\n";
            else if ((i == 0 && calc_option == 2))
                cout << setw(13) << left << "Pavardė" << setw(13) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)\n--------------------------------------------------\n";
            sarasas.at(i).calcGalutinis(calc_option);
            cout << fixed << setw(12) << left << sarasas.at(i).getVardas() << setw(13) << left << sarasas.at(i).getPavarde() << setw(20) << setprecision(2) << sarasas.at(i).getGalutinis() << "\n";
        }
    }
    else if (input_option == 3) { //meniu pasirinkimas 3 generuoti failus su studentais
        int nd_count;
        cout << "Kiek semestro pažymių generuoti?\n";
        cin >> nd_count;
        int f1 = 1000;
        int f2 = 10000;
        int f3 = 100000;
        int f4 = 1000000;
        int f5 = 10000000;
        generate_studlist(f1, nd_count);
        generate_studlist(f2, nd_count);
        generate_studlist(f3, nd_count);
        generate_studlist(f4, nd_count);
        //generate_studlist(f5, nd_count); //veikia, bet uztruko per ilgai testavimui
    }
}

