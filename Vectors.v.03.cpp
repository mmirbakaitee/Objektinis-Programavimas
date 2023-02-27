#include "vheaderis.h"

int main() {
    student stud;
    vector<student> students;

    char q = '0';

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

    return 0;
}