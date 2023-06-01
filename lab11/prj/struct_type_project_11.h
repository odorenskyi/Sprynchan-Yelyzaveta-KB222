#ifndef STRUCT_TYPE_PROJECT_11_H_INCLUDED
#define STRUCT_TYPE_PROJECT_11_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

struct Student {
    wstring surname;
    wstring name;
    wstring patronymic;
    wstring group;
};

extern vector<Student> students;

#endif // STRUCT_TYPE_PROJECT_11_H_INCLUDED
