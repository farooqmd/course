#include <iostream>
using namespace std;

#include "ValArray.hpp"

int main()
{
  // default length is 3
  ValArray<int, 10> vecNums;

  // fill the vector with some numbers
  for (int i = 0; i < vecNums.getSize(); ++i) {
    vecNums[i] = i % 3;
  }

  /* show the numbers, using auto -
     ValArray has iterators like a real STL container! */
  for (auto nr : vecNums) {
    cout << nr << endl;
  }

  return 0;
}
