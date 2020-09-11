import QtQuick 2.15
import QtQuick.Window 2.15


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
        color: "gray"
    }


    Text {
        id: name
        anchors.centerIn: parent
        text: qsTr("Passed ID: "+ passedArg)
    }
}
