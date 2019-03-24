import QtQuick 2.11
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import Model 1.0

Rectangle {
    //border.color: "#000001"


    //"#00BDF2"
    ListView {
        //implicitWidth: 250
        //implicitHeight: 250
        anchors.fill: parent
        clip: true
        model: dicModel

        delegate: ColumnLayout {
            width: parent.width

            Text {
                text: "Headword Entry: " + id + " " + word + " " + language
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
                            text: "Lexical Entries:"
                        }

                        Text {
                            text: lexicalcathegory
                        }

                        Text {
                            text: ltext + language
                        }

                        Column {
                            Repeater {
                                model: EntryModel {
                                    list : entries
                                }
                                delegate: ColumnLayout {

                                    Column {

                                        Column {
                                            Repeater {
                                                model: SenseModel {
                                                    list : senses
                                                }
                                                delegate: ColumnLayout {
                                                    Text {
                                                        text: "senses list:"
                                                    }

                                                    Text {
                                                        text: ltext
                                                    }

                                                    Column {
                                                        Repeater {
                                                            model: ExampleModel {
                                                                list : examples
                                                            }
                                                            delegate: ColumnLayout {
                                                                Text {
                                                                    text: ltext
                                                                }

                                                            }
                                                        }
                                                    }

                                                }
                                            }
                                        }
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


