#include <vector>
using namespace std;

/* Absolutely necessary here.
   Either like this... */
class Player;

class Piece {
  int x, y;
  Player *player;
};

class Player {
  int playerNum;
  vector< Piece* > pieces;
};

/* ... or like this */
class AnotherPiece;

class AnotherPlayer {
  int playerNum;
  vector< AnotherPiece* > pieces;
};

class AnotherPiece {
  int x, y;
  AnotherPlayer *player;
};

int main()
{
  Player player;

  AnotherPlayer anotherPlayer;
}


