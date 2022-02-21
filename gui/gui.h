#ifndef GUI_H
#define GUI_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariant>
#include <memory>
#include <vector>

#include "backend/moviedata.h"
#include "backend/tvshowdata.h"
#include "backend/tvshowepisodes.h"
#include "backend/tvshowseasondata.h"
#include "interfaces/IGUI.h"

namespace gui {

/**
 * @brief The GUI class
 *
 * Creates and manages GUI
 */
class GUI : public QObject, virtual public gui::IGUI {
  Q_OBJECT
 public:
  explicit GUI(QObject *parent = nullptr);
  ~GUI() = default;

  void init(const int &argc, char *argv[]) override;
  void exit() override;
  void execute() override;

 signals:

 private:
  std::unique_ptr<QGuiApplication> app_;
  std::unique_ptr<QQmlApplicationEngine> app_engine_;
};
}  // namespace gui

Q_DECLARE_METATYPE(std::vector<backend::MovieData>)
Q_DECLARE_METATYPE(std::vector<backend::TVShowData>)
Q_DECLARE_METATYPE(std::vector<backend::TVShowSeasonData>)
Q_DECLARE_METATYPE(std::vector<backend::TVShowEpisodes>)
#endif  // GUI_H
