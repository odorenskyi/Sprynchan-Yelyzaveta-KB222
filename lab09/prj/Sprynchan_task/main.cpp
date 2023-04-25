#include <iostream>
#include <conio.h>
#include "ModulesSprynchan.h"

using namespace std;

int main()
{
    system("chcp 1251 & cls");
    int x, y, z;
    int cons_energy;
    double speed;
    int n;

    cout << "d - calls a function s_calculation" << endl
         << "g - calls a function el_calculation" << endl
         << "h - calls a function Beaufort_scale" << endl
         << "j - calls a function count_zeros_or_ones" << endl
         << "'k','K' and 'ê' terminate the program" << endl;
    getchar();

    while(true) {
        cout << "Enter letter (d/g/h/j/k/K/ê): ";
        switch (getch()) {
            case 'd': cout << endl;
                      cout << "Enter x: ";
                      cin >> x;
                      cout << "Enter y: ";
                      cin >> y;
                      cout << "Enter z: ";
                      cin >> z;
                      cout << "the result of S = " << s_calculation(x,y,z) << endl;
                      break;
            case 'g': cout << endl;
                      cout << "Enter number of consumed energy: ";
                      cin >> cons_energy;
                      cout << "Electricity bill: " << el_calculation(cons_energy) << "UAH" << endl;
                      cout << endl;
                      break;
            case 'h': cout << endl;
                      cout << "Enter number of speed: ";
                      cin >> speed;
                      cout << "Beafort point of the weakest wind power in 24 hours is: " << Beaufort_scale(speed) << endl;
                      cout << endl;
                      break;
            case 'j':  cout << endl;
                      cout << "Enter number in range 0 - 500700: ";
                      cin >> n;
                      cout << "Tne amount of binary zeros or onces is " << count_zeros_or_ones(n) << endl;
                      cout << endl;
                      break;
            case 'k':
                 return 0;
                  break;
            case 'K':
                 return 0;
                  break;
            case 'ê':
                return 0;
                 break;
            default:
                cout << "\a" << endl << endl;
                 continue;
        }
    }
}
