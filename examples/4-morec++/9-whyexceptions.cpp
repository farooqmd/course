#include <iostream>
#include <fstream>

using namespace std;

// * Error handling is where you actually want to handle the errors
char *openAndRead(string filename) {
  ifstream file(filename);
  // turn on exceptions (this is annoying, though)
  file.exceptions( ifstream::failbit | ifstream::badbit );

  // "new" can throw "bad_alloc" 
  char* buf = new char[1024];
  // "ifstream" can throw ifstream::failure
  file.get(buf, 1024);
  return buf;
}

int main() {
  try {
    char* buf = openAndRead("example.txt");
    cout << buf << endl;
  } catch (bad_alloc &e) {
    cout << e.what() << endl;
  } catch (ifstream::failure &e) {
    cout << "Can't open " << filename << endl;
  }
}
