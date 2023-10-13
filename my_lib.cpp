#include "my_lib.h"

vector<Duomenys> skaitytiDuomenisIsFailo()
{
    vector<Duomenys> studentai;

    ifstream infile("studentai.txt");
    if (!infile)
    {
        cerr << "Error: Failo atidaryti nepavyko." << endl;
        terminate();
    }

    string eile;
    getline(infile, eile);
    int lineNum = 0;
    while (getline(infile, eile))
    {
        lineNum++;
        Duomenys studentas;
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
    sort(studentai.begin(), studentai.end(), rusiavimas);

    return studentai;
}

vector<Duomenys> ivestiDuomenisRanka()
{
    int zmones;
    string atsakymas;
    cout << "Iveskite zmoniu skaiciu: ";
    try
    {
        cin >> zmones;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Error. Veskite tik skaicius");
        }
    }
    catch (const runtime_error& e)
    {
    cerr << e.what() << endl;
    exit(EXIT_FAILURE);
    }
    vector<Duomenys> studentai;
for (int studentIndex = 0; studentIndex < zmones; studentIndex++) {
    Duomenys studentas;

    cout << "Iveskite varda: ";
    cin >> studentas.vardas;
    cout << "Iveskite pavarde: ";
    cin >> studentas.pavarde;

    cout << "Ar norite ivesti savo pazymius? Atsakymas: taip arba ne" << endl;
    try
    {
        cin >> atsakymas;
        if (atsakymas != "taip" && atsakymas != "ne")
        {
            throw runtime_error("Neteisinga ivestis. Veskite 'taip' arba 'ne'.");
        }
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
    }

    if (atsakymas == "taip") {
    cout << "Iveskite nd pazymius noredami uzbaigti ivedima, iveskite -1" << endl;
    int pazimys;
    while (cin >> pazimys)
        {
            if (pazimys == -1)
            {
                break;
            }

            try
                {
                    if (pazimys <= 0 || pazimys > 10)
                    {
                        throw runtime_error("Error. Pazimys turi buti skaicius (0,10] ribose.");
                    }
                }
                catch (const runtime_error& e)
                {
                    cerr << e.what() << endl;
                }
                studentas.nd.push_back(pazimys);
            }
            cout << "Iveskite egzamino rezultata: ";
            try
            {
                cin >> studentas.egz;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Error. Veskite tik skaicius");
                }
            }
            catch (const runtime_error& e)
            {
                cerr << e.what() << endl;
                exit(EXIT_FAILURE);
            }
    } else {
        int n;
        cout << "Kiek namu darbu atlikote? ";
        try
        {
            cin >> n;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Error. Veskite tik skaicius");
            }
        }
        catch (const runtime_error& e)
        {
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }

        random_device rd;
        mt19937 generator(rd() + studentIndex);
        int min = 1;
        int max = 10;
        for (int j = 0; j < n; j++) {
            uniform_int_distribution<int> distribution(min, max);
            int random_skaicius = distribution(generator);
            studentas.nd.push_back(random_skaicius);
            cout << random_skaicius << endl;
        }
        uniform_int_distribution<int> distribution(min, max);
        studentas.egz = distribution(generator);
        cout << "Egzamino pazimys: " << studentas.egz << endl;
    }

    studentai.push_back(studentas);
}
    sort(studentai.begin(), studentai.end(), rusiavimas);
    return studentai;
}




pair<double, double> skaiciuotiGalutini(const Duomenys &studentas)
{
    double vidurkis_nd = vidurkis(studentas.nd);
    double galutinis_vid = round((0.4 * vidurkis_nd + 0.6 * studentas.egz) * 100.0) / 100.0;
    double galutinis_med = round((0.4 * mediana(studentas.nd) + 0.6 * studentas.egz) * 100.0) / 100.0;

    return make_pair(galutinis_vid, galutinis_med);
}

void spausdintiDuomenis(const vector<Duomenys> &studentai)
{
    cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
         << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)" << endl;
    for (int i=0; i<32; i++)
    {
        cout<<"--";
    }
    cout<<endl;

    for (const Duomenys &studentas : studentai)
    {
        cout << setw(15) << left << studentas.pavarde << setw(15) << left << studentas.vardas;
        pair<double, double> galutiniai = skaiciuotiGalutini(studentas);
        cout << setw(20) << fixed << setprecision(2) << left << galutiniai.first << setw(20) << left << galutiniai.second << endl;
    }
}

