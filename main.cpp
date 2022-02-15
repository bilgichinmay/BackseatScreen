#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "gui/gui.h"

int main(int argc, char* argv[]) {
  gui::GUI rare_seat_entertainer;

  rare_seat_entertainer.init(argc, argv);
  rare_seat_entertainer.execute();
  // rare_seat_entertainer.exit();
}
