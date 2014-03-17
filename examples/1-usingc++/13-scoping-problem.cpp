#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string read_text() {
  // read text from file
  ifstream in("mobydick.txt");

  string text;
  getline(in, text);

  return text;
} // <-- destroy text

int main() {
  // creates a copy of the string!
  string s = read_text();

  // references to the rescue?
}

