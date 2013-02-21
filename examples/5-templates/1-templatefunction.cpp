#include <iostream>
#include <vector>
using namespace std;

template<class STLVectorClass>
void printIndexedTable(const STLVectorClass &vec)
{
  cout << "\\begin{tabular}{r|l}" << endl;
  int i = 0;
  for (auto val: vec) {
    cout << i++ << " & " << val << "\\\\"<< endl;
  }
  cout << "\\end{tabular}" << endl;
}

void int_example()
{
  vector<int> vecNums(10);
  // fill the vectors with some numbers
  for (unsigned int i = 0; i < vecNums.size(); ++i) {
    vecNums[i] = i % 3;
  }
  printIndexedTable(vecNums);
}

void float_example()
{
  vector<float> vecNums(10);
  // fill the vectors with some numbers
  for (unsigned int i = 0; i < vecNums.size(); ++i) {
    vecNums[i] = 3.1415926 * i;
  }
  printIndexedTable(vecNums);
}

int main()
{
  int_example();
  float_example();
}
