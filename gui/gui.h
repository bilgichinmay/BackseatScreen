#ifndef GUI_H
#define GUI_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <memory>

#include "interfaces/IGUI.h"

namespace gui {

class GUI : public QObject, virtual public gui::IGUI {
  Q_OBJECT
 public:
  explicit GUI(QObject *parent = nullptr);
  ~GUI() = default;

  void init(const int &argc, char *argv[]) override;
  void exit() override;
  void execute() override;
  void update() override;

 signals:

 private:
  std::unique_ptr<QGuiApplication> app_;
  std::unique_ptr<QQmlApplicationEngine> app_engine_;
};
}  // namespace gui
#endif  // GUI_H
