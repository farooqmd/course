#include <iostream>
using namespace std;

class Tile {
  string message;
public:
  Tile(const char *msg = "");
  ~Tile();
};

Tile::Tile(const char *msg)
{
  message = msg;
  cout << "creating a tile " << message << endl;
}
Tile::~Tile()
{
  cout << "loosing a tile with message " << message << endl;
}

class WallTile: public Tile {
public:
  WallTile();
  WallTile(const char *msg);
  ~WallTile() { cout << "loosing a wall tile" << endl; }
};

/*
  Default constructor, using default constructor of Tile().
  Doesn't need to be mentioned here, therefore.
 */
WallTile::WallTile()
{
  cout << "creating a default wall tile" << endl;
}

/*
  Alternative constructor with message, that is passed to the Tile.
  Here, we use the Tile(const char *) constructor. */
WallTile::WallTile(const char *msg): Tile(msg)
{
  cout << "creating a wall tile with message " << msg << endl;
}

int main()
{
  WallTile tile;
  WallTile tile2("marked");

  return 0;
}
