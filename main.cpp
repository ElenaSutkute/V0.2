#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

double vidurkis(mt19937 &generator, uniform_int_distribution<int> &distribution);
double mediana(mt19937 &generator, uniform_int_distribution<int> &distribution);

int main() {
    ofstream Failas;

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
