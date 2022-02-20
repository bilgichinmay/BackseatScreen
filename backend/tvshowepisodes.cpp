#include "tvshowepisodes.h"

backend::TVShowEpisodes::TVShowEpisodes(std::string id) : id_(id) {}

void backend::TVShowEpisodes::id(std::string id) { id_ = id; }

std::string backend::TVShowEpisodes::id() { return id_; }
