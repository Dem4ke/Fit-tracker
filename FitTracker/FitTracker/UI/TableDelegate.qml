import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: tableDelegate

    required property int row
    required property int column
    required property bool selected
    required property bool current

    implicitWidth: 150
    implicitHeight: 40

    border.width: 1
    border.color: "#dddddd"

    color: selected
        ? "#e6f2ff"
        : (row % 2 === 0 ? "#fafafa" : "white")

    Text {
        anchors.fill: parent
        anchors.margins: 8
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        elide: Text.ElideRight

        // If your model only provides Qt::DisplayRole:
        text: display

        font.pixelSize: 14
    }
}