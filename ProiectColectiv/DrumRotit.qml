import QtQuick 2.9


Rectangle {
    visible: true
    color: "grey"
    width: 200
    height: 25

    MouseArea {
        anchors.fill: parent
        onClicked: console.log("Drum Clicked")
    }
}
