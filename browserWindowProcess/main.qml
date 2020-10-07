import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    id: root
    x: mClient.initialX
    y: mClient.initialY
    width: mClient.initialWidth
    height: mClient.initialHeight
    visible: mClient.windowVisibility

    Rectangle
    {
        anchors.fill: parent
        color: "gray"
        ColumnLayout {
            anchors.fill: parent
            TextArea {
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: " height: " + root.height + " width: " + root.width + " x: " + root.x + " y:" + root.y
                anchors.centerIn: parent
            }
        }
    }
}
