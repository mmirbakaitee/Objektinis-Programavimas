#include "vheaderis.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    student stud;
    vector<student> students;

    char q = '0';
    char choiceG, choiceM;
    int n = 0;
    cout << "Ar norite generoti failus? Jei taip iveskite 'd', Kitu atveju betkokia kita raide" << endl;
    cin >> choiceG;
    while (choiceG == 'd' || choiceG == 'D') {
        printPGtxt(students, n, stud);
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
