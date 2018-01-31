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
  double position_x = constants[1];
  double position_y = constants[2];
  double position_z = constants[3];
  double velocity_x = constants[4];
  double velocity_y = constants[5];
  double velocity_z = constants[6];
  double angular_frequency = constants[7];
  double number_measurements = constants[8];
  double time_step = maximum_time/number_measurements;
  double mass = 1;
  double x = position_x,
         y = position_y,
         z = position_z,
         vx = velocity_x,
         vy = velocity_y,
         vz = velocity_z,
         w = angular_frequency,
         dt = time_step,
         m = mass;
  double acceleration_x = -w*w*x;
  double acceleration_y = -w*w*y;
  double acceleration_z = -w*w*z;
  double ax = acceleration_x;
  double ay = acceleration_y;
  double az = acceleration_z;
  ofstream data;
  data.open ("data.txt");
  data << "0 \t\t" << x << endl;
  for (double time = 0; time < maximum_time; time += dt){
    vx = vx + 0.5*ax*dt;
    x = x + vx*dt;
    ax = -w*w*x;
    vx = vx + 0.5*ax*dt;

    vy = vy + 0.5*ay*dt;
    y = y + vy*dt;
    ay = -w*w*y;
    vy = vy + 0.5*ay*dt;

    vz = vz + 0.5*az*dt;
    z = z + vz*dt;
    az = -w*w*z;
    vz = vz + 0.5*az*dt;
    double kinetic_energy = 0.5*m*vx*vx + 0.5*m*vy*vy + 0.5*m*vz*vz;
    double potential_energy = 0.5*m*w*w*x*x + 0.5*m*w*w*y*y + 0.5*m*w*w*z*z;
    double total_energy = kinetic_energy + potential_energy;
    cout << time << "\t\t" << total_energy << endl;
    data << kinetic_energy << "\t\t" << potential_energy << "\t\t" << total_energy << endl;
  }
  data.close();
  return 0;
}
