#ifndef TVSHOWSEASONDATA_H
#define TVSHOWSEASONDATA_H

#include <string>

namespace backend {
class TVShowSeasonData {
 public:
  TVShowSeasonData(std::string id, std::string title);
  ~TVShowSeasonData() = default;

  void id(std::string id);
  std::string id();

  void title(std::string title);
  std::string title();

 private:
  std::string id_;
  std::string title_;
};
}  // namespace backend
#endif  // TVSHOWSEASONDATA_H
