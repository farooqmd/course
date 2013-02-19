#include <iostream>
#include <vector>
using namespace std;

class Board {
  int x;
};

class Player {
  int x, y;
};

class Game {
public:
  Board* board;
  vector< Player* > players;

  // this also is the default constructor, with 2 players
  Game(int numPlayers = 2) {
    board = new Board;
    for (int i = 0; i < numPlayers; ++i)
      players.push_back(new Player);
  }
  // destructor, deallocate everything
  ~Game() {
    for (auto player: players) delete player;
    cout << "deleting" << board << endl;
    delete board;
  }
  
  // disallow the copy constructor
private:
  Game(const Game &);
};

/* Here, we need the reference, as Game cannot be copied.
   Forgetting the "&" will raise an error, caused by disallowing
   the copy constructor. */
void print(Game &game) {
  cout << game.board << endl;
}

int main()
{
  Game game;
  print(game);

  return 0;
}
