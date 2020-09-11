import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Main Window")
    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2 );
    }

    ColumnLayout{
        id: mainWindowColumn
        anchors.fill: parent
        anchors.margins: 5

        RowLayout {
            id: firstRow
            Button {
                text: "Login"

            }
            Button {
                text: "Home"
            }
            Button {
                text: "Browser"
                highlighted: false
                onClicked: {
                    highlighted = !highlighted
                    browserProcess.startProcessFromQml(mainWindow.height,
                                                       mainWindow.height-firstRow.height-10,
                                                       mainWindow.width)
                }
            }
            Button {
                text: "Analysis"
            }
        }

        Frame {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

}
