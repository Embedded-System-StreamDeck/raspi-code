import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    color: "#121212"
    opacity: 0.95

    signal close()

    Rectangle {
        id: header
        width: parent.width
        height: 60
        color: "#2c3e50"

        Text {
            anchors.centerIn: parent
            text: qsTr("Settings")
            color: "white"
            font.pixelSize: 24
            font.bold: true
        }

        Button {
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 20
            text: "X"
            onClicked: root.close()
            background: Rectangle {
                implicitWidth: 40
                implicitHeight: 40
                radius: 20
                color: parent.down ? "#a93226" : "#e74c3c"
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                font.pixelSize: 18
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    Flickable {
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20
        contentHeight: settingsLayout.height
        clip: true

        ColumnLayout {
            id: settingsLayout
            width: parent.width
            spacing: 20

            GroupBox {
                title: "Server Connection"
                Layout.fillWidth: true
                background: Rectangle {
                    color: "#2c3e50"
                    radius: 5
                    border.color: "#34495e"
                    border.width: 1
                }
                label: Label {
                    text: parent.title
                    color: "white"
                    font.bold: true
                    font.pixelSize: 16
                    bottomPadding: 10
                }

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10

                    Label {
                        text: "Server IP Address:"
                        color: "white"
                    }

                    TextField {
                        Layout.fillWidth: true
                        text: networkManager.serverAddress
                        placeholderText: "Enter server IP address"
                        onEditingFinished: networkManager.serverAddress = text
                    }

                    Label {
                        text: "Server Port:"
                        color: "white"
                    }

                    TextField {
                        Layout.fillWidth: true
                        text: networkManager.serverPort.toString()
                        placeholderText: "Enter server port"
                        validator: IntValidator { bottom: 1; top: 65535 }
                        onEditingFinished: networkManager.serverPort = parseInt(text)
                    }

                    RowLayout {
                        Layout.fillWidth: true
                        Button {
                            text: networkManager.connected ? "Disconnect" : "Connect"
                            Layout.fillWidth: true
                            onClicked: {
                                if (networkManager.connected) {
                                    networkManager.disconnectFromServer();
                                } else {
                                    networkManager.connectToServer();
                                }
                            }
                            background: Rectangle {
                                color: networkManager.connected ? "#e74c3c" : "#27ae60"
                                radius: 4
                            }
                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    
                    RowLayout {
                        Layout.fillWidth: true
                        Button {
                            text: networkManager.discovering ? "Cancel Discovery" : "Discover Server"
                            Layout.fillWidth: true
                            onClicked: {
                                if (networkManager.discovering) {
                                    networkManager.stopDiscovery();
                                } else {
                                    networkManager.discoverServer();
                                }
                            }
                            background: Rectangle {
                                color: networkManager.discovering ? "#e67e22" : "#3498db"
                                radius: 4
                            }
                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }

                    Text {
                        text: networkManager.discovering ? "Searching for server..." : 
                              (networkManager.connected ? "Connected to server" : "Not connected")
                        color: networkManager.connected ? "#2ecc71" : 
                               (networkManager.discovering ? "#f39c12" : "#e74c3c")
                        Layout.fillWidth: true
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }

            GroupBox {
                title: "About"
                Layout.fillWidth: true
                background: Rectangle {
                    color: "#2c3e50"
                    radius: 5
                    border.color: "#34495e"
                    border.width: 1
                }
                label: Label {
                    text: parent.title
                    color: "white"
                    font.bold: true
                    font.pixelSize: 16
                    bottomPadding: 10
                }

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10

                    Label {
                        text: "Raspberry Pi StreamDeck"
                        color: "white"
                        font.bold: true
                        font.pixelSize: 16
                    }

                    Label {
                        text: "Version 1.0"
                        color: "white"
                    }

                    Label {
                        text: "© 2023 Your Name"
                        color: "white"
                    }
                }
            }

            GroupBox {
                title: "Device Information"
                Layout.fillWidth: true
                background: Rectangle {
                    color: "#2c3e50"
                    radius: 5
                    border.color: "#34495e"
                    border.width: 1
                }
                label: Label {
                    text: parent.title
                    color: "white"
                    font.bold: true
                    font.pixelSize: 16
                    bottomPadding: 10
                }

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10

                    Label {
                        text: "Device IP Address: " + networkManager.deviceIpAddress
                        color: "white"
                    }

                    Button {
                        text: "Refresh IP Address"
                        Layout.fillWidth: true
                        onClicked: networkManager.updateServerWithDeviceIp()
                        background: Rectangle {
                            color: "#3498db"
                            radius: 4
                        }
                        contentItem: Text {
                            text: parent.text
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }
        }
    }
}
