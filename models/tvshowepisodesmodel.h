#ifndef TVSHOWEPISODESMODEL_H
#define TVSHOWEPISODESMODEL_H

#include <QAbstractListModel>
#include <iostream>
#include <memory>
#include <vector>

#include "backend/tvshowepisodes.h"

namespace gui {

class TVShowEpisodesModel : public QAbstractListModel {
  Q_OBJECT

  Q_PROPERTY(std::vector<backend::TVShowEpisodes> episodes READ episodesList
                 WRITE setEpisodesList)
 public:
  explicit TVShowEpisodesModel(QObject *parent = nullptr);

  enum { idRole = Qt::UserRole };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  std::vector<backend::TVShowEpisodes> episodesList();
  void setEpisodesList(std::vector<backend::TVShowEpisodes> list);

 private:
  std::vector<backend::TVShowEpisodes> episodes_list_;
};
}  // namespace gui
#endif  // TVSHOWEPISODESMODEL_H
