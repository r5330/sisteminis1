#include <iostream>
#include <string>
#include <vector>
#include <iostream> 
#include <sstream>
#include <iomanip>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::getline;
using std::istringstream;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;

class Student 
{

    string vardas, pavarde;
    vector<int> nd;
    int egz;
    double galutinis;
public:

    Student(string var, string pav, vector<int> sp, int e) : vardas{ var }, pavarde{ pav }, nd{ sp }, egz{ e }, galutinis {0} {}
    Student(const Student& Laik)
    {
        vardas = Laik.vardas;
        pavarde = Laik.pavarde;
        nd = Laik.nd;
        egz = Laik.egz;
        galutinis = Laik.galutinis;
    }
    Student& operator=(const Student& Laik) {}
    double calcVid()
    {
        for (int i = 0; i < nd.size(); i++)
        {
            galutinis += nd[i];
        }
        galutinis = (galutinis / nd.size()) * 0.4 + egz * 0.6;
        return galutinis;
    }
    double calcMed()
    {

    }
    void getGalutinis()
    {
        cout << fixed << setw(12) << left << vardas << setw(13) << left << pavarde << setw(20) << setprecision(2) << galutinis << "\n";
    }
    ~Student() {}
};

int main()
{
    int n;
    vector<Student> sarasas;

    string name;
    string lastname;
    string eil;
    int egzaminas;

    vector<int> pazymiai;
    int paz;

    cout << "...Įveskite studentų skaičių: \n\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n" << "...Įveskite studento vardą: \n\n";
        cin >> name;

        cout << "\n" << "...Įveskite studento pavardę: \n\n";
        cin >> lastname;

        cout << "\n" << "...Įveskite studento semestro pažymius (pažymius atskirkite tarpais, baige įvedinėti paspauskite ENTER): \n\n";
        cin.ignore();
        getline(cin, eil);
        istringstream iss(eil);
        while (iss >> paz)
        {
            pazymiai.push_back(paz);
        }

        cout << "\n" << "...Įveskite studento egzamino pažymį: \n\n";
        cin >> egzaminas;
        Student Laik(name, lastname, pazymiai, egzaminas);
        sarasas.push_back(Laik);
        cout << "\n" << "++++ Studentas išsaugotas ++++ \n\n\n";
    }
  
    cout << setw(12) << left << "Vardas" << setw(13) << left << "Pavardė" << setw(20) << left << "Galutinis (Vid.)" << "\n";
    cout << "--------------------------------------------------" << "\n";
     
    for (int i = 0; i < sarasas.size(); i++)
    {
        sarasas.at(i).calcVid();
        sarasas.at(i).getGalutinis();
    }



}
