#include <iostream>
using namespace std;

// This function creates a copy of the variable value
// "pass by value"
void f(int a) {
  cout << "  a = " << a << endl;
  a = 5;
  cout << "  a = " << a << endl;
}

// This function gets a reference to the variable
// "pass by reference"
void f2(int& a) {
  cout << "  a = " << a << endl;
  a = 5;
  cout << "  a = " << a << endl;
}

int main() {
  int x = 47;
  cout << "x = " << x << endl;
  f(x);
  cout << "x = " << x << endl;
  f2(x);
  cout << "x = " << x << endl;
}