void GeneruotiFailus() {
    const int studentCounts[] = {1000, 10000, 100000, 1000000, 10000000};

    for (int studentCount : studentCounts) {
        string filename = to_string(studentCount) + " studentu.txt";
        auto start = chrono::high_resolution_clock::now();
        ofstream Failas(filename);

        if (!Failas.is_open()) {
            cerr << "Failed to open " << filename << endl;
            return;
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
    }
}

void StudentuSkirstymas(const string& sortingCriteria) {
    vector<Duomenys> studentai;

    ifstream infile("100000 studentu.txt");

    cout<<"Skaitymas vyksta is failo su 100,000 studentu"<<endl;
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
        Duomenys studentas;
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


    for (Duomenys& studentas : studentai) {
    studentas.vid = round((0.4 * vidurkis(studentas.nd) + 0.6 * studentas.egz) * 100.0) / 100.0;
    }
    if (sortingCriteria == "pavardes") {

        auto startSort = chrono::high_resolution_clock::now();
        sort(studentai.begin(), studentai.end(), rusiavimas);
        auto endSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationSort = endSort - startSort;
        cout << "duomenu rusiavimas pagal pavardes ir vardus funkcija sort truko " << durationSort.count() << " sekundziu" << endl;
    } else if (sortingCriteria == "vidurki") {

        auto startSort = chrono::high_resolution_clock::now();
        SortStudentsByGalutinis(studentai);
        auto endSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationSort = endSort - startSort;
        cout << "duomenu skirstymas pagal vidurki truko " << durationSort.count() << " sekundziu" << endl;
    } else {
        cerr << "Neteisingai Ivestas rusiavimo kriterijus" << endl;
        return;
    }

    vector<Duomenys> protingi;
    vector<Duomenys> kiti;

    auto startFilter = chrono::high_resolution_clock::now();



    for (const Duomenys& studentas : studentai) {
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

    ofstream Vargsiukai("Vargsiukai.txt");
    Vargsiukai << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
            << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;

    for (const Duomenys& studentas : protingi) {
        Vargsiukai << setw(15) << left << studentas.vardas << setw(15) << left << studentas.pavarde
            << setw(20) << left << studentas.vid << setw(20) <<  endl;
    }

    Vargsiukai.close();

    auto endWriteVargsiukai = chrono::high_resolution_clock::now();
    chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
    cout << "duomenu isvedimas i Vargsiuku studentu faila truko " << durationWriteVargsiukai.count() << " sekundziu" << endl;

    auto startWriteMoksliukai = chrono::high_resolution_clock::now();

    ofstream Moksliukai("Moksliukai.txt");
    Moksliukai << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
            << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;

    for (const Duomenys& studentas : kiti) {
        Moksliukai << setw(15) << left << studentas.vardas << setw(15) << left << studentas.pavarde
            << setw(20) << left << studentas.vid << setw(20) <<  endl;
    }

    Moksliukai.close();

    auto endWriteMoksliukai = chrono::high_resolution_clock::now();
    chrono::duration<double> durationWriteMoksliukai = endWriteMoksliukai - startWriteMoksliukai;
    cout << "duomenu isvedimas i Moksliuku studentu faila truko " << durationWriteMoksliukai.count() << " sekundziu" << endl;
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

double mediana(const vector<int> &vektorius)
{
    int kiekis = vektorius.size();
    vector<int> kopija = vektorius;
    sort(kopija.begin(), kopija.end());
    if (kiekis % 2 != 0)
    {
        return static_cast<double>(kopija[kiekis / 2]);
    }
    return static_cast<double>(kopija[kiekis / 2 - 1] + kopija[kiekis / 2]) / 2.0;
}

bool rusiavimas(const Duomenys &a, const Duomenys &b)
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
void SortStudentsByGalutinis(vector<Duomenys>& students) {
    std::sort(students.begin(), students.end(), [](const Duomenys& a, const Duomenys& b) {
        return a.vid > b.vid;
    });
}
