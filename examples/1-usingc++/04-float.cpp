#include <iostream>
#include <cmath>

using namespace std;

// fundamental datatypes
int main() {
  // FLOATING POINT NUMBERS
  float x = 42.23;
  // scientific notation
  float x2 = 42.23e17;

  // double precision float
  double pi = 3.1315924;

  // and even larger
  long double almost_one = 0.999999999999999999999999999999999;

  // same operations as with integers
  double x3 = almost_one * x / x2;

  // mixed operations result in floats
  double x4 = almost_one / 42 + 3;

  // more functions in cmath
  x2 = sqrt(exp(pi) / pow(x2, pi) * log(almost_one) + cos(pi));

  // transform a float into an int
  // implicit
  int n = x2;
  // explicit
  int n2 = int(x);
  // round, floor, ceil
  n = round(x);
  n = ceil(x);
  n = floor(x);

  // floats can also be "infinity" and "NaN" (not-a-number)
  x = 1.0/0.0;
  x2 = 0.0/0.0;
  cout << x << endl;
  cout << x2 << endl;

  // sizes
  cout 
    << "float=" << sizeof(float) << endl
    << "double=" << sizeof(double) << endl
    << "long double=" << sizeof(long double) << endl;
}
