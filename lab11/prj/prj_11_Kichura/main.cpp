#include <codecvt>
#include <locale>
#include <iostream>
#include "ModulesKichura.h"
#include "ModulesDiachenko.h"
#include "ModulesSprynchan.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    wcout.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    wcin.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    vector<Student> students;

    read(students, "data.tsv");

    while (true) {
        int choice;

        wcout << L"Деканат: облік студентів" << endl <<
            L"1. Пошук запису" << endl <<
            L"2. Виведення бази даних на екран" << endl <<
            L"3. Зберігання бази даних у заданий файл" << endl <<
            L"4. Додавання нового запису в базу" << endl <<
            L"5. Вилучення запису із бази" << endl <<
            L"6. Завершення роботи програми і запис даних" << endl <<
            L"Введіть необхідну дію: ";

        wcin >> choice;
        wcin.ignore();
        switch (choice) {
            case 1:
            {
                wstring record;
                wcout << L"Введіть прізвище: ";
                getline(wcin, record);
                search(students, record);
                break;
            }
            case 2:
            {
                output(students);
                break;
            }
            case 3:
            {
                wstring path;
                wcout << L"Введіть шлях до файла: ";
                getline(wcin, path);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
                string converted_path = converter.to_bytes(path);
                save(students, converted_path);
                break;
            }
            case 4:
            {
                wstring surname;
                wstring name;
                wstring patronymic;
                wstring group;

                wcout << L"Введіть прізвище: ";
                getline(wcin, surname);
                wcout << L"Введіть ім'я: ";
                getline(wcin, name);
                wcout << L"Введіть по батькові: ";
                getline(wcin, patronymic);
                wcout << L"Введіть групу: ";
                getline(wcin, group);
                add(students, surname, name, patronymic, group);
                break;
            }
            case 5:
            {
                wstring surname;
                wstring name;
                wstring patronymic;

                wcout << L"Введіть прізвище: ";
                getline(wcin, surname);
                wcout << L"Введіть ім'я: ";
                getline(wcin, name);
                wcout << L"Введіть по батькові: ";
                getline(wcin, patronymic);
                remove(students, surname, name, patronymic);
                break;
            }
            case 6:
            {
                save(students, "data.tsv");
                return 0;
            }
            default:
                wcout << L"Помилкові дані." << endl;
        }
    }
}
