#include <iostream>
#include <vector>
using namespace std;

// * We can as easily create a vector of integers
int main() {
  vector<int> v;
  // create vector
  for (int i = 0; i < 10; i++) v.push_back(i);

  // output vector
  for (int n: v) cout << n << ", ";
  cout << endl;

  // multiply the vector by 10
  // * The "&" makes n a REFERENCE to the integer ...
  // * ... that we can modify
  for (int &n: v) n *= 10;

  // output again
  for(int n: v) cout << n << ", ";
  cout << endl;
}
