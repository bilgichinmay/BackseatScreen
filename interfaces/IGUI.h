#ifndef INTERFACES_IGUI_H
#define INTERFACES_IGUI_H

namespace gui {
class IGUI {
 public:
  virtual ~IGUI() = default;

  /**
   * @brief init
   * @param argc
   * @param argv
   */
  virtual void init(const int& argc, char* argv[]) = 0;

  /**
   * @brief execute
   *
   * Starts GUI execution.
   */
  virtual void execute() = 0;

  /**
   * @brief exit
   *
   * Finishes GUI execution.
   */
  virtual void exit() = 0;

  /**
   * @brief update
   *
   * Updates GUI whenever data from backend is changed/ updated.
   */
  virtual void update() = 0;
};
}  // namespace gui

#endif  // INTERFACES_IGUI_H
