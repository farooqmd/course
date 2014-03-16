#include <iostream>
#include <string>

using namespace std;

void replace_all(string &haystack, 
                 const string needle, 
                 const string replacement) {
  for (size_t pos = haystack.find(needle);
       pos != string::npos; 
       pos = haystack.find(needle, pos)) 
    haystack.replace(pos, 2, replacement);
}

int main() {
  string text = 
    "$1 bottles of beer on the wall. $1 bottles of beer.\n"
    "Take one down and pass it around, $2 bottles of beer.\n";
  int amount = 99;

  while (amount > 0) {
    string s = text;
    replace_all(s, "$1", to_string(amount));
    amount--;
    replace_all(s, "$2", to_string(amount));

    std::cout << s << std::endl;
  }
}
