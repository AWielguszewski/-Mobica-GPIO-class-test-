import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle {
    id: window
    visible: true
    width: 1920
    height: 1080
    color: "#252323"

signal qmlSignal(string msg)

        Text {
            x: 0
            y: 0
            width: 120
            text: qsTr("Hello")
            horizontalAlignment: Text.AlignLeft
        }

        Button {
            id: button1
            x: 810
            y: 490
            width: 300
            height: 100
            onClicked: {
                window.qmlSignal(text);
            }
            Rectangle{
                objectName: "btn"
                anchors.fill: parent

                Text {
                    id: text1
                    objectName: "txt"
                    x: 50
                    y: 25
                    width: 200
                    height: 50
                    text: qsTr("")
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 20
                }
            }
        }


}
