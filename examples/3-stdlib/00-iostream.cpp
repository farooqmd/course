#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  string name;

  cout << "IOStream demonstrator" << endl;
  // input an output from/to stdin
  cerr << "Please enter your name: ";
  cin >> name;
  cerr << "Thanks, " << name << endl;

  // format the output
  bool truth = (2>3);
  cout << boolalpha;
  cout << "The truth is " << truth << endl;
  cout << noboolalpha;
  cout << "The truth is " << truth << endl;

  int n = 4242;
  cout << showbase << hex;
  cout << "n is " << n << endl;
  cout << noshowbase;
  cout << "n is " << n << endl;
  cout << showbase << oct;
  cout << "n is " << n << endl;
  cout << dec;
  cout << "n is " << n << endl;

  float pi100 = 3.141592 / 100;
  cout << scientific;
  cout << "pi100 is " << pi100 << endl;
  cout << fixed;
  cout << "pi100 is " << pi100 << endl;

  // using <iomanip>, we can influence more details
  cout << setprecision(3);
  cout << "pi100 is " << pi100 << endl;
  cout << setprecision(7);
  cout << "pi100 is " << pi100 << endl;

  cout << setw(20) << n << " is n" << endl;
  cout << setw(20) << truth << " is truth" << endl;
  cout << setw(20) << pi100 << " is pi100" << endl;

  cout << left;
  cout << setw(20) << n << " is n" << endl;
  cout << setw(20) << truth << " is truth" << endl;
  cout << setw(20) << pi100 << " is pi100" << endl;

  return 0;
}
