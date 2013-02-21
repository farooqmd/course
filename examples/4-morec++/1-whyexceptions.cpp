#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// The "C-way" of error handling
char*
openAndRead(const char* filename) {
  // open the file for reading
  FILE* file = fopen(filename, "r");
  if (!file) {
    cout << "Can't open " << filename  << endl;
    return 0;
  }

  // allocate memory
  char *buf = (char*)malloc(1024);
  if (!buf) {
    cout << "Can't allocate enough memory!" << endl;
    fclose(file);
    return 0;
  }

  // read data from the file into the memory
  if (!fgets(buf, 1024, file)) {
    cout << "Can't read data from " << filename << endl;
    free(buf);
    fclose(file);
    return 0;
  }
  
  return buf;
}

int main() {
  char* buf = openAndRead("example.txt");
  if (buf != 0)
    cout << buf << endl;
}
