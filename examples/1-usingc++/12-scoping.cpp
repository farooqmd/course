#include <iostream>
using namespace std;

// GLOBAL VARIABLES
// visible everywhere!
const float PI = 3.141;
int counter;

float area(float r) { // <-- r is created
  // r is visible here
  counter++;
  float sqr = r*r; // <-- sqr is created
  return PI * sqr;
} // <-- r, sqr are destroyed

int main() {
  counter = 0;
  float x = 2.0;

  { 
    x *= 2.0;
    float r = x*x; 
    area(r);
  } // <-- r is destroyed, x is still visible 

  { 
    x *= 2.0;
    float r = x*x; 
    area(r);
  } // <-- r is destroyed, x is still visible 

  cout << "x=" << x << endl;
  cout << "area was called " << counter << " times." << endl;

}
