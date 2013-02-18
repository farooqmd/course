#include <iostream>
using namespace std;
#include "CountOccurance.hpp"

int main()
{
  for (int i = 0; i < 10; ++i) {
    new CountOccurance;
  }
  cout << CountOccurance::getCount() << endl;

  return 0;
}
