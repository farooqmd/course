#include <string>

#include "MainWindow.hpp"

#include "../gui/WorldView.hpp"
#include "../world/World.hpp"
#include "../world/Map.hpp"

#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QGridLayout>
#include <QBitmap>
#include <QTimer>

MainWindow::MainWindow(World *_world, QImage *worldmap, int _timeout)
  : QMainWindow(), world(_world), simRunning(0), timeout(_timeout)
{
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(step()));

  canvas = new QWidget(this);
  setCentralWidget(canvas);
  
  view = new WorldView(world, worldmap, this);

  startstop_button = new QPushButton("Start", canvas);
  connect(startstop_button, SIGNAL(clicked()), this, SLOT(startstop()));

  messages = new QTextEdit(canvas);
  messages->setReadOnly(true);
  messages->append("Mock Edward server starting up...");

  QGridLayout *layout = new QGridLayout(canvas);
  layout->addWidget(view, 0, 0, 1, 2);
  layout->addWidget(messages, 1, 0);
  layout->addWidget(startstop_button, 1, 1);

  layout->setRowStretch(0, 1);
  layout->setColumnStretch(0, 1);
}

MainWindow::~MainWindow()
{
  delete messages;
  delete startstop_button;
  delete view;
  delete canvas;

  delete timer;

  delete world;
}

void MainWindow::startstop()
{
  if (simRunning) {
    timer->stop();
    simRunning = 0;
    startstop_button->setText("Start");
  }
  else {
    startstop_button->setText("Stop");
    simRunning = 1;
    step();
    timer->start(timeout);
  }
}

void MainWindow::step()
{
  world->step();
  view->redraw();
}
