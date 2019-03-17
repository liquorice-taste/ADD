import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import Model 1.0


Rectangle {
    border.color: "#000001"


    //"#00BDF2"
    ListView {
        implicitWidth: 250
        implicitHeight: 250
        anchors.fill: parent
        clip: true
        model: DicModel {
            onModelReset: {
                console.log("changed")
            }

            list: headEntry

        }

        delegate: ColumnLayout {
            width: parent.width

            Text {
                text: "head: " + language
                //onEditingFinished: model.language = "head: " + text
                Layout.fillWidth: true
                Material.accent: "#fff"
            }
            Column {
                Repeater {
                    model: LexicalEntryModel{
                        list : lexicalEntries
                    }
                    delegate: ColumnLayout {
                        Text {
                            text: language
                        }

                        Text {
                            text: "lex u: " + ltext + language + "\n" + lexicalcathegory
                        }
                    }
                }
            }

            /*ListView {
                    model: LexicalEntryModel{
                    list : lexicalEntries
                    }
                    delegate: ColumnLayout {
                        TextField {
                            text: model.text
                        }
                        TextField {
                            text: model.language
                        }
                    }
                }*/
        }
    }
}


