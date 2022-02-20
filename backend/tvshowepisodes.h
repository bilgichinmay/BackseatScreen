#ifndef TVSHOWEPISODES_H
#define TVSHOWEPISODES_H

#include <string>

namespace backend {
class TVShowEpisodes {
 public:
  TVShowEpisodes(std::string id);
  ~TVShowEpisodes() = default;

  void id(std::string id);
  std::string id();

 private:
  std::string id_;
};
}  // namespace backend
#endif  // TVSHOWEPISODES_H
