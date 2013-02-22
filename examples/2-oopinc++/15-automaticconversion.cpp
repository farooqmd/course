#include <iostream>
using namespace std;

/* string wrapper to show what happens */
class String {
  string value;
public:
  /* this we only need for constructs like String x = "Hallo".
     Otherwise, the conversion from const string & is enough */
  //String(const char *val): value(val) {
  //  cout << "const char * constructor" << endl;
  //}
  String(const string &val): value(val)  {
    cout << "const string & constructor" << endl;
  }
};

int main()
{
  // here, the string constructor is called (closest binding)
  cout << "string s1: ";
  String s1(string("Hallo"));
  /* here, the const char *constructor, if available. If not
     "Hallo" gets converted to string and then to String. */
  cout << "string s2: ";
  String s2("Hallo");
}
