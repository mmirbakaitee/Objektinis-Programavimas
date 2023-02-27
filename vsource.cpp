#include "studentlib.h"
const char CDfv[] = "kursiokai.txt";

struct student {
    string vardas = "";
    string pavarde = "";
    vector<int> p;
    int e = 0;
    double avg = 0, median = 0;
};
void addstudent(vector<student>& students, student& stud);
void addgrade(vector<int>& p);
double getavg(const vector<int>& p);
double getmedian(const vector<int>& p);
void print(const vector<student>& students);
void scan(vector<student>& info, int amount, student& stud);
bool comp(const student& first, const student& scnd);