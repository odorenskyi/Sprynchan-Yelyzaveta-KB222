#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include "ModulesKichura.h"

using namespace std;

void add(vector<Student> &vec, wstring surname, wstring name, wstring patronymic, wstring group) {
    vec.push_back({});
    Student& back = vec.back();
    back.surname = surname;
    back.name = name;
    back.patronymic = patronymic;
    back.group = group;
}

void remove(vector<Student> &vec, wstring surname, wstring name, wstring patronymic) {
    for (vector<Student>::iterator it = vec.begin(); it != vec.end();) {
        if (it->surname == surname && it->name == name && it->patronymic == patronymic) {
            it = vec.erase(it);
            wcout << L"Видалено." << endl;
            return;
        } else
            ++it;
    }

    wcout << L"Не знайдено." << endl;
}
