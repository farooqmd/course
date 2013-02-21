#include <vector>
#include <array>
#include <iostream>

using namespace std;


// * VECTOR and ARRAY
int main() {
  // * ARRAY: C++-interface to constant size C-style array
  // * C++11
  // * equivalent to int a[4]
  array<int, 4> a = { {0, 1, 2, 3} };

  // * Random access
  cout << "a[3]=" << a[3] << endl;

  // * Loop
  for (int i: a) cout << i << endl;

  // * Iterators
  for (auto it = a.begin(); it != a.end(); it++)
    cout << *it << endl;

  // * No resize, insert, erase

  // * VECTOR: dynamic array
  // * create a vector
  vector<int> v = { {0, 1, 2, 3} };

  // random access
  cout << "v[3]=" << v[3] << endl;

  // C++11 container loop
  for (int i: v)
    cout << i << endl;

  // * Iterators
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << endl;

  // * put new element to the end
  v.push_back(4);

  // * resize vector
  v.resize(10, -1);
  for (int i: v)
    cout << i << endl;
  
  // * insert/erase element
  auto it1 = v.begin();
  it1++; it1++; it1++; it1++;
  auto it2 = v.begin();
  it2++; it2++;

  cout << "*it1=" << *it1 << endl;
  cout << "*it2=" << *it2 << endl;

  v.erase(it2);

  // * Iterators are invalidated!
  cout << "*it1=" << *it1 << endl;
  cout << "*it2=" << *it2 << endl;
}


// ADAPTOR: stack, queue
