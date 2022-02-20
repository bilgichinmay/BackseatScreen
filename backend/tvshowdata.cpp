#include "tvshowdata.h"

backend::TVShowData::TVShowData(std::string id, std::string title)
    : id_(id), title_(title) {}

void backend::TVShowData::id(std::string id) { id_ = id; }

std::string backend::TVShowData::id() { return id_; }

void backend::TVShowData::title(std::string title) { title_ = title; }

std::string backend::TVShowData::title() { return title_; }
