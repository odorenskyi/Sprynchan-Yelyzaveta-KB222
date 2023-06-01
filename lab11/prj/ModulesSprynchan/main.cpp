#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include "ModulesSprynchan.h"

using namespace std;

void search(vector<Student> &vec, wstring surname) {
    bool found = false;
    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec[i].surname == surname) {
            found = true;
            wcout << vec[i].surname << L'\u0009' << vec[i].name << L'\u0009' << vec[i].patronymic << L'\u0009' << vec[i].group << L'\u0009' << endl;
        }
    }
    if (!found)
        wcout << L"Не знайдено." << endl;
}

void output(vector<Student> &vec) {
    for (unsigned int i = 0; i < vec.size(); i++)
        wcout << vec[i].surname << L'\u0009' << vec[i].name << L'\u0009' << vec[i].patronymic << L'\u0009' << vec[i].group << L'\u0009' << endl;
}
