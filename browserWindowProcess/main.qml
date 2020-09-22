import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    width: passedWidth
    height: passedHeight
    visible: true
    title: qsTr("Hello World")
    flags: Window.FramelessWindowHint
    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2 +((passedMainHeight-passedHeight)/2));
    }
    Rectangle
    {
        anchors.fill: parent
        color: "lightgray"
        ColumnLayout {
            anchors.fill: parent
            RowLayout{
                TextArea {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    placeholderText: "Nothing received yet"
                    text: receivedText
                    anchors.centerIn: parent
                }
            }
            RowLayout{
                TextArea {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    placeholderText: "Nothing received yet"
                    anchors.centerIn: parent
                }
            }
            RowLayout{
                TextArea {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    placeholderText: "Nothing received yet"
                    anchors.centerIn: parent
                }
            }
        }


    }
}
