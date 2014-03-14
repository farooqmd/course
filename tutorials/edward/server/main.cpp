#include "MainWindow.hpp"
#include "../world/Map.hpp"
#include "../world/World.hpp"

#include <QApplication>
#include <QImage>
#include <QStringList>

#include <iostream>
#include <stdexcept>

using namespace std;

static Map *convertImageToMap(const QImage &worldmap) {
  auto map = new Map(worldmap.width(), worldmap.height());
  for (int x = 0; x < worldmap.width(); ++x)
    for (int y = 0; y < worldmap.height(); ++y) {
      QColor pixel = worldmap.pixel(x, y);
      // check for approximate blue
      if (pixel.hue() > 180 && pixel.hue() < 240) {
        map->makeWater(x, y);
      }
      else {
        map->makeLand(x, y);
      }
    }
  return map;
}

int main(int argc, char *argv[])
{
  try {
    QApplication a(argc, argv);
    QStringList args = a.arguments();
    if (args.length() != 3) {
      throw runtime_error("usage: Server <world bitmap> <step duration>");
    }
    QImage worldmap = QImage(args[1]);
    World *world = new World(convertImageToMap(worldmap));

    int timeout(args[2].toInt());
    
    MainWindow w(world, &worldmap, timeout);
    w.show();
  
    return a.exec();
  }
  catch(exception &e) {
    cerr << "caught exception: " << e.what() << endl;
    return -1;
  }
}
