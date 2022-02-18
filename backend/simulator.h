#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>

namespace backend {

class Simulator {
 public:
  Simulator();

  void searchMovie(std::string s);
  void searchTVShow(std::string s);
};

}  // namespace backend
#endif  // SIMULATOR_H
