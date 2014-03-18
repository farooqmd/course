#include <iostream>
using namespace std;

// * try ... catch ... to "catch" exceptions
// * throw to throw it
// * An exception can be anything
int main() {
  try {

    cout << "Before throwing an exception." << endl;
    // ...
    throw 17;
    // ...
    cout << "After throwing an exception." << endl;

  } catch (int errorcode) {
    cout << "Caught errorcode " << errorcode << endl;
  }

  cout << "After the try...catch." << endl;
}
