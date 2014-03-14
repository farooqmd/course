#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include<random>

class World {
public:

  World(class Map *);
  ~World();

  const Map *map() const { return theMap; }
  Map *map() { return theMap; }

  void step();

  int startX() const { return theStartX; }
  int startY() const { return theStartY; }

  int nSpies() const { return theSpyXY.size()/2; }

  int spyX(int spy) const { return theSpyXY[2*spy]; }
  int spyY(int spy) const { return theSpyXY[2*spy + 1]; }

  int nInfos() const { return theInfoXY.size()/2; }

  int infoX(int info) const { return theInfoXY[2*info]; }
  int infoY(int info) const { return theInfoXY[2*info + 1]; }

private:
  int &mspyX(int spy) { return theSpyXY[2*spy]; }
  int &mspyY(int spy) { return theSpyXY[2*spy + 1]; }

  int &minfoX(int info) { return theInfoXY[2*info]; }
  int &minfoY(int info) { return theInfoXY[2*info + 1]; }

  void findLand(int &x, int &y);

  void placeStart();
  void placeSpy(int count);
  void placeSpies(int count);
  void placeInfo(int n);
  void placeInfos(int count);

  class Map *theMap;

  int theStartX, theStartY;
  std::vector<int> theSpyXY;
  std::vector<int> theInfoXY;

  std::default_random_engine rng;
};

#endif
