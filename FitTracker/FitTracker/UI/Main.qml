import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Window {
    // Window properties
    id: root
    width: 1920
    height: 1080
    visible: true
    color: backColor
    title: qsTr("Fit tracker")

    // Properties
    property color backColor: "#2B2B30"
    property int margin: 10

    // Основной компоновщик элементов
    RowLayout {
        id: mainPage
        anchors.fill: parent

        // Заглушка для работы с кнопками переключения режимов
        ColumnLayout {
            id: modeLayout
            Layout.fillHeight: true

            Rectangle {
                width: 50
                height: 50
            }
            Rectangle {
                width: 50
                height: 50
            }
            Rectangle {
                width: 50
                height: 50
            }
            Rectangle {
                width: 50
                height: 50
            }
            Item {
                Layout.fillHeight: true
            }
        }

        // Страница с главной работой приложения
        Page {
            id: page
            Layout.fillWidth: true
            Layout.fillHeight: true

            // Days buttons
            header: RowLayout {
                id: daysLayout
                anchors.right: parent.right

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }
                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }
                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }
                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }
                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }
                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }
                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }

                // Заглушка для календаря
                Rectangle {
                    width: 50
                    height: 50
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHRight
                }
            }

            // Main tables of meals
            TableView {
                id: tableView
                anchors.fill: parent

                model: tableModel
                delegate: TableDelegate {}
            }

            //fotter:
        }
    }
}
