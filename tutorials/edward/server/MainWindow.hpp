#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

class MainWindow: public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(class World *, class QImage *, int timeout = 100);
  ~MainWindow();

private slots:
  void startstop();
  void step();

private:
  class QWidget     *canvas;
  class WorldView   *view;
  class QPushButton *startstop_button;
  class QTextEdit   *messages;

  class QTimer      *timer;

  class World *world;
  
  bool simRunning;
  int  timeout;
};

#endif
