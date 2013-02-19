// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Using a static variable in a function
#include <iostream>
using namespace std;

// define a constant
const int max_x = 10;

void func() {
  // * define a static variable
  // * is always the same variable
  // * can be used e.g. for a function call counter
  // * initialized value is used only once
  static int count = 0;
  cout << "function was called " << ++count << " times" << endl;
}

int main() {
  for(int x = 0; x < max_x; x++)
    func();
}
