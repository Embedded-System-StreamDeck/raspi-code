// StreamButton.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root
    width: 100
    height: 100

    property string iconSource
    property string buttonText
    property string command

    Rectangle {
        anchors.fill: parent
        radius: 10
        color: "#2c3e50"

        Column {
            anchors.centerIn: parent
            spacing: 4

            Image {
                source: iconSource
                width: 40
                height: 40
                fillMode: Image.PreserveAspectFit
            }

            Text {
                text: buttonText
                color: "white"
                font.pixelSize: 12
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                networkManager.sendRawCommand(command)
            }
        }
    }
}
