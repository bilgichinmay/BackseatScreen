#ifndef GUIEVENTHANDLER_H
#define GUIEVENTHANDLER_H

#include <json/json.h>

#include <QObject>
#include <iostream>
#include <memory>
#include <vector>

#include "backend/moviedata.h"
#include "backend/tmdbapicaller.h"
#include "backend/tvshowdata.h"
#include "backend/tvshowepisodes.h"
#include "backend/tvshowseasondata.h"
#include "gui.h"

namespace gui {

class GUIEventHandler : public QObject {
  Q_OBJECT
 public:
  explicit GUIEventHandler(QObject *parent = nullptr);

  Q_INVOKABLE void searchMovie(QString s);
  Q_INVOKABLE void searchTVShow(QString s);
  Q_INVOKABLE void getTVShowSeasons(QString id);
  Q_INVOKABLE void getEpisodesList(QString id, QString season);

  void parseJsonDataToTVShowList(std::string data);
  void parseJsonDataToTVShowSeasonList(std::string data);
  void parseJsonDataToTVShowEpisodesList(std::string data);
  void parseJsonDataToMovieList(std::string data);

  void clearData();

  Q_INVOKABLE std::vector<backend::MovieData> movies();
  Q_INVOKABLE void movies(std::vector<backend::MovieData> list);

  Q_INVOKABLE std::vector<backend::TVShowData> tvShows();
  Q_INVOKABLE void tvShows(std::vector<backend::TVShowData> list);

  Q_INVOKABLE std::vector<backend::TVShowSeasonData> seasons();
  Q_INVOKABLE void seasons(std::vector<backend::TVShowSeasonData> list);

  Q_INVOKABLE std::vector<backend::TVShowEpisodes> episodes();
  Q_INVOKABLE void episodes(std::vector<backend::TVShowEpisodes> list);

 signals:
  void moviesChanged();
  void tvShowsChanged();
  void seasonsChanged();
  void episodesChanged();

 private:
  std::shared_ptr<backend::TMDBApiCaller> tmdb_api_;

  std::vector<backend::TVShowData> tv_show_list_;
  std::vector<backend::TVShowSeasonData> tv_show_season_list_;
  std::vector<backend::TVShowEpisodes> tv_show_episodes_list_;
  std::vector<backend::MovieData> movie_list_;
};

}  // namespace gui
#endif  // GUIEVENTHANDLER_H
