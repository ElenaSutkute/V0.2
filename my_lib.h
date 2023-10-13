#ifndef MY_LIB_H
#define MY_LIB_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
using namespace std;

struct Duomenys
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double vid, med;
};


vector<Duomenys> skaitytiDuomenisIsFailo();
void spausdintiDuomenis(const vector<Duomenys> &studentai);
vector<Duomenys> ivestiDuomenisRanka();
pair<double, double> skaiciuotiGalutini(const Duomenys &studentas);
void StudentuSkirstymas(const string& sortingCriteria);
void GeneruotiFailus();
double vidurkis(const vector<int> &vektorius);
double mediana(const vector<int> &vektorius);
bool rusiavimas(const Duomenys &a, const Duomenys &b);
void SortStudentsByGalutinis(vector<Duomenys>& students);

#endif
