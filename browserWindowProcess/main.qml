import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    width: mClient.windowWidth
    height: mClient.windowHeight
    visible: mClient.windowVisibility
    title: qsTr("Hello World")
    //flags: Window.FramelessWindowHint
    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2 +((mClient.wrapperWindowHeight - mClient.initialHeight)/2));
    }
    Rectangle
    {
        anchors.fill: parent
        color: "gray"
        ColumnLayout {
            anchors.fill: parent
            TextArea {
                Layout.fillHeight: true
                Layout.fillWidth: true
                placeholderText: "Nothing received yet"
                text: mClient.receivedFromSever
                anchors.centerIn: parent
            }
        }
    }
}
