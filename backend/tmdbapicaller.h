#ifndef TMDBAPICALLER_H
#define TMDBAPICALLER_H

#include <curl/curl.h>

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

namespace backend {

class TMDBApiCaller {
 public:
  TMDBApiCaller();

  std::string searchMovie(std::string s);
  std::string searchTVShow(std::string s);

  std::string getUrl(std::string url);

 private:
};

}  // namespace backend
#endif  // TMDBAPICALLER_H
