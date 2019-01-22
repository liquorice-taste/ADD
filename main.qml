import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import TestModel 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 300
    height: 400

    title: qsTr("Awesome Dictionary")

    Connections {
        id: rip
        target: HttpRequest // Specify the target connection
        /* We declare and implement a function as an object parameter and
             * first name similar to the name of the signal.
             * The difference is that we add at the beginning on and
             * then write with a capital letter
             *
            onSendToQml: {
                labelCount.text = count // Set the counter to a text label
            } */
    }
    Testss {
        id: dataModel
    }

    Row {
        id: inputLayout
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.1 * window.height
        TextInput{
            id: searchInput
            font.family: "Helvetica"; font.pointSize: 13; font.bold: true
            width: 0.8 * inputLayout.width
            height: parent.height
            horizontalAlignment: TextInput.AlignHCenter
        }
        Button {
            width: 0.2 * inputLayout.width
            height: parent.height
            onClicked: {
                HttpRequest.getData(searchInput.text)
                console.log(lv.count)
            }
        }

    }
    ListModel {
        id:lmodel
        ListElement{
            word: "ace"

        }
        ListElement{
            word: "hell"
        }
        ListElement{
            word: "hello"
        }
    }
    ListView {
        id: lv
        anchors.top: inputLayout.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        model: dataModel//HttpRequest.jmodel
        /*delegate:
            Rectangle{
            height: 25
            width: parent.width

            Text {
                id: name
                //text: provider
            }
        }*/
    }


    Rectangle {
        width: 360
        height: 360



        Column {
            anchors.margins: 10
            anchors.fill: parent
            spacing: 10

            ListView {
                id: view

                width: parent.width
                height: parent.height - button.height - parent.spacing
                spacing: 10
                model: HttpRequest.jmodel
                clip: true

                delegate: Rectangle {
                    width: view.width
                    height: 40
                    color: model.color

                    Text {
                        anchors.centerIn: parent
                        renderType: Text.NativeRendering
                        text: model.text || "old"
                    }
                }
            }

            Rectangle {
                id: button

                width: 100
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                border {
                    color: "black"
                    width: 1
                }

                Text {
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                    text: "Add"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: dataModel.append({ color: "skyblue", text: "new" })
                }
            }
        }
    }



}
