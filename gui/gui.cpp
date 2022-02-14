#include "gui.h"

namespace gui {

/**
 * @brief Constructor
 *
 * @param parent
 */
GUI::GUI(QObject* parent) : QObject(parent) {}

/**
 * @brief GUI::init
 * @param argc
 * @param argv
 */
void GUI::init(const int& argc, char* argv[]) {
  app_ = std::make_unique<QGuiApplication>((int&)argc, argv);
  app_engine_ = std::make_unique<QQmlApplicationEngine>();
  app_engine_->load(QUrl(QStringLiteral("qrc:/gui/main.qml")));
}

/**
 * @brief GUI::execute
 */
void GUI::execute() { app_->exec(); }

/**
 * @brief GUI::exit
 */
void GUI::exit() { app_->exit(); }

/**
 * @brief GUI::update
 */
void GUI::update() {}

}  // namespace gui
