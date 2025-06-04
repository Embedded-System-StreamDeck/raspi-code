import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: root
    visible: true
    width: 480
    height: 320
    flags: Qt.Window | Qt.FramelessWindowHint
    visibility: Window.FullScreen
    title: qsTr("Raspberry Pi StreamDeck")
    color: "#121212"

    property bool isSettingsOpen: false

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#121212"
        
        Image {
            anchors.fill: parent
            source: "qrc:/resources/background/background.jpg"
            fillMode: Image.PreserveAspectCrop
            opacity: 0.2
        }
    }

    Rectangle {
        id: connectionStatus
        width: parent.width
        height: 30  // Reduced height to accommodate smaller screen
        color: networkManager.connected ? "#1e824c" : "#e74c3c"
        opacity: 0.8

        Text {
            anchors.centerIn: parent
            text: networkManager.connected 
                  ? qsTr("Connected to: %1:%2 (Device IP)").arg(networkManager.serverAddress).arg(networkManager.serverPort)
                  : qsTr("Disconnected - Tap to connect")
            color: "white"
            font.pixelSize: 14  // Smaller font size
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (!networkManager.connected) {
                    networkManager.connectToServer();
                } else {
                    isSettingsOpen = !isSettingsOpen;
                }
            }
        }
    }

    ButtonGrid {
        id: buttonGrid
        anchors.top: connectionStatus.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 10
        visible: !isSettingsOpen
    }

    SettingsPanel {
        id: settingsPanel
        anchors.fill: parent
        visible: isSettingsOpen
        onClose: {
            isSettingsOpen = false;
        }
    }

    // Gelen JSON veriyi debug amaçlı logla
    Connections {
        target: networkManager
        onMessageReceived: {
            let obj = JSON.parse(message)
            if (obj.buttons) {
                buttonGrid.buttonList = obj.buttons
            }
            
        }
    }


    Component.onCompleted: {
        // The server address is already set to device IP in NetworkManager constructor
        networkManager.connectToServer();
    }
}
