#include "movielistmodel.h"

gui::MovieListModel::MovieListModel(QObject *parent)
    : QAbstractListModel(parent) {}

std::vector<backend::MovieData> gui::MovieListModel::movieList() {
  return movie_list_;
}

void gui::MovieListModel::setMovieList(std::vector<backend::MovieData> list) {
  beginResetModel();
  movie_list_ = list;
  endResetModel();
}

int gui::MovieListModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid() || movie_list_.empty()) {
    return 0;
  }
  return movie_list_.size();
}

QVariant gui::MovieListModel::data(const QModelIndex &index, int role) const {
  auto movie =
      std::make_unique<backend::MovieData>(movie_list_.at(index.row()));

  switch (role) {
    case idRole:
      return QVariant(QString::fromStdString(movie->id()));
    case titleRole:
      return QVariant(QString::fromStdString(movie->title()));
  }

  return QVariant();
}

QHash<int, QByteArray> gui::MovieListModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[idRole] = "id";
  roles[titleRole] = "title";
  return roles;
}
