#include <iostream>
using namespace std;

/* simple string wrapper */
class MyString {
  string value;
public:
  /* putting "explicit" here forbids the implicit conversion
     and thus solves the ambiguity */
  MyString(const char *val): value(val) {}

  const string &getContent() {return value; }
};

/* a class that can be initialized both from MyString and string
   equally */
class User {
  string member;
public:
  User(MyString bla): member(bla.getContent()) {}
  User(string bla): member(bla) {}
};

int main()
{
  /* this fails, since the compiler doesn't what intermediate class to
     use, MyString or string */
  User user("Hallo");
  User user2(MyString("Welt"));
}
