import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4
import "qrc:/styles/componentCreation.js" as Style

Item {
	id : base
    visible: true
    width: 600
    height: 400

    property QtObject currentStyle : Style.createStyleObject(base,"qrc:/styles/" + QSettings.value("styles/skin") + "/Style.qml");

	Rectangle{
		id:idRect1
		objectName : "objRect1"
		color: "teal"
		height: idButton1.height
		anchors.left : parent.left
		anchors.right : parent.right

		Button {
			id: idButton1
			objectName: "objButton1"
			width: 173
			height: 88
			anchors.right : parent.right
			text: qsTr("txtButton1")
			onClicked:
			{
                if( "skin1" == QSettings.value("styles/skin") ){
					QSettings.setValue("styles/skin","skin2");
                    currentStyle = Style.createStyleObject(base,"qrc:/styles/" + QSettings.value("styles/skin") + "/Style.qml");
					console.log("StyleB");
                }
                else{
					QSettings.setValue("styles/skin","skin1");
                    currentStyle = Style.createStyleObject(base,"qrc:/styles/" + QSettings.value("styles/skin") + "/Style.qml");
                    console.log("StyleA");
                }
				QSettings.setValue("styles/textSize", currentStyle.textSize);
				QSettings.setValue("styles/textColor", currentStyle.textColor);
			}
		}

		Text {
			x: 100
			y: 0
			font.pixelSize: currentStyle.textSize
			color: currentStyle.textColor
			text: "Hello World"
		}
	}
    Rectangle{
        id:idRect2
		objectName : "objRect2"
        color: "plum"
        height:parent.height * 2 / 3
        anchors.left : parent.left
        anchors.right : parent.right
        anchors.top:idRect1.bottom

    }
}