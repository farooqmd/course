#include <iostream>
#include <sstream>
using namespace std;

#include "Vector.hpp"

int main()
{
  Vector<int> vecNums(10);
  Vector<string> vecStrings(vecNums.getSize());

  // fill the vectors with some numbers and strings
  for (int i = 0; i < vecNums.getSize(); ++i) {
    vecNums[i] = i % 3;
    ostringstream os; os << vecNums[i];
    vecStrings[i] = os.str();
  }

  // making a constant COPY of the strings vector works
  Vector<string> vecStringsCopy(vecStrings);

  /* using a (const) reference to the numbers is also ok,
     as Vector is const-aware */
  const Vector<int> &vecNumsConstRef(vecNums);

  // that doesn't work, it's const!
  // vecNumsConstRef[0] = 42;

  // show the numbers and strings
  for (int i = 0; i < vecNums.getSize(); ++i) {
    cout << vecNumsConstRef[i] << " = " << vecStringsCopy[i] << endl;
  }

  return 0;
}
