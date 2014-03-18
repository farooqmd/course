#include <iostream>
using namespace std;

class MyBaseException {};
class Exception1 : public MyBaseException {};
class Exception2 : public MyBaseException {};

// * Catch can distinguish between types
int main() {
  try {

    throw Exception1();

    throw Exception2();

  } catch (Exception1 &ex) {
    cout << "Caught exception1!" << endl;
  } catch (MyBaseException &ex) {
    cout << "Caught base exception!" << endl;
  }
}
