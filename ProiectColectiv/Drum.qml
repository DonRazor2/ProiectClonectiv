import QtQuick 2.9


Rectangle {
    id: window
    visible: true
    color: "green"
    width: 45
    height: 400

    ListView {
        id: lista_de_masini
        visible: true
        anchors.fill: parent
        spacing: 5
        interactive: false

        model: ListModel {
            id: listModel_example
            ListElement { name: "Car"; }
            ListElement { name: "Car2"; }
        }
        delegate: Item {
            height: 35
            width: 40 //hardcoded
            anchors.left: parent.left
            anchors.right: parent.right
            Rectangle {
                color: "red"
                anchors.fill: parent
            }
        }
        displaced: Transition {
            NumberAnimation { properties: "y"; duration: 1250
            }
        }

        add: Transition {
            NumberAnimation { properties: "y"; from:lista_de_masini.height + 100 ; duration: 1250
            }
        }
        MouseArea {
            onWheel: listModel_example.append(ListElement)
            onDoubleClicked: listModel_example.remove(0)
            anchors.fill: parent
        }
    }

}
