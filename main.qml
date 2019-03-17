import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQml 2.3
import QtQuick.Controls.Material 2.3


ApplicationWindow {
    id: win
    visible: true
    //Imagine:
    Material.theme: Material.Dark
    Material.accent: Material.Purple
    width: 480
    height: 640
    title: qsTr("Hello World")
    ColumnLayout {
        anchors.fill:parent
        anchors.top: parent.top
        spacing: 3

        Rectangle{
            height: childrenRect.height
            Layout.alignment: Qt.AlignCenter
            //color: "red"
            Layout.preferredWidth: 480
            Layout.preferredHeight: 40
            SearchArea{
                id: searchArea
                //anchors.fill:parent
            }
        }
        Rectangle
        {
            height: childrenRect.height

            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            //color: "blue"
            Layout.preferredWidth: 480
            Layout.preferredHeight: 40
            TabView{
                anchors.fill:parent
                tabPosition: Qt.BottomEdge
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
                /*style: TabViewStyle {
                        frameOverlap: 1
                        tab: Rectangle {
                            color: styleData.selected ? "steelblue" :"lightsteelblue"
                            border.color:  "steelblue"
                            implicitWidth: win.width / 2
                            implicitHeight: 40
                            radius: 2
                            Text {
                                id: tex
                                anchors.centerIn: parent
                                text: styleData.title
                                color: styleData.selected ? "white" : "black"

                            }
                        }
                        frame: Rectangle { color: "steelblue" }
                    }*/
            }
        }
    }
}
