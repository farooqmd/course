// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
using namespace std;

int global_variable;

void function(int function_parameter) {
  int local_variable;
  cout << "function_parameter: " << (long)&function_parameter << endl;
  cout << "local_variable: " << (long)&local_variable << endl;
}

// dynamic variables: created on the HEAP
int main() {
  int main_variable;

  // generate a new int on the heap
  int *pointer = new int;

  // now it is a normal pointer
  *pointer = 17;

  cout << "function(): " << (long)&function << endl;
  cout << "global_variable: " << (long)&global_variable << endl;
  cout << "dynamic_variable: " << (long)pointer << endl;
  cout << "main_variable: " << (long)&main_variable << endl;

  function(main_variable);

  // * delete the pointer (must be done manually!)
  // * otherwise it is a MEMORY LEAK
  delete pointer;
}
