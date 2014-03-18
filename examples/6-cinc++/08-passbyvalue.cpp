#include <iostream>
using namespace std;

// * the function creates a copy of the variable value
// * modifying the variable does not change the value in the calling
//   program!
void f(int a) {
  cout << "a = " << a << endl;
  a = 5;
  cout << "a = " << a << endl;
}

int main() {
  int x = 47;
  cout << "x = " << x << endl;
  f(x);
  cout << "x = " << x << endl;
}
