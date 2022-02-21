#include "tvshowepisodes.h"

backend::TVShowEpisodes::TVShowEpisodes(std::string id, std::string title)
    : id_(id), title_(title) {}

void backend::TVShowEpisodes::id(std::string id) { id_ = id; }

std::string backend::TVShowEpisodes::id() { return id_; }

void backend::TVShowEpisodes::title(std::string title) { title_ = title; }

std::string backend::TVShowEpisodes::title() { return title_; }
