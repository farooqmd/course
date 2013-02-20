#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> v = { 1, 2, 3, 4 };

  // Array loop
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;

  // C++11 container loop
  for (int i: v)
    cout << i << endl;

  // "classic" container loop
  for (vector<int>::iterator it = v.begin(); 
       it != v.end(); 
       it++)
    cout << *it << endl;
  
  // using C++ auto
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << endl;

}
