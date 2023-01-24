#pragma once
#include "library.h"

class Student {
    string vardas, pavarde;
    vector<int> nd;
    list<int> nd_l;
    deque<int> nd_d;
    int egz;
    double galutinis;
public:
    Student();
    Student(const Student& C);
    Student& operator=(const Student&) {
        return *this;
    }
    Student(string, string, list<int>, int);
    Student(string, string, deque<int>, int);
    Student(string, string, vector<int>, int);
    friend istream& operator>>(istream& input, Student& S);
    friend ostream& operator<<(ostream& output, const Student& S);
    void calcGalutinis(int);
    bool operator <(Student& b) {
        if (this->getPavarde() < b.getPavarde()) return true;
        else return false;
    }
    string getVardas();
    string getPavarde();
    ~Student() {}
    double getGalutinis();
};