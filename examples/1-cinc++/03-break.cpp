#include <iostream>
using namespace std;

// * "break" jumps out of the loop
// * "continue" continues with the next iteration
int main() {
  int guess;
  int secret = 15;

  do {
    cout << "Guess my number:" << endl;
    cin >> guess;

    if (guess < 0) {
      cout << "I won't continue playing with someone of a negative attitude." << endl;
      break;
    }
    if (guess > 20) {
      cout << "I won't comment on ridiculously large numbers." << endl;
      continue;
    }

    if (guess > secret)
      cout << "Too large!" << endl;
    else if (guess < secret)
      cout << "Too small!" << endl;
    else 
      cout << "You guessed it!" << endl;

  } while (guess != secret);
}
