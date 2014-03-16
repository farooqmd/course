#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string *read_input() {
  // create a new string
  string *textptr = new string();

  // open a file to read
  ifstream in("mobydick.txt");

  getline(in, *textptr);
  return textptr;
} 

int main() {
  // this will copy the pointer, not the text
  // the text is still in memory somewhere
  string *textptr = read_input();

  cout << *textptr << endl;
  
  // however, we need to explicitly delete the variable!
  delete textptr;
}
