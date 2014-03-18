#include <iostream>
using namespace std;

void f(int *r) {
  cout << "r = " << *r << endl;
  *r = 5;
  cout << "r = " << *r << endl;
}

int main() {
  int x = 47;
  cout << "x = " << x << endl;
  f(&x);
  cout << "x = " << x << endl;
}
