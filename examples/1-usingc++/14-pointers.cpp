#include <iostream>
using namespace std;

int main() {
  int a = 15;
  int &aref = a;
  int *aptr = &a;

  cout << "a=" << a << endl;
  cout << "aref=" << aref << endl;
  // apointer needs to be "dereferenced"
  cout << "*aptr=" << *aptr << endl;

  a = 17;
  cout << "a <- 17" << endl;

  cout << "a=" << a << endl;
  cout << "aref=" << aref << endl;
  cout << "*aptr=" << *aptr << endl;

  // but a pointer can be modified!
  int b = 42;
  aptr = &b;
  cout << "aptr = &b" << endl;

  cout << "a=" << a << endl;
  cout << "aref=" << aref << endl;
  cout << "*aptr=" << *aptr << endl;

  // in particular, it can also point to nowhere
  aptr = nullptr;
  cout << "*aptr=" << *aptr << endl;
}
