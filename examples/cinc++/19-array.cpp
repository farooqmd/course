#include <iostream>
using namespace std;

const int N = 10;

int main() {
  // * create a new int array with 10 elements
  int *ns = new int[N];

  // * put in values in a loop
  for (int i=0; i < N; i++)
    ns[i] = i*2;

  // * output values in a pointer loop
  // * POINTER ARITHMETICS
  for (int *p = ns; p < ns+10; p++)
    cout << *p << endl;

  delete ns;
}
  
