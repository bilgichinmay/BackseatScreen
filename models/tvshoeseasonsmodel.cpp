#include "tvshoeseasonsmodel.h"

gui::TVShoeSeasonsModel::TVShoeSeasonsModel(QObject *parent)
    : QAbstractListModel(parent) {}

std::vector<backend::TVShowSeasonData> gui::TVShoeSeasonsModel::seasonsList() {
  return seasons_list_;
}

void gui::TVShoeSeasonsModel::setSeasonsList(
    std::vector<backend::TVShowSeasonData> list) {
  beginResetModel();
  seasons_list_ = list;
  endResetModel();
}

int gui::TVShoeSeasonsModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid() || seasons_list_.empty()) {
    return 0;
  }
  return seasons_list_.size();
}

QVariant gui::TVShoeSeasonsModel::data(const QModelIndex &index,
                                       int role) const {
  auto season = std::make_unique<backend::TVShowSeasonData>(
      seasons_list_.at(index.row()));

  switch (role) {
    case idRole:
      return QVariant(QString::fromStdString(season->id()));
    case titleRole:
      return QVariant(QString::fromStdString(season->title()));
    case seasonNumberRole:
      return QVariant(QString::fromStdString(season->season()));
  }

  return QVariant();
}

QHash<int, QByteArray> gui::TVShoeSeasonsModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[idRole] = "id";
  roles[titleRole] = "title";
  roles[seasonNumberRole] = "season";
  return roles;
}
