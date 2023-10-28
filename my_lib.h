#ifndef MY_LIB_H
#define MY_LIB_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

template <typename Container>
struct Duomenys
{
    string vardas;
    string pavarde;
    Container nd;
    int egz;
    double vid, med;
};

template <typename Container>
vector<Duomenys<Container>> skaitytiDuomenisIsFailo();
template <typename Container>
void spausdintiDuomenis(const vector<Duomenys<Container>> &studentai);
template <typename Container>
vector<Duomenys<Container>> ivestiDuomenisRanka();
template <typename Container>
void StudentuSkirstymas(const string &sortingCriteria);
template <typename Container>
void GeneruotiFailus();
template <typename Container>
double vidurkis(const Container &vektorius);
template <typename Container>
bool rusiavimas(const Duomenys<Container> &a, const Duomenys<Container> &b);
template <typename Container>
void SortStudentsByGalutinis(vector<Duomenys<Container>> &students);

#endif
