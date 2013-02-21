#include <iostream>
using namespace std;

class Tile {
public:
  Tile(const char *msg = "") { cout << "creating a tile " << msg << endl; }
  ~Tile() { cout << "loosing a tile" << endl; }
};

class WallTile: public Tile {
public:
  WallTile() { cout << "creating a wall tile" << endl; }  
  WallTile(const char *msg): Tile(msg) { cout << "creating a wall tile " << msg << endl; }  
  WallTile(const char *msg, int): Tile("nothing") { cout << "creating a wall tile " << msg << endl; }  
  ~WallTile() { cout << "loosing a wall tile" << endl; }
};

int main()
{
  WallTile tile;
  WallTile tile2("marked");
  WallTile tile3("other mark", 42);

  return 0;
}
