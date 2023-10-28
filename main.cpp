#include "my_lib.h"


int main()
{
    string ats;
    string containerType;
    cout << "Ar naudoti vector ar list? (v/l)" << endl;

    try
    {
        cin >> containerType;
        if (containerType != "v" && containerType != "l")
        {
            throw runtime_error("Error. Pasirinkite 'v' arba 'l'");
        }
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (containerType == "v")
    {
        cout<<"Ar generuoti failus?"<<endl;
        cin>>ats;
        if (ats == "taip")
            {
                GeneruotiFailus<vector<int>>();
            }
    }
    else if (containerType == "l")
    {
        cout<<"Ar generuoti failus?"<<endl;
        cin>>ats;
        if (ats == "taip")
            {
                GeneruotiFailus<list<int>>();
            }
    }

    string kriterijus;
    cout << "Ar rusiuoti studentus pagal vidurki ar pagal pavardes?(v/p)" << endl;
    cin >> kriterijus;
    for (int i = 0; i < 3; i++)
    {
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cout << endl;
        if (containerType == "v")
        {
            StudentuSkirstymas<vector<int>>(kriterijus);
        }
        else if (containerType == "l")
        {
            StudentuSkirstymas<list<int>>(kriterijus);
        }
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cout << endl;
    }

    cout << "Ar skaityti duomenis is failo? taip/ne" << endl;
    string tekstinis;
    try
    {
        cin >> tekstinis;
        if (tekstinis != "taip" && tekstinis != "ne")
        {
            throw runtime_error("Error. Veskite tik 'taip' arba 'ne'");
        }
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (tekstinis == "taip")
    {
        if (containerType == "v")
        {
            vector<Duomenys<vector<int>>> studentai = skaitytiDuomenisIsFailo<vector<int>>();
            spausdintiDuomenis<vector<int>>(studentai);
        }
        else if (containerType == "l")
        {
            vector<Duomenys<list<int>>> studentai = skaitytiDuomenisIsFailo<list<int>>();
            spausdintiDuomenis<list<int>>(studentai);
        }
    }
    else
    {
        if (containerType == "v")
        {
            vector<Duomenys<vector<int>>> studentai = ivestiDuomenisRanka<vector<int>>();
            spausdintiDuomenis<vector<int>>(studentai);
        }
        else if (containerType == "l")
        {
            vector<Duomenys<list<int>>> studentai = ivestiDuomenisRanka<list<int>>();
            spausdintiDuomenis<list<int>>(studentai);
        }
    }

    return 0;
}
