CONFIG = qt debug

QT       += core gui

TARGET = Server
TEMPLATE = app

SOURCES += \
  main.cpp \
  MainWindow.cpp \
  ../world/World.cpp \
  ../world/Map.cpp \
  ../gui/WorldView.cpp \

HEADERS += \
  MainWindow.hpp \
  ../world/World.hpp \
  ../world/Map.hpp \
  ../gui/WorldView.hpp

QMAKE_CXXFLAGS_RELEASE = -O3 
QMAKE_LFLAGS_RELEASE = -O3
QMAKE_CXXFLAGS_DEBUG = -O0 -g
QMAKE_LFLAGS_DEBUG = -O0 -g

QMAKE_CXXFLAGS += -Wall -std=c++0x

macx {
  CONFIG -= app_bundle
  contains(QMAKE_CXX, /usr/bin/clang++) {
    message(Using LLVM libc++)
    QMAKE_CXXFLAGS += -stdlib=libc++ -Wno-deprecated-register
    QMAKE_LFLAGS += -lc++
  }
}





