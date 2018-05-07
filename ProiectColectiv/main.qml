import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    visible: true
    width: 1800
    height: 900

    Rectangle {
        id: main_window
        visible: true
        width: parent.width
        height: parent.height

        Intersectie {
            id: intersectie_stanga
            anchors.left: parent.left
        }

        Intersectie {
            id: intersectie_dreapta
            anchors.left: intersectie_stanga.right
        }
    }
}
