#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // BOOLEAN VALUES
  bool truth = true;
  bool untruth = false;

  // logical operations
  truth = ! untruth; // NOT
  bool answer = truth && untruth; // AND
  answer = truth || untruth; // OR
  answer = truth ^ untruth; // XOR (same as bitwise!)

  // comparison
  truth = 3 > 2;
  untruth = 3.0 < 2.0;
  truth = 3 == 3;
  untruth = 3.0 != 3.0;

  // sizes
  cout 
    << "Number of bytes:" << endl
    << "bool=" << sizeof(bool) << endl;
}
