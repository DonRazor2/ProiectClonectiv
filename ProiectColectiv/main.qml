import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    visible: true
    width: 1600
    height: 1000

    Rectangle {
        id: main_window
        visible: true
        width: parent.width
        height: parent.height

        Rectangle {
            id: intersectie
            visible: true
            color: "black"
            width: 100
            height: 100
            anchors.centerIn: parent
        }
        Drum {
            anchors.left: intersectie.left
            anchors.top: intersectie.bottom
        }
        Drum {
            anchors.right: intersectie.right
            anchors.top: intersectie.bottom
        }
        Drum {
            anchors.left: intersectie.left
            anchors.bottom: intersectie.top
        }
        Drum {
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
}
