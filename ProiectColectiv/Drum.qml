import QtQuick 2.9


Rectangle {
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
            width: 40
            anchors.left: parent.left
            anchors.right: parent.right
            Rectangle {
                color: "red"
                anchors.fill: parent
            }
        }
        displaced: Transition {
            NumberAnimation { properties: "y"; duration: 500
            }
        }

        add: Transition {
            NumberAnimation { properties: "y"; from:lista_de_masini.height + 50 ; duration: 500
            }
        }
        MouseArea {
            onWheel: listModel_example.append(ListElement)
            onDoubleClicked: listModel_example.remove(0)
            anchors.fill: parent
        }
    }

}
