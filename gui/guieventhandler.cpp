#include "guieventhandler.h"

gui::GUIEventHandler::GUIEventHandler(QObject *parent) : QObject(parent) {}

void gui::GUIEventHandler::searchMovie(QString s) {
  auto str = s.toStdString();

  // replace rest of the whitespaces with '+' sign.
  for (int i = 0; i < (int)str.length(); i++) {
    if (str[i] == ' ') str[i] = '+';
  }
  simulator_->searchMovie(str);
}

void gui::GUIEventHandler::searchTVShow(QString s) {
  auto str = s.toStdString();

  // replace rest of the whitespaces with '+' sign.
  for (int i = 0; i < (int)str.length(); i++) {
    if (str[i] == ' ') str[i] = '+';
  }
  simulator_->searchTVShow(str);
}
