#include <iostream>
using namespace std;

// * look at the addresses of variables

// * global variables
//   * will exist during the whole program 
//   * in own memory region
int global_variable1;
int global_variable2;
int global_variable3;
int global_variable4;

// * local variables and function parameters
//   * generated when function is called
//   * destroyed when function ends
//   * created on the STACK
void function1(int function_parameter1, int function_parameter2) {
  int local_variable1;
  int local_variable2;
  cout << "local_variable1: " << (long)&local_variable1 << endl;
  cout << "local_variable2: " << (long)&local_variable2 << endl;
  cout << "function_parameter1: " << (long)&function_parameter1 << endl;
  cout << "function_parameter2: " << (long)&function_parameter2 << endl;
}

void function2() {}

int main() {
  // * main variables: top of the stack
  int main_variable1;
  int main_variable2;

  // * function itself: own memory region
  cout << "function1(): " << (long)&function1 << endl;
  cout << "function2(): " << (long)&function2 << endl;
  cout << "global_variable1: " << (long)&global_variable1 << endl;
  cout << "global_variable2: " << (long)&global_variable2 << endl;
  cout << "global_variable3: " << (long)&global_variable3 << endl;
  cout << "global_variable4: " << (long)&global_variable4 << endl;
  cout << "main_variable1: " << (long)&main_variable1 << endl;
  cout << "main_variable2: " << (long)&main_variable2 << endl;

  function1(main_variable1, main_variable2);
}
