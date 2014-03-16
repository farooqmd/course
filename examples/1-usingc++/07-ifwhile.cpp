#include <iostream>
using namespace std;

int main() {
  int age;

  cout << "Please enter your age and hit 'Enter': ";
  cin >> age;

  // SYNTAX: if (<expression>) <statement>; else <statement>;
  if (age < 18)
    cout << "I will only play with adults." << endl;
  // a statement can be a block!
  else {

    // SYNTAX: while (<expression>) <statement>;
    while (age > 50) {
      cout << "Too dangerous to play with the elderly." << endl;
      cout << "Please enter your age again: ";
      cin >> age;
    }

    int guess;
    int secret = 42;
    // * SYNTAX: do <statement> while (<expression>);
    do {
      cout << "Please guess my number between 0 and 100: ";
      cin >> guess;

      if (guess < 0) {
        cout << "I won't continue playing with someone of a negative attitude." << endl;
        // break to get out of a loop
        break;
      } else if (guess > 100) {
        cout << "Between 0 and 100, you moron!" << endl;
        // continue to go to the next iteration
        continue;
      } else if (guess > secret) 
        cout << "Too large!" << endl;
      else if (guess < secret) 
        cout << "Too small!" << endl;
      else
        cout << "Yep!" << endl;
    } while (guess != secret);

    if (guess == secret) {
      // * SYNTAX: for (<initialization>; <conditional>; <step>) <statement>
      for (int i = 10; i >= 0; --i)
        cout << i << endl;
      cout << "YOU WIN!" << endl;
    }

  }
}
