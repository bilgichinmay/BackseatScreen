#include "tvshowseasondata.h"

backend::TVShowSeasonData::TVShowSeasonData(std::string id, std::string title,
                                            std::string season_number)
    : id_(id), title_(title), season_number_(season_number) {}

void backend::TVShowSeasonData::id(std::string id) { id_ = id; }

std::string backend::TVShowSeasonData::id() { return id_; }

void backend::TVShowSeasonData::title(std::string title) { title_ = title; }

std::string backend::TVShowSeasonData::title() { return title_; }

void backend::TVShowSeasonData::season(std::string number) {
  season_number_ = number;
}

std::string backend::TVShowSeasonData::season() { return season_number_; }
