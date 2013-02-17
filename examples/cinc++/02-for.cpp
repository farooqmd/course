#include <iostream>
#include <vector>
using namespace std;

int main() {
  // * SYNTAX: for (<initialization>; <conditional>; <step>) <statement>
  // * <initialization> is executed once at the beginning
  // * if <conditional> is true, execute <statement>, otherwise exit loop
  // * at the end of <statement>, execute <step>
  for (int i = 99; i > 0; i--) {
    cout << i << " bottle(s) of beer on the wall, " 
         << i << " bottle(s) of beer." << endl;
    cout << "Take one down and pass it around, "
         << (i-1) << " bottle(s) of beer on the wall."
         << endl;
  }

  // * for-loop can always be replaced by equivalent "while"-loop

  vector< int > v;
  for (int i = 0; i < 10; i++) v.push_back(i);
  // * New in C++11: "RANGED FOR LOOP"
  // * SYNTAX: for (<variable declaration>: <container>) <statement>
  // * Requires some kind of <container>, e.g. vector, array, or
  //   others (see later)
  // * The variable declared in <variable declaration> will take on
  //   the values in the container in a loop
  // * not extremely useful in this example, but *great* when working
  //   with other containers
  for (int i: v) cout << i << endl;
}
