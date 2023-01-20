#pragma once
#include "library.h"

class Student
{
    string vardas, pavarde;
    vector<int> nd;
    int egz;
    double galutinis;
public:
    Student();
    Student(string, string, vector<int>, int);
    Student(const Student& Laik);
    //Student& operator=(const Student& Laik);
    double calcVid();
    double calcMed();
    void getGalutinisV();
    void getGalutinisM();
    friend ostream& operator<<(ostream &output, const Student& S);
    friend istream& operator>>(istream &input, Student& S);
    ~Student();
};
