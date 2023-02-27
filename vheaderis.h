#pragma once
#ifndef VHEADER
#define VHEADER

#include "vsource.cpp"


void addstudent(vector<student>& students, student& stud) {
    char choice;
    int query;
    cout << "Ar norite kad skaitytume faila, jei taip iveskite 'p'.\nKitu atveju - bet kokia raide. \nJusu pasirinkimas: ";
    cin >> choice;
    if (choice == 'p' || choice == 'P')
    {
        int n = 0;
        scan(students, n, stud);
        sort(students.begin(), students.end(), comp);
        for (int i = 0; i < students.size(); i++)
        {
            students[i].avg = getavg(students[i].p);
            students[i].median = getmedian(students[i].p);
        }
    }
    else
    {
        student info;
        cout << "Iveskite studento varda bei pavarde: ";
        cin >> info.vardas >> info.pavarde;
        while (!all_of(info.vardas.begin(), info.vardas.end(), isalpha) || !all_of(info.pavarde.begin(), info.pavarde.end(), isalpha)) {
            cout << "SUKLYDOTE! VARDAS TURI TURETI TIK RAIDES. BANDYKITE DAR KARTA.\n Iveskite studento varda bei pavarde:";
            cin >> info.vardas >> info.pavarde;
        }

        cout << "Iveskite studento namu darbu pazymius intervale 1-10. Kiekvienas pazymys vedamas is naujos eilutes." << endl;
        addgrade(info.p);
        cout << "Iveskite studento egzamino pazymi intervale 1-10: ";
        cin >> info.e;

        while (info.e < 1 || info.e > 10 || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "SUKLYDOTE! EGZAMINO REZULTATAS TURI BUTI SKAICIUS INTERVALE 1-10. BANDYKITE DAR KARTA: ";
            cin >> info.e;
        }
        cout << "Kokius duomenis naudojant turetu buti isvedami rezultatai? \n Jei ranka rasykite 1, jei atsistiktinai - 2. \n Jusu pasirinkimas: " << endl;
        cin >> query;
        while (query != 1 && query != 2 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "SUKLYDOTE! PASIRINKIMAS TURI BUTI SKAICIUS. BANDYKITE DAR KARTA. ";
            cin >> query;
        }
        if (query == 2) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(1, 10);
            cout << endl;
            cout << "Atsitiktinai sugeneruoti studento namu darbu pazymiai: ";
            for (int i = 0; i < info.p.size(); i++) {
                info.p[i] = dist(gen);
                cout << info.p[i] << " ";
            }
            cout << endl;
            info.e = dist(gen);
            cout << "Atsitiktinai sugeneruotas studento egzamino pazymys: " << info.e;
            cout << endl;
        }
        info.avg = getavg(info.p);
        info.median = getmedian(info.p);
        students.push_back(info);
    }
}
void addgrade(vector<int>& p) {
    int r;
    cin >> r;
    while (r < 1 || r > 10 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "SUKLYDOTE! STUDENTO NAMU DARBU PAZYMYS TURI BUTI INTERVALE 1-10. BANDYKITE DAR KARTA: ";
        cin >> r;
    }
    p.push_back(r);

    while (cin >> r)
    {
        if (r < 1 || r > 10)
        {
            break;
        }
        p.push_back(r);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getavg(const vector<int>& p) {
    int suma = 0;
    for (auto i : p) {
        suma += i;
    }
    return (double)suma / p.size();
}
double getmedian(const vector<int>& p) {
    vector<int> sortedp = p;
    sort(sortedp.begin(), sortedp.end());
    if (sortedp.size() % 2 == 0) {
        int vid = sortedp.size() / 2;
        return (double)(sortedp[vid - 1] + sortedp[vid]) / 2;
    }
    else {
        return (double)sortedp[sortedp.size() / 2];
    }
}
bool comp(const student& first, const student& scnd) {
    return first.vardas < scnd.vardas;
}
void print(const vector<student>& students) {
    cout << fixed << setprecision(2);
    for (auto i : students)
        cout << left << setw(20) << i.vardas << setw(20) << i.pavarde << setw(15) << i.avg * 0.4 + i.e * 0.6 << setw(15) << i.median * 0.4 + i.e * 0.6 << endl;
}

void scan(vector<student>& info, int amount, student& stud) {
    string vardas, pavarde, e, t;
    int grades, k = 0;
    ifstream fd(CDfv);
    try {
        if (fd.is_open()) {
            fd >> vardas >> pavarde;
            while (fd >> t && t != "Egz.")
            {
                amount++;
            }
            while (!fd.eof())
            {
                fd >> stud.vardas >> stud.pavarde;
                //    cout << stud.vardas << " " << stud.pavarde << " ";
                for (int i = 0; i < amount; i++)
                {
                    fd >> grades;
                    if (fd.fail()) {
                        throw runtime_error("NETINKAMAS NAMU DARBU SKAICIUS");
                    }
                    if (grades < 0 || grades > 10 || grades == 0) {
                        throw invalid_argument("NAMU DARBU SKAICIUS TURI BUTI TARP 1 IR 10");
                    }
                    stud.p.push_back(grades);
                    //       cout << stud.p[i] << " ";

                }
                if (stud.p.size() < amount) {
                    throw runtime_error("NEPAKANKA PAZYMIU");
                }
                fd >> stud.e;
                if (fd.fail()) {
                    throw runtime_error("NETINKAMAS EGZAMINO PAZIMYS");
                }
                info.push_back(stud);
                stud.p.clear();
                //    cout << stud.e << endl;
            }
            fd.close();
        }
        else {
            throw runtime_error("FAILAS NEATIDAROMAS");
        }
    }
    catch (const exception& e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

#endif
