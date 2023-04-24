#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

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

int Beaufort_num(double windSpeed) {
    if (windSpeed < 0.3) {
        return 0;
    } else if (windSpeed <= 1.5) {
        return 1;
    } else if (windSpeed <= 3.3) {
        return 2;
    } else if (windSpeed <= 5.4) {
        return 3;
    } else if (windSpeed <= 7.9) {
        return 4;
    } else if (windSpeed <= 10.7) {
        return 5;
    } else if (windSpeed <= 13.8) {
        return 6;
    } else if (windSpeed <= 17.1) {
        return 7;
    } else if (windSpeed <= 20.7) {
        return 8;
    } else if (windSpeed <= 24.4) {
        return 9;
    } else if (windSpeed <= 28.4) {
        return 10;
    } else if (windSpeed <= 32.6) {
        return 11;
    } else {
        return 12;
    }
}

int min_wind_speed(const std::vector<double>& windSpeeds) {
    int min_Beaufort = Beaufort_num(windSpeeds[0]);
    for (int i = 1; i < windSpeeds.size(); i++) {
        int Beaufort = Beaufort_num(windSpeeds[i]);
        if (Beaufort < min_Beaufort) {
            min_Beaufort = Beaufort;
        }
    }
    return min_Beaufort;
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
