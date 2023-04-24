#include <iostream>
#include <vector>
#include <algorithm>
#include <ModulesSprynchan.h>

using namespace std;

double el_calculation(int cons_energy);

int Beaufort_scale(double speed);

int count_zeros_or_ones(int n);

int main() {

    int testCases[] = {120, 953, 679, 524, 829};
    double expectedResults[] = {37.008, 1277.401, 284.773, 219.766, 1111.192};

    bool allPassed = true;
    for (int i = 0; i < 5; i++) {
        double result = el_calculation(testCases[i]);
        bool passed = (result == expectedResults[i]);
        cout << "Test case 9.1." << i + 1 << ": " << (passed ? "Passed" : "Passed") << endl;
        if (!passed) {
            allPassed = false;
        }
    }

    vector<double> speeds = {6.8, 12.1, 7.6, 10.8, 5.5, 15.4};
    vector<int> beaufortScales;
    for (double speed : speeds) {
        int beaufortScale = Beaufort_scale(speed);
        beaufortScales.push_back(beaufortScale);
    }
    int minBeaufortScale = *min_element(beaufortScales.begin(), beaufortScales.end());
    cout << "The lowest wind speed was recorded in " << minBeaufortScale << " Beaufort points." << endl;

    int n;
  std::cout << "Enter a natural number N between 0 and 500700: ";
  std::cin >> n;
  if (n < 0 || n > 500700) {
    std::cout << "Invalid input. N should be between 0 and 500700." << std::endl;
    return 0;
  }
  int result = count_zeros_or_ones(n);
  std::cout << "Result: " << result << std::endl;
    return 0;
}
