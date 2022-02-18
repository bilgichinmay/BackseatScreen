#ifndef GUIEVENTHANDLER_H
#define GUIEVENTHANDLER_H

#include <QObject>
#include <memory>

#include "backend/simulator.h"

namespace gui {

class GUIEventHandler : public QObject {
  Q_OBJECT
 public:
  explicit GUIEventHandler(QObject *parent = nullptr);

  Q_INVOKABLE void searchMovie(QString s);
  Q_INVOKABLE void searchTVShow(QString s);

 signals:

 private:
  std::shared_ptr<backend::Simulator> simulator_;
};

}  // namespace gui
#endif  // GUIEVENTHANDLER_H
