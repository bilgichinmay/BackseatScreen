#include "tvshowlist.h"

gui::TVShowListModel::TVShowListModel(QObject *parent)
    : QAbstractListModel(parent) {}

std::vector<backend::TVShowData> gui::TVShowListModel::tvshows() {
  return tv_shows_list_;
}

void gui::TVShowListModel::setTVShows(std::vector<backend::TVShowData> list) {
  beginResetModel();
  tv_shows_list_ = list;
  endResetModel();
}

int gui::TVShowListModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid() || tv_shows_list_.empty()) {
    return 0;
  }
  return tv_shows_list_.size();
}

QVariant gui::TVShowListModel::data(const QModelIndex &index, int role) const {
  auto tv_show =
      std::make_unique<backend::TVShowData>(tv_shows_list_.at(index.row()));

  switch (role) {
    case idRole:
      return QVariant(QString::fromStdString(tv_show->id()));
    case titleRole:
      return QVariant(QString::fromStdString(tv_show->title()));
  }

  return QVariant();
}

QHash<int, QByteArray> gui::TVShowListModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[idRole] = "id";
  roles[titleRole] = "title";
  return roles;
}
