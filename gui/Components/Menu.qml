import QtQuick 2.12

Rectangle {
    signal menuSelected

    visible: true
    color: "#363636"

    width: 160
    height: 80

    MouseArea {
        anchors.fill: parent
        onClicked: { menuSelected() }
    }

    border.color: "white"
    border.width: 2
}
