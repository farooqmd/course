#include <iostream>
using namespace std;

class Tile {
  // make the class polymorphic
  virtual void makeMePolymorph() {};
};

class WallTile: public Tile {
  string info;
public:
  WallTile(string i): info(i) {}
  const string &getData() const { return info; }
};

int main()
{
  Tile *tile = new Tile;
  WallTile *wall = new WallTile("Information");

  // ok, we cast down
  Tile *tilePtr = dynamic_cast<Tile *>(wall);
  cout << "wall " << wall << " casts to tile " << tilePtr << endl;

  /* bad, casting up
     dynamic_cast is ok, we get a 0-pointer that we can check for.
     static_cast just does nothing!
  */
  WallTile *wallPtr = dynamic_cast<WallTile *>(tile);
  cout << "tile " << tile << " casts to tile " << wallPtr << endl;
  if (wallPtr) {
    cout << "happily reading out" << wallPtr->getData() << endl;
  }
  else {
    cout << "refusing to dereference null pointer" << endl;
  }
  delete tile;
  delete wall;
}
