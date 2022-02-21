#include "tvshowepisodesmodel.h"

gui::TVShowEpisodesModel::TVShowEpisodesModel(QObject *parent)
    : QAbstractListModel(parent) {}

std::vector<backend::TVShowEpisodes> gui::TVShowEpisodesModel::episodesList() {
  return episodes_list_;
}

void gui::TVShowEpisodesModel::setEpisodesList(
    std::vector<backend::TVShowEpisodes> list) {
  beginResetModel();
  episodes_list_ = list;
  endResetModel();
}

int gui::TVShowEpisodesModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid() || episodes_list_.empty()) {
    return 0;
  }
  return episodes_list_.size();
}

QVariant gui::TVShowEpisodesModel::data(const QModelIndex &index,
                                        int role) const {
  auto movie =
      std::make_unique<backend::TVShowEpisodes>(episodes_list_.at(index.row()));

  switch (role) {
    case idRole:
      return QVariant(QString::fromStdString(movie->id()));
  }

  return QVariant();
}

QHash<int, QByteArray> gui::TVShowEpisodesModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[idRole] = "id";
  return roles;
}
