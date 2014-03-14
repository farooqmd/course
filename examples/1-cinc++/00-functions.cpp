#include <iostream>
using namespace std;

// * Define a function
// * a function that returns an integer
int getinput() {
  int val;
  cout << "type an integer: ";
  cin >> val;
  return val;
}

// * another function
// * return value is a char
// * input parameter is an int
// * a function can have several input parameters (ARGUMENTS)
// * ... but only a single RETURN TYPE
char cfunc(int i) {
  if(i == 0)
    return 'a';
  if(i == 1)
    return 'g';
  if(i == 5)
    return 'z';
  return 'c';
}

// * functions can also not have a return value
// * in that case, all functionality is in the SIDE EFFECTS
void saybye() {
  cout << "Good bye!" << endl;
}

int main() {
  int input = getinput();
  cout << cfunc(input) << endl;
  saybye();
}
