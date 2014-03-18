#include <vector>
#include <iostream>

using namespace std;

int main() {
  // vector is a template, that can store different types
  vector<string> shopping_list = { {"Milk", "Butter", "Beer", "Bread"} };

  // Access to single elements
  cout << "shopping_list[2]=" << shopping_list[2] << endl;
  shopping_list[1] = "Margarine";

  // Old-style loop
  // Not good for other containers, as v[i] might be slow (or not available)
  cout << "Classical loop:" << endl;
  for (size_t i = 0; i < shopping_list.size(); ++i)
    cout << "  " << shopping_list[i] << endl;

  // C++11 container loop
  cout << "C++11 loop:" << endl;
  for (string item: shopping_list)
    cout << "  " << item << endl;

}
