#include <iostream>
using namespace std;
#include "Integer.hpp"

int main()
{
  Integer *a = new Integer;

  // using the arrow
  a->setValue(1);
  cout << a->getValue() << endl;

  // and now dots, but arrow is more natural
  (*a).setValue(2);
  cout << (*a).getValue() << endl;

  Integer b;
  // here, dot is more natural
  b.setValue(3);
  cout << b.getValue() << endl;

  return 0;
}
    
