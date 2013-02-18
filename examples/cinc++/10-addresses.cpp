// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
using namespace std;

// * look at the addresses of variables
// * type casting
int a, b, c, d;

void f() {
  int fi;
  int fj;
  cout << "fi: " << (long)&fi << endl;
  cout << "fj: " << (long)&fj << endl;
}

int main() {
  int i, j, k;
  cout << "f(): " << (long)&f << endl;
  cout << "a: " << (long)&a << endl;
  cout << "b: " << (long)&b << endl;
  cout << "c: " << (long)&c << endl;
  cout << "d: " << (long)&d << endl;
  cout << "i: " << (long)&i << endl;
  cout << "j: " << (long)&j << endl;
  cout << "k: " << (long)&k << endl;
  f();
}
