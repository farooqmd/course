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
