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
        anchors.topMargin: 5

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
                    analysisButton.highlighted = false
                    mServer.processVisibilityHandler(false)
                }
            }
            Button {
                id: homeButton
                text: "Home"
                onClicked: {
                    highlighted = !highlighted
                    loginButton.highlighted = false
                    browserButton.highlighted = false
                    analysisButton.highlighted = false
                    mServer.processVisibilityHandler(false)
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
                    analysisButton.highlighted = false
                    //process visibility changer
                    mServer.processVisibilityHandler(browserButton.highlighted)
                }
            }
            Button {
                id: analysisButton
                text: "Analysis"
                highlighted: false
                onClicked: {
                    highlighted = !highlighted
                    loginButton.highlighted = false
                    homeButton.highlighted = false
                    browserButton.highlighted = false
                    //process visibility changer
                    mServer.processVisibilityHandler(analysisButton.highlighted)
                }
            }
        }

        Frame {
            id: frame
            Layout.fillHeight: true
            Layout.fillWidth: true
            visible: !loginButton.highlighted && !homeButton.highlighted && !browserButton.highlighted && !analysisButton.highlighted
        }

        Rectangle {
            id: loginProcess
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightblue"
            visible: loginButton.highlighted
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

        Rectangle {
            id: backgroundBrowserProcess
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "gray"
            visible: browserButton.highlighted || analysisButton.highlighted
        }
    }


}
