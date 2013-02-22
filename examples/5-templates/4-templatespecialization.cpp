#include <iostream>
using namespace std;

/* a template class that tells at compile time whether a
   type is a pointer. */
template<class T>
class isAPointer {
public:
  // per default, it is not a pointer
  static bool value() { return false; }
};
/* specialization for pointers */
template<class T>
class isAPointer<T *> {
public:
  // yes, it is a pointer
  static bool value() { return true; }
};

int main()
{
  cout << isAPointer<int *>::value() << " "
       << isAPointer<int>::value() << endl;

  return 0;
}
