import QtQuick 2.12

Rectangle {
    signal menuSelected
    property string menuType : ""
    property bool isClicked : false

    visible: true
    color: "#888888"

    width: 160
    height: 80
    radius: height/2

    Text {
        visible: menuType !== "Home"
        text: menuType
        anchors.centerIn: parent
        color: "#ffffff"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (isClicked === false) {
                isClicked = !isClicked
                menuSelected()
            }
        }
    }

    border.color: "#363636"
    border.width: isClicked ? 0 : 8
}
