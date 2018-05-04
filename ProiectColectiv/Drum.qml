import QtQuick 2.9


Rectangle {
    visible: true
    color: "green"
    width: 45
    height: 400

    MouseArea {
        anchors.fill: parent
        onClicked: console.log("Drum Clicked")
    }
}

