#include "vheaderis.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    student stud;
    vector<student> students;

    char q = '0';
    char choiceG, choiceM;
    int n = 0;
    string ammount;
    cout << "Ar norite generuoti faila? Jei taip iveskite 'd', Kitu atveju betkokia kita raide" << endl;
    cin >> choiceG;
    while (choiceG == 'd' || choiceG == 'D') {
        cout << "Kiek irasu turetu buti faile (1000 10000 100000 1000000 10000000): ";
        cin >> ammount;
        while (ammount != "1000" && ammount != "10000" && ammount != "100000" && ammount != "1000000" && ammount != "10000000")
        {
            cout << "Netinkama. Galimi pasirinkimo variantai: 1000 10000 100000 1000000 10000000, pasirinkite is naujo:  ";
            cin >> ammount;
        }
        cout << "Ar sugeneruotas failas egzistuoja direktorijoje?\nATSAKYMAS: ";
        string Filename;
        if (ammount == "1000") {
            Filename = "studentai1000.txt";
            if (FileExists(Filename))
            {
                cout << "Failas yra!" << endl;
                printtxt(students, n, stud, ammount);
            }
            else if (!FileExists(Filename))
            {
                cout << "Failo nera!" << endl;
                printPGtxt(students, n, stud, ammount);
            }
        }
        else if (ammount == "10000") {
            Filename = "studentai10000.txt";
            if (FileExists(Filename))
            {
                cout << "Failas yra!" << endl;
                printtxt(students, n, stud, ammount);
            }
            else if (!FileExists(Filename))
            {
                cout << "Failo nera!" << endl;
                printPGtxt(students, n, stud, ammount);
            }
        }
        else if (ammount == "100000") {
            Filename = "studentai100000.txt";
            if (FileExists(Filename))
            {
                cout << "Failas yra!" << endl;
                printtxt(students, n, stud, ammount);
            }
            else if (!FileExists(Filename))
            {
                cout << "Failo nera!" << endl;
                printPGtxt(students, n, stud, ammount);
            }
        }
        else if (ammount == "1000000") {
            Filename = "studentai1000000.txt";
            if (FileExists(Filename))
            {
                cout << "Failas yra!" << endl;
                printtxt(students, n, stud, ammount);
            }
            else if (!FileExists(Filename))
            {
                cout << "Failo nera!" << endl;
                printPGtxt(students, n, stud, ammount);
            }
        }
        else if (ammount == "10000000") {
            Filename = "studentai10000000.txt";
            if (FileExists(Filename))
            {
                cout << "Failas yra!" << endl;
                printtxt(students, n, stud, ammount);
            }
            else if (!FileExists(Filename))
            {
                cout << "Failo nera!" << endl;
                printPGtxt(students, n, stud, ammount);
            }
        }

        cout << "Ar norite eiti prie kito pasirinkimo? Jei ne, iveskite 'd', jei taip - betkoks kitas klavisas.\n Jusu pasirinkimas: ";
        cin >> choiceG; cout << endl; 
    }
   
    cout << "Galutinai baigti darba? Jei taip iveskite 'm', Kitu atveju betkokia kita raide" << endl;
    cin >> choiceM;
    if (choiceM == 'm' || choiceM == 'M') {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << endl;
        cout << left << "VISOS PROGRAMOS TRUKME:    " << left << duration.count() / 1000000.0 << " seconds. " << endl;
        exit(0);
    }
        if (choiceG != 'd' && choiceG != 'D' && choiceM != 'm' && choiceM != 'M') {
            do {
                addstudent(students, stud);
                cout << endl;
                cout << "Spauskite n klavisa, jei norite tikrai baigti darba. Kitu atveju spustelkite kitoki klavisa. | ";
                cin >> q;
                cout << endl << endl;
                if (q == 'N' || q == 'n') {
                    cout << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Vidurkis" << setw(15) << "Mediana" << endl;
                    cout << "-------------------------------------------------------------------------------------------------------\n";
                }
            } while (q != 'N' && q != 'n');

            print(students);

        }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << left  << "VISOS PROGRAMOS TRUKME:    " << left << duration.count() / 1000000.0 << " seconds. " << endl;
    return 0;
}
