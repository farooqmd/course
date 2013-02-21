#include <iostream>
#include <string>
using namespace std;

// * struct definition
struct Player {
  string name;
  int numberOfPieces;
};

// * function that uses a struct
void printPlayer(Player &player) {
  cout << "Player " << player.name << " has " 
       << player.numberOfPieces << " pieces in the game."
       << endl;
}

int main() {
  // constant initializer
  Player p1 = { "Axel", 3 };

  // initialize single elements
  Player p2;
  p2.name = "Olaf";
  p2.numberOfPieces = 3;

  // initialize via a pointer
  Player p3;
  Player *p3ptr = &p3;

  // "s->n" is a shortcut for "(*s).n"
  p3ptr->name = "Florian";
  p3ptr->numberOfPieces = 3;

  printPlayer(p1);
  printPlayer(p2);
  printPlayer(p3);

}
