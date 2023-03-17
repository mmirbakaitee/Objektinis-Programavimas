#pragma once
#ifndef VHEADER
#define VHEADER

#include "vsource.cpp"

bool FileExists(const std::string& Filename)
{
    return access(Filename.c_str(), 0) == 0;
}

void addstudent(vector<student>& students, student& stud) {
    char choice;
    int query;
    cout << "Ar norite kad skaitytume faila, jei taip iveskite 'p'.\nKitu atveju - bet kokia raide. \nJusu pasirinkimas: ";
    cin >> choice;
    if (choice == 'p' || choice == 'P') {
        int n = 0;
        scan(students, n, stud);
        sort(students.begin(), students.end(), compN);
        for (int i = 0; i < students.size(); i++) {
            students[i].avg = getavg(students[i].p);
            students[i].median = getmedian(students[i].p);
        }
    }
    else {
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
        while (query != 1 && query != 2 || cin.fail()) {
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
bool compN(const student& first, const student& scnd) {
    return first.vardas < scnd.vardas;
}


bool compV(const student& first, const student& scnd) {
    return first.avg * 0.4 + first.e * 0.6 > scnd.avg * 0.4 + scnd.e * 0.6;
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
            string row;
            string w;
            getline(fd, row);
            stringstream r(row);
            while (r >> w)
            {
                amount++;
            }
            while (!fd.eof())
            {
                fd >> stud.vardas >> stud.pavarde;
                for (int i = 0; i < amount - 1; i++)
                {
                    fd >> grades;
                    stud.p.push_back(grades);
                }
                fd >> stud.e;
                info.push_back(stud);
                stud.p.clear();
            }
            fd.close();
        }
        else {
            throw runtime_error("FAILAS NEATIDAROMAS");
        }
    }
    catch (const exception& e) {
        cerr << "KLAIDA: " << e.what() << endl;
    }
}

//funkcija, kuri veikia kai sugeneruotas failas egzistuoja
void printtxt(vector<student>& info, int amount, student& stud, string ammount) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys(1, 10);
    vector<student> kietiakaii;
    vector<student> varguoliaii;
    string vardas, pavarde;
    char eil[100];
    int gradeam=0;

    amount = stoi(ammount);
    char x[100];
    if (amount == 1000)     strcpy_s(x, sizeof(x), CRP1fv);
    if (amount == 10000)    strcpy_s(x, sizeof(x), CRP2fv);
    if (amount == 100000)   strcpy_s(x, sizeof(x), CRP3fv);
    if (amount == 1000000)  strcpy_s(x, sizeof(x), CRP4fv);
    if (amount == 10000000) strcpy_s(x, sizeof(x), CRP5fv);

    ifstream fq(x);
    fq >> vardas >> pavarde;
    string row;
    string w;
    getline(fq, row);
        stringstream r(row);
        while (r >> w)
        {
            gradeam++;
        }
        //getline(fq, row);
        auto startnus = std::chrono::high_resolution_clock::now();
        amount = 0;
        while (!fq.eof())
        {
            amount++;
            fq >> stud.vardas >> stud.pavarde;
            for (int j = 1; j < gradeam; j++)
            {
                int pazz;
                fq >> pazz;
                stud.p.push_back(pazz);
               
            }
            fq >> stud.e;
            stud.avg = getavg(stud.p);
            stud.median = getmedian(stud.p);
            info.push_back(stud);
            stud.p.clear();
        }
        fq.close();
        auto endnus = std::chrono::high_resolution_clock::now();
        auto durationnus = std::chrono::duration_cast<std::chrono::microseconds>(endnus - startnus);

        ofstream fg(CRGfv); ofstream fk(CRKfv); ofstream fv(CRVfv);
        fg << fixed << setprecision(2);
        fg << fixed << setprecision(2);
        fg << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
        fg << setfill('-') << setw(60) << "" << setfill(' ') << endl;
        fk << fixed << setprecision(2);
        fk << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
        fk << setfill('-') << setw(60) << "" << setfill(' ') << endl;
        fv << fixed << setprecision(2);
        fv << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
        fv << setfill('-') << setw(60) << "" << setfill(' ') << endl;

        for (auto i : info)
        {
            sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", i.vardas.c_str(), i.pavarde.c_str(), i.avg, i.median);
            fg << eil;
        }

        sort(info.begin(), info.end(), compV);
        auto startrus = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < amount; i++) {
            if (info[i].avg * 0.4 + info[i].e * 0.6 >= 5.00) {
                kietiakaii.push_back(info[i]);
            }
            else {
                varguoliaii.push_back(info[i]);
            }
        }
        auto endrus = std::chrono::high_resolution_clock::now();
        auto durationrus = std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus);

        auto startkiet = std::chrono::high_resolution_clock::now();
        for (auto i : kietiakaii) {
            sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", i.vardas.c_str(), i.pavarde.c_str(), i.avg * 0.4 + i.e * 0.6, i.median);
            fk << eil;
        }
        auto endkiet = std::chrono::high_resolution_clock::now();
        auto durationkiet = std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet);

        auto startvarg = std::chrono::high_resolution_clock::now();
        for (auto i : varguoliaii) {
            sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", i.vardas.c_str(), i.pavarde.c_str(), i.avg * 0.4 + i.e * 0.6, i.median);
            fv << eil;
        }
        auto endvarg = std::chrono::high_resolution_clock::now();
        auto durationvarg = std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg);

        cout << endl;
        cout << left << "FAILO NUSKAITYMO TRUKME:      " << left << durationnus.count() / 1000000.0 << " seconds. " << endl;
        cout << left << "FAILO RUSIAVIMO TRUKME:       " << left << durationrus.count() / 1000000.0 << " seconds. " << endl;
        cout << left << "KIETIAKU IRASYMO TRUKME:      " << left << durationkiet.count() / 1000000.0 << " seconds. " << endl;
        cout << left << "VARGUOLIU IRASYMO TRUKME:     " << left << durationvarg.count() / 1000000.0 << " seconds. " << endl;
        cout << endl;
        fv.close(); fk.close(); fg.close();
        info.clear();
        kietiakaii.clear();
        varguoliaii.clear();
    }

