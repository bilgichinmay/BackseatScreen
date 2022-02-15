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
        id: tvShowTab
        anchors.top: header.bottom
        Text {
            id: tvShowTabText
            text: qsTr("TV Shows")
            anchors.centerIn: parent
            color: "#ffffff"
        }

        onMenuSelected: {
            mainStack.push(tvSeriesSearchElement)
        }
    }

    Menu {
        id: moviesTab
        anchors.top: tvShowTab.bottom
        Text {
            id: movieTabText
            text: qsTr("Movies")
            anchors.centerIn: parent
            color: "#ffffff"
        }

        onMenuSelected: {
            mainStack.push(movieSearchElement)
        }
    }

    Menu {
        id: backButton
        anchors.bottom: parent.bottom

        Text {
            id: backButtonText
            text: qsTr("Back")
            anchors.centerIn: parent
            color: "#ffffff"
        }

        onMenuSelected: {
            mainStack.pop(null)
        }

    }

    StackView {
        id: mainStack
        width: parent.width - tvShowTab.width
        height: parent.height - header.height
        anchors.right: parent.right
        anchors.top: header.bottom
        clip: true

        initialItem: startScreen
    }

    Component {
        id: startScreen

        Rectangle {
            anchors.fill: parent
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
        TVSeriesScreen {}
    }
    Component {
        id: movieSearchElement
        MovieScreen {}
    }
}
