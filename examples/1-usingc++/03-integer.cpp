#include <iostream>
#include <cmath>

using namespace std;

// fundamental datatypes
int main() {
  // INTEGER NUMBERS
  int n = 42;
  // a constant: cannot be modified
  const int N = 42;

  // in hex notation
  int n2 = 0xAFFE;
  // oct
  int n3 = 01234;

  // with specifier: 
  // only positive integer
  unsigned int positive_n = 654321;
  // large integer (double size)
  long int big_n = 123456789;

  // now let's do some operations
  big_n = (n2 + n3) * N - 3;
  // integer division and modulo
  n = n2 / n3; 
  n = n2 % n3;
  
  // unary operations: 
  // equivalent to n = n + 7
  n += 1; 
  n -= 2; 
  n *= 3; 
  n /= 4;

  // decrement and increment
  n++; n--;

  // <cmath> contains further useful functions
  // we can call a function like f(p)
  int min_n = min(n2, n3);
  int max_n = max(n2, n3);
  int n_square = pow(n2, n3);

  // bitwise logical operations
  n = n2 & n3; n &= n3; // AND
  n = n2 | n3; n |= n3; // OR
  n = n2 ^ n3; n ^= n3; // XOR
  n = n2 << 3; n <<= 3; // left shift (not I/O!)
  n = n2 >> 3; n >>= 3; // right shift (not I/O!)

  // sizes
  cout 
    << "Number of bytes:" << endl
    << "int=" << sizeof(int) << endl
    << "unsigned int=" << sizeof(unsigned int) << endl
    << "long int=" << sizeof(long int) << endl;


}
