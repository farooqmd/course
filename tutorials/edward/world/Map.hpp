#ifndef MAP_H
#define MAP_H
#include<vector>

class Map {
  int theWidth, theHeight;
  std::vector<bool> land;
public:
  Map(int width, int height);

  int width() const { return theWidth; }
  int height() const { return theHeight; }

  bool isLand(int x, int y) const { return land[map(x, y)]; }
  bool isWater(int x, int y) const { return !isLand(x, y); }

  void makeLand(int x, int y) { land[map(x, y)] = true; }
  void makeWater(int x, int y) { land[map(x, y)] = false; }

  int foldX(int x) const;

private:
  int map(int x, int y) const;
};

#endif
