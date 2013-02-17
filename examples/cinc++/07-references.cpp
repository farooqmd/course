#include <iostream>
using namespace std;

// * REFERENCES "point" to another variable
// * they are used exactly as the variable itself
// * a reference can not be modified, i.e. it can not be made to point
//   to another variable
int main() {
  int a = 15;
  int b = a;
  int &c = a;

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
