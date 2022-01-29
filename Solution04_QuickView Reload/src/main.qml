import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import com.bizerba.Settings 1.0

Item {
    width: 360
    height: 360
    visible: true

    Row {
        spacing: 20
        anchors.centerIn: parent

        ComboBox {
            id: comboBox
            model: ["Default", "Material", "Universal"]
        }

        Button {
            text: "Reload"
            onClicked: engine.reloadStyle(comboBox.currentText)
        }
    }
}
