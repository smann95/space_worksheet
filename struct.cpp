#include <iostream>
using namespace std;

struct stuff {
  double numbers;
  string title;
} x, y, z;

int main()
{
x.title = "position";
x.numbers = 0;

cout << x.title << ":\n";
cout << x.numbers << endl;
  return 0;
}
