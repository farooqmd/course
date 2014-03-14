#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  // * A vector is a CONTAINER that can contain several values of a type
  // * A vector is a TEMPLATE (see later)
  // * Create a vector of strings
  vector<string> v;

  ifstream in("example.txt");
  string s;
  // * "in >> s" will return false when there is nothing left to read
  while (in >> s)
    // * "push_back" adds the string to the end of the vector
    // * note that it is used as an OBJECT MEMBER FUNCTION (with ".")
    //   of the vector v
    v.push_back(s); 
  
  // * v.size() returns the number of elements in v
  cout << "Counted " << v.size() << " words." << endl;
  
  // * Loop over all strings and output them to the screen
  for (unsigned int i = 0; i < v.size(); i++)
    // * access the elements using "[]"
    cout << v[i] << endl;
} 

