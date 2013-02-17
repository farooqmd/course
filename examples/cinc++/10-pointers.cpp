#include <iostream>
using namespace std;

// * POINTERS also point to another variable
// * "*" to declare the pointer (ex. int *a)
// * "&" to get a pointer to an existing variable (ex. &a)
// * pointer needs to be DEREFERENCED when using the value (ex. *a) 
// * effectively, the memory address of the variable is stored
// * a pointer can also be modified to point to another variable
// * a pointer can also point somewhere else
// * dereferencing a pointer that points outside of the own memory
//   causes the dreaded "Segmentation Fault" 
// * pointers are the single biggest source for errors in C/C++
// * ... however, they are also one of the most important techniques
int main() {
  int a = 15;
  int b = a;
  int *c = &a;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << *c << endl;

  a = 17;
  cout << "a <- 17" << endl;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << *c << endl;

  *c = 3;
  cout << "c <- 3" << endl;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << *c << endl;

  // change where the pointer points to
  c = &b;
  cout << "let c point somewhere else" << endl;
  b = 42;
  cout << "b <- 42" << endl;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << *c << endl;
}
