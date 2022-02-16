import QtQuick 2.10
import QtQuick.Controls 2.3

Rectangle {
    visible: true
    color: "#363636"

    property string mediaType : ""
    property string enteredText: ""

    Text {
        text: mediaType + " Search Screen"
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
                anchors.fill: parent
                color: "#aaaaaa"
            }
            placeholderText: "Search your favourite shows here..."

            onTextChanged: {
                enteredText = text
            }
        }
    }
}
