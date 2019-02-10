import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4
import Model 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 300
    height: 400

    title: qsTr("Awesome Dictionary")

    Connections {
        id: rip
        target: HttpRequest
    }

    Row {
        id: inputLayout
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.1 * window.height
        TextInput{
            id: searchInput
            font.family: "Helvetica"
            font.pointSize: 13
            font.bold: true
            width: 0.8 * inputLayout.width
            height: parent.height
            horizontalAlignment: TextInput.AlignHCenter
        }
        Button {
            width: 0.2 * inputLayout.width
            height: parent.height
            onClicked: {
                HttpRequest.getData(searchInput.text)
                console.log(dataModel.rowCount())
            }
        }

    }
    //DictionaryModel{
    // id: dicModel
    /*entries: [
            HeadwordEntry {
                num: 12
            },
            HeadwordEntry {
                num: 13
                language: "another old"
            }
        ]*/

    //   }


    ListModel {
        id: dataModel

        ListElement {
            language: "orange"
            num: 1
        }
        ListElement {
            language: "skyblue"
            num: 2
        }
        ListElement {
            language: "skyblue"
            num: 2
        }
    }


    DictionaryModel {
        id: mof
        data: [
        ]
    }

    ListView {
        id: lv
        anchors.top: inputLayout.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        model: mof.data
        delegate:
            Rectangle{
            anchors.margins: 5
            anchors.fill: parent
            radius: height / 2
            color: "cyan"
            border {
                color: "black"
                width: 1
            }
            height: 25
            width: parent.width

            Text {
                id: name
                text: dataModel.language
            }
        }
    }



}
