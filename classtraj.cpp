#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv[])
{
  if (argc < 6){
    cout << error << endl;}

  stringstream ss_1(argv[1]);
    if (!(ss_1 >>clear initial_position))
      cout << initial_position;
  return 0;
}
