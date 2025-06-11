import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    property var buttonList: []
    
    // Predefined buttons for common functions
    property var defaultButtons: [
        { label: "Volume Up", command: "volume_up" },
        { label: "Volume Down", command: "volume_down" },
        { label: "Mute", command: "mute" },
        { label: "Unmute", command: "unmute" },
        { label: "Screenshot", command: "screenshot" },
        { label: "Stop", command: "record_stop" }
    ]

    GridLayout {
        anchors.fill: parent
        anchors.margins: 20
        columns: 2 // 2x3 grid layout for better readability
        rowSpacing: 20
        columnSpacing: 20

        Repeater {
            model: root.buttonList.length > 0 ? root.buttonList : root.defaultButtons
            delegate: StreamButton {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: (parent.width - 20) / 2
                Layout.preferredHeight: (parent.height - 40) / 3
                Layout.margins: 5
                buttonText: modelData.label || "Button " + (index + 1)
                command: modelData.command || "none"
            }
        }
    }

    Component.onCompleted: {
        console.log("ButtonGrid initialized with: ", JSON.stringify(buttonList))
    }
}
