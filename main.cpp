#include "my_lib.h""

int main()
{
    string ats;
    vector<Duomenys> studentai;
    string failai;
    cout<<"Ar generuoti failus? taip/ne"<<endl;

        try
    {
        cin>>failai;
        if (failai != "taip" && failai != "ne")
        {
            throw runtime_error("Error. Veskite tik 'taip' arba 'ne'");
        }
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (failai == "taip") {
        string kriterijus;
        cout<<"Ar rusiuoti studentus pagal vidurki ar pagal pavardes?"<<endl;
        cin>>kriterijus;
        GeneruotiFailus();
        for (int i = 0; i < 5; i++) {
            StudentuSkirstymas(kriterijus);
            for (int i = 0; i < 48; i++) {
                cout << "--";
            }
            cout << endl;
        }
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
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (tekstinis == "taip")
    {
        studentai = skaitytiDuomenisIsFailo();
    }
    else
    {
            studentai = ivestiDuomenisRanka();
    }

    spausdintiDuomenis(studentai);

    return 0;
}

