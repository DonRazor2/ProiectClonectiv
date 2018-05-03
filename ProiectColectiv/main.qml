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

        Rectangle {
            id: drum_jos
            visible: true
            color: "red"
            width: 100
            height: 400
            anchors.horizontalCenter: main_window.horizontalCenter
            anchors.top: intersectie.bottom
        }

        Rectangle {
            id: drum_sus
            visible: true
            color: "green"
            width: 100
            height: 400
            anchors.horizontalCenter: main_window.horizontalCenter
            anchors.bottom: intersectie.top
        }

        Rectangle {
            id: drum_dreapta
            visible: true
            color: "blue"
            width: 400
            height: 100
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: intersectie.right
        }

        Rectangle {
            id: drum_stanga
            visible: true
            color: "yellow"
            width: 400
            height: 100
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: intersectie.left

            Rectangle {
                id: loc_masina_1
                visible: true
                width: 40
                height: 50
                color: "red"
                anchors.centerIn: parent
            }
        }
    }
}
