import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

import EventHandler 1.0
import MovieList 1.0
import TVShowList 1.0
import TVShowSeasonList 1.0
import TVShowEpisodesList 1.0

Rectangle {
    visible: true
    color: "#363636"

    property string mediaType
    property string enteredText: ""
    property string selectedShow: ""
    property string selectedShowID: ""
    property string selectedSeason: ""
    property string selectedEpisode: ""

    EventHandler {
        id: backend

        onMoviesChanged: {
            movieListModel.movies = backend.movies()
        }
        onTvShowsChanged: {
            tvShowListModel.tvshows = backend.tvShows()
        }
        onSeasonsChanged: {
            tvShowSeasonListModel.seasons = backend.seasons()
        }
        onEpisodesChanged: {
            tvShowEpisodeListModel.episodes = backend.episodes()
        }
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
            anchors.rightMargin: 20

            Text {
                id: searchConfirmButtonText
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

                        selectedShow = ""
                        selectedSeason = ""
                        selectedEpisode = ""

                        if (mediaType == "tv") {
                            backend.searchTVShow(enteredText)
                            tvShowListModel.tvshows = backend.tvShows()
                            movieListContainer.visible = false
                        } else {
                            backend.searchMovie(enteredText)
                            movieListModel.movies = backend.movies()
                            tvShowListContainer.visible = false
                            tvShowSeasonListContainer.visible = false
                            tvShowEpisodeListContainer.visible = false
                        }
                    }
                }
            }
        }

        TextField {
            id: searchTextField

            width: parent.width - 120 - searchConfirmButton.width
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
        id: outputField
        color: parent.color

        width: parent.width
        height: 60

        anchors.top: textFieldContainer.bottom

        Text {
            id: outputText
            text: "You will be watching : " + selectedShow + " "
                  + selectedSeason + " " + selectedEpisode
            color: "#ffffff"
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: movieListContainer
        color: parent.color

        width: parent.width
        height: parent.height - textFieldContainer.height

        anchors.top: outputField.bottom

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

                    width: 800
                    height: 80
                    color: "#363636"

                    Text {
                        id: movieTitle
                        text: model.title
                        color: "#ffffff"
                        topPadding: 20
                        leftPadding: 100
                    }

                    Button {
                        id: tvShowEpisodeSelector

                        width: 60
                        height: 60
                        anchors.right: parent.right
                        anchors.rightMargin: 40

                        background: Rectangle {
                            anchors.fill: parent
                            color: "#aaaaaa"
                        }
                        Text {
                            id: buttonText
                            text: "Select"
                            color: "#ffffff"
                            anchors.centerIn: parent
                        }
                        onClicked: {
                            selectedShow = model.title
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: tvShowEpisodeListContainer
        color: parent.color
        width: parent.width
        height: parent.height - textFieldContainer.height
        anchors.top: outputField.bottom

        GridLayout {
            id: tvShowEpisodeListLayout
            anchors.fill: parent
            rowSpacing: 5
            columnSpacing: 0
            flow: GridLayout.TopToBottom
            clip: true

            Repeater {
                id: tvShowEpisodeLister

                model: TVShowEpisodesListModel {
                    id: tvShowEpisodeListModel
                }

                delegate: tvShowEpisodeDelegate

                Component {
                    id: tvShowEpisodeDelegate
                    Rectangle {
                        id: tvShowEpisodeListerDelegate

                        width: 800
                        height: 80
                        color: "#363636"

                        Text {
                            id: tvShowEpisodeTitle
                            text: model.title
                            color: "#ffffff"
                            topPadding: 20
                            leftPadding: 100
                        }

                        Button {
                            id: tvShowEpisodeSelector

                            width: 60
                            height: 60
                            anchors.right: parent.right
                            anchors.rightMargin: 40

                            background: Rectangle {
                                anchors.fill: parent
                                color: "#aaaaaa"
                            }
                            Text {
                                id: buttonText
                                text: "Select"
                                color: "#ffffff"
                                anchors.centerIn: parent
                            }
                            onClicked: {
                                selectedEpisode = model.title
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: tvShowSeasonListContainer
        color: parent.color
        width: parent.width
        height: parent.height - textFieldContainer.height
        anchors.top: outputField.bottom

        GridLayout {
            id: tvShowSeasonListLayout
            anchors.fill: parent
            rowSpacing: 5
            columnSpacing: 0
            flow: GridLayout.TopToBottom
            clip: true

            Repeater {
                id: tvShowSeasonLister

                model: TVShowSeasonListModel {
                    id: tvShowSeasonListModel
                }

                delegate: tvShowSeasonDelegate

                Component {
                    id: tvShowSeasonDelegate
                    Rectangle {
                        id: tvShowSeasonListerDelegate

                        width: 800
                        height: 80
                        color: "#363636"

                        Text {
                            id: tvShowSeasonTitle
                            text: model.title
                            color: "#ffffff"
                            topPadding: 20
                            leftPadding: 100
                        }

                        Button {
                            id: tvShowSeasonSelector

                            width: 60
                            height: 60
                            anchors.right: parent.right
                            anchors.rightMargin: 40

                            background: Rectangle {
                                anchors.fill: parent
                                color: "#aaaaaa"
                            }
                            Text {
                                id: buttonText
                                text: "Select"
                                color: "#ffffff"
                                anchors.centerIn: parent
                            }
                            onClicked: {
                                selectedSeason = model.title
                                backend.getEpisodesList(selectedShowID,
                                                        model.season)
                                tvShowSeasonListContainer.visible = false
                                tvShowEpisodeListModel.episodes = backend.episodes()
                            }
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
        anchors.top: outputField.bottom

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

                        width: 800
                        height: 80
                        color: "#363636"

                        Text {
                            id: tvShowTitle
                            text: model.title
                            color: "#ffffff"
                            topPadding: 20
                            leftPadding: 100
                        }

                        Button {
                            id: tvShowSelector

                            width: 60
                            height: 60
                            anchors.right: parent.right
                            anchors.rightMargin: 40

                            background: Rectangle {
                                anchors.fill: parent
                                color: "#aaaaaa"
                            }
                            Text {
                                id: buttonText
                                text: "Select"
                                color: "#ffffff"
                                anchors.centerIn: parent
                            }
                            onClicked: {
                                selectedShow = model.title
                                selectedShowID = model.id
                                backend.getTVShowSeasons(model.id)
                                tvShowListContainer.visible = false
                                tvShowSeasonListModel.seasons = backend.seasons(
                                            )
                            }
                        }
                    }
                }
            }
        }
    }
}
