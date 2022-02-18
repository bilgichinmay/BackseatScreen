import QtQuick 2.10
import QtQuick.Controls 2.3

Rectangle {
    visible: true
    color: "#363636"

    property string mediaType : ""
    property string enteredText: ""

    property string apiCall : webpageAddress + "?api_key=" + apiKey + "&query=" + searchQuery //enteredText
    property string webpageAddress : "https://api.themoviedb.org/3/search/"
    property string apiKey : "361c7eb5c8aa08e79186317b4e404cb9"

    Text {
        text: mediaType + " search screen" + "\n" + apiCall
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
                enteredText = text
            }
        }
    }

    property string searchQuery: enteredText.replace(" ", "+")

//    function modifySearchQuery (s) {
//        s.replace(" ", "\+");
//        return s;
//    }
}
