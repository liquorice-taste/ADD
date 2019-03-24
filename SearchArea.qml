import QtQuick 2.11
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

Rectangle {
    id: rec
    //border.color: "#000001"
    Layout.fillWidth: true
    //height: 30
    Connections {
        id: rip
        target: HttpRequest
    }
    Material.theme: Material.Dark
    RowLayout {
        id: rl
        anchors.fill: parent
        spacing: 2
        TextEdit {

            //horizontalAlignment: TextInput.AlignLeft
            verticalAlignment: TextEdit.AlignVCenter
            horizontalAlignment: TextEdit.AlignLeft
            id: tex
            text: "cock"
            font.family: "Helvetica [Cronyx]"
            //adaptive font:
            //font.pixelSize : int
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBaseline
        }
        /*TextField {

        }*/

        Button {
            id: but
            padding: 10
            Layout.fillHeight: true
            width: parent.width * 0.2
            Layout.alignment: Qt.AlignRight

            onClicked: {
                HttpRequest.getData(tex.text)
            }
        }
    }


}
