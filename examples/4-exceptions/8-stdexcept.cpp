#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
  vector<int> v;
  try {

    v.at(3) = 42;

  } catch (exception &ex) {
   cout << "Could not create vector: " << ex.what() << endl;
  }
}

// * logic_error: problem in the code
// * runtime_error: problem that can be detected only at runtime (e.g. file not found)
