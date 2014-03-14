#include "WorldView.hpp"
#include "../world/World.hpp"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <stdexcept>


WorldView::WorldView(World *_world, QImage *worldmap, QWidget *_widget):
  QGraphicsView(_widget), world(_world), hq(0)
{
  scene = new QGraphicsScene();

  background = scene->addPixmap(QPixmap::fromImage(*worldmap));
  background->setPos(0, 0);
  background->setZValue(-1);

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setScene(scene);
}

void WorldView::resizeEvent(class QResizeEvent *)
{
  fitInView(scene->sceneRect());
  show();  
}

void WorldView::setHQ(int x, int y)
{
  if (!hq) {
    hq = addItem(4, 40);
  }
  hq->setPos(x, y);
}

void WorldView::setSpy(int n, int x, int y)
{
  if (spies.find(n) == spies.end()) {
    spies.insert({{n, addItem(1, 320)}});
  }
  spies[n]->setPos(x, y);
}

void WorldView::setInfoPack(int n, int x, int y)
{
  if (infos.find(n) == infos.end()) {
    infos.insert({{n, addItem(1, 150)}});
  }
  infos[n]->setPos(x, y);
}

QGraphicsItem *WorldView::addItem(int radius, int hue)
{ 
  QColor color; color.setHsv(hue, 255, 255);
  return scene->addEllipse(0, 0, radius, radius, color, color);
}

void WorldView::redraw()
{
  setHQ(world->startX(), world->startY());
  for(int spy = 0; spy < world->nSpies(); ++spy) {
    setSpy(spy, world->spyX(spy), world->spyY(spy));
  }
  for(int info = 0; info < world->nInfos(); ++info) {
    setInfoPack(info, world->infoX(info), world->infoY(info));
  }
  show();
}
