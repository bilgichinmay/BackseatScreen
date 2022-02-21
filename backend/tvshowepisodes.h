#ifndef TVSHOWEPISODES_H
#define TVSHOWEPISODES_H

#include <string>

namespace backend {

/**
 * @brief The TVShowEpisodes class
 *
 * Data Access Layer for TV Show Episodes data
 */
class TVShowEpisodes {
 public:
  TVShowEpisodes(std::string id, std::string title);
  ~TVShowEpisodes() = default;

  void id(std::string id);
  std::string id();

  void title(std::string title);
  std::string title();

 private:
  std::string id_;
  std::string title_;
};
}  // namespace backend
#endif  // TVSHOWEPISODES_H
