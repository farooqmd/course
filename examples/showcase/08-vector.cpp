// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Copy an entire file into a vector of string
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  vector<string> v;

  ifstream in("example.txt");
  string s;
  while (in >> s)
    v.push_back(s); 
  
  cout << "Counted " << v.size() << " words." << endl;
  
  // * RANGED FOR LOOP, C++11 style
  // * Like "foreach" in Python
  for (string &s: v)
    cout << s << endl;
} 
