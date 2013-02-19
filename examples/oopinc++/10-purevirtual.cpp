#include <iostream>
using namespace std;

class Tile {
public:
  // this make "Tile" abstract
  virtual string whatAmI() = 0;
};

class FloorTile: public Tile {
public:
  // but FloorTile is not abstract:
  virtual string whatAmI() { return "floor tile"; }
};

void informMe(Tile &tile)
{
  cout << "this is a " << tile.whatAmI() << endl;
}

int main() {
  // not possible, tile is abstract
  Tile tile;
  // but that is ok
  FloorTile floorTile;
  // works as intended
  informMe(floorTile);
}
