#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "ModulesSprynchan.h"

double s_calculation(double x, double y, double z) {
     double S =  z * sin(pow(x, 2) * y) + sqrt(fabs(z - 12 * x)) / pow(y, 3);
     return S;
}

double el_calculation(int cons_energy) {
    double price;

    if (cons_energy <= 150) {
        price = 0.3084;
    } else if (cons_energy <= 800) {
        price = 0.4194;
    } else {
        price = 1.3404;
    }

    return cons_energy * price;
}

int Beaufort_scale(double speed) {
    if (speed < 0.3) return 0;
    if (speed <= 1.5) return 1;
    if (speed <= 3.3) return 2;
    if (speed <= 5.4) return 3;
    if (speed <= 7.9) return 4;
    if (speed <= 10.7) return 5;
    if (speed <= 13.8) return 6;
    if (speed <= 17.1) return 7;
    if (speed <= 20.7) return 8;
    if (speed <= 24.4) return 9;
    if (speed <= 28.4) return 10;
    if (speed <= 32.6) return 11;
    return 12;
}

int count_zeros_or_ones(int n) {
  int bit = (n >> 9) & 1;
  int count = 0;
  if (bit == 1) {
    while (n) {
      count += (n & 1) ? 0 : 1;
      n >>= 1;
    }
  } else {
    while (n) {
      count += (n & 1) ? 1 : 0;
      n >>= 1;
    }
  }
  return count;
}

bool check_punct(string text) {
    string originalText = "Як парость виноградної лози, плекайте мову.\n"
                          "Пильно й ненастанно політь бурʼян.\n"
                          "Чистіта від сльози вона хай буде.\n"
                          "Вірно і слухняно нехай вона щоразу служить вам,\n"
                          "Хоч і живе своїм живим життям.";


    for (int i = 0; i < text.length(); i++) {
        if (ispunct(text[i]) || isspace(text[i])) {
            text.erase(i--, 1);
        }
    }


    return text == originalText;
}

void append_date(const std::string& filename) {
    std::ofstream outfile(filename, std::ios_base::app);
    if (!outfile) {
        std::cerr << "Помилка: не вдалося відкрити файл для дозапису!\n";
        return;
    }

    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    char date[11];
    std::strftime(date, sizeof(date), "%d.%m.%Y", now_tm);

    outfile << "\nДата дозапису: " << date << "\n";
    outfile.close();
}

void myFunction() {
    double x, y, z;
    int b;

    cout << "Введіть числа x, y, z та натуральне число v:" << endl;
    cin >> x >> y >> z >> b;

    ofstream outFile;
    outFile.open("output.txt", ios_base::app);

    if (!outFile) {
        cerr << "Не вдалося відкрити файл output.txt" << endl;
        return;
    }

    outFile << "Результати функції s_calculation з аргументами " << x << ", " << y << ", " << z << ": " << s_calculation(x, y, z) << endl;

    int binary_b[32];
    int i = 0;
    while (b > 0) {
        binary_b[i] = v % 2;
        b /= 2;
        i++;
    }
    outFile << "Число " << b << " у двійковому коді: ";
    for (int j = i - 1; j >= 0; j--) {
        outFile << binary_b[j];
    }
    outFile << endl;

    outFile.close();
}
