#include <vector>
#include <iostream>

using namespace std;

int main() {
  // vector is a template, that can store different types
  vector<string> shopping_list = { {"Milk", "Butter", "Beer", "Bread"} };

  // => ITERATORS
  //   * An iterator is something like a pointer
  //   * It points to a value in a container
  //   * The value can be accessed via dereference (*it)
  //   * An iterator can be incremented (a++) to get to the next value
  //     of the container
  //   * Iterators can be compared (a != b)

  // access the beginning of the container
  vector<string>::iterator it = shopping_list.begin();
  cout << "Single iterator:" << endl;
  cout << "  *it=" << *it << endl;

  // Classical iterator loop
  cout << "Classical iterator loop:" << endl;
  vector<string>::iterator it2;
  for (it2 = shopping_list.begin(); 
       *it2 != "Butter"; ++it2) {}
  // iterators get long to type!

  // using C++11 auto
  // auto automatically derives the type if possible
  cout << "Classical iterator loop with auto:" << endl;
  for (; it2 != shopping_list.end(); it2++)
    cout << "  " << *it2 << endl;

}
