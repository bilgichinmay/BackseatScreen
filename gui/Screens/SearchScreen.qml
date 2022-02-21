import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

import EventHandler 1.0
import MovieList 1.0
import TVShowList 1.0

Rectangle {
    visible: true
    color: "#363636"

    property string mediaType
    property string enteredText: ""

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
            width: 80
            height: parent.height
            radius: height / 2
            color: "#888888"
            anchors.right: parent.right

            Text {
                id: searchConButtonText
                text: "Search"
                color: "#ffffff"
                anchors.centerIn: parent
            }

            MouseArea {
                property bool isClicked: false

                anchors.fill: parent
                onClicked: {
                    if (isClicked === false) {
                        isClicked = !isClicked

                        if (mediaType == "tv") {
                            backend.searchTVShow(enteredText)
                            tvShowListModel.tvshows = backend.tvShows()
                            movieListContainer.visible = false
                        } else {
                            backend.searchMovie(enteredText)
                            movieListModel.movies = backend.movies()
                            tvShowListContainer.visible = false
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
                radius: height / 4
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

        anchors.top: textFieldContainer.bottom

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
                    color: "#363636"

                    Text {
                        id: movieTitle
                        text: model.title
                        color: "#ffffff"
                        topPadding: 20
                        leftPadding: 100
                    }

                    border.color: "#ffffff"
                    border.width: 1

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            mainStack.pop(null)
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: tvShowListContainer
        color: parent.color
        width: parent.width
        height: parent.height - textFieldContainer.height
        anchors.top: textFieldContainer.bottom

        GridLayout {
            id: tvShowListLayout
            anchors.fill: parent
            rowSpacing: 5
            columnSpacing: 0
            flow: GridLayout.TopToBottom
            clip: true

            Repeater {
                id: tvShowLister

                model: TVShowListModel {
                    id: tvShowListModel
                }

                delegate: tvShowDelegate

                Component {
                    id: tvShowDelegate
                    Rectangle {
                        id: tvShowListerDelegate

                        width: parent.width
                        height: 80

                        Text {
                            id: tvShowTitle
                            text: model.title
                            color: "#ffffff"
                            topPadding: 20
                            leftPadding: 100
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {

                            }
                        }

                        //                        Button {
                        //                            id: tvShowSelector

                        //                            width: 80
                        //                            height: 80
                        //                            anchors.right: parent.right

                        //                            background: Rectangle {
                        //                                anchors.fill: parent
                        //                                color: "#ffffff"
                        //                            }

                        //                            onClicked: {
                        //                                mainStack.pop(null)
                        //                            }
                        //                        }
                    }
                }
            }
        }
    }
}
