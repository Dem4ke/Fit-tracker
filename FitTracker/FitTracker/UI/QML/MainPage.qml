import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Page {
    property color backColor: "#2B2B30"
    property int baseMargin: 10
    property int radius: 50

    // Show days as a week list
    RowLayout {
        id: weekListLayout
        spacing: baseMargin
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: baseMargin
/*
        Button {
            text: "Previous week"
            onClicked: mainPage.weekList.previousRow()
        }*/

        Repeater {
            model: mainPage.weekList

            Rectangle {
                radius: root.radius
                width: root.radius
                height: root.radius

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        mainPage.setNewDay(date);
                    }
                }
            }
        }
/*
        Button {
            text: "Next week"
            onClicked: mainPage.weekList.nextRow()
        }*/

        // Empty item
        /*
        Item {
            Layout.fillWidth: true
        }

        // Weight widget
        Rectangle {
            Text {
                anchors.fill: parent
                text: mainPage.day.weight
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    // Show weight widget
                }
            }
        }*/
    }
}