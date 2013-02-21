#include <vector>
#include <forward_list>
#include <iostream>

using namespace std;

//   * (Singly) Linked List
//   * Doubly Linked List
int main() {
  forward_list<int> v = {{1,2,3,4}};

  for (auto i: v) 
    cout << i << endl;

  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << endl;

}
