#include "ModulesSprynchan.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(NULL));
    string authorInfo = "�������� ��������� �.������������� 12.05.2023";
    int randomNumber = rand() % 91 + 10;
    string inputText;
    ifstream inputFile("input.txt");

    getline(inputFile, inputText, '\0');

    bool hasPunctuationMistakes = !checkPunctuation(inputText);

    ofstream outputFile("output.txt");
    outputFile << authorInfo << endl;
    outputFile << "��������� �����: " << randomNumber << endl;
    outputFile << "����� �� ����������� �������: " << (hasPunctuationMistakes ? "���" : "�") << endl;

    inputFile.close();
    outputFile.close();

    std::ofstream outfile("input.txt", std::ios_base::app);
    if (!outfile) {
        std::cerr << "�������: �� ������� ������� ���� ��� ��������!\n";
        return 1;
    }

    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    char date[11];
    std::strftime(date, sizeof(date), "%d.%m.%Y", now_tm);

    outfile << "\n���� ��������: " << date << "\n";
    outfile.close();

    double x, y, z;
    int b;

    cout << "������ ����� x, y, z �� ���������� ����� b:" << endl;
    cin >> x >> y >> z >> b;

    ofstream outFile;
    outFile.open("output.txt", ios_base::app);

    if (!outFile) {
        cerr << "�� ������� ������� ���� output.txt" << endl;
        return;
    }

    outFile << "���������� ������� s_calculation � ����������� " << x << ", " << y << ", " << z << ": " << s_calculation(x, y, z) << endl;

    int binary_b[32];
    int i = 0;
    while (b > 0) {
        binary_b[i] = b % 2;
        b /= 2;
        i++;
    }
    outFile << "����� " << b << " � ��������� ���: ";
    for (int j = i - 1; j >= 0; j--) {
        outFile << binary_b[j];
    }
    outFile << endl;
}
    outFile.close();

    return 0;
}
