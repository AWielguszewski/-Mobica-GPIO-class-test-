import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle {
    id: window
    visible: true
    width: 1920
    height: 1080


        Text {
            x: 0
            y: 0
            width: 120
            text: qsTr("Hello")
            horizontalAlignment: Text.AlignLeft
        }

}
