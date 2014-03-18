#include <iostream>
#include <cmath>
using namespace std;

// * Exceptions make a function return
float myroot(float x) {
  if (x < 0.0) throw string("Can't take root of a negative number!");
  return sqrt(x);
}


int main() {
  try {

    cout << "myroot(2.0)=" << myroot(2.0) << endl;
    cout << "myroot(-1.0)=" << myroot(-1.0) << endl;

  } catch (string& ex) {
    cout << "Caught exception: " << ex << endl;
  }

  // * An uncaught exception terminates the program gracefully
  throw 42;
}
