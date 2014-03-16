#include "World.hpp"
#include "Map.hpp"
#include<random>
#include<algorithm>

World::World(Map *_map)
  : theMap(_map)
{
  placeStart();
  placeSpies(10);
  placeInfos(1000);
}

World::~World()
{
  delete theMap;
}

void World::findLand(int &x, int &y)
{
  do {
    x = std::uniform_int_distribution<int>(0, map()->width())(rng);
    y = std::uniform_int_distribution<int>(0, map()->height())(rng);
  } while (!map()->isLand(x, y));
}

void World::placeStart()
{
  findLand(theStartX, theStartY);
}

void World::placeSpy(int n)
{
  mspyX(n) = startX();
  mspyY(n) = startY();
}

void World::placeSpies(int count)
{
  theSpyXY.resize(2*count);
  for (int i = 0; i < count; ++i) {
    placeSpy(i);
  }
}

void World::placeInfo(int n)
{
  findLand(minfoX(n), minfoY(n));
}

void World::placeInfos(int count)
{
  theInfoXY.resize(2*count);
  for (int i = 0; i < count; ++i) {
    placeInfo(i);
  }
}

void World::step()
{
  auto spy = std::uniform_int_distribution<int>(0, nSpies() - 1)(rng);
  
  // try a number of times, but stop eventually, if there is just water around...
  int cnt = 0;
  int newX, newY;
  do {
    auto distx = std::uniform_int_distribution<int>(-1, 1)(rng);
    auto disty = std::uniform_int_distribution<int>(-1, 1)(rng);

    newX = spyX(spy) + distx;
    newY = spyY(spy) + disty;
    ++cnt;
  } while (map()->isWater(newX, newY) && cnt < 10);
  mspyX(spy) = newX;
  mspyY(spy) = newY;

  // replace found information
  for(int i = 0; i < nInfos(); ++i) {
    if (newX == infoX(i) && newY == infoY(i)) {
      placeInfo(i);
    }
  }
}
