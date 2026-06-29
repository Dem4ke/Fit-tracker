import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Window {
    // Window properties
    id: root
    width: 500
    height: 500
    visible: true
    color: backColor
    title: qsTr("Fit tracker")

    property color backColor: "#2B2B30"

    MainPage {
        id: mainPage
        anchors.fill: parent
    }
}