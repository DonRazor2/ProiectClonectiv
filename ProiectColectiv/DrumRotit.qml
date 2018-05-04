import QtQuick 2.9


Rectangle {
    visible: true
    color: "green"
    width: 400
    height: 45

    MouseArea {
        anchors.fill: parent
        onClicked: console.log("Drum Clicked")
    }
}

