import QtQuick 2.10
import QtQuick.Controls 2.3

import EventHandler 1.0

Rectangle {
    visible: true
    color: "#363636"

    property string mediaType : ""

    EventHandler {
        id: backend
    }

    Text {
        text: mediaType //+ " search screen" + "\n" + apiCall
        anchors.centerIn: parent
        color: "#ffffff"
    }

    Rectangle {
        id: textFieldContainer
        color: parent.color

        width: parent.width
        height: 60

        TextField {
            id: searchTextField

            width: parent.width - 80
            height: parent.height
            anchors.centerIn: parent

            background: Rectangle {
                radius: height/4
                anchors.fill: parent
                color: "#aaaaaa"
            }
            placeholderText: "Search your favourite shows here..."

            onTextChanged: {
                if (mediaType == "tv") {
                    backend.searchTVShow(text)
                } else {
                    backend.searchMovie(text)
                }
            }
        }
    }
}
