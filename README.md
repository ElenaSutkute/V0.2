1. Visų pirma programa paklausia, ar norime, kad duomenys būtų saugomi list tipo konteineryje ar vector tipo. Kad pasitinkti tipą, reikia įvesti raidę l, jei norite, kad būtų naudojamas list ir v, jei vector. Tada yra klausiama, ar sugeneruoti failus ir ar norime studentus rūšiuoti pagal jų galutinį pažymų, jei norite jį pasirinkti, įveskite raidę v, ar pagal pavardes, įrašyti raidę p. Atsakius taip bus sugeneruoti 5 tekstiniai failai: 1000, 10 000, 100 000, 1 000 000 ir 10 000 000 srudentų. Sugeneravus failą, į ekraną yra išvedamas laikas, per kurį failas buvo sugeneruotas. Baigus generuoti failus yra skaitomi duomenys iš pasirinkto failo. Norint pakeisti failą, iš kurio bus skaitoma, reikia atlikti pakeitimus 252 ir 254 eilutėse faile my_lib.cpp. Kai duomenys yra nuskaityti, studentai yra surūšiuojami pagal paradžioje pasirinkt1 būdą, paskaičiuojamas studentų galutinis pažymys pagal vidurkį ir studentai yra suskirtomi į du failus: Moksliukai, kurių vidurkis yra >=5 ir Vargšiuksi, kurių vidurkis <5. Eigoje yra skaičiuojami visų šių operacijų įvykdymo laikai, ši veiksmas vykdomas 5 kartus, kad patikrinti vykdymo laiko patikimumą.
2. Visų pirma, paklausiama ar norite nuskaityti duomenis iš failo. Galimi atsakymai yra tik taip arba ne.
   2.1. Įvedus taip, duomenys yra nuskaitomi iš failo kursiokai.txt. Jei vedant pažymius į tekstinį failą buvo padarytos klaidos,   studento nebus galutiniame sąraše ir bus parašyta kelintas studentas turi klaidų savo pažymių tarpe.
   2.2. Įvedus ne, reikia pasirinkti kiek norėsite vesti studentų. Galima vesti tik skaičius.
    2.2.1. Tuomet reikia įvesti studento vardą bei pavardę.
    2.2.2. Klausiama ar norite įvesti studento pažymius bei egzamino rezutatą ranka, ar kad kompiuteris juos sugeneruotų automatiškai. Galimi įvedimo rezultatai taip arba ne.
       2.2.2.1. Įvedus taip galite vesti kiek norite studento pažymių, norėdami nutraukti įvedimą parašykite -1; Tuomet reikia įvesti egzamino rezultatą. Rezultatai būtinai turi būtų (0,10] ribose.
       2.2.2.2. Įvedus ne reikia pasirinkti kiek buvo atliktų namų darbų ir tada studento namų darbų ir egzamino rezultatai bus generuojami automatiškai.
Galutiniame rezultate matysime studentų pavades ir vardus surūšiuotus abeceliškai ir jų galutinį dalyko rezutatą, paskaičiuotą tiek pagal medianą, tiek pagal vidurkį.


<img width="542" alt="image" src="https://github.com/ElenaSutkute/V0.2/assets/145843117/1978500e-edeb-4d6a-8097-3e5f3227e4c7">
