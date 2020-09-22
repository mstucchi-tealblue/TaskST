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
                id: loginButton
                text: "Login"
                highlighted: true
                onClicked: {
                    highlighted = !highlighted
                    homeButton.highlighted = false
                    browserButton.highlighted = false
                    //browserProcess.killProcessFromQml();
                }

            }
            Button {
                id: homeButton
                text: "Home"
                onClicked: {
                    highlighted = !highlighted
                    loginButton.highlighted = false
                    browserButton.highlighted = false
                    //browserProcess.killProcessFromQml();
                }
            }
            Button {
                id: browserButton
                text: "Browser"
                highlighted: false
                onClicked: {
                    highlighted = !highlighted
                    loginButton.highlighted = false
                    homeButton.highlighted = false
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
            id: frame
            Layout.fillHeight: true
            Layout.fillWidth: true
            visible: !loginProcess.visible && !homeProcess.visible
        }

        Rectangle {
            id: loginProcess
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightblue"
            visible: loginButton.highlighted
            Button {
                text: "changeColor"
                onClicked: mainWindow.color = "red"
            }

            Text{
                text: "This is login, pid:"+pid
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: homeProcess
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightgreen"
            visible: homeButton.highlighted
            Text{
                text: "This is home, pid:"+pid
                anchors.centerIn: parent
            }
        }
    }


}
