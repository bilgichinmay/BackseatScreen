#ifndef TVSHOWSEASONDATA_H
#define TVSHOWSEASONDATA_H

#include <string>

namespace backend {

/**
 * @brief The TVShowSeasonData class
 *
 * Data Access Layer for TV Show seasons data
 */
class TVShowSeasonData {
 public:
  TVShowSeasonData(std::string id, std::string title,
                   std::string season_number);
  ~TVShowSeasonData() = default;

  void id(std::string id);
  std::string id();

  void title(std::string title);
  std::string title();

  void season(std::string number);
  std::string season();

 private:
  std::string id_;
  std::string title_;
  std::string season_number_;
};
}  // namespace backend
#endif  // TVSHOWSEASONDATA_H
