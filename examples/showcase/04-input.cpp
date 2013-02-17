#include <iostream>
using namespace std;
int main()
{
  int number;
  cout << "Enter a decimal number: ";

  // * There are output as well as INPUT STREAMS
  // * Again, how a type is input is user-defined
  cin >> number;
  cout << "value in octal=0" << oct << number << endl;
  cout << "value in hex=0x" << hex << number << endl;
}
