#include <iostream>

#include <unordered_set>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
  unordered_set<string> us;
  us.insert("Milk");
  us.insert("Butter");

  set<string> ts;
  ts.insert("Milk");
  ts.insert("Butter");
  ts.insert("Apples");

  for (string s: us)
    cout << "  " << s << endl;

  for (string s: ts)
    cout << "  " << s << endl;

  unordered_map<string, int> um;
  um.insert({{"Brot", 42}});
  um.insert({{"Butter", 3}});

  cout << um.find("Brot")->second << endl;
}
