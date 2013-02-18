#include <iostream>
using namespace std;

// * typecasts change one type to another one
int main() {
  // C-style typecast
  int a = 37;
  long address_a = (long)&a;

  long b = 123456789;
  float c = (float)b;

  // C++ explicit casts
  // static cast: harmless cast
  // in many cases performed automatically by compiler
  int d = 37;
  long e = static_cast<long>(d);

  // reinterpret cast: not so harmless
  int f = 37;
  long address_f = reinterpret_cast<long>(&f);
}
