#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include <QtGui/QGraphicsView>
#include <unordered_map>

class WorldView: public QGraphicsView
{
public:
  WorldView(class World *, class QImage *, class QWidget *);

  void resizeEvent(class QResizeEvent * = 0);

  void redraw();

private:
  void setHQ(int x, int y);
  void setSpy(int n, int x, int y);
  void setInfoPack(int n, int x, int y);
  class QGraphicsItem *addItem(int radius, int hue);

  class QGraphicsScene *scene;
  class QGraphicsPixmapItem  *background;

  class World *world;

  class QGraphicsItem *hq;
  std::unordered_map<int, class QGraphicsItem *> spies;
  std::unordered_map<int, class QGraphicsItem *> infos;
};

#endif
