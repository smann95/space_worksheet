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
  double position = constants[1];
  double velocity = constants[2];
  double angular_frequency = constants[3];
  double number_measurements = constants[4];
  double time_step = maximum_time/number_measurements;
  double mass = 1;
  double x = position,
         v = velocity,
         w = angular_frequency,
         dt = time_step,
         m = mass;
  double acceleration = -w*w*x;
  double a = acceleration;
  ofstream data;
  data.open ("data.txt");
  data << "0 \t\t" << x << endl;
  for (double time = 0; time < maximum_time; time += dt){
    v = v + 0.5*a*dt;
    x = x + v*dt;
    a = -w*w*x;
    v = v + 0.5*a*dt;
    double kinetic_energy = 0.5*m*velocity*velocity;
    double potential_energy = 0.5*m*w*w*position*position;
    double total_energy = kinetic_energy + potential_energy;
    data << time + dt << "\t\t" << x << "\t\t" << total_energy << endl;
  }
  data.close();
  return 0;
}
