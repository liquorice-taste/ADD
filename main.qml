import QtQuick 2.12
//import QtQuick.Controls 2.5
import QtQuick.Window 2.11
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQml 2.12
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: win
    visible: true
    width: 480
    height: 640
    Material.theme: Material.System
    Material.accent: Material.Purple
    Material.background: Material.Teal

    Column {
        ToolBar {
            Material.theme: Material.System
            Material.accent: Material.Purple
            Material.background: Material.Teal
            height: parent.height * 0.07
                RowLayout {
                    anchors.fill: parent
                    ToolButton {
                        text: qsTr("‹")
                        onClicked: stack.pop()
                    }
                    Label {
                        text: "Awesome Dictionary"
                        elide: Label.ElideRight
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment: Qt.AlignVCenter
                        Layout.fillWidth: true
                    }
                    ToolButton {
                        text: qsTr("⋮")
                        onClicked: menu.open()
                    }
                }
            }
        anchors.fill: parent
        spacing: 0
        Rectangle {

            color: "red"
            width: parent.width
            height: parent.height * 0.05
            SearchArea{
                id: searchArea
                antialiasing: false
                anchors.fill: parent
                clip: false
                visible: true
            }
        }

        Rectangle {
            id: rec
            color: "green"
            width: parent.width
            height: parent.height * 0.88
            TabView{

                style: TabViewStyle {

                    frameOverlap: 1
                    tab: Rectangle {
                        //color: styleData.selected ? "steelblue" :"lightsteelblue"
                        //border.color:  "steelblue"
                        implicitWidth: rec.width / 2
                        implicitHeight: win.height * 0.05
                        radius: 2
                        Text {
                            id: txt
                            anchors.centerIn: parent
                            text: styleData.title
                            //color: styleData.selected ? "white" : "black"
                        }
                    }
                    //frame: Rectangle { color: "steelblue" }
                }
                anchors.fill: rec
                tabPosition: Qt.BottomEdge
                Material.theme: Material.Dark
                Material.accent: "#333745"
                //anchors.fill:parent
                //anchors.top: searchArea.bottom
                //Layout.fillWidth: true
                //anchors.top: searchArea.bottom
                //anchors.left: parent.width
                //anchors.right: parent.height
                //anchors.fill: parent

                Tab{

                    title: "Dictionary"

                    DictionaryList {
                        //anchors.centerIn: parent
                    }
                }
                Tab{
                    title: "Theasaurus"
                }
            }
        }
    }
}
