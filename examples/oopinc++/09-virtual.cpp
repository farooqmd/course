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

void informMe(Tile &tile)
{
  cout << "virtual it is a " << tile.virtualWhatAmI() << endl;
  cout << "but like this a " << tile.whatAmI() << endl;
}

/* two small classes that demonstrate that objects with
   virtual Functions carry more information.
   SimpleVirtual is larger in size than Simple with gcc. */
class Simple {
  int x;
};
class SimpleVirtual {
  int x;
  virtual void virtualFunction();
};

int main() {
  Tile tile;
  FloorTile floorTile;
  informMe(tile);
  informMe(floorTile);

  cout << "size of Simple: " << sizeof(Simple) << endl;
  cout << "size of SimpleVirtual" << sizeof(SimpleVirtual) << endl;

  return 0;
}
