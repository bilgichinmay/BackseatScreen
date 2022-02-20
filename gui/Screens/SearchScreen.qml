import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

import EventHandler 1.0
import MovieList 1.0
import TVShowList 1.0

Rectangle {
    visible: true
    color: "#363636"

    property string mediaType : ""
    property string enteredText : ""

    EventHandler {
        id: backend

        onMoviesChanged: {
            movieListModel.movies = backend.movies()
        }
        onTvShowsChanged: {
            tvShowListModel.tvshows = backend.tvShows()
        }
    }

    Text {
        text: mediaType
        anchors.centerIn: parent
        color: "#ffffff"
    }

    Rectangle {
        id: textFieldContainer
        color: parent.color

        width: parent.width
        height: 60

        Rectangle {
            id: searchConfirmButton
            width : 80
            height: parent.height
            radius: height/2
            color: "#888888"
            anchors.right: parent.right

            Text {
                id: searchConButtonText
                text: "Search"
                color: "#ffffff"
                anchors.centerIn: parent
            }

            MouseArea {
                property bool isClicked : false

                anchors.fill: parent
                onClicked: {
                    if (isClicked === false) {
                        isClicked = !isClicked

                        if (mediaType == "tv") {
                            backend.searchTVShow(enteredText)
                            tvShowListModel.tvshows = backend.tvShows()
                        } else {
                            backend.searchMovie(enteredText)
                            movieListModel.movies = backend.movies()
                        }
                    }
                }
            }
        }

        TextField {
            id: searchTextField

            width: parent.width - 100 - searchConfirmButton.width
            height: parent.height
            anchors.centerIn: parent

            background: Rectangle {
                radius: height/4
                anchors.fill: parent
                color: "#aaaaaa"
            }
            placeholderText: "Search your favourite shows here..."

            onTextChanged: {
                enteredText = text
            }
        }
    }

    Rectangle {
        id: movieListContainer
        color: parent.color

        width: parent.width
        height: parent.height - textFieldContainer.height

        anchors.top : textFieldContainer.bottom

        GridLayout {
            id: movieListLayout
            anchors.fill: parent
            rowSpacing: 5
            columnSpacing: 0
            flow: GridLayout.TopToBottom

            Repeater {
                id: movieLister

                model: MovieListModel {
                    id: movieListModel
                }

                delegate: Rectangle {
                    id: movieListerDelegate

                    width: parent.width
                    height: 80

                    Text {
                        id: movieTitle
                        text: model.title
                        color:  "#ffffff"
                        topPadding: 20
                        leftPadding: 100
                    }

                    border.color: "#555555"
                    border.width : 1
                }
            }
        }
    }

    Rectangle {
        id: tvShowListContainer
        color: parent.color

        width: parent.width
        height: parent.height - textFieldContainer.height

        anchors.top : textFieldContainer.bottom

        GridLayout {
            id: tvShowListLayout
            anchors.fill: parent
            rowSpacing: 5
            columnSpacing: 0
            flow: GridLayout.TopToBottom

            Repeater {
                id: tvShowLister

                model: TVShowListModel {
                    id: tvShowListModel
                }

                delegate: Rectangle {
                    id: tvShowListerDelegate

                    width: parent.width
                    height: 80

                    Text {
                        id: tvShowTitle
                        text: model.title
                        color:  "#ffffff"
                        topPadding: 20
                        leftPadding: 100
                    }

                    border.color: "#555555"
                    border.width : 1
                }
            }
        }
    }
}
