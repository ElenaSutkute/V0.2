#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

using namespace std;

struct Studentai{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double vid;
};

double vidurkis(const vector<int> &vektorius);
double mediana(const vector<int> &vektorius);
bool rusiavimas(const Studentai &a, const Studentai &b);

int main()
{
    ofstream Failas;
    ofstream Vargsiukai("Vargsiukai.txt");
    ofstream Moksliukai("Moksliukai.txt");



    Vargsiukai<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"
    << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;
    Moksliukai<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"
    << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;


   /* const int studentCounts[] = {1000, 10000, 100000, 1000000, 10000000};

    for (int studentCount : studentCounts) {
        string filename = to_string(studentCount) + " studentu.txt";
        auto start = chrono::high_resolution_clock::now();
        ofstream Failas(filename);

        if (!Failas.is_open()) {
            cerr << "Failed to open " << filename << endl;
            return 1;
        }

        Failas << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde";
        for (int i = 1; i <= 7; i++) {
            Failas << setw(5) << left << "ND" + to_string(i);
        }
        Failas << setw(5) << "Egz." << endl;

        random_device rd;
        mt19937 generator(rd() + studentCount);
        uniform_int_distribution<int> distribution(1, 10);

        for (int i = 1; i <= studentCount; i++) {
            Failas << setw(15) << left << "Vardas" + to_string(i) << setw(15) << left
            << "Pavarde" + to_string(i);
            int min = 1;
            int max = 10;
            for (int j = 0; j < 7; j++) {
                uniform_int_distribution<int> distribution(min, max);
                int random_skaicius = distribution(generator);
                Failas << setw(5) << random_skaicius;
            }
            uniform_int_distribution<int> distribution(min, max);
            Failas << setw(5) << distribution(generator) << endl;
        }

        Failas.close();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << studentCount << " studentu failas sukurtas per " << duration.count() << " sekundziu" << endl;
    }*/
    vector<Studentai> studentai;

    ifstream infile("1000000 studentu.txt");

    cout<<"Skaitymas vyksta is failo su 1 000 000 studentu"<<endl;
    if (!infile)
    {
        cerr << "Error: Failo atidaryti nepavyko." << endl;
        terminate();
    }

    string eile;
    getline(infile, eile);
    int lineNum = 0;
    auto startRead = chrono::high_resolution_clock::now();
    while (getline(infile, eile))
    {
        lineNum++;
        Studentai studentas;
        istringstream iss(eile);
        iss >> studentas.vardas >> studentas.pavarde;

        for (int i = 0; i < 7; i++)
        {
            int pazimys;
            iss >> pazimys;

            if (iss.fail())
            {
                cerr << "Error skaitant " << lineNum << " studento pazymius." << endl;
                break;
            }
            if (pazimys == -1)
            {
                break;
            }
            studentas.nd.push_back(pazimys);
        }

        if (!iss.fail())
        {
            iss >> studentas.egz;
            studentai.push_back(studentas);
        }
    }
    infile.close();


    auto endRead = chrono::high_resolution_clock::now();
    chrono::duration<double> durationRead = endRead - startRead;
    cout << "duomenu skaitymas is failo truko " << durationRead.count() << " sekundziu" << endl;

    auto startSort = chrono::high_resolution_clock::now();
    sort(studentai.begin(), studentai.end(), rusiavimas);
    auto endSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationSort = endSort - startSort;
    cout << "duomenu rusiavimas pagal pavardes ir vardus funkcija sort truko " << durationSort.count() << " sekundziu" << endl;

    vector<Studentai> protingi;
    vector<Studentai> kiti;

    auto startFilter = chrono::high_resolution_clock::now();

        for (Studentai& studentas : studentai) {
        studentas.vid = round((0.4 * vidurkis(studentas.nd) + 0.6 * studentas.egz) * 100.0) / 100.0;
    }

    for (const Studentai& studentas : studentai) {
        if (studentas.vid < 5) {
            protingi.push_back(studentas);
        } else {
            kiti.push_back(studentas);
        }
    }

    auto endFilter = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFilter = endFilter - startFilter;
    cout << "duomenu rusiavimas pagal vidurki truko " << durationFilter.count() << " sekundziu" << endl;

    auto startWriteVargsiukai = chrono::high_resolution_clock::now();

    for (const Studentai& studentas : protingi) {
        Vargsiukai << setw(15) << left << studentas.vardas << setw(15) << left << studentas.pavarde
            << setw(20) << left << studentas.vid << setw(20) <<  endl;
    }

    auto endWriteVargsiukai = chrono::high_resolution_clock::now();
    chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
    cout << "duomenu isvedimas i Vargsiuku studentu faila truko " << durationWriteVargsiukai.count() << " sekundziu" << endl;

    auto startWriteMoksliukai = chrono::high_resolution_clock::now();

    for (const Studentai& studentas : kiti) {
        Moksliukai << setw(15) << left << studentas.vardas << setw(15) << left << studentas.pavarde
            << setw(20) << left << studentas.vid << setw(20) <<  endl;
    }

    auto endWriteMoksliukai = chrono::high_resolution_clock::now();
    chrono::duration<double> durationWriteMoksliukai = endWriteMoksliukai - startWriteMoksliukai;
    cout << "duomenu rusiavimas pagal vidurki Moksliuku studentu faile truko " << durationWriteMoksliukai.count() << " sekundziu" << endl;

    Vargsiukai.close();
    Moksliukai.close();

    return 0;
}

double vidurkis(const vector<int> &vektorius)
{
    int kiekis = vektorius.size();
    int suma = 0;
    for (int i = 0; i < kiekis; i++)
    {
        suma += vektorius[i];
    }
    return static_cast<double>(suma) / static_cast<double>(kiekis);
}



bool rusiavimas(const Studentai &a, const Studentai &b)
{
    if (a.pavarde != b.pavarde)
    {
        return a.pavarde < b.pavarde;
    }
    else
    {
        return a.vardas < b.vardas;
    }
}
