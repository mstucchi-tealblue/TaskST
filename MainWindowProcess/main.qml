import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Main Window")

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: 5

        RowLayout {
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
                    browserProcess.startProcessFromQml()
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