//funkcija, kuri veikia kai sugeneruoto failo nera
void printPGtxt(vector<student>& info, int amount, student& stud, string ammount) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys(1, 10);
    vector<student> kietiakaii;
    vector<student> varguoliaii;
    int gradeam;
    char eil[100];
    cout << "Kiek pazymiu turetu tureti studentas (1-100):  ";
    cin >> gradeam;
    while (cin.fail() || gradeam <= 0 || gradeam > 100)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite pazymiu kieki tarp 1-100:  ";
        cin >> gradeam;
    }
    cout << endl;
   
    amount = stoi(ammount);
    char x[100];
    if (amount == 1000)     strcpy_s(x, sizeof(x), CRP1fv);
    if (amount == 10000)    strcpy_s(x, sizeof(x), CRP2fv);
    if (amount == 100000)   strcpy_s(x, sizeof(x), CRP3fv);
    if (amount == 1000000)  strcpy_s(x, sizeof(x), CRP4fv);
    if (amount == 10000000) strcpy_s(x, sizeof(x), CRP5fv);
   
    auto startkur = std::chrono::high_resolution_clock::now();
    ofstream fr(x);
    auto endkur = std::chrono::high_resolution_clock::now();
    auto durationkur = std::chrono::duration_cast<std::chrono::microseconds>(endkur - startkur); cout << endl;
    fr << left << setw(21) << "Vardas" << setw(21) << "Pavarde";
    for (int i = 1; i < gradeam + 1; i++) {
        fr << left << "PAZ" << setw(3) << i << "   ";
    }
    fr << setw(3) << "Egz." << endl;

    for (int i = 1; i <= amount; i++)
    {
        fr << left << "Vardas" << setw(15) << i << "Pavarde" << setw(15) << i;
        for (int j = 0; j < gradeam; j++) {
            fr << left << setw(9) << pazymys(gen);
        }
        fr << left << setw(6) << pazymys(gen) << endl;

    }
    fr.close();

    auto startnus = std::chrono::high_resolution_clock::now();
    ifstream fq(x);
    string line;
    getline(fq, line);
    for (int i = 0; i < amount; i++) {
        fq >> stud.vardas >> stud.pavarde;
        for (int j = 0; j < gradeam; j++)
        {
            int pazz;
            fq >> pazz;
            stud.p.push_back(pazz);
        }
        fq >> stud.e;
        stud.avg = getavg(stud.p);
        stud.median = getmedian(stud.p);
        info.push_back(stud);
        stud.p.clear();
    }
    fq.close();
    auto endnus = std::chrono::high_resolution_clock::now();
    auto durationnus = std::chrono::duration_cast<std::chrono::microseconds>(endnus - startnus);

    ofstream fg(CRGfv); ofstream fk(CRKfv); ofstream fv(CRVfv);
    fg << fixed << setprecision(2);
    fg << fixed << setprecision(2);
    fg << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
    fg << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    fk << fixed << setprecision(2);
    fk << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
    fk << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    fv << fixed << setprecision(2);
    fv << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
    fv << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    for (auto i : info)
    {
        sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", i.vardas.c_str(), i.pavarde.c_str(), i.avg, i.median);
        fg << eil;
    }

    sort(info.begin(), info.end(), compV);
    auto startrus = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < amount; i++) {
        if (info[i].avg * 0.4 + info[i].e * 0.6 >= 5.00) {
            kietiakaii.push_back(info[i]);
        }
        else {
            varguoliaii.push_back(info[i]);
        }
    }
    auto endrus = std::chrono::high_resolution_clock::now();
    auto durationrus = std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus);

    auto startkiet = std::chrono::high_resolution_clock::now();
    for (auto i : kietiakaii) {
        sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", i.vardas.c_str(), i.pavarde.c_str(), i.avg * 0.4 + i.e * 0.6, i.median);
        fk << eil;
    }
    auto endkiet = std::chrono::high_resolution_clock::now();
    auto durationkiet = std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet);

    auto startvarg = std::chrono::high_resolution_clock::now();
    for (auto i : varguoliaii) {
        sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", i.vardas.c_str(), i.pavarde.c_str(), i.avg * 0.4 + i.e * 0.6, i.median);
        fv << eil;
    }
    auto endvarg = std::chrono::high_resolution_clock::now();
    auto durationvarg = std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg);

    cout << endl;
    cout << left << "FAILO SUKURIMO TRUKME:        " << left << durationkur.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "FAILO NUSKAITYMO TRUKME:      " << left << durationnus.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "FAILO RUSIAVIMO TRUKME:       " << left << durationrus.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "KIETIAKU IRASYMO TRUKME:      " << left << durationkiet.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "VARGUOLIU IRASYMO TRUKME:     " << left << durationvarg.count() / 1000000.0 << " seconds. " << endl;
    cout << endl;
    fv.close(); fk.close(); fg.close();
    info.clear();
    kietiakaii.clear();
    varguoliaii.clear();
}

#endif
