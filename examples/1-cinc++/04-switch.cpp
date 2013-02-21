// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// A menu using a switch statement
#include <iostream>
using namespace std;

// * "switch" allows to choose between variants
// * "Fall through" to next case
// * "break" to prevent that
int main() {
  int guess;
  int secret = 15;

  do {
    cout << "Guess my number:" << endl;
    cin >> guess;
    switch (guess) {
    case 1:
      cout << "That would be too simple." << endl;
      break;
    case 23:
    case 42: 
      cout << "Physicist or Computer Scientist, eh?" << endl;
      break;
    default:
      if (guess > secret)
        cout << "Too large!" << endl;
      else if (guess < secret)
        cout << "Too small!" << endl;
      else 
        cout << "You guessed it!" << endl;
    }
  } while (guess != secret);
}
