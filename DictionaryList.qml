import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Model 1.0

ColumnLayout {
    Frame {
        Layout.fillWidth: true

        ListView {
            implicitWidth: 250
            implicitHeight: 250
            anchors.fill: parent
            clip: true

            model: DicModel {
                list: headEntry
            }

            delegate: RowLayout {
                width: parent.width

                TextField {
                    text: language
                    onEditingFinished: model.language = text
                    Layout.fillWidth: true
                }
                ListView {
                    model: LexicalEntryModel{
                    list : lexicalEntries
                    }
                    delegate: RowLayout {
                        TextField {
                            text: model.text
                        }
                    }
                }
            }
        }
    }

    RowLayout {
        Button {
            text: qsTr("Add new item")
            onClicked: headEntry.appendItem()
            Layout.fillWidth: true
        }
        Button {
            text: qsTr("Remove completed")
            onClicked: headEntry.removeCompletedItems()
            Layout.fillWidth: true
        }
    }


}
