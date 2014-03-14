// and auto-decrement operators.
#include <iostream>
using namespace std;

// * a++: first use a, then increment it
// * ++a, first increment a, then use it
int main() {
  int i = 0;
  int j = 0;
  cout << ++i << endl; // Pre-increment
  cout << j++ << endl; // Post-increment
  cout << --i << endl; // Pre-decrement
  cout << j-- << endl; // Post decrement
}
