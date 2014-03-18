#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// The "C-way" of error handling
char*
openAndRead(const char* filename) {
  // open the file for reading
  FILE* file = fopen(filename, "r");
  // allocate memory
  char *buf = (char*)malloc(1024);
  // read data from the file into the memory
  fgets(buf, 1024, file);
  // return the data
  return buf;
}

int main() {
  char* buf = openAndRead("example.txt");
  cout << buf << endl;
}
