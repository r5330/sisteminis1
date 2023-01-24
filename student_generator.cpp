#include "library.h"

void generate_studlist(int stud_count, int nd_count) {

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    vector<int> nd(nd_count, 0);
    ofstream out_f(to_string(stud_count) + ".txt");
    for (int i = 0; i <= stud_count; i++) {
        if (i == 0) {
            out_f << setw(20) << left << "Pavardė" << setw(20) << "Vardas";
            for (int j = 1; j <= nd_count; j++) out_f << "ND" << setw(3) << j;
            out_f << setw(5) << "Egz" << "\n";
        }
        else {
            for (int k = 0; k < nd_count; k++) {
                nd[k] = rand() % 10 + 1;
            }
            Student Stud("Vardas" + to_string(i), "Vardas" + to_string(i), nd, (rand() % 10) + 1);
            out_f << Stud;
        }
    }
    out_f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << stud_count << " Studentų failo generavimas užtruko : " << diff.count() << " s\n";
}