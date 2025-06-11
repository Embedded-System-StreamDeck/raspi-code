// StreamButton.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    width: 100
    height: 100

    property string buttonText
    property string command

    Rectangle {
        id: buttonBackground
        anchors.fill: parent
        radius: 10
        color: "#2c3e50"
        border.color: "#3498db"
        border.width: 2

        // Add a state for visual feedback
        states: [
            State {
                name: "pressed"
                PropertyChanges {
                    target: buttonBackground
                    color: "#1a5276" // Darker color when pressed
                    scale: 0.95
                }
            }
        ]

        // Simplified transitions without ScaleAnimation
        transitions: [
            Transition {
                from: ""
                to: "pressed"
                ColorAnimation { duration: 100 }
                PropertyAnimation { 
                    property: "scale"; 
                    duration: 100 
                }
            },
            Transition {
                from: "pressed"
                to: ""
                ColorAnimation { duration: 200 }
                PropertyAnimation { 
                    property: "scale"; 
                    duration: 200 
                }
            }
        ]

        Text {
            anchors.centerIn: parent
            text: buttonText
            color: "white"
            font.pixelSize: 18
            font.bold: true
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
            width: parent.width - 10
            elide: Text.ElideRight
        }

        MouseArea {
            anchors.fill: parent
            onPressed: buttonBackground.state = "pressed"
            onReleased: buttonBackground.state = ""
            onCanceled: buttonBackground.state = ""
            onClicked: {
                console.log("Button clicked: " + buttonText + ", sending command: " + command)
                networkManager.sendRawCommand(command)
            }
        }
    }
}
