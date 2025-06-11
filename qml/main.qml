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
        color: {
            if (networkManager.connected) return "#1e824c" // Green for connected
            if (networkManager.discovering) return "#f39c12" // Orange for discovering
            return "#e74c3c" // Red for disconnected
        }
        opacity: 0.8

        Text {
            anchors.centerIn: parent
            text: {
                if (networkManager.connected) 
                    return qsTr("Connected to: %1:%2").arg(networkManager.serverAddress).arg(networkManager.serverPort)
                if (networkManager.discovering)
                    return qsTr("Discovering server... Tap to cancel")
                return qsTr("Disconnected - Tap to discover")
            }
            color: "white"
            font.pixelSize: 14  // Smaller font size
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (networkManager.discovering) {
                    // If discovering, stop it
                    networkManager.stopDiscovery()
                } else if (!networkManager.connected) {
                    // If disconnected, start discovery
                    networkManager.discoverServer()
                } else {
                    // If connected, toggle settings
                    isSettingsOpen = !isSettingsOpen
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
        function onMessageReceived(message) {
            let obj = JSON.parse(message)
            if (obj.buttons) {
                buttonGrid.buttonList = obj.buttons
            }
        }
        
        function onServerDiscovered(address, port) {
            console.log("Server discovered at: " + address + ":" + port)
        }
    }

    Component.onCompleted: {
        // Start server discovery automatically
        networkManager.discoverServer();
    }
}
