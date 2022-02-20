#include "moviedata.h"

backend::MovieData::MovieData(std::string id, std::string title)
    : id_(id), title_(title) {}

void backend::MovieData::id(std::string id) { id_ = id; }

std::string backend::MovieData::id() { return id_; }

void backend::MovieData::title(std::string title) { title_ = title; }

std::string backend::MovieData::title() { return title_; }
