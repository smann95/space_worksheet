#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
  if (argc < 2){
    cout << "error" << endl;
    return 1;
  }
  vector<double> constants;
  double temp;
  ifstream input (argv[1]);
  while (input >> temp){
    constants.push_back(temp);
  }
 double maximum_time = constants[0];
 double initial_position = constants[1];
 double initial_velocity = constants[2];
 double angular_frequency = constants[3];
 double number_measurements = constants[4];
 double time_step = maximum_time/number_measurements;
double mass = 1;

 double x0 = initial_position,
        v0 = initial_velocity,
        w = angular_frequency,
        m = mass;
 for (double time = 0; time <= maximum_time; time += time_step){
   double position = x0*cos(w*time) + (v0/w)*sin(w*time);
   double velocity = -w*x0*sin(w*time) + v0*cos(w*time);
   double acceleration = -w*w*x0*sin(w*time) - v0*w*cos(w*time);
   double kinetic_energy = 0.5*m*velocity*velocity;
   double potential_energy = 0.5*m*w*w*position*position;
   double total_energy = kinetic_energy + potential_energy;
   cout << time << "\t\t" << position << "\t\t" << acceleration << "\t\t"
     << total_energy <<  endl;
 }
  return 0;
}
