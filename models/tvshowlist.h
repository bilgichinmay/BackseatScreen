#ifndef TVSHOWLIST_H
#define TVSHOWLIST_H

#include <QAbstractListModel>
#include <iostream>
#include <memory>
#include <vector>

#include "backend/tvshowdata.h"

namespace gui {

class TVShowListModel : public QAbstractListModel {
  Q_OBJECT

  Q_PROPERTY(
      std::vector<backend::TVShowData> tvshows READ tvshows WRITE setTVShows)
 public:
  explicit TVShowListModel(QObject *parent = nullptr);

  enum { idRole = Qt::UserRole, titleRole };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  std::vector<backend::TVShowData> tvshows();
  void setTVShows(std::vector<backend::TVShowData> list);

 private:
  std::vector<backend::TVShowData> tv_shows_list_;
};
}  // namespace gui
#endif  // TVSHOWLIST_H
