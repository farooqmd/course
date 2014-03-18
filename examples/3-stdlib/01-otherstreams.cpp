#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  // You can also open a file as a stream to read from or write to

  // Open for reading
  ifstream in("example.txt"); 
  // Open for writing
  ofstream out("example-copy.txt"); 

  string s;
  while (in >> s) // Discards whitespaces
    out << s << " "; // ... must add it back

  // Also, you can use a stringstream to write 
  // to and read from
  int n = 4242;
  float pi = 3.14159;

  ostringstream outs;
  // we need to add a whitespace!
  outs << n << " " << pi; 

  string contents = outs.str();

  istringstream ins(contents);
  int n2;
  float pi2;
  ins >> n2 >> pi2;

  cout << "n=" << n2 << " pi=" << pi2 << endl;
}
