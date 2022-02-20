#include "tvshowseasondata.h"

backend::TVShowSeasonData::TVShowSeasonData(std::string id, std::string title)
    : id_(id), title_(title) {}

void backend::TVShowSeasonData::id(std::string id) { id_ = id; }

std::string backend::TVShowSeasonData::id() { return id_; }

void backend::TVShowSeasonData::title(std::string title) { title_ = title; }

std::string backend::TVShowSeasonData::title() { return title_; }
