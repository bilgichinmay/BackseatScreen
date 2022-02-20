#ifndef MOVIEDATA_H
#define MOVIEDATA_H

#include <string>

namespace backend {
class MovieData {
 public:
  MovieData(std::string id, std::string title);
  ~MovieData() = default;

  void id(std::string id);
  std::string id();

  void title(std::string title);
  std::string title();

 private:
  std::string id_;
  std::string title_;
};
}  // namespace backend

#endif  // MOVIEDATA_H
