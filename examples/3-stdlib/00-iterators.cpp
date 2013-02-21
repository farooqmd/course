#include <vector>
#include <iostream>

using namespace std;

// * CONTAINER
//   * Something that holds several values of a specific type
//   * Allows to ITERATE (LOOP) over the values in the container
int main() {
  vector<int> v = { 1, 2, 3, 4 };

  // * Array loop
  // * Not good for other containers, as v[i] might be slow!
  cout << "Array loop:" << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;

  // * C++11 container loop
  // * Only works when you really want to loop over the whole
  //   container at once
  // * Counter example: Player::chooseNextPiece()
  cout << "C++11 loop:" << endl;
  for (int i: v)
    cout << i << endl;

  // * ITERATOR
  //   * An iterator is a generalized pointer
  //   * It points to a value in a container
  //   * The value can be accessed via dereference (*a)
  //   * An iterator can be incremented (a++) to get to the next value
  //     of the container
  //   * A container has begin() and end()

  // * an iterator that points to the beginning of the vector
  vector<int>::iterator it = v.begin();
  cout << "Single iterator:" << endl;
  cout << "\t*it=" << *it << endl;

  // * "classic" container loop, using iterators
  cout << "Classic loop:" << endl;
  for (vector<int>::iterator it = v.begin(); 
       it != v.end(); 
       it++)
    cout << "\t" << *it << endl;
  
  // * using C++11 auto
  cout << "Classic loop with auto:" << endl;
  for (auto it = v.begin(); it != v.end(); it++)
    cout << "\t" << *it << endl;

}
