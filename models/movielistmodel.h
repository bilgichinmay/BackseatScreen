#ifndef MOVIELISTMODEL_H
#define MOVIELISTMODEL_H

#include <QAbstractListModel>
#include <iostream>
#include <memory>
#include <vector>

#include "backend/moviedata.h"

namespace gui {

/**
 * @brief The MovieListModel class
 *
 * Qt model for movies
 */
class MovieListModel : public QAbstractListModel {
  Q_OBJECT

  Q_PROPERTY(
      std::vector<backend::MovieData> movies READ movieList WRITE setMovieList)
 public:
  explicit MovieListModel(QObject *parent = nullptr);

  enum { idRole = Qt::UserRole, titleRole };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  std::vector<backend::MovieData> movieList();
  void setMovieList(std::vector<backend::MovieData> list);

 private:
  std::vector<backend::MovieData> movie_list_;
};
}  // namespace gui
#endif  // MOVIELISTMODEL_H
