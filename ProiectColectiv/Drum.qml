import QtQuick 2.9

Rectangle {
    id: window
    visible: true
    color: "grey"
    width: 25
    height: 200

    ListView {
        id: lista_de_masini
        visible: true
        anchors.fill: parent
        spacing: 3
        interactive: false

        model: ListModel {
            id: listModel_example
            ListElement { name: "Car"; }
            ListElement { name: "Car2"; }
        }

        delegate: Item {
            height: 20
            width: 15 //hardcoded
            anchors.left: parent.left
            anchors.right: parent.right
            Image {
                source: "RedCar.ico"
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
                rotation: 90
            }
        }

        displaced: Transition {
            NumberAnimation { properties: "y"; duration: 1250; easing.type: Easing.InOutQuint
            }
        }

        add: Transition {
            NumberAnimation { properties: "y"; from:lista_de_masini.height ; duration: 1250; easing.type: Easing.InOutQuint
            }
        }

        MouseArea {
            onClicked: listModel_example.append(ListElement)
            onPressAndHold: listModel_example.remove(0)
            anchors.fill: parent
        }
    }
}
