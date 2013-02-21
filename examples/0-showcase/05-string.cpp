#include <string>
#include <iostream>
using namespace std;
int main() {
  // * Strings are dynamical
  // * They can be appended, concatenated, etc.
  // * Significant improvement over C's "char*" (that still works!)
  string s1, s2; // Empty strings
  string s3 = "Hello, World!"; // Initialized
  string s4("6*7"); // Also initialized
  s2 = "42"; // Assigning to a string
  s1 = s3 + " " + s4; // Concatenating strings
  s1 += "="; // Appending to a string
  cout << s1 + s2 + "!" << endl;
}
