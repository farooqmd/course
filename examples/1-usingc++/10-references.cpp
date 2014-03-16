#include <iostream>
using namespace std;

// * REFERENCES "point" to another variable
int main() {
  int a = 15;
  int b = a;
  int &c = a;

  // they are used exactly as the variable itself
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << c << endl;

  a = 17;
  cout << "a <- 17" << endl;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << c << endl;

  c = 3;
  cout << "c <- 3" << endl;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << c << endl;

}
