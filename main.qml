import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4

ApplicationWindow {
    id: window
    visible: true
    width: 300
    height: 400

    title: qsTr("Awesome Dictionary")

    Connections {
            target: hi // Specify the target connection
            /* We declare and implement a function as an object parameter and
             * first name similar to the name of the signal.
             * The difference is that we add at the beginning on and
             * then write with a capital letter
             *
            onSendToQml: {
                labelCount.text = count // Set the counter to a text label
            } */
        }

    Row {
        id: inputLayout
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.2 * window.height

        TextInput{
            id: searchInput
            width: 0.8 * inputLayout.width
            horizontalAlignment: TextInput.AlignHCenter
        }
        Button {
            width: 0.2 * inputLayout.width
            onClicked: {
                hi.getData(searchInput.text)
            }
        }
    }
}
