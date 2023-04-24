#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

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
