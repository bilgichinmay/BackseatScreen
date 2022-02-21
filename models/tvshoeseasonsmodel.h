#ifndef TVSHOESEASONSMODEL_H
#define TVSHOESEASONSMODEL_H

#include <QAbstractListModel>
#include <iostream>
#include <memory>
#include <vector>

#include "backend/tvshowseasondata.h"

namespace gui {

class TVShoeSeasonsModel : public QAbstractListModel {
  Q_OBJECT

  Q_PROPERTY(std::vector<backend::TVShowSeasonData> seasons READ seasonsList
                 WRITE setSeasonsList)
 public:
  explicit TVShoeSeasonsModel(QObject *parent = nullptr);

  enum { idRole = Qt::UserRole, titleRole };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  std::vector<backend::TVShowSeasonData> seasonsList();
  void setSeasonsList(std::vector<backend::TVShowSeasonData> list);

 private:
  std::vector<backend::TVShowSeasonData> seasons_list_;
};
}  // namespace gui
#endif  // TVSHOESEASONSMODEL_H
