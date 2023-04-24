#ifndef MODULESSPRYNCHAN_H_INCLUDED
#define MODULESSPRYNCHAN_H_INCLUDED

double s_calculation(double x, double y, double z);

double el_calculation(int cons_energy);

int Beaufort_num(double windSpeed);

int min_wind_speed(const std::vector<double>& windSpeeds);

int count_zeros_or_ones(int n);

#endif // MODULESSPRYNCHAN_H_INCLUDED
