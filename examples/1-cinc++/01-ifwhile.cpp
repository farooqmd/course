// IF, WHILE and DO...WHILE
#include <iostream>
using namespace std;

int main() {
  int age;
  cout << "Please enter your age and hit 'Enter'" << endl;
  cin >> age;

  // * SYNTAX: if (<expression>) <statement> [else <statement>]
  // * "if" works with and without "else"
  // * EXPRESSION in brackets has to evaluate to a boolean value
  //   ("true" or "false")
  // * STATEMENT can be a single statement, or a compound statement
  //   (BLOCK) between braces ("{}")
  if (age < 18)
    cout << "I will only play with adults." << endl;
  else {

    // * SYNTAX: while (<expression>) <statement>
    while (age > 50) {
      cout << "Too dangerous to play with the elderly." << endl;
      cout << "Please enter your age again." << endl;
      cin >> age;
    }

    int guess;
    int secret = 42;
    // * SYNTAX: do <statement> while (<expression>);
    do {
      cout << "Please guess my number." << endl;
      cin >> guess;

      if (guess > secret) cout << "Too large!" << endl;
      else if (guess < secret) cout << "Too small!" << endl;
    } while (guess != secret);

    cout << "You guessed it!" << endl;
  }
}
