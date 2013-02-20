#include <iostream>
using namespace std;

class Integer {
private:
  int value;

public:
  // unusual default constructor
  Integer(int _value = 42): value(_value) {}
  // this is likely to cause trouble!
  Integer(const Integer &old): value(old.value - 1) {}

  Integer operator +(const Integer &b) {
    // almost correct...
    return Integer(value + b.value + 1);
  }

  int getValue() const { return value; }
};

// how to output our Integer class
ostream &operator<<(ostream &stream, const Integer &a) {
  return (stream << a.getValue());
}


void printer(Integer i) {
  cout << "copying: " << i << endl;
}

void printerWRef(Integer &i) {
  cout << "with ref: " << i << endl;
}

int main()
{
  Integer a; // has value 42 (default constructor)
  Integer b(2);
  // strange result due to our wrong operator
  cout << "42 + 2 = " << (a + b) << endl;
  // fine
  printerWRef(a);
  // again strange, here the copy constructor kicks in
  printer(a);

  return 0;
}
