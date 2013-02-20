#include <iostream>
#include <string>
using namespace std;

/* illustration of multiple inheritance */

class Person {
protected:
  string name;
public:
  Person(const string &_name): name(_name) {}
  string getName() { return name; }
};

class Horse {
protected:
  float tailLength;
public:
  Horse(float _tailLength): tailLength(_tailLength) {}
  float getTailLength() { return tailLength; }
};

class Centaur: public Person, public Horse {
public:
  Centaur(const string &_name, float _tailLength)
  : Person(_name), Horse(_tailLength) {
  }
};

int main() {
  Person axel("Axel");
  Horse julius(10);
  Centaur centaurus("Centaurus", 20);

  cout << "axel: "  << axel.getName() << endl;
  cout << "julius: "  << julius.getTailLength() << endl;
  cout << "centaurus: "  << centaurus.getName() << " "
       << centaurus.getTailLength() << endl;

  return 0;
}
