#include <iostream>
using namespace std;

class Class
{
  int myNumber;

public:
  // a member that does not change after constructing the object
  const int myInitialValue;

  // const members can only be initialized after the colon
  Class(int n): myInitialValue(n) { myNumber = n; }

  void setMyNumber(int i) { myNumber = i; }

  int getMyNumber()  const { return myNumber; }

  void test()       { cout << "test called" << endl; }
  void test() const { cout << "const test called" << endl; }
};

// a constant, the compiler might e.g. hard-code it in loops
const int theNumber = 42;

const char *ptrtoConstChar = "Hase";
const char * const constantPtrtoConstChar = "Hase";

void variable_tests()
{
  // this is not possible, theNumber is constant
  // theNumber = 0;

  // this also not
  //ptrtoConstChar[3] = 0;
  cout << "my name was " << ptrtoConstChar << endl;
  // however, this works, as name itself is not constant
  ptrtoConstChar = "Igel";
  cout << "it is now " << ptrtoConstChar << endl;

  // constantPtrtoConstChar is really immutable:
  //constantPtrtoConstChar = "Igel";
}

void nonconst_tests(Class &cls)
{
  // not a const object, I can change it
  cls.setMyNumber(20);

  // I can read the constant, it is public
  cout << "cls's initial number was: " << cls.myInitialValue << endl;
  // but I cannot change it
  //cls.myInitialValue = 42;

  // const functions can be called on non-const objects
  cout << "cls's number is: " << cls.getMyNumber() << endl;

  // this calls the non-const version, fits better
  cls.test();
}

void const_tests(const Class &cls)
{
  // this doesn't work, it is a const object now
  //cls.setMyNumber(20);

  // I can still read the constant, it is public
  cout << "cls's initial number was: " << cls.myInitialValue << endl;

  // const functions can be called on non-const objects
  cout << "cls's number is: " << cls.getMyNumber() << endl;

  // this calls the const version, now that fits better
  cls.test();
}

int main()
{
  variable_tests();
  
  Class cls(theNumber);

  nonconst_tests(cls);

  const_tests(cls);
}
