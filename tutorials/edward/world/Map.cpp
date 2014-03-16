#include "Map.hpp"

Map::Map(int _w, int _h)
  : theWidth(_w), theHeight(_h), land(_w*_h)
{
  land.clear();
}

int Map::map(int x, int y) const
{
  while (x < 0) { x += width();  }; x = x % width();
  while (y < 0) { y += height(); }; y = y % height();
  return width()*(y % height()) + (x % width());
}
