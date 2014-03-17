#include <iostream>
#include <cmath>
using namespace std;

// Define a simple function
void sayhi() {
  cout << "Hi!" << endl;
}

// input parameters and types, return type can be specified
float area(float r) {
  return 3.14159 * r*r;
}

// default values can be given for the last parameters
// only *one* possible return type!
float lj(float r, float sigma=1.0, float epsilon=1.0) {
  // r does *not* change the value outside
  r /= sigma;
  return 4*epsilon * (pow(r, 12) - pow(r, 6));
}

// main is also "just" a function
// return type is the "exit code"
// input are the command line arguments (see later)
int main(int argc, char *argv[]) {
  sayhi();

  cout << "area(2.0)=" << area(2.0) << endl;

  float r = 1.3;
  cout << "lj(" << r << ")=" << lj(r) << endl;
  cout << "lj(" << r << ", 2.0)=" << lj(r, 2.0) << endl;
  cout << "lj(" << r << ", 2.0, 2.0)=" << lj(r, 2.0, 2.0) << endl;


  return 0;
}
