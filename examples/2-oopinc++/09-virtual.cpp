#include <iostream>
using namespace std;

/* virtualWhatAmI implements a simple form of runtime type information.
   Without the keyword "virtual", this doesn't work. whatAmI gives the same
   answer for any class cast to a Tile.
*/

class Tile {
public:
  string whatAmI() { return "tile"; }
  virtual string virtualWhatAmI() { return whatAmI(); }
};

class FloorTile: public Tile {
public:
  string whatAmI() { return "floor tile"; }
  virtual string virtualWhatAmI() { return whatAmI(); }
};

class WallTile: public FloorTile {
public:
  string whatAmI() { return "wall tile"; }
  virtual string virtualWhatAmI() { return whatAmI(); }
};

void informMe(Tile &tile)
{
  cout << "virtual it is a " << tile.virtualWhatAmI() << endl;
  cout << "but like this a " << tile.whatAmI() << endl;
}

int main() {
  Tile tile;
  FloorTile floorTile;
  WallTile wallTile;

  informMe(tile);
  informMe(floorTile);
  informMe(wallTile);

  return 0;
}
