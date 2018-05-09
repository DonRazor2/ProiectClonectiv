import QtQuick 2.9

Rectangle {
    visible: true
    width: 450
    height: 450
    color: "#55FF66"

    Rectangle {
        id: intersectie
        visible: true
        color: "black"
        width: 50
        height: 50
        anchors.centerIn: parent
    }

    Drum {
        id: drum_jos_stanga
        anchors.left: intersectie.left
        anchors.top: intersectie.bottom
        rotation: 180

    }

    Drum {
        id: drum_jos_dreapta
        anchors.right: intersectie.right
        anchors.top: intersectie.bottom
    }

    Drum {
        id: drum_sus_stanga
        anchors.left: intersectie.left
        anchors.bottom: intersectie.top
        rotation: 180
    }

    Drum {
        id: drum_sus_dreapta
        anchors.right: intersectie.right
        anchors.bottom: intersectie.top
    }

    DrumRotit {
        anchors.left: intersectie.right
        anchors.bottom: intersectie.bottom
    }

    DrumRotit {
        anchors.left: intersectie.right
        anchors.top: intersectie.top
    }
    DrumRotit {
        anchors.right: intersectie.left
        anchors.top: intersectie.top
    }

    DrumRotit {
        anchors.right: intersectie.left
        anchors.bottom: intersectie.bottom
    }
}
