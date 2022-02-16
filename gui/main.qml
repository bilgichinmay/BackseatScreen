import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 2.12

import "Components"
import "Screens"

Window {
    id: root
    visible: true
    title: qsTr("Rare seat entertainment system")

    // 16:9 aspect ratio as in Mercedes S-Class
    width: 1280
    height: 720
    color: "#363636"

    Header {
        id: header
        anchors.top: parent.top
    }

    Menu {
        id: tvShowButton
        anchors.top: header.bottom
        menuType:  "TV Shows"
        onMenuSelected: {
                mainStack.push(tvSeriesSearchElement)
        }
    }

    Menu {
        id: moviesButton
        anchors.top: tvShowButton.bottom
        menuType: "Movies"
        onMenuSelected: {
            mainStack.push(movieSearchElement)
        }
    }

    Menu {
        id: homeButton
        anchors.bottom: parent.bottom
        menuType: "Home"
        onMenuSelected: {
            mainStack.pop(null)
            deselectButtons()
        }
        Image {
            id: homeIcon
            anchors.centerIn: parent
            width: 40
            height: 40
            source: "qrc:/gui/images/home.png"
        }
    }

    StackView {
        id: mainStack
        width: parent.width - tvShowButton.width
        height: parent.height - header.height
        anchors.right: parent.right
        anchors.top: header.bottom
        clip: true

        initialItem: startScreen
    }

    Component {
        id: startScreen

        Rectangle {
            color: "#363636"

            Text {
                id: startScreenText
                text: qsTr("Welcome")
                anchors.centerIn: parent
                color: "#ffffff"
            }
        }
    }

    Component {
        id: tvSeriesSearchElement
        SearchScreen {
            mediaType: "TV Show"
        }
    }
    Component {
        id: movieSearchElement
        SearchScreen {
            mediaType: "Movies"
        }
    }

    function deselectButtons() {
        tvShowButton.isSelected = false
        moviesButton.isSelected = false
        homeButton.isSelected = false
    }
}
