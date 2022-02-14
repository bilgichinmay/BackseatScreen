import QtQuick 2.3
import QtQuick.Window 2.0

Window {
    id: root
    visible: true

    // 16:9 aspect ratio as in Mercedes S-Class
    width: 1280
    height: 720
    title: qsTr("Rare seat entertainment system")
    color: "#363636"
    Text {
        text: qsTr("Hello Mercedes User")
        anchors.centerIn: parent
        color: "#ffffff"
    }
}
