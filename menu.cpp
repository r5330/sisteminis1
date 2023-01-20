#include "library.h"

void main_menu() //pagrindinis menu
{
    int option;
    do
    {
        cout << "\n------Savarankiškas darbas 1------\n1. Pridėti studentus savarankiškai\n2. Skaityti iš failo\n3. Generuoti atsitiktinius studentus\n4. Baigti darbą\n";
        cin >> option;
        switch (option)
        {
        case 1:
            //ivedimo funkcija
            console_input();
            break;
        case 2:
            //skaitymas is failo
            file_input();
            break;
        case 3:
            //kurti studentu faila
            break;
        case 4:
            break;
        }
    } while (option != 4);
}
