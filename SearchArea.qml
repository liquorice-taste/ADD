import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

Item {
    Layout.fillWidth: true

    Connections {
        id: rip
        target: HttpRequest
    }

    RowLayout {
        Rectangle{
            width: 420
            height: 60
            TextInput {
                anchors.fill: parent
                horizontalAlignment: TextInput.AlignLeft
                verticalAlignment: TextInput.AlignVCenter
                id: tex
                text: "insert the word"
            }
        }
        Button {
            width: 60
            height: 60
            Material.background: Material.Teal
            //color: "blue"
            onClicked: {
                HttpRequest.getData(tex.text)
            }
        }
    }


}
