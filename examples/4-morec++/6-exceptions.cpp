#include <iostream>
using namespace std;

// * Catch can distinguish between types
int main() {
  try {
    
    throw 17;

    throw string("Some error.");

    throw 3.14159;

  } catch (int errorcode) {
    cout << "Caught error code: " << errorcode << endl;
  } catch (string &message) {
    cout << "Caught error message: " << message << endl;
  } catch (...) {
    cout << "Caught some other exception." << endl;
  }
}
