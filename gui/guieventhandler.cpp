#include "guieventhandler.h"

gui::GUIEventHandler::GUIEventHandler(QObject *parent) : QObject(parent) {
  clearData();
  tmdb_api_ = std::make_shared<backend::TMDBApiCaller>();
}

void gui::GUIEventHandler::searchMovie(QString s) {
  auto str = s.toStdString();

  // replace whitespaces with '+' sign.
  for (int i = 0; i < (int)str.length(); i++) {
    if (str[i] == ' ') str[i] = '+';
  }

  // get movies list based on given keywords
  std::string res = tmdb_api_->searchMovie(str);
  std::cout << res << std::endl;

  // parse json and fill data
  parseJsonDataToMovieList(res);
}

void gui::GUIEventHandler::searchTVShow(QString s) {
  auto str = s.toStdString();

  // replace whitespaces with '+' sign.
  for (int i = 0; i < (int)str.length(); i++) {
    if (str[i] == ' ') str[i] = '+';
  }

  // get tv shows list based on given keywords
  std::string res = tmdb_api_->searchTVShow(str);
  std::cout << res << std::endl;

  // parse json and fill data
  parseJsonDataToTVShowList(res);
}

void gui::GUIEventHandler::getTVShowSeasons(QString id) {
  auto tv_show_id = id.toStdString();

  // get tv show seasons
  std::string res = tmdb_api_->getTVShowSeasons(tv_show_id);
  std::cout << res << std::endl;

  // parse json and fill data
  parseJsonDataToTVShowSeasonList(res);
}

void gui::GUIEventHandler::getEpisodesList(QString id, QString season) {
  auto tv_show_id = id.toStdString();
  auto tv_show_season = season.toStdString();

  // get episodes for given TV show for given season
  std::string res = tmdb_api_->getEpisodesList(tv_show_id, tv_show_season);
  std::cout << res << std::endl;

  // parse json and fill data
  parseJsonDataToTVShowEpisodesList(res);
}

void gui::GUIEventHandler::parseJsonDataToTVShowList(std::string data) {
  clearData();

  Json::Value jsonData;
  Json::Reader jsonReader;

  if (jsonReader.parse(data, jsonData)) {
    Json::Value results;

    if (jsonReader.parse(jsonData["results"].toStyledString(), results)) {
      int number_of_results = jsonData["total_results"].asInt();

      for (int i = 0; i < number_of_results; i++) {
        std::cout << "ID: " << results[i]["id"].asString() << std::endl;
        backend::TVShowData tv_show(results[i]["id"].asString(),
                                    results[i]["name"].asString());
        tv_show_list_.push_back(tv_show);
      }

      std::cout << "Number of results: " << number_of_results << std::endl;
    } else {
      std::cout << "ERROR RETRIEVING RESULTS FROM JSON" << std::endl;
    }
  } else {
    std::cout << "ERROR PARSING JSON" << std::endl;
  }
}

void gui::GUIEventHandler::parseJsonDataToMovieList(std::string data) {
  clearData();

  Json::Value jsonData;
  Json::Reader jsonReader;

  if (jsonReader.parse(data, jsonData)) {
    Json::Value results;

    if (jsonReader.parse(jsonData["results"].toStyledString(), results)) {
      int number_of_results = jsonData["total_results"].asInt();

      for (int i = 0; i < number_of_results; i++) {
        std::cout << "ID: " << results[i]["id"].asString() << std::endl;
        backend::MovieData movie(results[i]["id"].asString(),
                                 results[i]["original_title"].asString());
        movie_list_.push_back(movie);
      }
      std::cout << "Number of results: " << number_of_results << std::endl;
    } else {
      std::cout << "ERROR RETRIEVING RESULTS FROM JSON" << std::endl;
    }
  } else {
    std::cout << "ERROR PARSING JSON" << std::endl;
  }
}

void gui::GUIEventHandler::parseJsonDataToTVShowSeasonList(std::string data) {
  clearData();

  Json::Value jsonData;
  Json::Reader jsonReader;

  if (jsonReader.parse(data, jsonData)) {
    Json::Value seasons;

    if (jsonReader.parse(jsonData["seasons"].toStyledString(), seasons)) {
      int number_of_seasons = jsonData["seasons"].size();

      for (int i = 0; i < number_of_seasons; i++) {
        std::cout << "ID: " << seasons[i]["id"].asString() << std::endl;
        backend::TVShowSeasonData season(seasons[i]["id"].asString(),
                                         seasons[i]["name"].asString());
        tv_show_season_list_.push_back(season);
      }
      std::cout << "Number of seasons: " << number_of_seasons << std::endl;
    } else {
      std::cout << "ERROR RETRIEVING RESULTS FROM JSON" << std::endl;
    }
  } else {
    std::cout << "ERROR PARSING JSON" << std::endl;
  }
}

void gui::GUIEventHandler::parseJsonDataToTVShowEpisodesList(std::string data) {
  clearData();

  Json::Value jsonData;
  Json::Reader jsonReader;

  if (jsonReader.parse(data, jsonData)) {
    Json::Value episodes;

    if (jsonReader.parse(jsonData["episodes"].toStyledString(), episodes)) {
      int number_of_episodes = jsonData["episodes"].size();

      for (int i = 0; i < number_of_episodes; i++) {
        std::cout << "ID: " << episodes[i]["id"].asString() << std::endl;
        backend::TVShowEpisodes episode(episodes[i]["id"].asString());
        tv_show_episodes_list_.push_back(episode);
      }
      std::cout << "Number of episodes: " << number_of_episodes << std::endl;
    } else {
      std::cout << "ERROR RETRIEVING RESULTS FROM JSON" << std::endl;
    }
  } else {
    std::cout << "ERROR PARSING JSON" << std::endl;
  }
}

void gui::GUIEventHandler::clearData() {
  tv_show_list_.clear();
  tv_show_season_list_.clear();
  tv_show_episodes_list_.clear();
  movie_list_.clear();
}
