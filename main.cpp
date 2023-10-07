#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
using namespace std;

struct Studentai{
    string vardas;
    string pavarde;
    vector<int> pazimys;
    int egz;
    double med;
    double vid;
};

double vidurkis(mt19937 &generator, uniform_int_distribution<int> &distribution);
double mediana(mt19937 &generator, uniform_int_distribution<int> &distribution);

int main()
{
    ofstream Failas;
    ofstream Vargsiukai("Vargsiukai.txt");
    ofstream Moksliukai("Moksliukai.txt");

    Failas<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"
    << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)" << endl;
    Vargsiukai<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"
    << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)" << endl;
    Moksliukai<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"
    << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)" << endl;


    const int studentCounts[] = {1000, 10000, 100000, 1000000, 10000000};
    for (int studentCount : studentCounts) {
        string filename = to_string(studentCount) + " studentu.txt";
        Failas.open(filename);

        Failas << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
               << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)" << endl;

        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(1, 10);

        for (int i = 1; i <= studentCount; i++) {
            Failas << setw(15) << left << "Vardas" + to_string(i) << setw(15) << left
                   << "Pavarde" + to_string(i)
                   << setw(20) << left << round((0.4 * vidurkis(generator, distribution) + 0.6 * distribution(generator)) * 100.0) / 100.0
                   << setw(20) << left << round((0.4 * mediana(generator, distribution) + 0.6 * distribution(generator)) * 100.0) / 100.0
                   << endl;
        }

        Failas.close();
    }

    ifstream isFailo("1000 studentu.txt");

    if (!isFailo) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    vector<Studentai> studentai;

    string line;
    getline(isFailo, line);

    while (getline(isFailo, line)) {
        Studentai studentas;
        istringstream iss(line);

        if (!(iss >> studentas.vardas >> studentas.pavarde >> studentas.vid >> studentas.med)) {
            cerr << "Error reading data from the file." << endl;
            return 1;
        }

        studentai.push_back(studentas);
    }

    isFailo.close();

    vector <Studentai> protingi;
    vector <Studentai> kiti;

    for (const Studentai& studentas : studentai) {
        if (studentas.vid<5){
            protingi.push_back(studentas);

        }
        else{
            kiti.push_back(studentas);
        }
    }
    for (const Studentai& studentas : protingi) {
        Vargsiukai << setw(15) << left << studentas.vardas << setw(15) << left << studentas.pavarde
            << setw(20) << left << studentas.vid << setw(20) << left << studentas.med << endl;
    }
    for (const Studentai& studentas : kiti) {
        Moksliukai << setw(15) << left << studentas.vardas << setw(15) << left << studentas.pavarde
            << setw(20) << left << studentas.vid << setw(20) << left << studentas.med << endl;
    }
    Vargsiukai.close();
    Moksliukai.close();

    return 0;
}

double vidurkis(mt19937 &generator, uniform_int_distribution<int> &distribution) {
    double suma = 0;
    for (int j = 0; j < 15; j++) {
        int random_skaicius = distribution(generator);
        suma += random_skaicius;
    }
    return suma / 15.0;
}

double mediana(mt19937 &generator, uniform_int_distribution<int> &distribution) {
    vector<int> pazymiai;
    for (int j = 0; j < 15; j++) {
        int random_skaicius = distribution(generator);
        pazymiai.push_back(random_skaicius);
    }
    sort(pazymiai.begin(), pazymiai.end());
    if (15 % 2 != 0) {
        return static_cast<double>(pazymiai[15 / 2]);
    }
    return static_cast<double>(pazymiai[15 / 2 - 1] + pazymiai[15 / 2]) / 2.0;
}

