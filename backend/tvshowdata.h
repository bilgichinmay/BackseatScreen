#ifndef TVSHOWDATA_H
#define TVSHOWDATA_H

#include <string>
#include <vector>

namespace backend {
class TVShowData {
 public:
  TVShowData(std::string id, std::string title);
  ~TVShowData() = default;

  void id(std::string id);
  std::string id();

  void title(std::string title);
  std::string title();

 private:
  std::string id_;
  std::string title_;
};
}  // namespace backend
#endif  // TVSHOWDATA_H
