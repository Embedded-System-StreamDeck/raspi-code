import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    property var buttonList: []
    
    // Varsayılan 6 buton için array
    property var defaultButtons: [
        { label: "Button 1", command: "none", iconSource: "qrc:/resources/icons/none.png" },
        { label: "Button 2", command: "none", iconSource: "qrc:/resources/icons/none.png" },
        { label: "Button 3", command: "none", iconSource: "qrc:/resources/icons/none.png" },
        { label: "Button 4", command: "none", iconSource: "qrc:/resources/icons/none.png" },
        { label: "Button 5", command: "none", iconSource: "qrc:/resources/icons/none.png" },
        { label: "Button 6", command: "none", iconSource: "qrc:/resources/icons/none.png" }
    ]

    GridLayout {
        anchors.fill: parent
        anchors.margins: 50  // Increased outer margins
        columns: 3 // 3x2 grid layout
        rowSpacing: 50       // Increased row spacing
        columnSpacing: 50    // Increased column spacing

        Repeater {
            model: root.buttonList.length > 0 ? root.buttonList : root.defaultButtons
            delegate: StreamButton {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: (parent.width - 30) / 3  // Adjusted width calculation with spacing
                Layout.preferredHeight: (parent.height - 15) / 2 // Adjusted height calculation with spacing
                Layout.margins: 5  // Additional margin around each button
                buttonText: modelData.label || "Button " + (index + 1)
                command: modelData.command || "none"
                iconSource: modelData.iconSource && modelData.iconSource !== "" ? 
                           modelData.iconSource : "qrc:/resources/icons/none.png"
            }
        }
    }

    Component.onCompleted: {
        console.log("ButtonGrid initialized with: ", JSON.stringify(buttonList))
    }
}
