#include <string>
#include <iostream>
using namespace std;

// a string consists of several components
int main() {
  string s1, s2; // Empty strings
  string s3 = "Hello, World!"; // Initialized
  string s4("6*7"); // Also initialized

  s2 = "42"; // Assigning to a string
  s1 = s3 + " " + s4; // Concatenating strings
  s1 += "="; // Appending to a string

  cout << s3 << endl;

  // string functions use OBJECT SYNTAX
  s3.insert(7, "funny ");
  // can think like insert(s3, 7, "funny ")
  cout << s3 << endl;

  s3.replace(7, 6, "scary ");
  cout << s3 << endl;

  // conversion between numbers and string
  s1 = to_string(3);
  s2 = to_string(42.23);

  int n = stoi(s1);
  float f = stof(s2);
}
