// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <string>
#include <fstream>
using namespace std;

int main() {
  // * You can also open a file as a stream to read from or write to
  // * "getline" allows to read a line from a stream into a string
  ifstream in("example.txt"); // Open for reading
  ofstream out("example-copy.txt"); // Open for writing
  string s;
  while (in >> s) // Discards whitespaces
    out << s << " "; // ... must add it back
}

// * Assume that we want to keep the whole file in memory?
