#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <iostream>

using namespace std;

int main() {
  array<string, 2> a = { {"Milk", "Butter" } };
  // random access
  a[1] = "Margarine";
  // no push_back
  // no push_front

  vector<string> v = { {"Milk", "Butter" } };
  v.push_back("Beer");
  // random access
  v[1] = "Margarine";
  // no push_front

  list<string> l = { {"Milk", "Butter" } };
  l.push_back("Beer");
  // no random access
  l.push_front("Bread");
 
  forward_list<string> fl 
    = { {"Milk", "Butter" } };
  // no push_back
  // no random access
  fl.push_front("Bread");

  cout << "Vector:" << endl;

  for (string s: v)
    cout << "  " << s << endl;

  cout << "List:" << endl;

  for (string s: l)
    cout << "  " << s << endl;
}
