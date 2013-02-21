#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  // * Stream output of different types
  // * The way how to output a type something can be defined by the
  //   user
  cout << "an integer: " << 15 << endl;
  cout << "a floating-point number: " << 3.14159 << endl;

  // * Output formatting with MANIPULATORS
  cout << "with defined width: " << setw(20) << 15 << endl;
  cout << "in octal: " << oct << 15 << endl;
  cout << "in hex: " << hex << 15 << endl;
  cout << "rounded float: " << setprecision(5) << 3.14159 << endl;
  cout << "scientific float: " << scientific << 3.14159 << endl;

  // * CHARACTER ARRAY CONCATENATION
  cout << "A long line can be split, as C/C++ will "
          "automatically concatenate string constants." 
       << endl;
}
