#include "studentlib.h"
const char CDfv[] =  "kursiokai.txt";
const char CDPfv[] = "studentai.txt";
const char CRPfv[] = "studentai.txt";
const char CRGfv[] = "studentugalutiniai.txt";
const char CRKfv[] = "kietiakai.txt";
const char CRVfv[] = "varguoliai.txt";

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
void scan(vector<student>& info, int amount, student& stud);
void print(const vector<student>& students); 
void printPGtxt(vector<student>& info, int amount, student& stud);
bool compN(const student& first, const student& scnd);
//bool compV(const student& first, const student& scnd);
